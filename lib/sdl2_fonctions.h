#ifndef SDL2_FONCTIONS_H
#define SDL2_FONCTIONS_H

#include <SDL2/SDL.h>

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);

SDL_Texture* load_image(const char* nomfichier, SDL_Renderer* renderer);

void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);

void update_screen(SDL_Renderer *renderer);

void clean_texture(SDL_Texture *texture);

void clear_renderer(SDL_Renderer *renderer);

void clean_sdl(SDL_Renderer *renderer,SDL_Window *window);

#endif
