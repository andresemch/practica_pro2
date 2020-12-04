#include "Ubicacion.hh"
#include <iostream>

using namespace std;

Ubicacion::Ubicacion() {
  x = -1;
  y = -1;
  z = -1;
}

Ubicacion::Ubicacion(int i, int j, int k) {
//Pre:  ((i >= 0) and (j >= 0) and (k >= 0)) or
//      ((i == -1) and (j == 0) and (k == 0)) or
//      ((i == -1) and (j == -1) and (k == -1))
  x = i;
  y = j;
  z = k;
}

Ubicacion::Ubicacion(const Ubicacion &u) {
  x = u.x;
  y = u.y;
  z = u.z;
}

Ubicacion::~Ubicacion() {
}

int Ubicacion::hilera(void) const {
  return x;
}

int Ubicacion::plaza(void) const {
  return y;
}

int Ubicacion::piso(void) const {
  return z;
}

void Ubicacion::print() const {
  cout << "<" << x << "," << y << "," << z << ">";
}

Ubicacion& Ubicacion::operator=(const Ubicacion &u) {
  if (this != &u) {
    x = u.x;
    y = u.y;
    z = u.z;
  }
  return *this;
}

/* Prioridad estandar: hilera < plaza < altura */
bool Ubicacion::operator<(const Ubicacion& u) const
{
  return ((x < u.x) or
          ((x == u.x) and (y < u.y)) or
          ((x == u.x) and (y == u.y) and (z < u.z)));
}


/* Prioridad hilera < altura < plaza
bool Ubicacion::operator<(const Ubicacion& u) const
{
  return ((x < u.x) or
          ((x == u.x) and (z < u.z)) or
          ((x == u.x) and (z == u.z) and (y < u.y)));
}
*/

/* Prioridad altura < hilera < plaza
bool Ubicacion::operator<(const Ubicacion& u) const
{
  return ((z < u.z) or
          ((z == u.z) and (x < u.x)) or
          ((z == u.z) and (x == u.x) and (y < u.y)));
}
*/

bool Ubicacion::operator==(const Ubicacion& u) const {
  return ((x == u.x) and (y == u.y) and (z == u.z));
}

bool Ubicacion::operator!=(const Ubicacion& u) const {
  return not(*this == u);
}

bool Ubicacion::operator<=(const Ubicacion& u) const {
  return *this < u or u == *this;
}

bool Ubicacion::operator>=(const Ubicacion& u) const {
  return not (*this < u);
}

bool Ubicacion::operator>(const Ubicacion& u) const {
  return *this >= u and *this != u;
}
