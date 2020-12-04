/** @file Conj_huecos.hh
    @brief Especificació de la classe Conj_huecos
*/

#ifndef _CONJ_HUECOS
#define _CONJ_HUECOS

#include "Segmento.hh"
#include "Ubicacion.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <set>
#endif

using namespace std;

/** @class Conj_huecos
    @brief Representa una conjunt de d'espais vàlids per a posicionar els següents contenidors
*/

class Conj_huecos {

public:

// Constructores

/** @brief Creadora sense atributs
      \pre <em>Cert</em>
      \post El resultat és un conjunt d'espais buit
*/
Conj_huecos();

/** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat és un conjunt d'espais
*/
Conj_huecos(const Conj_huecos& ch);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Conj_huecos
*/
~Conj_huecos();

// Consultores

/** @brief Escull el millor espai vàlid disponible
      \pre 1 >= <em>lon</em> <= 3
      \post Retorna la ubicació adient per a que es pugui insertar un contenidor amb longitud determinada
*/
Ubicacion espai_valid(int lon);

// Entrada/sortida

/** @brief Operació d'escriptura del conjunt d'espais
      \pre <em>cert</em>
      \post S'ha la ubicació i la longitud de cadascun dels elements del p.i. pel canal estàndar de sortida en format <em>m</em>(<em>l</em>)
*/
void print() const;

// Modificadores

/** @brief Modificadora amb atributs
      \pre <em>fil</em> > 0, <em>pla</em> > 0 i <em>pis<em> > 0
      \post El resultat és un conjunt d'espais creats a partir de dues de les dimensions: N <em>fil</em> i M <em>pla</em>
*/
void genera(int fil, int pla);

/** @brief Modificadora que buida conjunt d'espais
      \pre <em>Cert</em>
      \post Buida el conjunt
*/
void buidar();

/** @brief Modificadora d'addició d'un espai vàlid
      \pre <em>Cert</em> >
      \post El resultat és un conjunt d'espais amb un nou espai creat a partir de la ubicació i la longitud determinada
*/
void afegeix_espai(const Ubicacion& u, int lon);

/** @brief Modificadora de supressió d'un espai vàlid
      \pre <em>Cert</em> >
      \post El resultat és un conjunt d'espais amb un espai menys determinat a partir de la ubicació i la longitud determinada
*/
void elimina_espai(const Ubicacion& u, int lon);

private:

  vector<set<Ubicacion>> chuecos;
  int size;

};

#endif
