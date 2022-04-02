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

void clean_images(images_t *textures, TTF_Font * police){
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
    //clean_texture(textures->print_yest);
    //textures->print_yest = NULL;
    clean_texture(textures->zone0salle0);
    //printf("Clean_textures se réalise 'correctement'\n");
    textures->zone0salle0 = NULL;
    clean_texture(textures->zone0salle1);
    textures->zone0salle1 = NULL;
    clean_texture(textures->zone0salle2);
    textures->zone0salle1 = NULL;
    clean_texture(textures->zone0salle3);
    textures->zone0salle1 = NULL;
    clean_texture(textures->zone1salle0);
    textures->zone1salle0 = NULL;
    clean_texture(textures->zone1salle1);
    textures->zone1salle1 = NULL;
    clean_texture(textures->zone1salle2);
    textures->zone1salle2 = NULL;
    clean_texture(textures->zone1salle3);
    textures->zone1salle3 = NULL;
    clean_texture(textures->zone2salle0);
    textures->zone2salle0 = NULL;
    clean_texture(textures->zone2salle1);
    textures->zone2salle1 = NULL;
    clean_texture(textures->zone2salle2);
    textures->zone2salle2 = NULL;
    clean_texture(textures->zone2salle3);
    textures->zone2salle3 = NULL;
    clean_texture(textures->joueur);
    textures->joueur = NULL;
    clean_texture(textures->monstre);
    textures->monstre = NULL;
    clean_texture(textures->monstre_zone1);
    textures->monstre_zone1 = NULL;
    clean_texture(textures->monstre_zone2);
    textures->monstre_zone2 = NULL;
    clean_texture(textures->boss);
    textures->boss = NULL;
    clean_texture(textures->perso_z0);
    textures->perso_z0 = NULL;
    clean_texture(textures->perso_z1);
    textures->perso_z1 = NULL;
    clean_texture(textures->perso_z2);
    textures->perso_z2 = NULL;
    clean_texture(textures->marchand);
    textures->marchand = NULL;
    clean_texture(textures->marchande);
    textures->marchande = NULL;
    clean_texture(textures->coffre_vide);
    textures->coffre_vide = NULL;
    clean_texture(textures->coffre);
    textures->coffre = NULL;
    clean_texture(textures->or);
    textures->or = NULL;
    clean_texture(textures->dialogue);
    textures->dialogue = NULL;
    clean_texture(textures->epee1);
    textures->epee1=NULL;
    clean_texture(textures->epee2);
    textures->epee2=NULL;
    clean_texture(textures->bouclier1);
    textures->bouclier1=NULL;
    clean_texture(textures->bouclier2);
    textures->bouclier2=NULL;
    clean_texture(textures->potion_pv);
    textures->potion_pv = NULL;
    clean_texture(textures->potion_mana);
    textures->potion_mana = NULL;
    clean_texture(textures->selection_active);
    textures->selection_active = NULL;
    clean_texture(textures->selection_inactive);
    textures->selection_inactive = NULL;
    clean_texture(textures->equipe);
    textures->equipe=NULL;
    clean_texture(textures->fond_inventaire);
    textures->fond_inventaire=NULL;
    clean_texture(textures->case_combat);
    textures->case_combat = NULL;
    clean_texture(textures->arene_combat);
    textures->arene_combat = NULL;
    clean_texture(textures->potion_b_petite);
    textures->potion_b_petite = NULL;
    clean_texture(textures->bouclier2_petit);
    textures->bouclier2_petit = NULL;
    clean_texture(textures->potion_r_petite);
    textures->potion_r_petite = NULL;
    clean_texture(textures->epee1_petite);
    textures->epee1_petite = NULL;
    clean_texture(textures->epee2_petite);
    textures->epee2_petite = NULL;
    clean_texture(textures->bouclier1_petit);
    textures->bouclier1_petit = NULL;
    clean_texture(textures->or_petit);
    textures->or_petit = NULL;
    clean_texture(textures->game_over);
    textures->game_over = NULL;
    clean_texture(textures->surbrillance_combat);
    textures->surbrillance_combat = NULL;
    if(police != NULL){
        clean_font(police);
        police = NULL;
    }



}


/**
 * \fn void init_images(SDL_Renderer *renderer, textures_t *textures)
 * \brief La fonction initialise les textures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_images(SDL_Renderer *renderer, images_t *textures){
  //load_image("./rsrc/img/joueur.bmp",&renderer,&textures->print_yest);
    load_image("./rsrc/img/zone0_salle0.bmp",&renderer,&textures->zone0salle0);
    //textures->menu = load_image("./rsrc/img/menu.bmp",renderer);
    load_image("./rsrc/img/zone0_salle1.bmp",&renderer,&textures->zone0salle1);
    load_image("./rsrc/img/zone0_salle2.bmp",&renderer,&textures->zone0salle2);
    load_image("./rsrc/img/zone0_salle3.bmp",&renderer,&textures->zone0salle3);
    load_image("./rsrc/img/zone1_salle0.bmp",&renderer,&textures->zone1salle0);
    load_image("./rsrc/img/zone1_salle1.bmp",&renderer,&textures->zone1salle1);
    load_image("./rsrc/img/zone1_salle2.bmp",&renderer,&textures->zone1salle2);
    load_image("./rsrc/img/zone1_salle3.bmp",&renderer,&textures->zone1salle3);
    load_image("./rsrc/img/zone2_salle0.bmp",&renderer,&textures->zone2salle0);
    load_image("./rsrc/img/zone2_salle1.bmp",&renderer,&textures->zone2salle1);
    load_image("./rsrc/img/zone2_salle2.bmp",&renderer,&textures->zone2salle2);
    load_image("./rsrc/img/zone2_salle3.bmp",&renderer,&textures->zone2salle3);
    load_image("./rsrc/img/joueur.bmp",&renderer,&textures->joueur);
    load_image("./rsrc/img/monstre.bmp",&renderer,&textures->monstre);
    load_image("./rsrc/img/monstre.bmp",&renderer,&textures->monstre_zone1);
    load_image("./rsrc/img/monstre.bmp",&renderer,&textures->monstre_zone2);
    load_image("./rsrc/img/monstre.bmp",&renderer,&textures->boss);
    load_image("./rsrc/img/perso_z0.bmp",&renderer,&textures->perso_z0);
    load_image("./rsrc/img/perso_z1.bmp",&renderer,&textures->perso_z1 );
    load_image("./rsrc/img/perso_z2.bmp",&renderer,&textures->perso_z2);
    load_image("./rsrc/img/marchand.bmp",&renderer,&textures->marchand);
    load_image("./rsrc/img/marchande.bmp",&renderer,&textures->marchande);
    load_image("./rsrc/img/coffre_vide.bmp",&renderer,&textures->coffre_vide);
    load_image("./rsrc/img/coffre.bmp",&renderer,&textures->coffre);
    load_image("./rsrc/img/piece.bmp",&renderer,&textures->or);
    load_image("./rsrc/img/dialogue.bmp",&renderer,&textures->dialogue);
    load_image("./rsrc/img/epee1_inventaire.bmp",&renderer,&textures->epee1);
    load_image("./rsrc/img/epee2_inventaire.bmp",&renderer,&textures->epee2);
    load_image("./rsrc/img/bouclier1_inventaire.bmp",&renderer,&textures->bouclier1);
    load_image("./rsrc/img/bouclier2_inventaire.bmp",&renderer,&textures->bouclier2);
    load_image("./rsrc/img/selection_active.bmp",&renderer,&textures->selection_active);
    load_image("./rsrc/img/selection_inactive.bmp",&renderer,&textures->selection_inactive);
    load_image("./rsrc/img/equipe.bmp",&renderer, &textures->equipe);
    load_image("./rsrc/img/fiole_rouge.bmp",&renderer,&textures->potion_pv);
    load_image("./rsrc/img/fiole_bleu.bmp",&renderer,&textures->potion_mana);
    load_image("./rsrc/img/fond_inventaire.bmp",&renderer,&textures->fond_inventaire);
    //textures->font = apply_font("./rsrc/img/ka1.ttf", 30);
    load_image("./rsrc/img/rectangles_combat.bmp", &renderer,&textures->case_combat);
    load_image("./rsrc/img/surbrillance_combat.bmp",&renderer,&textures->surbrillance_combat);
    load_image("./rsrc/img/fond_inventaire.bmp",&renderer, &textures->game_over);
    load_image("./rsrc/img/arene.bmp",&renderer, &textures->arene_combat);
    load_image("./rsrc/img/fiole_bleu_boutique.bmp",&renderer, &textures->potion_b_petite);
    load_image("./rsrc/img/fiole_rouge_boutique.bmp",&renderer, &textures->potion_r_petite);
    load_image("./rsrc/img/epee1.bmp", &renderer,&textures->epee1_petite);
    load_image("./rsrc/img/epee2.bmp", &renderer, &textures->epee2_petite);
    load_image("./rsrc/img/bouclier1.bmp", &renderer, &textures->bouclier1_petit);
    load_image("./rsrc/img/bouclier2.bmp", &renderer,&textures->bouclier2_petit);
    load_image("./rsrc/img/piece_petite.bmp", &renderer,&(textures->or_petit));
}

/**
 * \fn void fond_position(SDL_Renderer *renderer, images_t *textures)
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran
 * \param renderer le renderer
 * \param textures les textures du jeu
*/
void fond(SDL_Renderer *renderer, images_t *textures, monde_t * monde){

    int zone = monde->joueur->zone;
    int salle = monde->joueur->salle;
    int etat = monde->etat_jeu;
    //fond du menu
    if(etat == ETAT_JEU_PRINCIPAL || etat == ETAT_DIALOGUE || etat == ETAT_COFFRE || etat == ETAT_AIDE){
        if(zone == 0){
            switch(salle){
                case 0:
                    //printf("zone 0 salle 0 \n");
                    apply_texture(&textures->zone0salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 1:
                    //printf("zone 0 salle 1 \n");
                    apply_texture(&textures->zone0salle1, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 2:
                    //printf("zone 0 salle 2 \n");
                    apply_texture(&textures->zone0salle2, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 3:
                    //printf("zone 0 salle 3 \n");

                    apply_texture(&textures->zone0salle3, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
            }
        }
        if(zone == 1){
            switch(salle){
                case 0:
                    apply_texture(&textures->zone1salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 1:
                    apply_texture(&textures->zone1salle1, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 2:
                    apply_texture(&textures->zone1salle2, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 3:
                    apply_texture(&textures->zone1salle3, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
            }
        }
        if(zone == 2){
            switch(salle){
                case 0:
                    apply_texture(&textures->zone2salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 1:
                    apply_texture(&textures->zone2salle1, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 2:
                    apply_texture(&textures->zone2salle2, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
                case 3:
                    apply_texture(&textures->zone2salle3, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
                    break;
            }
        }
    }
    else if(etat == ETAT_INVENTAIRE){
        apply_texture(&textures->fond_inventaire, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
    }
    else if(etat == ETAT_COMBAT){
      apply_texture(&textures->arene_combat, renderer, (taille_fenetre[0]/2)-500, (taille_fenetre[1]/2) - 375);

    }
    else{
        apply_texture(&textures->zone0salle0, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
    }
}

void joueur_position(SDL_Renderer *renderer, images_t *textures, joueur_t* joueur){
    // Affichage du joueur.
    apply_texture(&textures->joueur, renderer, joueur->combattant->x + (taille_fenetre[0]/2) - 500, joueur->combattant->y + (taille_fenetre[1]/2) - 375);
    // Affichage de l'équipement du joueur
    // Epee
    if(joueur->objet_equipe[0].id==joueur->inventaire[0].id&&joueur->inventaire[0].id!=0){
        apply_texture(&textures->epee1_petite, renderer, joueur->combattant->x+35 + (taille_fenetre[0]/2) - 500, joueur->combattant->y +30 + (taille_fenetre[1]/2) - 375);
    }
    if(joueur->objet_equipe[0].id==joueur->inventaire[1].id&&joueur->inventaire[1].id!=0){
        apply_texture(&textures->epee2_petite, renderer, joueur->combattant->x+35 + (taille_fenetre[0]/2) - 500, joueur->combattant->y +30 + (taille_fenetre[1]/2) - 375);
    }
    // Bouclier
    if(joueur->objet_equipe[1].id==joueur->inventaire[2].id&&joueur->inventaire[2].id!=0){
        apply_texture(&textures->bouclier1_petit, renderer, joueur->combattant->x-10 + (taille_fenetre[0]/2) - 500, joueur->combattant->y +33 + (taille_fenetre[1]/2) - 375);
    }
    if(joueur->objet_equipe[1].id==joueur->inventaire[3].id&&joueur->inventaire[3].id!=0){
        apply_texture(&textures->bouclier2_petit, renderer, joueur->combattant->x-10 + (taille_fenetre[0]/2) - 500, joueur->combattant->y +33 + (taille_fenetre[1]/2) - 375);
    }
}

void monstre_position(SDL_Renderer *renderer, images_t *textures, monstre_t* monstre){
    apply_texture(&textures->monstre, renderer, monstre->combattant->x + (taille_fenetre[0]/2) - 500, monstre->combattant->y + (taille_fenetre[1]/2) - 375);
}

void nonCombattant_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* perso, int type){
    switch(type){
        case 0:
            apply_texture(&textures->perso_z0, renderer, perso->x + (taille_fenetre[0]/2) - 500, perso->y + (taille_fenetre[1]/2) - 375);
        break;
        case 1:
            apply_texture(&textures->perso_z1, renderer, perso->x + (taille_fenetre[0]/2) - 500, perso->y + (taille_fenetre[1]/2) - 375);
        break;
        case 2:
            apply_texture(&textures->perso_z2, renderer, perso->x + (taille_fenetre[0]/2) - 500, perso->y + (taille_fenetre[1]/2) - 375);
        break;
        case 3:
            apply_texture(&textures->marchand, renderer, perso->x + (taille_fenetre[0]/2) - 500, perso->y + (taille_fenetre[1]/2) - 375);
        break;
        case 4:
            apply_texture(&textures->marchande, renderer, perso->x + (taille_fenetre[0]/2) - 500, perso->y + (taille_fenetre[1]/2) - 375);
        break;
    }
}

void dialogue_position(SDL_Renderer *renderer, images_t *textures, int type){
    apply_texture(&textures->dialogue, renderer, (taille_fenetre[0]/2) - 500, 750 - 156 + (taille_fenetre[1]/2) - 375);
    apply_texture(&textures->joueur, renderer, 450 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
    switch(type){
        case 0:
            apply_texture(&textures->perso_z0, renderer, 550 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
        break;
        case 1:
            apply_texture(&textures->perso_z1, renderer, 550 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
        break;
        case 2:
            apply_texture(&textures->perso_z2, renderer, 550 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
        break;
        case 3:
            apply_texture(&textures->marchand, renderer, 550 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
        break;
        case 4:
            apply_texture(&textures->marchande, renderer, 550 + (taille_fenetre[0]/2) - 500, 300 + (taille_fenetre[1]/2) - 375);
        break;
    }
}

void coffre_position(SDL_Renderer *renderer, images_t *textures, nonCombattant_t* coffre, int ouvert){
    if(ouvert == 1)
        apply_texture(&textures->coffre_vide, renderer, coffre->x + (taille_fenetre[0]/2) - 500, coffre->y + (taille_fenetre[1]/2) - 375);
    if(ouvert == 0)
        apply_texture(&textures->coffre, renderer, coffre->x + (taille_fenetre[0]/2) - 500, coffre->y + (taille_fenetre[1]/2) - 375);
}

void or_position(SDL_Renderer *renderer, images_t *textures, int x, int y){
    apply_texture(&textures->or, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
}

void icone_boutique_position(SDL_Renderer *renderer, images_t *textures, int x, int y, int num){
    // 1: potion rouge, 2: potion bleue, 3: epee 1, 4: bouclier 1, 5: epee 2, 6: bouclier 2, 7: icone or
    switch(num){
        case 1:
              apply_texture(&textures->potion_r_petite, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 2:
              apply_texture(&textures->potion_b_petite, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 3:
              apply_texture(&textures->epee1_petite, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 4:
              apply_texture(&textures->bouclier1_petit, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 5:
              apply_texture(&textures->epee2_petite, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 6:
              apply_texture(&textures->bouclier2_petit, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
        case 7:
        			apply_texture(&textures->or_petit, renderer, x + (taille_fenetre[0]/2) - 500, y + (taille_fenetre[1]/2) - 375);
        break;
    }
}
