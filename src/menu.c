#include <stdio.h>
#include  "../lib/menu.h"
#define LARGEUR_TEXT 350//(SCREEN_WIDTH/4)
#define HAUTEUR_TEXT 80//(POSITION_MENU_HEIGHT/10)
#define TEXT_OBJET_L 350//(LARGEUR_TEXT/2)
#define TEXT_OBJET_H 80//(HAUTEUR_TEXT/2)
#define POSITION_MENU_WIDTH (SCREEN_WIDTH/3)
#define POSITION_MENU_HEIGHT (SCREEN_HEIGHT/4)
#define POSITION_INVENTAIRE_L (SCREEN_WIDTH/2)
#define POSITION_INVENTAIRE_H (SCREEN_HEIGHT/3)




void affichage_menu(SDL_Renderer *renderer, monde_t * monde, images_t *textures){
    char opt[20] = "";
    //jouer
    if(monde->option == 1){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150, opt , textures->font, POSITION_MENU_WIDTH , POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_MENU_WIDTH, 2*POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_MENU_WIDTH , 3*POSITION_MENU_HEIGHT, 350, 80);
        }
    }
    //Nouvelle partie
    if(monde->option == 2){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_MENU_WIDTH , POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150 , opt , textures->font, POSITION_MENU_WIDTH, 2*POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_MENU_WIDTH , 3*POSITION_MENU_HEIGHT, 350, 80);
        }
    }
    //quitter
    if(monde->option == 3){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_MENU_WIDTH , POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_MENU_WIDTH, 2*POSITION_MENU_HEIGHT , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150, opt , textures->font, POSITION_MENU_WIDTH , 3*POSITION_MENU_HEIGHT, 350, 80);
        }
    }
}

void evenements_menu(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if(event->type == SDL_KEYDOWN){
        if(keystates[SDL_SCANCODE_DOWN]){
            if(monde->option < 3)
                monde->option++;
            else
                monde->option = 1;
        }
        if(keystates[SDL_SCANCODE_UP]){
            if(monde->option > 1)
                monde->option--;
            else
                monde->option = 3; //3 options pour le moment
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){

            init_monde_jeu(monde,"./rsrc/txt/init.txt"); //TO DO utiliser sauvegarde de différentes parties

            monde->etat_jeu = 1;

        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
            monde->etat_jeu = -1;
        }
    }

}
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures){
    char opt[20] = "";
    //jouer
    if(monde->option == 1){
        sprintf(opt, "inventaire");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 0, opt , textures->font, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        }
        sprintf(opt, "Objet 1");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_INVENTAIRE_L*0.4, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
        }
        sprintf(opt, "Objet 2");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
        }
        sprintf(opt, "Objet 3");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*0.4 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
        }
        sprintf(opt, "Objet 4");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
        }
    }
    //Nouvelle partie
    if(monde->option == 2){
      sprintf(opt, "inventaire");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(textures->font != 0){
          apply_text(renderer, 150, 255, 0 , opt , textures->font, POSITION_INVENTAIRE_L*0.4, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*0.4 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    //quitter
    if(monde->option == 3){
      sprintf(opt, "inventaire");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_INVENTAIRE_L*0.4, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(textures->font != 0){
          apply_text(renderer, 150, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*0.4 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    if(monde->option == 4){
      sprintf(opt, "inventaire");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_INVENTAIRE_L*0.4, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(textures->font != 0){
          apply_text(renderer, 150, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*0.4 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
    if(monde->option == 5){
      sprintf(opt, "inventaire");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 1");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0 , opt , textures->font, POSITION_INVENTAIRE_L*0.4, POSITION_INVENTAIRE_H , LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 2");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2 , POSITION_INVENTAIRE_H, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 3");
      if(textures->font != 0){
          apply_text(renderer, 0, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*0.4 , POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
      sprintf(opt, "Objet 4");
      if(textures->font != 0){
          apply_text(renderer, 150, 255, 0, opt , textures->font, POSITION_INVENTAIRE_L*1.2, POSITION_INVENTAIRE_H*1.5, LARGEUR_TEXT, HAUTEUR_TEXT);
      }
    }
}
void evenements_inventaire(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
        if(keystates[SDL_SCANCODE_DOWN]){
            if(monde->option < 5)
                monde->option++;
            else
                monde->option = 1;
        }
        if(keystates[SDL_SCANCODE_UP]){
            if(monde->option > 1)
                monde->option--;
            else
                monde->option = 5; //5 options pour le moment
        }
        if(keystates[SDL_SCANCODE_LEFT]){
          if(monde->option > 2)
            monde->option--;
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
          if(monde->option < 5)
            monde->option++;
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
