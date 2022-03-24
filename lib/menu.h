#ifndef MENU_H
#define MENU_H
#include <stdlib.h>
#include <stdio.h>
#include "monde.h"
#include "sdl2_fonctions.h"
#include "images.h"

void affichage_menu(SDL_Renderer *renderer, monde_t * monde, images_t *textures);
void choix_partie(SDL_Event* event, monde_t * monde);
void evenements_menu(SDL_Event* event, monde_t * monde);
void evenements_inventaire(SDL_Event* event, monde_t * monde);
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures);














#endif
