/** @file Segmento.hh
    @brief Especificació de la classe Segmento 
*/

#ifndef _SEGMENTO
#define _SEGMENTO

#include "Ubicacion.hh"

using namespace std;

/** @class Segmento
    @brief Representa un segment amb una ubicació i una longitud
*/
class Segmento {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és un segment amb ubicació (-1,-1,-1) i longitud zero
*/   
Segmento();

/** @brief Creadora amb atributs 
      \pre <em>u</em> és una ubicació vàlida i <em>l</em> > 0
      \post El resultat és un contenidor amb ubicació <em>u</em> i longitud <em>l</em>
*/   
Segmento(const Ubicacion &u, int l);

/** @brief Creadora de còpia 
      \pre <em>Cert</em>
      \post El resultat és un segment amb la mateixa ubicació i longitud que <em>s</em>
*/
Segmento(const Segmento &s);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Segmento
*/   
~Segmento();

// Consultores

/** @brief Consultora de la ubicació d'un segment
      \pre <em>Cert</em>
      \post El resultat és la ubicació del segment p.i.
*/
Ubicacion ubic() const;

/** @brief Consultora de la longitud d'un segment
      \pre <em>Cert</em>
      \post El resultat és la longitud del segment p.i.
*/
int longitud() const;

// Entrada/sortida

/** @brief Operació d'escriptura del segment
      \pre <em>Cert</em>
      \post S'ha escrit la ubicació i la longitud del p.i. pel canal estàndar de sortida en format (<em>u</em>,<em>l</em>)
*/
void print() const;

// Operadors

/** @brief Operador d'assignació 
      \pre <em>Cert</em>
      \post El resultat és un segment amb la mateixa ubicació i longitud que <em>s</em>
*/  
Segmento& operator=(const Segmento &s);

/** @brief Operador d'igualtat 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>s</em> tenen la mateixa ubicació i longitud
*/  
bool operator==(const Segmento &s) const;  

/** @brief Operador de desigualtat 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. i <em>s</em> tenen la ubicació o la longitud diferent
*/
bool operator!=(const Segmento &s) const;  

/** @brief Operador de menor 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor que <em>s</em> per longitud o en cas d'empat per ubicació
*/
bool operator<(const Segmento &s) const;  

/** @brief Operador de menor o igual 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és menor o igual que <em>s</em> segons els operadors de menor i d'igualtat
*/
bool operator<=(const Segmento &s) const;  

/** @brief Operador de major 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major que <em>s</em> segons els operadors de menor i d'igualtat
*/
bool operator>(const Segmento &s) const;  

/** @brief Operador de major o igual 
      \pre <em>Cert</em>
      \post El resultat indica si el p.i. és major o igual que <em>s</em> segons els operadors de menor i d'igualtat
*/
bool operator>=(const Segmento &s) const;  


private:
    // Ubicacion y longitud

    Ubicacion u;
    int l;
};

#endif
