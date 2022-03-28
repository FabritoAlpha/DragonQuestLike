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
#define DECALAGE_TEXT_IMG_L 100
#define DECALAGE_TEXT_IMG_H 100


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
          sprintf(opt, "Quitter");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
          }
      }
      //quitter
      if(monde->option == 2){
          sprintf(opt, "Jouer");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
          }
          sprintf(opt, "Quitter");
          if(police != 0){
              apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
          }
      }
      if(monde->option < 1 || monde->option > 2){
        sprintf(opt, "Jouer");
        if(police != 0){
            apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(police != 0){
            apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
        }
      }
  }
  if(monde->etat_jeu == 4){
      //Partie 1
      if(monde->option == 1){
          sprintf(opt, "Partie 1");
          if(police != 0){
              apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Partie 2");
          if(police != 0){
              apply_text(renderer, 0, 255, 0 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Nouvelle partie");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
          }
          sprintf(opt, "Retour");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
          }
      }
      //Partie 2
      if(monde->option == 2){
          sprintf(opt, "Partie 1");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Partie 2");
          if(police != 0){
              apply_text(renderer, 150, 255, 150 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Nouvelle partie");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
          }
          sprintf(opt, "Retour");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
          }
      }
      //Nouvelle partie
      if(monde->option == 3){
          sprintf(opt, "Partie 1");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Partie 2");
          if(police != 0){
              apply_text(renderer, 0, 255, 0 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Retour");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
          }
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
      }
      //Retour
      if(monde->option == 4){
          sprintf(opt, "Partie 1");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Partie 2");
          if(police != 0){
              apply_text(renderer, 0, 255, 0 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
          }
          sprintf(opt, "Nouvelle partie");
          if(police != 0){
              apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
          }
          sprintf(opt, "Retour");
          if(police != 0){
              apply_text(renderer, 150, 255, 150, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
          }
      }
      if(monde->option > 4 || monde->option < 1){
        sprintf(opt, "Partie 1");
        if(police != 0){
            apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
        }
        sprintf(opt, "Partie 2");
        if(police != 0){
            apply_text(renderer, 0, 255, 0 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
        }
        sprintf(opt, "Nouvelle partie");
        if(police != 0){
            apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
        }
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
    char opt[20] = "";
    char opt2[20] = "";
    //jouer
    if(monde->option == 1){
        sprintf(opt, "inventaire");
        apply_text(renderer, 150, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //snprintf(opt2, 20, "%ls", monde->joueur->inventaire[0]);
        //sprintf(opt,opt2);
        //apply_text(renderer, 150, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6-100 , LARGEUR_TEXT/2, HAUTEUR_TEXT/2);
        //sprintf(opt, "Objet 1");
        snprintf(opt2, 20, "%i", monde->joueur->inventaire[0]);
        sprintf(opt,"%s", opt2);
        apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0 , opt , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 2");
        snprintf(opt2, 20, "%i", monde->joueur->inventaire[0]);
        sprintf(opt,"%s", opt2);
        apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 3");
        snprintf(opt2, 20, "%i", monde->joueur->inventaire[0]);
        sprintf(opt,"%s", opt2);
        apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*1.5);
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        //sprintf(opt, "Objet 4");
        snprintf(opt2, 20, "%i", monde->joueur->inventaire[0]);
        sprintf(opt,"%s", opt2);
        apply_texture(textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*1.5);
        apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
    }
    if(monde->option == 2){
      sprintf(opt, "inventaire");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(police != 0){
          apply_text(renderer, 150, 255, 0 , opt , police, POSITION_INVENTAIRE_L*0.3, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.3 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    //quitter
    if(monde->option == 3){
      sprintf(opt, "inventaire");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(police != 0){
          apply_text(renderer, 0, 255, 0 , opt , police, POSITION_INVENTAIRE_L*0.3, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(police != 0){
          apply_text(renderer, 150, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.3 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    if(monde->option == 4){
      sprintf(opt, "inventaire");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(police != 0){
          apply_text(renderer, 0, 255, 0 , opt , police, POSITION_INVENTAIRE_L*0.3, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(police != 0){
          apply_text(renderer, 150, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.3 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    if(monde->option == 5){
      sprintf(opt, "inventaire");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(police != 0){
          apply_text(renderer, 0, 255, 0 , opt , police, POSITION_INVENTAIRE_L*0.3, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(police != 0){
          apply_text(renderer, 0, 255, 0, opt , police, POSITION_INVENTAIRE_L*0.3 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(police != 0){
          apply_text(renderer, 150, 255, 0, opt , police, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
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
          }
        }
        if(keystates[SDL_SCANCODE_UP]){
          switch(monde->option){
            case 1 :monde->option=4;break;//
            case 2 :monde->option=1;break;//1
            case 3 :monde->option=1;break;//2
            case 4 :monde->option=2;break;//3
            case 5 :monde->option=3;break;//4
          }
        }
        if(keystates[SDL_SCANCODE_LEFT]){
          switch(monde->option){
            case 1 :break;//
            case 2 :monde->option=3;break;//1
            case 3 :monde->option=2;break;//2
            case 4 :monde->option=5;break;//3
            case 5 :monde->option=4;break;//4
          }
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
          switch(monde->option){
            case 1 :break;//
            case 2 :monde->option=3;break;//1
            case 3 :monde->option=2;break;//2
            case 4 :monde->option=5;break;//3
            case 5 :monde->option=4;break;//4
          }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){
            //
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
            //
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
            //
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 4){
            //
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 5){
            //
        }
    }

}
