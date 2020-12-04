/** @file Ubicacion.hh
    @brief Especificació de la classe Ubicacion
*/

#ifndef _UBICACION
#define _UBICACION

using namespace std;

/** @class Ubicacion
    @brief Representa una ubicació en una terminal amb 3 coordenades
*/
class Ubicacion {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és una ubicació amb coordenades virtuals (-1,-1,-1)
*/
Ubicacion();

/** @brief Creadora amb atributs
      \pre <em>i</em>,<em>j</em>,<em>k</em> són >= 0 o bé <em>i</em>,<em>j</em>,<em>k</em> són -1 o bé <em>i</em>=-1 i <em>j</em>,<em>k</em> són 0
      \post El resultat és una ubicació (<em>i</em>,<em>j</em>,<em>k</em>)
*/
Ubicacion(int i, int j, int k);

/** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat és una ubicació amb les mateixes coordenades que <em>u</em>
*/
Ubicacion(const Ubicacion &u);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Ubicacion
*/
~Ubicacion();

// Consultores

/** @brief Consultora de la fila d'una ubicació
      \pre <em>Cert</em>
      \post El resultat és la primera coordenada de la ubicació p.i.
*/
int hilera() const;

/** @brief Consultora de la plaça d'una ubicació
      \pre <em>Cert</em>
      \post El resultat és la segona coordenada de la ubicació p.i.
*/
int plaza() const;

/** @brief Consultora del pis d'una ubicació
      \pre <em>Cert</em>
      \post El resultat és la tercera coordenada de la ubicació p.i.
*/
int piso() const;

/** @brief Operació d'escriptura de la ubicació
      \pre <em>cert</em>
      \post S'ha escrit la ubicació p.i. pel canal estàndar de sortida en format <<em>x</em>,<em>y</em>,<em>z</em>>
*/
void print() const;

// Operadors

/** @brief Operador d'assignació
      \pre <em>Cert</em>
      \post El resultat és una ubicació amb les mateixes coordenades que <em>u</em>
*/
Ubicacion& operator=(const Ubicacion &u);

/** @brief Operador d'igualtat
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>u</em> tenen les mateixes coordenades
*/
bool operator==(const Ubicacion &u) const;

/** @brief Operador de desigualtat
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>u</em> tenen alguna coordenada diferent
*/
bool operator!=(const Ubicacion &u) const;

/** @brief Operador de menor
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor que <em>u</em> segons la primera coordenada, en cas d'empat segons la segona, i en cas d'empat segons la tercera
*/
bool operator<(const Ubicacion &u) const;

/** @brief Operador de menor o igual
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor o igual que <em>u</em> segons els operadors de menor i d'igualtat
*/
bool operator<=(const Ubicacion &u) const;

/** @brief Operador de major
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major que <em>u</em> segons els operadors de menor i d'igualtat
*/
bool operator>(const Ubicacion &u) const;

/** @brief Operador de major o igual
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major o igual que <em>u</em> segons els operadors de menor i d'igualtat
*/
bool operator>=(const Ubicacion &u) const;

private:
    // Coordenades de la ubicació
    int x, y, z;
};

#endif
