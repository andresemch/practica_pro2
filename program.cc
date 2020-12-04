/**
 * @mainpage Gestión de una terminal de contenedores

Construimos un programa modular que ofrece un menú de opciones para gestionar una terminal de contenedores. Se introducen las clases <em>Contenedor</em>, <em>Segmento</em> y <em>Ubicacion</em>.
*/

/** @file main.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

#include "Ubicacion.hh"
#include "Contenedor.hh"
#include "Segmento.hh"
#include "Terminal.hh"
#include "Area_espera.hh"
#include "Conj_contenedor.hh"
#include "Conj_huecos.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif
using namespace std;

/** @brief Programa principal.
*/
int main() {
  Terminal term;
  Area_espera aespera;
  Conj_contenedor cc;
  Conj_huecos ch;

  string mat;
  int lon;
  int i,j,k;
  string comando;

  cin >> comando;
  while (comando != "fin") {

    if (comando == "crea_terminal") {
      if (!cc.esta_buit()) {
        cc.buidar();
        ch.buidar();
        aespera.buidar();
      }
      cin >> i >> j >> k;
      cout << "#crea_terminal " << i << ' ' << j << ' ' << k << endl;
      term.dimensiona(i,j,k);
      ch.genera(i,j);
    }

    cin >> comando;

    while (comando != "fin" and comando != "crea_terminal") {

      if (comando == "inserta_contenedor" or comando == "i") {
        cin >> mat >> lon;
        cout << '#' << comando << ' ' << mat << ' ' << lon << endl;
        Contenedor cont(mat,lon);
        if (cc.existeix_cont(mat)) {
          cout << "error: el contenedor ya existe" << endl;
        } else {
          Ubicacion u(ch.espai_valid(lon)); // (-1,-1,-1) en caso que no se encuentre espacio
          u.print();
          cout << endl;
          Ubicacion espera(-1,0,0);
          if (u == espera) aespera.afegeix_contenidor(cont);
          else {
            term.afegeix_contenidor(cont,u);
            term.regenera_inserta(u,ch,lon);
            term.inserta_area_espera(ch,aespera,cc);
          }
          cc.afegeix_contenidor(cont,u);
        }

      } else if (comando == "retira_contenedor" or comando == "r") {
       cin >> mat;
       cout << '#' << comando << ' ' << mat << endl;
       if (cc.existeix_cont(mat)) {
         if (aespera.existeix_cont(mat)) {
           aespera.retira_contenidor(mat);
         } else {
           int lon = cc.longitud(mat);
           Contenedor cont(mat,lon);
           Ubicacion u = cc.ubi(mat);
           term.funcio_recursiva(u,lon,ch,aespera,cc);
           aespera.retira_contenidor(mat);
           term.inserta_area_espera(ch,aespera,cc);
         }
         cc.elimina_contenidor(mat);

       } else {
         cout << "error: el contenedor no existe" << endl;
       }

      } else if (comando == "donde") {
       cin >> mat;
       cout << "#donde " << mat << endl;
       if (cc.existeix_cont(mat)) {
         int lon = cc.longitud(mat);
         Contenedor cont(mat,lon);
         cc.escriu_ubi_cont(cont);
       } else {
         cout << "<-1,-1,-1>" << endl;
       }

      } else if (comando == "longitud") {
        cin >> mat;
        cout << "#longitud " << mat << endl;
        if (cc.existeix_cont(mat)) {
          cout << cc.longitud(mat) << endl;
        } else {
          cout << "error: el contenedor no existe" << endl;
        }

      } else if (comando == "contenedor_ocupa") {
        int i, j, k;
        cin >> i >> j >> k;
        if (!term.existeix_ubi(i,j,k)) {
          if (i!=-1 or j!= 0 or k!=0){
            cout << "#contenedor_ocupa " << i << ' ' << j << ' ' << k << endl;
            cout << "error: ubicacion fuera de rango" << endl;
          }
        } else {
          cout << "#contenedor_ocupa " << i << ' ' << j << ' ' << k << endl;
          term.mostra_cont(i,j,k);
        }

        //ATENCIÓ: ha de mostrar espai en blanc en cas que a la ubicació no hi hagi cap contenidor

      } else if (comando == "num_hileras") {
        cout << "#num_hileras" << endl;
        cout << term.nombre_fileres() << endl;

      } else if (comando == "num_plazas") {
        cout << "#num_plazas" << endl;
        cout << term.nombre_places() << endl;

      } else if (comando == "num_pisos") {
        cout << "#num_pisos" << endl;
        cout << term.nombre_pisos() << endl;

      } else if (comando == "area_espera") {
        cout << "#area_espera" << endl;
        aespera.print();
        cout << endl;

      } else if (comando == "contenedores") {
        cout << "#contenedores" << endl;
        cc.print();
        cout << endl;

      } else if (comando == "area_almacenaje") {
        cout << "#area_almacenaje" << endl;
        term.imprimeix_magatzem();

      } else if (comando == "huecos") {
        cout << "#huecos" << endl;
        ch.print();
        cout << endl;

      }
      cin >> comando;
    }
  }
}
