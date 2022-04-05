/**
  * \file deplacements.h
  * \brief header des déplacements
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _DEPLACEMENTS_H
#define _DEPLACEMENTS_H
#include <math.h>
#include "monde.h"

#define COLLISION 1
#define PAS_COLLISION 0

//Choix du joueur pour le menu 1 du combat
#define ATTAQUE 1
#define FUITE 2

//Choix du joueur pour le menu 2 du combat
#define RIEN 0
#define EPEE 1
#define SORT 2
#define OBJETS 3
#define RETOUR 4

//Choix du joueur pour le menu 3 du combat
#define CHOIX_POTION_PV 1
#define CHOIX_POTION_MANA 2

//Coût d'un sort
#define COUT_SORT 10

//Constantes pour le déplacement du monstre
#define DIST_MIN 10
#define DIST_MAX 50
#define NB_DIRECTION 4
#define DIST_AGRO 250

//Directions
#define GAUCHE 0
#define DROITE 1
#define HAUT 2
#define BAS 3

int distance_pnj_coffre(joueur_t * joueur, nonCombattant_t * entite);

int nonCombattant_proche(monde_t * monde);

void changement_salle(joueur_t * j, int changement_salle);

void changement_zone(monde_t * monde);

int collision_combattant_ecran(combattant_t * combattant, monde_t * monde);

int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre, monde_t * monde );

int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj);

int collision_combattant_coffre(combattant_t * combattant, nonCombattant_t * coffre);

int collision_combattant(combattant_t * combattant, int indice_monstre, monde_t * monde/*, int indice_salle, int indice_zone*/);

int deplacement_droit(combattant_t * entite, int indice_monstre, monde_t * monde);

int deplacement_gauche(combattant_t * entite, int indice_monstre, monde_t * monde);

int deplacement_haut(combattant_t * entite, int indice_monstre, monde_t * monde);

int deplacement_bas(combattant_t * entite, int indice_monstre, monde_t * monde);

int distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre);

void deplacement_monstre(monstre_t * monstre, monde_t * m);

void sauvegarde(monde_t* monde);

#endif
