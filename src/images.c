/**
 * \file images.c
 * \brief gestion de l'affichage
 * \author Anna Béranger
 * \date 17/02/2022
 */

#include "../lib/images.h"
#include "../lib/entitee.h"



/**
 * \fn void clean_images(images_t *textures)
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_images(images_t *textures){
    printf("Je ne plante pas dans clean images avant clean_texture\n");
    clean_texture(textures->fond);
    printf("Clean_textures se réalise 'correctement'\n");
    textures->fond = NULL;
    clean_texture(textures->joueur);
    textures->joueur = NULL;
    clean_texture(textures->monstre);
    textures->monstre = NULL;
    if(textures->font != NULL){
        clean_font(textures->font);
        textures->font = NULL;
    }

}


/**
 * \fn void init_images(SDL_Renderer *renderer, textures_t *textures)
 * \brief La fonction initialise les textures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_images(SDL_Renderer *renderer, images_t *textures){
    textures->fond = load_image("./rsrc/img/fond_vert.bmp",renderer);
    textures->joueur = load_image("./rsrc/img/joueur.bmp",renderer);
    textures->monstre = load_image("./rsrc/img/monstre.bmp",renderer);
    textures->font = apply_font("./rsrc/img/ka1.ttf", 30);

}

/**
 * \fn void fond_position(SDL_Renderer *renderer, images_t *textures)
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran
 * \param renderer le renderer
 * \param textures les textures du jeu
*/
void fond_position(SDL_Renderer *renderer, images_t *textures){
    apply_texture(textures->fond, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
}

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur){
    apply_texture(textures->joueur, renderer, joueur->combattant->x + (taille_fenetre[0]/2) - 500, joueur->combattant->y + (taille_fenetre[1]/2) - 375);
}

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre){
    apply_texture(textures->monstre, renderer, monstre->combattant->x + (taille_fenetre[0]/2) - 500, monstre->combattant->y + (taille_fenetre[1]/2) - 375);
}
