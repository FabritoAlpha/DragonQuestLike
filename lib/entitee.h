/**
  * \file entitee.h
  * \brief header des entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
#ifndef ENTITEE_H
#define ENTITEE_H

#include <stdlib.h>
#include <stdio.h>

#define TAILLE_INVENTAIRE 0;
#define NB_EQUIPEMENT 0;
#define PAS 1

/**
  * \struct combattant_t
  * \brief représentation d'une entitee combattante
*/
typedef struct{
  int pv; /**< nombre de point de vie */
  int attaque; /**< valeur de ses points d'attaques */
  int vitesse;
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

  int type; /**< correspond à son type 0=normal 1=boss */
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
  int niveau; /**< niveau du combattant */
} nonCombattant_t;

/**
  * \fn void a_gauche(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à gauche selon un PAS.
*/
void a_gauche(combattant_t* entitee, int PAS);

void a_droite(combattant_t* entitee, int PAS);

void en_bas(combattant_t* entitee, int PAS);

void en_haut(combattant_t* entitee, int PAS);

joueur_t creer_joueur();

void init_joueur(joueur_t* joueur, int pv, int attaque, int vitesse, int x, int y);

void init_monstre(monstre_t* monstre, int pv, int attaque, int vitesse, int x, int y, int niveau, int type);

void init_nonCombattant(nonCombattant_t* nonCombattant, int id, float x, float y);














#endif