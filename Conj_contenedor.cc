#include "Conj_contenedor.hh"
#include <iostream>
using namespace std;

Conj_contenedor::Conj_contenedor() {
  map<string,Segmento> ccont;
}

Conj_contenedor::Conj_contenedor(const Conj_contenedor& c) {
  map<string,Segmento> ccont = c.ccont;
}

Conj_contenedor::~Conj_contenedor() {}

bool Conj_contenedor::existeix_cont(string mat) {
  map<string,Segmento>::iterator it = ccont.find(mat);
  return (it != ccont.end());
}

bool Conj_contenedor::esta_buit() {
  map<string,Segmento>::iterator it = ccont.begin();
  return (it == ccont.end());
}

int Conj_contenedor::longitud(string mat) const {
  map<string,Segmento>::const_iterator it = ccont.find(mat);
  Segmento g = it->second;
  return (g.longitud());
}

Ubicacion Conj_contenedor::ubi(string mat) const {
  map<string,Segmento>::const_iterator it;
  it = ccont.find(mat);
  Segmento g = it->second;
  Ubicacion u = g.ubic();
  return u;
}

void Conj_contenedor::print() const {
  for (map<string,Segmento>::const_iterator it=ccont.begin(); it!=ccont.end(); ++it) {
    Segmento g = it->second;
    cout << it->first;
    g.print();
    cout << endl;
  }
}

void Conj_contenedor::escriu_ubi_cont(Contenedor& cont) const {
  string mat = cont.matricula();
  map<string,Segmento>::const_iterator it;
  it = ccont.find(mat);
  Segmento g = it->second;
  Ubicacion u = g.ubic();
  u.print();
  cout << endl;
}

void Conj_contenedor::afegeix_contenidor(const Contenedor& c, Ubicacion u) {
  int l = c.longitud();
  Segmento g(u,l);
  ccont.insert(pair<string,Segmento> (c.matricula(), g));
}

void Conj_contenedor::elimina_contenidor(string mat) {
  map<string,Segmento>::const_iterator it;
  it = ccont.find(mat);
  ccont.erase(it);
}

void Conj_contenedor::buidar() {
  ccont.clear();
}
