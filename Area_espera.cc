#include "Area_espera.hh"
#include <iostream>
using namespace std;

Area_espera::Area_espera() {}

Area_espera::Area_espera(const Contenedor& cont) {
  area_espera.push_back(cont);
}

Area_espera::Area_espera(const Area_espera& aesp) {
  area_espera = aesp.area_espera;
}

Area_espera::~Area_espera() {}

list<Contenedor> Area_espera::llista() const {
  return area_espera;
}

bool Area_espera::existeix_cont(string mat) const {
  list<Contenedor>::const_iterator it = area_espera.begin();
  while (it != area_espera.end()) {
    if ((*it).matricula() == mat) return true;
    ++it;
  }
  return false;
}


void Area_espera::print() const {
  for (list<Contenedor>::const_iterator it=area_espera.begin(); it!=area_espera.end(); ++it) {
    (*it).print();
    cout << endl;
  }
}

void Area_espera::afegeix_contenidor(const Contenedor& cont) {
  list<Contenedor>::iterator it = area_espera.begin();
  area_espera.insert(it,cont);
}

void Area_espera::retira_contenidor(string mat) {
  bool trobat = false;
  list<Contenedor>::iterator it = area_espera.begin();
  while (it != area_espera.end() and !trobat) {
    if ((*it).matricula() == mat) {
      it = area_espera.erase(it);
      trobat = true;
    }
    else ++it;
  }
}

void Area_espera::buidar() {
  area_espera.clear();
}
