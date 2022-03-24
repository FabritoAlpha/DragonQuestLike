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
    //SDL_Texture* menu; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone0salle0; /*!< Texture liée à l'image du fond de l'écran. */
    //SDL_Texture* s1; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone0salle1;
    SDL_Texture* zone1salle0; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone1salle1; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* joueur; /*!< Texture liée à l'image du joueur. */
    SDL_Texture* monstre; /*!< Texture liée à l'image des monstres. */
    SDL_Texture* epee1; /*!< Texture liée à l'image de l'épee 1. */
    SDL_Texture* epee2; /*!< Texture liée à l'image de l'épee 2. */
    SDL_Texture* bouclier1; /*!< Texture liée à l'image du bouclier 1. */
    SDL_Texture* bouclier2; /*!< Texture liée à l'image du bouclier 2. */
    SDL_Texture* selection_inactive; /*!< Texture liée à l'image de fond d'un objet quand il n'est pas équipé. */
    SDL_Texture* selection_active; /*!< Texture liée à l'image de fond d'un objet quand il est équipé. */
    TTF_Font *font; /*!< Texture liée à la police du texte affiché à l'écran */


} images_t;

void clean_images(images_t *textures);

void init_images(SDL_Renderer *renderer, images_t *textures);

void fond_position(SDL_Renderer *renderer, images_t *textures, int etat, int zone, int salle);

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur);

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre);

#endif
