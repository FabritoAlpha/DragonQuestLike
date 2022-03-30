#include <stdio.h>
#include  "../lib/menu.h"
#define LARGEUR_TEXT 350//(SCREEN_WIDTH/4)
#define HAUTEUR_TEXT 80//(POSITION_MENU_HEIGHT/10)
#define TEXT_OBJET_L (LARGEUR_TEXT/5)
#define TEXT_OBJET_H (HAUTEUR_TEXT/5)
#define POSITION_MENU_WIDTH (SCREEN_WIDTH/3)
#define POSITION_MENU_HEIGHT (SCREEN_HEIGHT/4)
#define POSITION_INVENTAIRE_L (SCREEN_WIDTH/2)
#define POSITION_INVENTAIRE_H (SCREEN_HEIGHT/3)
#define POSITION_INVENTAIRE_IMG_L POSITION_INVENTAIRE_L
#define POSITION_INVENTAIRE_IMG_H POSITION_INVENTAIRE_H
#define DECALAGE_IMG_TEXT_L 90
#define DECALAGE_TEXT_IMG_L 125
#define DECALAGE_TEXT_IMG_H 150


void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police){
    char opt[20] = "";

    //menu de base
    if(monde->etat_jeu == 0){
        //jouer
        if(monde->option == 1){
            sprintf(opt, "Jouer");
            if(police != 0){
                apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
            }
        } else{
            sprintf(opt, "Jouer");
            if(police != 0){
                apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
            }
        }
        //quitter
        if(monde->option == 2){
            sprintf(opt, "Quitter");
            if(police != 0){
                apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
            }
        } else{
            sprintf(opt, "Quitter");
            if(police != 0){
                apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
            }
        }
    }

    //menu choix de partie
    if(monde->etat_jeu == 4){
        //Partie 1
        if(monde->option == 1){
            sprintf(opt, "Partie 1");
            if(police != 0){
                apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
            }
        } else{
            sprintf(opt, "Partie 1");
            if(police != 0){
                apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
            }
        }
        //Partie 2
        if(monde->option == 2){
            sprintf(opt, "Partie 2");
            if(police != 0){
                apply_text(renderer, 150, 255, 150 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
            }
        } else{
            sprintf(opt, "Partie 2");
            if(police != 0){
                apply_text(renderer, 0, 255, 0 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
            }
        }
        //Nouvelle partie
        if(monde->option == 3){
            //si on a pas enclenché le nouveau menu de nouvelle partie
            if(monde->option2 == 0){
                //l'affichage de l'option nouvelle partie est affichée sélectionnée
                sprintf(opt, "Nouvelle partie");
                if(police != 0){
                    apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
                }
            //sinon on affiche la sélection du nouveau menu
            } else{
                sprintf(opt, "Nouvelle partie");
                if(police != 0){
                    apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
                }
                sprintf(opt, "Effacer:");
                if(police != 0){
                    apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 - 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                }
                if(monde->option2 == 1){
                    sprintf(opt, "Partie1");
                    if(police != 0){
                        apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Partie1");
                    if(police != 0){
                        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
                if(monde->option2 == 2){
                    sprintf(opt, "Partie2");
                    if(police != 0){
                        apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 + 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Partie2");
                    if(police != 0){
                        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 + 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
                if(monde->option2 == 3){
                    sprintf(opt, "Annuler");
                    if(police != 0){
                        apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 + 360, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Annuler");
                    if(police != 0){
                        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 + 360, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
            }
        } else{
            sprintf(opt, "Nouvelle partie");
            if(police != 0){
                apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
            }
        }
        //Retour
        if(monde->option == 4){
            sprintf(opt, "Retour");
            if(police != 0){
                apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
            }
        } else{
            sprintf(opt, "Retour");
            if(police != 0){
                apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
            }
        }
    }
}

void choix_partie(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
        //si on enfonce la touche du bas
        if(keystates[SDL_SCANCODE_DOWN]){
            monde->option2 = 0;
            //si on est pas à la dernière option on va sur l'option suivante
            if(monde->option < 4)
                monde->option++;
            else
                //sinon on retourne sur la première option
                monde->option = 1;
        }
        if(keystates[SDL_SCANCODE_UP]){
            monde->option2 = 0;
            if(monde->option > 1)
                monde->option--;
            else
                monde->option = 4; //3 options pour le moment
        }
        //partie 1
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){
          //on initialise la partie
          init_monde_jeu(monde,"./rsrc/txt/partie1.txt"); //TO DO utiliser sauvegarde de différentes parties
          monde->partie = 1;
          printf("partie1");
          //on commence le jeu
          monde->etat_jeu = 1;
        }
        //partie 2
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
          //on initialise la partie
          init_monde_jeu(monde,"./rsrc/txt/partie2.txt"); //TO DO utiliser sauvegarde de différentes parties
          monde->partie = 2;
          printf("partie2");
          //on commence le jeu
          monde->etat_jeu = 1;
        }
        //nouvelle partie
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
            if(monde->option2 == 0)
                monde->option2 = 4;
        }
        //si on es dans le sous-menu de nouvelle partie
        if(monde->option2 != 0){
            if(event->type == SDL_KEYDOWN){
                //si on enfonce la touche de droite
                if(keystates[SDL_SCANCODE_RIGHT]){
                    //si on est pas à la dernière option on va sur l'option suivante
                    if(monde->option2 < 3)
                        monde->option2++;
                    else
                        //sinon on retourne sur la première option
                        monde->option2 = 1;
                }
                //si on enfonce la touche de gauche
                if(keystates[SDL_SCANCODE_LEFT]){
                    if(monde->option2 > 1)
                        monde->option2--;
                    else
                        monde->option2 = 3; //3 options pour le moment
                }
            }
            printf("option2: %d", monde->option2);
            //nouvelle partie sur l'emplacement partie 1
            if(keystates[SDL_SCANCODE_RETURN] && monde->option2 == 1){
              //on initialise la partie
              init_monde_jeu(monde,"./rsrc/txt/init.txt");
              monde->partie = 1;
              monde->etat_jeu = 1;
            }
            //nouvelle partie sur l'emplacement partie 2
            if(keystates[SDL_SCANCODE_RETURN] && monde->option2 == 2){
              //on initialise la partie
              init_monde_jeu(monde,"./rsrc/txt/init.txt");
              monde->partie = 2;
              monde->etat_jeu = 1;
            }
            //annuler le chargement d'une nouvelle partie
            if(keystates[SDL_SCANCODE_RETURN] && monde->option2 == 3){
              monde->option2 = 0;
            }
        }
        //retour
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 4){
          //on retourne au menu précedent
          monde->etat_jeu = 0;
        }
    }
}

void evenements_menu(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if(event->type == SDL_KEYDOWN){
      // CHEAT CODE INVENTAIRE DIRECT
        if(keystates[SDL_SCANCODE_H]){
          monde->etat_jeu=3;
        }
        if(keystates[SDL_SCANCODE_DOWN]){
            if(monde->option < 2)
                monde->option++;
            else
                monde->option = 1;
        }
        if(keystates[SDL_SCANCODE_UP]){
            if(monde->option > 1)
                monde->option--;
            else
                monde->option = 2; //2 options pour le moment
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){
            //on entre dans un menu avec le choix de la partie
            monde->etat_jeu = 4;
            monde->option = 0;
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
            monde->etat_jeu = -1;
        }
    }

}
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font * police){
    monde->joueur->inventaire[0]=monde->biblio_objet[0]; // placement de l'item dans l'inventaire pour tester le menu
    monde->joueur->inventaire[1]=monde->biblio_objet[1]; // placement de l'item dans l'inventaire pour tester le menu
    monde->joueur->inventaire[2]=monde->biblio_objet[2]; // placement de l'item dans l'inventaire pour tester le menu
    monde->joueur->inventaire[3]=monde->biblio_objet[3]; // placement de l'item dans l'inventaire pour tester le menu
    monde->joueur->inventaire[4]=monde->biblio_objet[4]; // placement de l'item dans l'inventaire pour tester le menu
    monde->joueur->inventaire[5]=monde->biblio_objet[5]; // placement de l'item dans l'inventaire pour tester le menu
    char opt[20] = "";
    char opt2[20] = "";
    // Affichage du mana
    sprintf(opt, "Mana");
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.55 , SCREEN_HEIGHT/12 , TEXT_OBJET_L*0.6, TEXT_OBJET_H/2+50);
    snprintf(opt, 20, "%d", monde->joueur->manaCour);
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.60 , SCREEN_HEIGHT/12 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);
    sprintf(opt, "ManaMax");
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.65 , SCREEN_HEIGHT/12 , TEXT_OBJET_L*0.9, TEXT_OBJET_H/2+50);
    snprintf(opt, 20, "%d", monde->joueur->manaMax);
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.73 , SCREEN_HEIGHT/12 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);
    // Affichage des points de vie 
    sprintf(opt, "PV");
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.55 , SCREEN_HEIGHT/6 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);
    snprintf(opt, 20, "%d", monde->joueur->combattant->pvCour);
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.60 , SCREEN_HEIGHT/6 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);
    sprintf(opt, "PVMax");
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.65 , SCREEN_HEIGHT/6 , TEXT_OBJET_L*0.8, TEXT_OBJET_H/2+50);
    snprintf(opt, 20, "%d", monde->joueur->combattant->pvMax);
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.73 , SCREEN_HEIGHT/6 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);
    // Affichange des degats
    sprintf(opt, "Attaque");
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.55 , SCREEN_HEIGHT/4 , TEXT_OBJET_L*0.9, TEXT_OBJET_H/2+50);
    snprintf(opt, 20, "%d", monde->joueur->combattant->attaque);
    apply_text(renderer, 0, 255, 150, opt , police, SCREEN_WIDTH*0.63 , SCREEN_HEIGHT/4 , TEXT_OBJET_L*0.5, TEXT_OBJET_H/2+50);

    // Affichange dynamique des séléctions avec option 1 2 3 4 5.
    if(monde->option == 1){ // OPTION 1 INVENTAIRE
        sprintf(opt, "inventaire");
        apply_text(renderer, 150, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //Objet1
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 2
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 3
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 4
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 2){ // OPTION 2 OBJET 1
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //Objet 1
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer,150, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 2
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 3
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 4
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 3){ // OPTION 3 OBJET 2
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 150, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 4){ // OPTION 4 OBJET 3
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 150, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 5){ // OPTION 5 OBJET 4
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 150, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 6){ // OPTION 6 OPTION VIE
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 150, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
    if(monde->option == 7){ // OPTION 7 OPTION MANA
        sprintf(opt, "inventaire");
        apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[0].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[1].nom);
        if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        apply_texture(textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[2].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%s", monde->joueur->inventaire[3].nom);
        if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
            apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        apply_texture(textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        apply_text(renderer, 0, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        //Objet 6 Potion Santée
        sprintf(opt, "Potion de vie");
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        //Objet 7 Potion Mana
        sprintf(opt, "Potion de mana");
        apply_text(renderer, 150, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L-30, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+150, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
    }
}
void evenements_inventaire(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
        if(keystates[SDL_SCANCODE_DOWN]){
          switch(monde->option){
            case 1 :monde->option=2;break;//
            case 2 :monde->option=4;break;//1
            case 3 :monde->option=5;break;//2
            case 4 :monde->option=1;break;//3
            case 5 :monde->option=1;break;//4
            case 6 :monde->option=7;break;//6
            case 7 :monde->option=6;break;//7
          }
        }
        if(keystates[SDL_SCANCODE_UP]){
          switch(monde->option){
            case 1 :monde->option=4;break;//
            case 2 :monde->option=1;break;//1
            case 3 :monde->option=1;break;//2
            case 4 :monde->option=2;break;//3
            case 5 :monde->option=3;break;//4
            case 6 :monde->option=7;break;//6
            case 7 :monde->option=6;break;//7
          }
        }
        if(keystates[SDL_SCANCODE_LEFT]){
          switch(monde->option){
            case 1 :break;//
            case 2 :monde->option=6;break;//1
            case 3 :monde->option=2;break;//2
            case 4 :monde->option=7;break;//3
            case 5 :monde->option=4;break;//4
            case 6 :monde->option=3;break;//6
            case 7 :monde->option=5;break;//7
          }
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
          switch(monde->option){
            case 1 :break;//
            case 2 :monde->option=3;break;//1
            case 3 :monde->option=6;break;//2
            case 4 :monde->option=5;break;//3
            case 5 :monde->option=7;break;//4
            case 6 :monde->option=2;break;//6
            case 7 :monde->option=4;break;//7
          }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){
            //
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
            //Epee en bois équipée
            if(monde->joueur->objet_equipe[0].id!=monde->joueur->inventaire[0].id){
                //Stat Debuff
                if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[1].id){
                    monde->joueur->manaMax-=monde->joueur->objet_equipe[0].mana_sup;
                    monde->joueur->nb_obj_equip--;
                }
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax; 
                }
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                //Equipe
                monde->joueur->objet_equipe[0]=monde->joueur->inventaire[0];
                //Stat buff
                monde->joueur->combattant->attaque+=monde->joueur->objet_equipe[0].attaque_sup;
                monde->joueur->nb_obj_equip++;

            } 
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
            //Epee en diamant équipée
            if(monde->joueur->objet_equipe[0].id!=monde->joueur->inventaire[1].id){
                //Stat Debuff
                if(monde->joueur->objet_equipe[0].id==monde->joueur->inventaire[0].id){
                    monde->joueur->combattant->attaque-=monde->joueur->objet_equipe[0].attaque_sup;
                    monde->joueur->nb_obj_equip--;
                }
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax; 
                }
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                //Equipe
                monde->joueur->objet_equipe[0]=monde->joueur->inventaire[1];
                //Stat buff
                monde->joueur->manaMax+=monde->joueur->objet_equipe[0].mana_sup;
                monde->joueur->manaCour+=monde->joueur->objet_equipe[0].mana_sup;
                monde->joueur->nb_obj_equip++;
                
            }     
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 4){
            //Bouclier en bois
            if(monde->joueur->objet_equipe[1].id!=monde->joueur->inventaire[2].id){
                //Stat Debuff
                if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[3].id){
                    monde->joueur->manaMax-=monde->joueur->objet_equipe[1].mana_sup;
                    monde->joueur->nb_obj_equip--;
                }
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax;
                }
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                //Equipe
                monde->joueur->objet_equipe[1]=monde->joueur->inventaire[2];
                //Stat buff
                monde->joueur->combattant->pvMax+=monde->joueur->objet_equipe[1].vie_sup;
                monde->joueur->combattant->pvCour+=monde->joueur->objet_equipe[1].vie_sup;
                monde->joueur->nb_obj_equip++;

            }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 5){
            //Bouclier en diamant
            if(monde->joueur->objet_equipe[1].id!=monde->joueur->inventaire[3].id){
                //Stat Debuff
                if(monde->joueur->objet_equipe[1].id==monde->joueur->inventaire[2].id){
                    monde->joueur->combattant->pvMax-=monde->joueur->objet_equipe[1].vie_sup;
                    monde->joueur->nb_obj_equip--;
                }
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax; 
                }
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                //Equipe
                monde->joueur->objet_equipe[1]=monde->joueur->inventaire[3];
                //Stat buff
                monde->joueur->manaMax+=monde->joueur->objet_equipe[1].mana_sup;
                monde->joueur->manaCour+=monde->joueur->objet_equipe[1].mana_sup;
                monde->joueur->nb_obj_equip++;

            }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 6){

            if(monde->joueur->inventaire[4].id==6){
                monde->joueur->combattant->pvCour+=monde->joueur->inventaire[4].vie_sup;
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                monde->joueur->inventaire[4].id=0;
            }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 7){

            if(monde->joueur->inventaire[5].id==7){
                printf("rentre ici\n");
                monde->joueur->manaCour+=monde->joueur->inventaire[5].mana_sup;
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax;
                }
                monde->joueur->inventaire[5].id=0;
            }
        }
        
    }


}

void evenements_combat(SDL_Event * event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    int joueur_etait_vivant = (monde->joueur->combattant->pvCour > 0);
    int indice_deg = 0; //Si le joueur n'a pas attaqué vaut 0, 1 sinon
    if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat == VIVANT){
        if(monde->num_menu_comb == 1){


            if(event->type == SDL_KEYDOWN){
                if(keystates[SDL_SCANCODE_LEFT]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  gauche
                        case RIEN:
                            monde->option = ATTAQUE;
                            break;
                        case ATTAQUE:
                            monde->option = FUITE;
                            break;
                        case FUITE:
                            monde->option = ATTAQUE;
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_RIGHT]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  droite
                        case RIEN:
                            monde->option = FUITE;
                            break;
                        case ATTAQUE:
                            monde->option = FUITE;
                            break;
                        case FUITE:
                            monde->option = ATTAQUE;
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_RETURN] && monde->option != RIEN){
                    switch(monde->option){
                        case ATTAQUE:
                            //On change le numéro menu combat pour afficher celui des attaques dispos
                            //printf("On passe au menu des attaques\n");
                            monde->num_menu_comb = MENU2;
                            //printf("Nouveau numéro de menu : %d\n", monde->num_menu_comb);
                            monde->option = RIEN;
                            break;
                        case FUITE:
                            //On quitte le combat
                            //On modifie l'état du jeu afin de retourner à  la carte principale
                            monde->etat_jeu = 1;
                            break;

                    }
                }
            }
        }

        else if(monde->num_menu_comb == MENU2){

            //On doit dorénavant permettre la saisie du coup

            if(event->type == SDL_KEYDOWN){
                if(keystates[SDL_SCANCODE_LEFT]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  gauche
                        case RIEN:
                            monde->option = EPEE;
                            break;
                        case EPEE:
                            monde->option = RETOUR;
                            break;
                        case SORT:
                            monde->option = EPEE;
                            break;
                        case ARC:
                            //Si on a assez de mana on va sur la case sort sinon on va sur la case epee
                            if(monde->joueur->manaCour >=5){
                                monde->option = SORT;
                            }
                            else{
                                monde->option = EPEE;
                            }
                            break;
                        case RETOUR:
                            monde->option = ARC;
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_RIGHT]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  droite
                        case RIEN:
                            monde->option = RETOUR;
                            break;
                        case EPEE:
                            //Si on a assez de manas on va sur sort sinon on va sur arc car on ne peut pas utiliser le sort
                            if(monde->joueur->manaCour >=5){
                                monde->option = SORT;
                            }
                            else{
                                monde->option = ARC;
                            }
                            break;
                        case SORT:
                            monde->option = ARC;
                            break;
                        case ARC:
                            monde->option = RETOUR;
                            break;
                        case RETOUR:
                            monde->option = EPEE;
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_RETURN] && monde->option != RIEN){
                    switch(monde->option){
                        //Action lorsqu'on clique sur entrer en Ã©tant sur une des actions possibles
                        case EPEE:
                            //On inflige des dégâts au monstre
                            //Actualise ses pts de vie
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour -=monde->joueur->combattant->attaque;
                            //Finit le combat si pv du monstre <= 0
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour <= 0){
                                monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
                                //monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
                                monde->joueur->or += 30;
                                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat = MORT;
                            }
                            indice_deg++;//On indique que le joueur a attaqué
                            break;
                        case SORT:
                            //On inflige des dégâts au monstre
                            //Actualise ses pts de vie
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour -=monde->joueur->combattant->attaque;
                            //On réduit de 5 ses points de mana
                            monde->joueur->manaCour -= 5;
                            //Finit le combat si pv du monstre <= 0
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour <= 0){
                                monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
                                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
                                monde->joueur->or += 30;
                            }
                            indice_deg++;
                            break;
                        case ARC:
                            //On inflige des dÃ©gÃ¢ts au monstre
                            //Actualise ses pts de vie
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour -=monde->joueur->combattant->attaque;
                            //Finit le combat si pv du monstre <= 0
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour <= 0){
                                monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
                                printf("On tue par l'arc\n");
                                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
                                monde->joueur->or += 30;
                            }
                            indice_deg++;
                            break;
                        case RETOUR:
                            //Si on appuie sur "Retour" on affiche de nouveau le menu1
                            monde->num_menu_comb = MENU1;
                            monde->option = RIEN;
                            break;
                    }
                }
            }
        }
    }
    if(!joueur_etait_vivant){
      while(event->type != SDL_KEYDOWN){
        printf("Boucle\n");
      }
      printf("Sortie de boucle\n");
		if(monde->partie == 1){
            init_monde_jeu(monde, "./rsrc/txt/partie1.txt");
        }
        else{
            init_monde_jeu(monde, "./rsrc/txt/partie1.txt");
        }
    }
    //Le monstre attaque si le joueur a attaqué

    else if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat == VIVANT && monde->num_menu_comb != MENU1 && monde->etat_jeu != 1 && indice_deg == 1){
		//Le monstre inflige des dégâts basiquement au joueur
		monde->joueur->combattant->pvCour -= monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->attaque;

		if( monde->joueur->combattant->pvCour <= 0 && joueur_etait_vivant == 1){
      printf("Joueur mort\n");
			//S'il tue le joueur on affiche game over
			//apply_texture(textures->game_over, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
			//Il doit cliquer sur une touche en dehors de escape afin de le passer
		}
	}
    //On réinitialise la valeur de menu sur celle du premier pour le ré-afficher par la suite
    if(monde->num_menu_comb != MENU2){
        monde->num_menu_comb = MENU1;
    }
}

void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police){
    //Si le monstre est vivant et le joueur vivant alors on affiche tout ce qui est utile à prendre en compte pour les combats:
    //PV/PM
    //Menus ave choix des actions
    //printf("Option du menu: %d\n", monde->option);
    //printf("Numéro du menu:%d\n",monde->num_menu_comb);
    if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->etat == VIVANT && monde->joueur->combattant->pvCour > 0){
        //On affiche le monstre et le personnage
        apply_texture(textures->joueur,renderer, 1*SCREEN_WIDTH/8, 1*SCREEN_HEIGHT/8);

        //récupéation de l'information via la zone et la salle du joueur
        switch(monde->joueur->zone){
            case 0:
        //Renommer monstre_zone0
        //printf("Le monstre s'affiche\n");
                apply_texture(textures->monstre, renderer, 100, 100);
        break;
            case 1:
        apply_texture(textures->monstre_zone1, renderer, 7*SCREEN_WIDTH/8, 1*SCREEN_HEIGHT/8);
        break;
            case 2:
                switch(monde->joueur->salle){
                    case (0||1||2):
            apply_texture(textures->monstre_zone2, renderer, 7*SCREEN_WIDTH/8, 1*SCREEN_HEIGHT/8);
                        break;
                    case 3:
            apply_texture(textures->boss, renderer, 7*SCREEN_WIDTH/8, 1*SCREEN_HEIGHT/8);
                        break;
                }
        break;
        }

        //On affiche les points de vie/pm du joueur et du monstre

        char pv_j[3];
        char pv_m[3];
        char pm_j[3];

        sprintf(pv_j, "%d", (monde->joueur->combattant->pvCour));
        sprintf(pv_m, "%d", (monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0]->combattant->pvCour));
        sprintf(pm_j, "%d", (monde->joueur->manaCour));

        //Il faut afficher la barre de point de vie du joueur et du monstre ainsi que la barre de mana du joueur

        //Trois apply_texture à faire
        //->un pour chaque barre

        //sprintf(opt, pv_j);
        apply_text(renderer, 0, 255, 0, pv_j, police, 1*SCREEN_WIDTH/8, 2*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

        //sprintf(opt, pv_m);
        apply_text(renderer, 0, 255, 0, pv_m, police, 4*SCREEN_WIDTH/8, 2*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

        //sprintf(opt, mana_j);
        apply_text(renderer, 0, 255, 0, pm_j, police, 7*SCREEN_WIDTH/8, 2*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));


        //Si on affiche le menu 1
        if(monde->num_menu_comb == MENU1){
            //chaînes de caractères du texte
            char atq[10];
            char fuite[10];

            //Les cases dans lesquelles le texte se trouve
            apply_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 6*SCREEN_HEIGHT/8);
            apply_texture(textures->case_combat, renderer, 5*SCREEN_WIDTH/8, 6*SCREEN_HEIGHT/8);

            //Texte à afficher
            sprintf(atq, "Attaque");
            sprintf(fuite, "Fuite");

            switch(monde->option){
                case RIEN:
                    apply_text(renderer, 0, 255, 0, atq, police, 3*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));

                    apply_text(renderer, 0, 255, 0, fuite, police, 6*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));
                    break;
                case ATTAQUE:
                    apply_text(renderer, 255, 0, 0, atq, police, 3*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));

                    apply_text(renderer, 0, 255, 0, fuite, police, 6*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));
                    break;
                case FUITE:
                    apply_text(renderer, 0, 255, 0, atq, police, 3*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));

                    apply_text(renderer, 255, 0, 0, fuite, police, 6*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));
                    break;
            }
        }

        //Si on affiche le menu 2
        if(monde->num_menu_comb == MENU2){

            char epee[10];
            char sort[10];
            char arc[10];
            char retour[10];

            //Chaînes de caractères utiles pour afficher le texte
            sprintf(epee, "épée");
            sprintf(sort, "Sort");
            sprintf(arc, "Arc");
            sprintf(retour, "Retour");

            //case pour le choix coup d'épée
            apply_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 5*SCREEN_HEIGHT/8);
            //case pour le choix sort
            apply_texture(textures->case_combat, renderer, 5*SCREEN_WIDTH/8, 5*SCREEN_HEIGHT/8);
            //case pour le choix tir Ã  l'arc
            apply_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);
            //case pour le choix retour
            apply_texture(textures->case_combat, renderer, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);



            apply_text(renderer, 0, 255, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
            apply_text(renderer, 0, 255, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
            apply_text(renderer, 0, 255, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
            apply_text(renderer, 0, 255, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
            switch(monde->option){
                case RIEN:
                    apply_text(renderer, 0, 255, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    break;
                case EPEE:
                    apply_text(renderer, 255, 0, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    break;
                case SORT:
                    apply_text(renderer, 0, 255, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 255, 0, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    break;
                case ARC:
                    apply_text(renderer, 0, 255, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 255, 0, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    break;
                case RETOUR:
                    apply_text(renderer, 0, 255, 0, epee, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, sort, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 0, 255, 0, arc, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    apply_text(renderer, 255, 0, 0, retour, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));
                    break;
            }
        }
    }

    else if(monde->joueur->combattant->pvCour <= 0){
        //Si le joueur est mort alors on affiche une image de game over
        //Il faudra appuyez sur une touche pour sortir du jeu
        apply_texture(textures->game_over, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
        apply_text(renderer, 255, 0, 0, "Game Over", police, SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 125, 200, 100);
        apply_text(renderer, 255, 0, 0, "Press Enter To Retry", police, SCREEN_WIDTH/2 - 200, SCREEN_HEIGHT/2 + 25, 400, 100);

    }
    else{
        //ça signifie que seul le monstre est mort -> on retourne seulement au jeu
        monde->etat_jeu = 1;
    }
}