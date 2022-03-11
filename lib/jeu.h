/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#ifndef _JEU_H
#define _JEU_H

#include <stdlib.h>
#include <stdio.h>
#include "monde.h"
#include "sdl2_fonctions.h"
#include "images.h"


void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde);
void init(SDL_Window **window, SDL_Renderer **renderer, images_t *textures, monde_t * monde);
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * tick,int *tick_monstre);
void evenements(SDL_Event* event, monde_t * monde);
int test_collision_joueur(joueur_t * joueur, salle_t * salle_courante, int largeur_ecran, int longueur_ecran); // à améliorer avec un type boolen
int test_collision_monstre(monstre_t * monstre, salle_t * salle_du_monstre, int largeur_ecran, int longueur_ecran);// même chose
void affichage_menu(SDL_Renderer *renderer, monde_t * monde, images_t *textures);
void evenements_menu(SDL_Event* event, monde_t * monde);

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
