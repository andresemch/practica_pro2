#include "Contenedor.hh"
#include <iostream>
#include <cassert>

using namespace std;

bool Contenedor::matricula_valida(const string& s)
{
  if (s.size() == 0) return false;
  if (s[0] < 'A' or s[0] > 'Z') return false;
  for (unsigned int i = 1; i < s.size(); i++) {
    if ((s[i] < 'A' or s[i] > 'Z') and (s[i] < '0' or s[i] > '9'))
    	return false;
  }
  return true;
}

Contenedor::Contenedor() {
  mat = "";
  lon = 0;
}

Contenedor::Contenedor(const string& m, int l) {
  assert(matricula_valida(m));
  assert(l >= 1 and l <= 3);
  mat = m;
  lon = l;
}

Contenedor::Contenedor(const Contenedor &c) {
  mat = c.mat;
  lon = c.lon;
}

Contenedor::~Contenedor() {
}

int Contenedor::longitud() const {
  return lon;
}

string Contenedor::matricula() const {
  return mat;
}

void Contenedor::print() const {
  cout << mat << "(" << lon << ")";
}

Contenedor& Contenedor::operator=(const Contenedor &c) {
  if (this != &c) {
    mat = c.mat;
    lon = c.lon;
  }
  return *this;
}

bool Contenedor::operator==(const Contenedor& c) const {
  return ((lon == c.lon) and (mat == c.mat));
}

bool Contenedor::operator!=(const Contenedor& c) const {
  return ((lon != c.lon) or (mat != c.mat));
}

bool Contenedor::operator<(const Contenedor& c) const {
  return ((mat < c.mat) or ((mat == c.mat) and (lon < c.lon)));
}

bool Contenedor::operator<=(const Contenedor& c) const {
  return ((*this == c) or (*this < c));
}

bool Contenedor::operator>(const Contenedor& c) const {
  return (not(*this <= c));
}

bool Contenedor::operator>=(const Contenedor& c) const {
  return ((*this == c) or (*this > c));
}
