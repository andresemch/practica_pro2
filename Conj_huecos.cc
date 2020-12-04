#include "Conj_huecos.hh"
#include <iostream>
using namespace std;

Conj_huecos::Conj_huecos() {
}

Conj_huecos::Conj_huecos(const Conj_huecos& ch) {
  size = ch.size;
  chuecos = ch.chuecos;
}

Conj_huecos::~Conj_huecos() {}

Ubicacion Conj_huecos::espai_valid(int lon) {
  Ubicacion u(-1,0,0);
  bool no_trobat = true;
  for (int i=lon; i<size and no_trobat; ++i) {
    if (!chuecos[i].empty()) {
      set<Ubicacion>::iterator it = chuecos[i].begin();
      u = *it;
      chuecos[i].erase(it);
      no_trobat = false;
    }
  }
  return u;
}

void Conj_huecos::print() const {
  for (int i=1; i<size; ++i) {
    set<Ubicacion> s=chuecos[i];
    for (set<Ubicacion>::iterator it=s.begin(); it!=s.end(); ++it) {
      cout << '(';
      (*it).print();
      cout << ',' << i << ')' << endl;
    }
  }
}

void Conj_huecos::genera(int fil, int pla) {
  size = pla+1;
  chuecos.resize(size);

  for (int i=0; i<fil; ++i) {
    set<Ubicacion> s;
    Ubicacion u(i,0,0);
    chuecos[pla].insert(u);
  }
}

void Conj_huecos::buidar() {
  for (int i=0; i<size; ++i) {
    chuecos[i].clear();
  }
}

void Conj_huecos::afegeix_espai(const Ubicacion& u, int lon) {
  chuecos[lon].insert(u);
}

void Conj_huecos::elimina_espai(const Ubicacion& u, int lon) {
  chuecos[lon].erase(u);
}
