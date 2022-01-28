/**
  * \file entitee.h
  * \brief header des entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>

#define TAILLE_INVENTAIRE 0;
#define NB_EQUIPEMENT 0;

/**
  * \struct combattant_t
  * \brief représentation d'une entitee combattante
*/
typedef struct{
  int pv; /**< nombre de point de vie */
  int attaque; /**< valeur de ses points d'attaques */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
} combattant_t;

/**
  * \struct objet_t
  * \brief représentation d'un objet
*/
typedef struct{
  int id; /**< id de l'objet */
  int attaque_sup; /**< attaque de l'objet */
  char* nom; /**< nom de l'objet */
  char* description; /**< description de l'objet */
} objet_t;

/**
  * \struct joueur_t
  * \brief représentation du joueur
*/
typedef struct{
  combattant_t* combattant; /**< points de vie et position */
  int inventaire[TAILLE_INVENTAIRE]; /**< id des objets en possession du joueur */
  int objet_equipe[NB_EQUIPEMENT]; /**< id des objets équipés par le joueur */
} joueur_t;

/**
  * \struct monstre_t
  * \brief représentation d'un monstre
*/
typedef struct{
  combattant_t* combattant; /**< points de vie et position */
  int niveau; /**< niveau du monstre */
  int en_vie; /**< mort: 0, en vie: 1 */
} monstre_t;

/**
  * \struct nonCombattant_t
  * \brief représentation d'une entitee non combattante
*/
typedef struct{
  int id; /**< id des entités coffre: 0, pnj n°1: 1, pnj n°2: 2 */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
  int visite; /**< 1: le joueur a déjà intéragi avec l'entité */
} nonCombattant_t;

/**
  * \fn void a_gauche(combattant_t*)
  * \param entitee entitée à déplacer
  * \brief déplacement d'une entitée à gauche
*/
void a_gauche(combattant_t* entitee);

void a_droite(combattant_t* entitee);

void en_bas(combattant_t* entitee);

void en_haut(combattant_t* entitee);

void init_joueur(joueur_t* joueur, int pv, int attaque, int x, int y);

void init_monstre(monstre_t* monstre, int pv, int attaque, int x, int y, int niveau);

void init_nonCombattant(nonCombattant_t* nonCombattant)
