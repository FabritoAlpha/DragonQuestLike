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


void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police);
void choix_partie(SDL_Event* event, monde_t * monde);
void evenements_menu(SDL_Event* event, monde_t * monde);
void evenements_inventaire(SDL_Event* event, monde_t * monde);
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police);
void evenements_combat(SDL_Event * event, monde_t * monde);
void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police);














#endif
