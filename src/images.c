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
    //printf("Je ne plante pas dans clean images avant clean_texture\n");
    /*if(textures->zone0salle1 != NULL){
        clean_texture(textures->zone0salle1);
        printf("Ok1");
        textures->zone0salle1 = NULL;
        printf("Ok");
    }*/
    //clean_texture(textures->zone0salle0);
    //printf("Clean_textures se réalise 'correctement'\n");
    //textures->zone0salle0 = NULL;

/*
    if(textures->zone1salle0 != NULL){
        clean_texture(textures->zone1salle0);
        printf("Ok2");
        textures->zone1salle0 = NULL;
        printf("Ok2");
    }
    if(textures->zone1salle1 != NULL){
        clean_texture(textures->zone1salle1);
        printf("Ok3");
        textures->zone1salle1 = NULL;
        printf("Ok3");
    }*/
    clean_texture(textures->zone0salle0);
    //printf("Clean_textures se réalise 'correctement'\n");
    textures->zone0salle0 = NULL;
    clean_texture(textures->zone0salle1);
    textures->zone0salle1 = NULL;
    clean_texture(textures->zone1salle0);
    textures->zone1salle0 = NULL;
    clean_texture(textures->zone1salle1);
    textures->zone1salle1 = NULL;
    clean_texture(textures->joueur);
    textures->joueur = NULL;
    clean_texture(textures->monstre);
    textures->monstre = NULL;
    clean_texture(textures->selection_active);
    textures->selection_active = NULL;
    clean_texture(textures->selection_inactive);
    textures->selection_inactive = NULL;
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
    textures->zone0salle0 = load_image("./rsrc/img/zone0_salle0.bmp",renderer);
    //textures->menu = load_image("./rsrc/img/menu.bmp",renderer);
    textures->zone0salle1 = load_image("./rsrc/img/zone0_salle1.bmp",renderer);
    textures->zone1salle0 = load_image("./rsrc/img/zone1_salle0.bmp",renderer);
    textures->zone1salle1 = load_image("./rsrc/img/zone1_salle1.bmp",renderer);
    textures->joueur = load_image("./rsrc/img/joueur.bmp",renderer);
    textures->monstre = load_image("./rsrc/img/monstre.bmp",renderer);
    textures->selection_active = load_image("./rsrc/img/selection_active.bmp",renderer);
    textures->selection_inactive = load_image("./rsrc/img/selection_inactive.bmp",renderer);
    textures->font = apply_font("./rsrc/img/ka1.ttf", 30);
}

/**
 * \fn void fond_position(SDL_Renderer *renderer, images_t *textures)
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran
 * \param renderer le renderer
 * \param textures les textures du jeu
*/
void fond_position(SDL_Renderer *renderer, images_t *textures, int etat, int zone, int salle){

    //fond du menu
    if(etat == 1){
        if(zone == 0){
            if(salle == 0){
                apply_texture(textures->zone0salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
            }
            if(salle == 1){
                apply_texture(textures->zone0salle1, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
            }
        }
        if(zone == 1){
            if(salle == 0){
                apply_texture(textures->zone1salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
            }
            if(salle == 1){
                apply_texture(textures->zone1salle1, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
            }
        }
    }
    else{
        apply_texture(textures->zone0salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
    }
}

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur){
    apply_texture(textures->joueur, renderer, joueur->combattant->x + (taille_fenetre[0]/2) - 500, joueur->combattant->y + (taille_fenetre[1]/2) - 375);
}

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre){
    apply_texture(textures->monstre, renderer, monstre->combattant->x + (taille_fenetre[0]/2) - 500, monstre->combattant->y + (taille_fenetre[1]/2) - 375);
}
