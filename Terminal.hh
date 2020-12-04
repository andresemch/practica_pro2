/** @file Terminal.hh
    @brief Especificació de la classe Terminal
*/

#ifndef _TERMINAL
#define _TERMINAL

#include "Contenedor.hh"
#include "Ubicacion.hh"
#include "Conj_huecos.hh"
#include "Conj_contenedor.hh"
#include "Area_espera.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

using namespace std;

/** @class Terminal
    @brief Representa una terminal amb nombre de fileres, nombres de places i nombre de pisos
*/

class Terminal {

public:

// Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és una terminal sense cap paràmetre definit
*/
Terminal();

/** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat és una terminal amb la mateix N,M i H que <em>t</em>
*/
Terminal(const Terminal& t);

// Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Terminal
*/
~Terminal();

// Consultores

/** @brief Consultora del nombre de fileres de la terminal
      \pre <em>Cert</em>
      \post El resultat és el nombre de fileres del p.i.
*/
int nombre_fileres() const;

/** @brief Consultora del nombre de places de la terminal
      \pre <em>Cert</em>
      \post El resultat és el nombre de fileres del p.i.
*/
int nombre_places() const;

/** @brief Consultora del nombre de pisos de la terminal
      \pre <em>Cert</em>
      \post El resultat és el nombre de pisos del p.i.
*/
int nombre_pisos() const;

/** @brief Consultora de disponibilitat d'una plaça
      \pre <em>Cert</em>
      \post Torna un valor booleà dient si dita ubicació esta ocupada o no
*/
bool esta_ocupada(const Ubicacion& u) const;

/** @brief Consultora de si existeix dita ubicació
      \pre <em>Cert</em>
      \post Torna un valor booleà dient si dita ubicació entra dins de la terminal o no
*/
bool existeix_ubi(int i, int j, int k) const;

// Entrada/sortida

/** @brief Operació d'escriptura del que es troba a una ubicació determinada de la terminal
      \pre 0 <= <em>ubi_fileres</em> < N, 0 <= <em>ubi_places</em> < M i 0 <= <em>ubi_pisos</em> < H, hi ha un contenidor a dita posició
      \post El resultat serà el contenidor del p.i. terminal que hi ha a la ubicació
            Si la ubicació no està ocupada, no mostrarà res.
*/
void mostra_cont(int ubi_fileres, int ubi_places, int ubi_pisos) const;

/** @brief Operació d'escriptura de Ter
      \pre 0 <em>Cert</em>
      \post Mostra una representació bidimensional de cada filera amb cada
            inicial de matrícul
*/
void imprimeix_magatzem();

// Modificadores

/** @brief Modificadora amb atributs
      \pre <em>fil</em> > 0, <em>pla</em> > 0 i <em>pis<em> > 0
      \post El resultat és una terminal amb N <em>fil</em>, M <em>pla</em> i H <em>pis</em>
*/
void dimensiona(int fil, int pla, int pis);

/** @brief Modificadora de supressió en cas que hi hagi contenidor(s) a sobre del contenidor que es desitja retirar
      \pre <em>Cert<em>
      \post El resultat és una terminal amb els canvis pertinents en funció dels espais disponibles i l'àrea d'espera
*/
void funcio_recursiva(const Ubicacion& u, int lon, Conj_huecos& ch, Area_espera& aesp, Conj_contenedor& cc);

/** @brief Modificadora de l'àrea d'espera en funció dels nous espais generats
      \pre <em> Cert </em>
      \post S'afegiran a la terminal els contenidors de l'àrea d'espera que es puguin afegir
*/
void inserta_area_espera(Conj_huecos& ch, Area_espera& aesp, Conj_contenedor& cc);

/** @brief Modificadora d'addició d'element Contenedor al p.i.
      \pre <em> Cert </em>
      \post El resultat serà el p.i. Ter amb un contenidor cont afegit a l'ubbicació especificada
            En cas que no sigui possible afegir-ho a làrea d'emmagatzematge,
            s'afegirà a l'àrea d'espera.
*/
void afegeix_contenidor(const Contenedor& cont, Ubicacion& u/*, Area_espera& aesp*/);

/** @brief Modificadora de supressió d'element Contenedor al p.i.
      \pre <em> Cert </em>
      \post El resultat serà el p.i. Ter amb un contenidor cont suprimit
*/
void retira_contenidor(const Contenedor& cont, const Ubicacion& u);

/** @brief Modificadora dels espais vàlids a causa del nou contenidor insertat
      \pre <em> Cert </em>
      \post La terminal no serà modificada però el conjunt d'espais vàlids canviarà
*/
void regenera_inserta(const Ubicacion& u, Conj_huecos& ch, int lon);

/** @brief Modificadora dels espais vàlids a causa de la supressió d'un contenidor
      \pre <em> Cert </em>
      \post La terminal no serà modificada però el conjunt d'espais vàlids canviarà
*/
void regenera_retira(const Ubicacion& u, Conj_huecos& ch, int lon);

private:

  int dist_esquerra(int i, int j, int k);
  int dist_dreta(int i, int j, int k);

  int n, m, h;
  vector<vector<vector<string>>> terminal;

};

#endif
