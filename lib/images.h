#ifndef _IMAGES_H
#define _IMAGES_H

#include "sdl2_fonctions.h"
#include "monde.h"

#define ETAT_COMBAT 12

/**
 * \brief stocke les images (textures) nécessaires à l'affichage graphique
*/

typedef struct images_s{
    //SDL_Texture* menu; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone0salle0; /*!< Texture liée à l'image du fond de l'écran. */
    //SDL_Texture* s1; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone0salle1; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone0salle2; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone0salle3; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone1salle0; /*!< Texture liée à l'image du fond de l'écran. */
    //SDL_Texture* s1; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone1salle1; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone1salle2; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone1salle3; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone2salle0; /*!< Texture liée à l'image du fond de l'écran. */
    //SDL_Texture* s1; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* zone2salle1; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone2salle2; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* zone2salle3; /*!< Texture liée à l'image du fond de l'écran*/
    SDL_Texture* joueur; /*!< Texture liée à l'image du joueur. */
    SDL_Texture* monstre; /*!< Texture liée à l'image des monstres. */
    SDL_Texture* monstre_zone1; /*!< Texture liée à l'image des monstres. */
    SDL_Texture* monstre_zone2; /*!< Texture liée à l'image des monstres. */
    SDL_Texture* boss; /*!< Texture liée à l'image des monstres. */
    SDL_Texture* personnage; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* epee1; /*!< Texture liée à l'image de l'épee 1. */
    SDL_Texture* epee2; /*!< Texture liée à l'image de l'épee 2. */
    SDL_Texture* bouclier1; /*!< Texture liée à l'image du bouclier 1. */
    SDL_Texture* bouclier2; /*!< Texture liée à l'image du bouclier 2. */
    SDL_Texture* potion_pv; /*!< Texture liée à l'image de la potion de point de vie. */
    SDL_Texture* potion_mana; /*!< Texture liée à l'image de la potion de mana. */
    SDL_Texture* selection_inactive; /*!< Texture liée à l'image de fond d'un objet quand il n'est pas équipé. */
    SDL_Texture* selection_active; /*!< Texture liée à l'image de fond d'un objet quand il est équipé. */
    SDL_Texture* fond_inventaire;
    SDL_Texture* case_combat;
    SDL_Texture* game_over;
    SDL_Texture* arene_combat;
    //TTF_Font *font; /*!< Texture liée à la police du texte affiché à l'écran */


} images_t;

void clean_images(images_t *textures, TTF_Font* police);

void init_images(SDL_Renderer *renderer, images_t *textures);

void fond(SDL_Renderer *renderer, images_t *textures, monde_t * monde);

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur);

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre);

void nonCombattant_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* perso);

#endif
