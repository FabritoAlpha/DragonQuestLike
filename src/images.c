/**
 * \file images.c
 * \brief gestion de l'affichage
 * \author Anna Béranger
 * \date 17/02/2022
 */

#include "../lib/images.h"

/**
 * \fn void clean_images(images_t *textures)
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_images(images_t *textures){
    if(textures->fond != NULL){
        clean_texture(textures->fond);
        textures->fond = NULL;
    }
}

/**
 * \fn void init_images(SDL_Renderer *renderer, textures_t *textures)
 * \brief La fonction initialise les textures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_images(SDL_Renderer *renderer, images_t *textures){
    textures->fond = load_image("../rsrc/img/test.bmp",renderer);
}

/**
 * \fn void fond_position(SDL_Renderer *renderer, images_t *textures)
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran
 * \param renderer le renderer
 * \param textures les textures du jeu
*/
void fond_position(SDL_Renderer *renderer, images_t *textures){
    apply_texture(textures->fond, renderer, 0, 0);
}
