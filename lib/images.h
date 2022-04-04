/**
  * \file images.h
  * \brief header des images
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _IMAGES_H
#define _IMAGES_H

#include "monde.h"


/**
  * \struct images_t
  * \brief stocke les images (textures) nécessaires à l'affichage graphique du jeu
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
    SDL_Texture* fond_inventaire; /*!< Texture liée à l'image de fond de l'inventaire. */
    SDL_Texture* case_combat; /*!< Texture liée à l'image de fond d'une option en combat. */
    SDL_Texture* surbrillance_combat; /*!< Texture liée à l'image de surbrillance d'une option en combat. */
    SDL_Texture* game_over; /*!< Texture liée à l'image de fond lorsque l'on perd un combat. */
    SDL_Texture* arene_combat; /*!< Texture liée à l'image de fond lors d'un combat. */
    SDL_Texture* potion_b_petite; /*!< Texture liée à l'image d'une petite icône de potion de mana. */
    SDL_Texture* potion_r_petite; /*!< Texture liée à l'image d'une petite icône de potion de vie. */
    SDL_Texture* epee1_petite; /*!< Texture liée à l'image d'une petite icône d'épée en pierre'. */
    SDL_Texture* epee2_petite; /*!< Texture liée à l'image d'une petite icône d'épée en diamant'. */
    SDL_Texture* bouclier1_petit; /*!< Texture liée à l'image d'une petite icône de bouclier en pierre. */
    SDL_Texture* bouclier2_petit; /*!< Texture liée à l'image d'une petite icône de bouclier en diamant. */
    SDL_Texture* or_petit; /*!< Texture liée à l'image d'une petite icône de pièce d'or. */
    SDL_Texture* zone0; /*!< Texture liée à l'image de la carte de la zone 0. */
    SDL_Texture* zone1; /*!< Texture liée à l'image de la carte de la zone 1. */
    SDL_Texture* zone2; /*!< Texture liée à l'image de la carte de la zone 2. */
    SDL_Texture* coeur; /*!< Texture liée au grand icone pv */
    SDL_Texture* larme; /*!< Texture liée au grand icone mana */
    SDL_Texture* feu; /*!< Texture liée au grand icone feu */
    SDL_Texture* sorcier_cage; /*!< Texture liée à l'image du sorcier en cage */
    SDL_Texture* amis_cage; /*!< Texture liée à l'image des amis en cage */
    SDL_Texture* amis_victoire; /*!< Texture liée à l'mage des trois amis libérés */
} images_t;

void clean_images(images_t *textures, TTF_Font* police);

void init_images(SDL_Renderer *renderer, images_t *textures);

void fond(SDL_Renderer *renderer, images_t *textures, monde_t * monde);

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur, int x, int y);

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre, monde_t * monde);

void nonCombattant_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* perso, int type);

void dialogue_position(SDL_Renderer *renderer, images_t *textures, int type);

void coffre_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* coffre, int ouvert);

void icone_boutique_position(SDL_Renderer *renderer, images_t *textures, int x, int y, int num);

void carte_position(SDL_Renderer *renderer, images_t *textures, int zone);

void grand_icone_position(SDL_Renderer *renderer, images_t *textures, int x, int y, int num);

void derniere_salle_position(SDL_Renderer *renderer, images_t *textures, int etat);

#endif
