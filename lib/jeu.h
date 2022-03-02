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

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde);
void init(SDL_Window **window, SDL_Renderer **renderer, images_t *textures, monde_t * monde);
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures);
void evenements(SDL_Event* event, monde_t * monde);

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


void creation_jeu();
void init_partie();
void save_partie();
void fin_partie();
void combat();
void affichage_menu_combat();;
void affichage_inventaire();
void affichage_menu();
void deplacement_personnage();
void deplacement_monstre();
void affichage_boutique();
void affichage_dialogue();

/**
	*\fn void init_salle(salle_t * salle, int num_salle)
	*\brief initialisation d'une salle d'une zone
	*\param salle une salle d'une zone
	*\param num_salle numéro de la salle de la zone
*/
void init_salle(salle_t * salle, int num_salle);

#endif
