/**
  * \file affichage.h
  * \brief header des affichages
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

#include  "images.h"
#include  "deplacements.h"

#define LARGEUR_TEXT 350//(SCREEN_WIDTH/4)
#define HAUTEUR_TEXT 80//(POSITION_MENU_HEIGHT/10)
#define TEXT_OBJET_L (LARGEUR_TEXT/5)
#define TEXT_OBJET_H (HAUTEUR_TEXT/5)
#define POSITION_MENU_WIDTH (SCREEN_WIDTH/3)
#define POSITION_MENU_HEIGHT (SCREEN_HEIGHT/4)
#define POSITION_INVENTAIRE_L (SCREEN_WIDTH/2)
#define POSITION_INVENTAIRE_H (SCREEN_HEIGHT/3)
#define POSITION_INVENTAIRE_IMG_L POSITION_INVENTAIRE_L
#define POSITION_INVENTAIRE_IMG_H POSITION_INVENTAIRE_H
#define DECALAGE_IMG_TEXT_L 90
#define DECALAGE_TEXT_IMG_L 125
#define DECALAGE_TEXT_IMG_H 150
#define COULEUR_1_SELECTION 255
#define COULEUR_2_VIDE 0

void affichage_carte(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur);

void affichage_aide(SDL_Renderer *renderer, TTF_Font * police);

void affichage_nonCombattants(SDL_Renderer *renderer, images_t *textures, zone_t* zone, salle_t* salle);

void affichage_dialogue(SDL_Renderer *renderer, images_t *textures, monde_t * monde, TTF_Font * police);

void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police);

void affichage_victoire(SDL_Renderer* renderer, images_t * textures, TTF_Font* police);

void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font * police);

void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police);

void affichage_statistiques(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur);

#endif
