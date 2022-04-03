#ifndef _IMAGES_H
#define _IMAGES_H

#include "monde.h"


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
    SDL_Texture* perso_z0; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* perso_z1; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* perso_z2; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* marchand; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* marchande; /*!< Texture liée à l'image d'un personnage. */
    SDL_Texture* coffre; /*!< Texture liée à l'image d'un coffre. */
    SDL_Texture* coffre_vide; /*!< Texture liée à l'image d'un coffre. */
    SDL_Texture* or; /*!< Texture liée à l'image d'une pièce. */
    SDL_Texture* dialogue; /*!< Texture liée à la zone de dialogue. */
    SDL_Texture* epee1; /*!< Texture liée à l'image de l'épee 1. */
    SDL_Texture* epee2; /*!< Texture liée à l'image de l'épee 2. */
    SDL_Texture* bouclier1; /*!< Texture liée à l'image du bouclier 1. */
    SDL_Texture* bouclier2; /*!< Texture liée à l'image du bouclier 2. */
    SDL_Texture* potion_pv; /*!< Texture liée à l'image de la potion de point de vie. */
    SDL_Texture* potion_mana; /*!< Texture liée à l'image de la potion de mana. */
    SDL_Texture* selection_inactive; /*!< Texture liée à l'image de fond d'une case d'un objet quand. */
    SDL_Texture* selection_active; /*!< Texture liée à l'image de fond d'un objet quand il es survolé. */
    SDL_Texture* equipe; /*!< Texture liée à l'image de fond d'un objet quand il est équipé. */
    SDL_Texture* fond_inventaire;
    SDL_Texture* case_combat;
    SDL_Texture* surbrillance_combat;
    SDL_Texture* game_over;
    SDL_Texture* arene_combat;
    SDL_Texture* potion_b_petite;
    SDL_Texture* potion_r_petite;
    SDL_Texture* epee1_petite;
    SDL_Texture* epee2_petite;
    SDL_Texture* bouclier1_petit;
    SDL_Texture* bouclier2_petit;
    SDL_Texture* or_petit;
    SDL_Texture* zone0; /*!< Texture liée à l'image de la carte de la zone 0. */
    SDL_Texture* zone1; /*!< Texture liée à l'image de la carte de la zone 1. */
    SDL_Texture* zone2; /*!< Texture liée à l'image de la carte de la zone 2. */
    SDL_Texture* coeur; /*!< Texture liée au grand icone pv */
    SDL_Texture* larme; /*!< Texture liée au grand icone mana */
    SDL_Texture* feu; /*!< Texture liée au grand icone feu */
} images_t;

void clean_images(images_t *textures, TTF_Font* police);

void init_images(SDL_Renderer *renderer, images_t *textures);

void fond(SDL_Renderer *renderer, images_t *textures, monde_t * monde);

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur, int x, int y);

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre);

void nonCombattant_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* perso, int type);

void dialogue_position(SDL_Renderer *renderer, images_t *textures, int type);

void coffre_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* coffre, int ouvert);

void or_position(SDL_Renderer *renderer, images_t *textures, int x, int y);

void icone_boutique_position(SDL_Renderer *renderer, images_t *textures, int x, int y, int num);

void carte_position(SDL_Renderer *renderer, images_t *textures, int zone);

void grand_icone_position(SDL_Renderer *renderer, images_t *textures, int x, int y, int num);

#endif
