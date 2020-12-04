/** @file Conj_contenedor.hh
    @brief Especificació de la classe Conj_contenedor
*/

#ifndef _CONJ_CONTENEDOR
#define _CONJ_CONTENEDOR

#include "Contenedor.hh"
#include "Segmento.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif
using namespace std;

/** @class Conj_contenedor
    @brief Representa un conjunt de contenidors ordenat alfabèticament en funció de la matricula
*/
class Conj_contenedor {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és un conjunt de contenidors buit
*/
Conj_contenedor();

/** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat és un conjunt de contenidors amb els mateixos contenidors que <em>c</em>
*/
Conj_contenedor(const Conj_contenedor& c);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Conj_contenedor
*/
~Conj_contenedor();

// Consultores

/** @brief Consultora si existeix un contenidor amb la mateixa matricula
      \pre 0 <em>Cert</em>
      \post Torna un valor booleà dient si dit contenidor existeix al p.i.
*/
bool existeix_cont(string mat);

/** @brief Consultora si està buit el conjunt
      \pre 0 <em>Cert</em>
      \post Torna un valor booleà dient si dit el p.i. està buit o no
*/
bool esta_buit();

/** @brief Consultora del paràmetre longitud d'un objecte Segmento
      \pre <em>Cert</em>
      \post El resultat serà la longitud del contenidor amb matrícula <em>mat</em>
*/
int longitud(string mat) const;

/** @brief Consultora d'ubicació d'un contenidor en funció de la matricula
      \pre 0 <em>Cert</em>
      \post Retorna un objecte Ubicacion amb coordenades del contenidor al p.i.
*/
Ubicacion ubi(string mat) const;

// Entrada/sortida

/** @brief Operació d'escriptura del conjunt de contenidors
      \pre <em>cert</em>
      \post S'ha escrit la matrícula, la ubicació i la longitud de cadascun dels elements del p.i. pel canal estàndar de sortida en format <em>m</em>(<em>l</em>)
*/
void print() const;

/** @brief Operació d'escriptura d'ubicació d'un contenidor en funció de la matricula
      \pre 0 <em>Cert</em>
      \post Mostra un objecte Ubicacion amb coordenades del contenidor al p.i.
*/
void escriu_ubi_cont(Contenedor& cont) const;

// Modificadores

/** @brief Modificadora d'afegit del conjunt de contenidors
      \pre <em>cert</em>
      \post Afegeix la matrícula al p.i.
*/
void afegeix_contenidor(const Contenedor& c, Ubicacion u);

/** @brief Modificadora de supressió del conjunt de contenidors
      \pre <em>cert</em>
      \post Afegeix la matrícula al p.i.
*/
void elimina_contenidor(string mat);

/** @brief Modificadora que buida conjunt de contenidors
      \pre <em>cert</em>
      \post Buida el conjunt
*/
void buidar();

private:

  map<string,Segmento> ccont;

};

#endif
