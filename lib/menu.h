#ifndef MENU_H
#define MENU_H

#include "monde.h"
#include "images.h"

//Choix du joueur pour le menu 1 du combat
#define ATTAQUE 1
#define FUITE 2

//Choix du joueur pour le menu 2 du combat
#define RIEN 0
#define EPEE 1
#define SORT 2
#define ARC 3
#define RETOUR 4

//Choix du joueur pour le menu de l'Inventaire
#define INVENTAIRE 1
#define EPEE_PIERRE 2
#define EPEE_DIAM 3
#define BOUCLIER_PIERRE 4
#define BOUCLIER_DIAM 5
#define POTION_PV 6
#define POTION_MANA 7

void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police);
void choix_partie(SDL_Event* event, monde_t * monde);
void evenements_menu(SDL_Event* event, monde_t * monde);
void evenements_inventaire(SDL_Event* event, monde_t * monde);
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police);
void evenements_combat(SDL_Event * event, monde_t * monde);
void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police);
void evenements_fin_partie(SDL_Event * event, monde_t * monde);
void affichage_victoire(SDL_Renderer* renderer, images_t * textures, TTF_Font* police);

#endif
