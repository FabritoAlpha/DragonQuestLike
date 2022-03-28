/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#ifndef _JEU_H
#define _JEU_H
#include <math.h>
#include "menu.h"

#define COLLISION 1
#define PAS_COLLISION 0

//Numéro du menu lors du combat
#define MENU1 1
#define MENU2 2

//Choix du joueur pour le menu 1 du combat	
#define ATTAQUE 1
#define FUITE 2

//Choix du joueur pour le menu 2 du combat
#define RIEN 0
#define EPEE 1
#define SORT 2
#define ARC 3
#define RETOUR 4

void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde, TTF_Font * police);
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * tick,int *tick_monstre, TTF_Font * police);
void evenements(SDL_Event* event, monde_t * monde);
int test_collision_joueur(joueur_t * joueur, salle_t * salle_courante, int largeur_ecran, int longueur_ecran); // à améliorer avec un type boolen
int test_collision_monstre(monstre_t * monstre, salle_t * salle_du_monstre, int largeur_ecran, int longueur_ecran);// même chose


int collision_combattant_ecran(combattant_t * combattant, monde_t * monde);
int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre);
int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj);
int collision_combattant_coffre(combattant_t * combattant, nonCombattant_t * coffre);
int collision_combattant(combattant_t * combattant,int indice_monstre, monde_t * monde);


int deplacement_droit(combattant_t * entitee, int indice_monstre, monde_t * monde);
int deplacement_gauche(combattant_t * entitee, int indice_monstres, monde_t * monde);
int deplacement_haut(combattant_t * entitee, int indice_monstre, monde_t * monde);
int deplacement_bas(combattant_t * entitee, int indice_monstre, monde_t * monde);


void deplacement_monstre(monstre_t * monstre,monde_t * m);

void deplacement_salles(joueur_t * j, int indice_salle);

void deplacement_zones(joueur_t * j);

void deplacement_monstre(monstre_t * monstre, monde_t * m);

/**
	*\struct salle_t
	*\brief représentation d'une salle
*/

//On a besoin d'une fonction qui crée le jeu ? -> Une fonction qui l'initialise -> Soit à partir d'un nouveau, soit à partir d'une partie déjà sauvegardee ?
//Fonction de sauvegarde soit qui écrase la sauvegarde précédente si elle existe, soit une nouvelle sauvegarde si la partie est nouvelle
//Fonction de fin de partie
//Fonction de combat ?
//Fonction qui gère l'affichage de l'inventaire
//Fonction qui gère l'affichage du menu
//Fonction qui gère le déplacement du joueur et une celle des monstres
//Fonction qui gère l'affichage des boutiques
//Fonction qui gère les dialogues




/**
	*\fn void init_salle(salle_t * salle, int num_salle)
	*\brief initialisation d'une salle d'une zone
	*\param salle une salle d'une zone
	*\param num_salle numéro de la salle de la zone
*/
void init_salle(salle_t * salle, int num_salle);

#endif
