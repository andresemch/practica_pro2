#include "Terminal.hh"
#include <iostream>
using namespace std;

Terminal::Terminal() {
  n = 0;
  m = 0;
  h = 0;
}

Terminal::Terminal(const Terminal& t) {
  n = t.n;
  m = t.m;
  h = t.h;
  terminal = t.terminal;
}

Terminal::~Terminal() {}

void Terminal::dimensiona(int fil, int pla, int pis) {
  n = fil;
  m = pla;
  h = pis;
  terminal = vector<vector<vector<string>>> (n,vector<vector<string>>(m,vector<string>(h)));
}

int Terminal::nombre_fileres() const {
  return n;
}

int Terminal::nombre_places() const {
  return m;
}

int Terminal::nombre_pisos() const {
  return h;
}

bool Terminal::esta_ocupada(const Ubicacion& u) const {
  return (terminal[u.hilera()][u.plaza()][u.piso()] != "");
}

bool Terminal::existeix_ubi(int i, int j, int k) const {
  if (i < 0 or i >= n) return false;
  else if (j < 0 or j >= m) return false;
  else if (k < 0 or k >= h) return false;
  else return true;
}

void Terminal::mostra_cont(int ubi_fileres, int ubi_places, int ubi_pisos) const {
  if (terminal[ubi_fileres][ubi_places][ubi_pisos] != "") {
    cout << terminal[ubi_fileres][ubi_places][ubi_pisos] << endl;
  } else {
    cout << endl;
  }
}

void Terminal::imprimeix_magatzem() {
  for (int i=0; i<n; ++i) {
    cout << "hilera " << i << endl;
    for (int k=h-1; k>=0; --k) {
      cout << k << ' ';
      for (int j=0; j<m; ++j) {

        if (terminal[i][j][k] != "") {
          string s = terminal[i][j][k];
          cout << s.at(0);
        }
        else cout << ' ';

      }
      cout << endl;
    }
    cout << "  ";
    for (int npla=0; npla<m; ++npla) cout << npla%10;
    cout << endl << endl;
  }
}

void Terminal::funcio_recursiva(const Ubicacion& u, int lon, Conj_huecos& ch, Area_espera& aesp, Conj_contenedor& cc) {
  int i=u.hilera(), j=u.plaza(), k=u.piso();
  for (int it=0; it<lon and k+1<h; ++it) {
    string mat = terminal[i][j+it][k+1];
    if (mat != "") {
      Ubicacion pos = cc.ubi(mat);
      int length = cc.longitud(mat);
      funcio_recursiva(pos,length,ch,aesp,cc);
    }
  }
  string matricula = terminal[i][j][k];
  Contenedor cont(matricula, lon);
  retira_contenidor(cont,u); //Desapareix del p.i. terminal
  cc.elimina_contenidor(matricula); //Desapareix del cc
  Ubicacion ubic(-1,0,0);
  cc.afegeix_contenidor(cont, ubic); //S'afegeix al cc com a element àrea espera
  regenera_retira(u,ch,lon); // posar en private si no surt a program.cc
  aesp.afegeix_contenidor(cont);
}

void Terminal::inserta_area_espera(Conj_huecos& ch, Area_espera& aesp, Conj_contenedor& cc) {
  bool es_pot_colocar = true;
  list<Contenedor> area_espera = aesp.llista();
  while (es_pot_colocar) {
    list<Contenedor>::iterator it = area_espera.begin();
    bool trobat = false;
    while (it != area_espera.end() and !trobat) {
      Ubicacion u(ch.espai_valid((*it).longitud())); //troba l'espai vàlid per al cont
      Ubicacion u_no_existeix(-1,0,0);
      if (u == u_no_existeix) ++it;
      else {
        Contenedor c((*it).matricula(),(*it).longitud());
        afegeix_contenidor(c,u);
        regenera_inserta(u,ch,(*it).longitud());
        cc.elimina_contenidor((*it).matricula());
        cc.afegeix_contenidor(c,u);
        aesp.retira_contenidor((*it).matricula());
        it = area_espera.erase(it);
        trobat = true;
      }
    }
    if (it == area_espera.end() and !trobat) es_pot_colocar = false;
  }
}

void Terminal::afegeix_contenidor(const Contenedor& cont, Ubicacion& u/*, Area_espera& aesp*/) {
  for (int i=0; i<cont.longitud(); ++i) {
    terminal[u.hilera()][u.plaza()+i][u.piso()] = cont.matricula();
  }
}

void Terminal::retira_contenidor(const Contenedor& cont, const Ubicacion& u) {
  for (int i=0; i<cont.longitud(); ++i) {
    terminal[u.hilera()][u.plaza()+i][u.piso()] = "";
  }
}

void Terminal::regenera_inserta(const Ubicacion& u, Conj_huecos& ch, int lon) {
  int i = u.hilera(), j = u.plaza(), k = u.piso();
  int dist_r = dist_dreta(i,j+lon,k);
  if (dist_r != 0) {
    Ubicacion ubic(i,j+lon,k);
    ch.afegeix_espai(ubic,dist_r);
  }
  if (k+1 < h) {
    int dist_l_sup = dist_esquerra(i,j-1,k+1);
    int dist_r_sup = dist_dreta(i,j+lon,k+1);
    if (dist_l_sup != 0) {
      Ubicacion ubic_sup(i,j-dist_l_sup,k+1);
      ch.elimina_espai(ubic_sup,dist_l_sup);
      ch.afegeix_espai(ubic_sup,dist_l_sup+lon+dist_r_sup);
    } else {
      Ubicacion ubic_sup(i,j,k+1);
      ch.afegeix_espai(ubic_sup,lon+dist_r_sup);
    }
    if (dist_r_sup != 0) {
      Ubicacion ubic_sup(i,j+lon,k+1);
      ch.elimina_espai(ubic_sup,dist_r_sup);
    }
  }
}

void Terminal::regenera_retira(const Ubicacion& u, Conj_huecos& ch, int lon) {
  int i = u.hilera(), j = u.plaza(), k = u.piso();
  int dist_r = dist_dreta(i,j+lon,k);
  int dist_l = dist_esquerra(i,j-1,k);
  if (dist_l != 0) {
    Ubicacion ubic(i,j-dist_l,k);
    ch.elimina_espai(ubic,dist_l);
    ch.afegeix_espai(ubic,dist_l+lon+dist_r);
  } else {
    Ubicacion ubic(i,j,k);
    ch.afegeix_espai(ubic,lon+dist_r);
  }
  if (dist_r != 0) {
    Ubicacion ubic(i,j+lon,k);
    ch.elimina_espai(ubic,dist_r);
  }
  if (k+1 < h) {
    int dist_l_sup = dist_esquerra(i,j-1,k+1);
    int dist_r_sup = dist_dreta(i,j+lon,k+1);
    if (dist_l_sup != 0) {
      Ubicacion ubic_sup(i,j-dist_l_sup,k+1);
      ch.elimina_espai(ubic_sup,dist_l_sup+lon+dist_r_sup);
      ch.afegeix_espai(ubic_sup,dist_l_sup);
    } else {
      Ubicacion ubic_sup(i,j,k+1);
      ch.elimina_espai(ubic_sup,lon+dist_r_sup);
    }
    if (dist_r_sup != 0) {
      Ubicacion ubic_sup(i,j+lon,k+1);
      ch.afegeix_espai(ubic_sup,dist_r_sup);
    }
  }
}


int Terminal::dist_esquerra(int i, int j, int k) {
  int dist_esq = 0;
  bool final = false;
  while (!final and j-dist_esq >= 0) {
    if (terminal[i][j-dist_esq][k]=="" and (k==0 or terminal[i][j-dist_esq][k-1]!="")) ++dist_esq;
    else final = true;
  }
  return dist_esq;
}

int Terminal::dist_dreta(int i, int j, int k) {
  int dist_dre = 0;
  bool final = false;
  while (!final and j+dist_dre < m) {
    if (terminal[i][j+dist_dre][k]=="" and (k==0 or terminal[i][j+dist_dre][k-1]!="")) ++dist_dre;
    else final = true;
  }
  return dist_dre;
}
