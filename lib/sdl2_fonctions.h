/**
  * \file sdl2_fonctions.h
  * \brief header des fonctions de gestion de la sdl2
  * \author Anna Béranger, Arthur Fabre, Alex Choux
	* \date 03/03/2022
*/

#ifndef SDL2_FONCTIONS_H
#define SDL2_FONCTIONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern int taille_fenetre[2];

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);

void load_image(const char* nomfichier, SDL_Renderer** renderer, SDL_Texture** text);

void apply_texture(SDL_Texture **texture,SDL_Renderer *renderer,float x, float y);

void update_screen(SDL_Renderer *renderer);

void clean_texture(SDL_Texture *texture);

void clear_renderer(SDL_Renderer *renderer);

void clear_texture(SDL_Texture *texture);

void clean_sdl(SDL_Renderer *renderer,SDL_Window *window);

void init_ttf();

TTF_Font* apply_font(const char* fileName, int size);

void apply_text(SDL_Renderer *renderer, int r, int g, int b , const char* text, TTF_Font* font, int x, int y, int w, int h);

void clean_font(TTF_Font *font);

#endif
