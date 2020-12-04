/** @file Area_espera.hh
    @brief Especificació de la classe Area_espera
*/

#ifndef _AREA_ESPERA
#define _AREA_ESPERA

#include "Contenedor.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <list>
#endif

using namespace std;

/** @class Area_espera
    @brief Representa una pila de contenidors amb esctructura classe Contenedor
*/

class Area_espera {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és una àre de espera buida
*/
Area_espera();

/** @brief Creadora amb atributs
      \pre <em>Cert</em>
      \post El resultat és una àrea de espera inicialitzada amb el paràmetre <em>cont</em>
*/
Area_espera(const Contenedor& cont);

/** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat és una pila igual a la del paràmetre <em>esp</em>
*/
Area_espera(const Area_espera& esp);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Area_espera
*/
~Area_espera();

// Consultores

/** @brief Consultora de la llista de contenidors de l'àrea d'espera
      \pre <em>Cert</em>
      \post El resultat és la llista àrea d'espera del p.i.
*/
list<Contenedor> llista() const;

/** @brief Consultora si existeix un contenidor amb la mateixa matricula
      \pre 0 <em>Cert</em>
      \post Torna un valor booleà dient si dit contenidor existeix al p.i.
*/
bool existeix_cont(string mat) const;

// Entrada/sortida

/** @brief Operació d'escriptura del p.i. per ordre de sortida
      \pre 0 <em>Cert</em>
      \post Mostra la pila del p.i. mostrant paràmetres matrícula i longitud
            pertanyents als elements de l'objecte de la classe Contenedor
*/
void print() const;

// Modificadores

/** @brief Modificadora d'addició d'element Contenedor al p.i.
      \pre <em> Cert </em>
      \post El resultat serà el p.i. area_espera amb un contenidor cont afegit
*/
void afegeix_contenidor(const Contenedor& cont);

/** @brief Modificadora de supressió d'element Contenedor al p.i.
      \pre <em> Cert </em>
      \post El resultat serà el p.i. area_espera amb un contenidor cont suprimit
*/
void retira_contenidor(string mat);

/** @brief Modificadora que buida l'àrea d'espera
      \pre <em>cert</em>
      \post Buida el p.i.
*/
void buidar();

private:

  list<Contenedor> area_espera;

};

#endif
