/** @file Contenedor.hh
    @brief Especificació de la classe Contenedor 
*/

#ifndef _CONTENEDOR
#define _CONTENEDOR

#include <string>

using namespace std;

/** @class Contenedor
    @brief Representa un contenidor amb una matrícula i una longitud
*/
class Contenedor {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és un contenidor sense matrícula i longitud zero
*/   
Contenedor();

/** @brief Creadora amb atributs 
      \pre <em>m</em> és una matrícula vàlida i <em>l</em> val entre 1 i 3
      \post El resultat és un contenidor amb matrícula <em>m</em> i longitud <em>l</em>
*/   
Contenedor (const string& m, int l);

/** @brief Creadora de còpia 
      \pre <em>Cert</em>
      \post El resultat és un contenidor amb la mateixa matrícula i longitud que <em>c</em>
*/
Contenedor(const Contenedor& c);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Contenedor
*/   
~Contenedor();

// Consultores

/** @brief Consultora de la longitud d'un contenidor
      \pre <em>Cert</em>
      \post El resultat és la longitud del contenidor p.i.
*/
int longitud() const;

/** @brief Consultora de la matrícula d'un contenidor
      \pre <em>Cert</em>
      \post El resultat és la matrícula del contenidor p.i.
*/
string matricula() const;

// Entrada/sortida

/** @brief Operació d'escriptura del contenidor
      \pre <em>cert</em>
      \post S'ha escrit la matrícula i la longitud del p.i. pel canal estàndar de sortida en format <em>m</em>(<em>l</em>)
*/
void print() const;

// Operadors

/** @brief Operador d'assignació 
      \pre <em>Cert</em>
      \post El resultat és un contenidor amb la mateixa matrícula i longitud que <em>c</em>
*/  
Contenedor& operator=(const Contenedor& c);

/** @brief Operador d'igualtat 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>c</em> tenen la mateixa matrícula i longitud
*/  
bool operator==(const Contenedor& c) const;

/** @brief Operador de desigualtat 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>c</em> tenen la matrícula o la longitud diferent
*/
bool operator!=(const Contenedor& c) const;

/** @brief Operador de menor 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor que <em>c</em> en ordre lexicogràfic per matrícula o en cas d'empat per longitud
*/
bool operator<(const Contenedor& c) const;  

/** @brief Operador de menor o igual 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor o igual que <em>c</em> segons els operadors de menor i d'igualtat
*/
bool operator<=(const Contenedor& c) const;

/** @brief Operador de major 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major que <em>c</em> segons els operadors de menor i d'igualtat
*/
bool operator>(const Contenedor& c) const;

/** @brief Operador de major o igual 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major o igual que <em>c</em> segons els operadors de menor i d'igualtat
*/
bool operator>=(const Contenedor& c) const;

private:

  static bool matricula_valida(const string& s);

  string mat;
  int lon;
};
 
#endif
