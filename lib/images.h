#ifndef TEXTURES_H
#define TEXTURES_H

#include "sdl2_fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include "entitee.h"

/**
 * \brief stocke les images (textures) nécessaires à l'affichage graphique
*/

typedef struct images_s{

    SDL_Texture* fond; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* joueur; /*!< Texture liée à l'image du joueur. */
    TTF_Font *font; /*!< Texture liée à la police du texte affiché à l'écran */

} images_t;

void clean_images(images_t *textures);

void init_images(SDL_Renderer *renderer, images_t *textures);

void fond_position(SDL_Renderer *renderer, images_t *textures);

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur);

#endif
