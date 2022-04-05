/**
  * \file jeu.h
  * \brief header du jeu
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _JEU_H
#define _JEU_H
#include "interactions.h"
#include "affichage.h"
#include "menu.h"

void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde, TTF_Font * police);

void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * next_tick, TTF_Font* police);

void evenements(SDL_Event* event, monde_t * monde);

#endif
