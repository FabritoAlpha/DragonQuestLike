/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#ifndef _JEU_H
#define _JEU_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "monde.h"
#include "sdl2_fonctions.h"
#include "images.h"

#define COLLISION 1
#define PAS_COLLISION 0



void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde);
void init(SDL_Window **window, SDL_Renderer **renderer, images_t *textures, monde_t * monde);
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * tick,int *tick_monstre);
void evenements(SDL_Event* event, monde_t * monde);
int test_collision_joueur(joueur_t * joueur, salle_t * salle_courante, int largeur_ecran, int longueur_ecran); // à améliorer avec un type boolen
int test_collision_monstre(monstre_t * monstre, salle_t * salle_du_monstre, int largeur_ecran, int longueur_ecran);// même chose
void affichage_menu(SDL_Renderer *renderer, monde_t * monde, images_t *textures);
void evenements_menu(SDL_Event* event, monde_t * monde);


int collision_combattant_ecran(combattant_t * combattant);
int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre);
int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj);
int collision_combattant_coffre(combattant_t * combattant, nonCombattant_t * coffre);
int collision_combattant(combattant_t * combattant, salle_t * salle, int indice_monstre, joueur_t * joueur);


int deplacement_droit(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j);
int deplacement_gauche(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j);
int deplacement_haut(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j);
int deplacement_bas(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j);

void deplacement_monstre(monstre_t * monstre,monde_t * m);
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
