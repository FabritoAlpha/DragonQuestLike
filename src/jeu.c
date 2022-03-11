/**
*\file jeu.c
*\brief gestion du jeu
*\author Anna Beranger
*\date 17/02/2022
*/

#include "../lib/monde.h"
#include "../lib/images.h"
#include "../lib/sdl2_fonctions.h"
#include "../lib/jeu.h"
/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde){
    //printf("Test de la destruction du monde\n");
    detruire_monde(&monde);
    printf("Test de la destruction de textures\n");
    clean_images(textures);
    printf("Test de la destruction de la sdl");
    clean_sdl(renderer,window);
}

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param wordl le monde
 */
void init(SDL_Window **window, SDL_Renderer **renderer, images_t *textures, monde_t * monde){
    init_monde(monde);
    init_sdl(window, renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ttf();
    init_images(*renderer,textures);
}


/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * next_tick){
    int time_sec=(SDL_GetTicks()/10);
    //on vide le renderer
    clear_renderer(renderer);

    fond_position(renderer, textures);

    if(monde->etat_jeu == 0){
      affichage_menu(renderer, monde, textures);
    }

    if(monde->etat_jeu == 1){
      joueur_position(renderer, textures, monde->joueur);

      for(int i = 0; i < NB_MONSTRES_SALLE ; i++){
        monstre_position(renderer, textures, monde->zones[0]->salles[0]->monstres[i]);

        if(time_sec>(*next_tick)){
          (*next_tick)+=1;
          deplacement_monstre(monde->zones[0]->salles[0]->monstres[i]);
        }

      }

    }

    update_screen(renderer);
}

void affichage_menu(SDL_Renderer *renderer, monde_t * monde, images_t *textures){
    char opt[20] = "";
    //jouer
    if(monde->option == 1){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150, opt , textures->font, SCREEN_WIDTH/3 , SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0 , opt , textures->font, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/4, 350, 80);
        }
    }
    //Nouvelle partie
    if(monde->option == 2){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/3 , SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150 , opt , textures->font, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/4, 350, 80);
        }
    }
    //quitter
    if(monde->option == 3){
        sprintf(opt, "Jouer");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0, opt , textures->font, SCREEN_WIDTH/3 , SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Nouvelle Partie");
        if(textures->font != 0){
            apply_text(renderer, 0, 255, 0 , opt , textures->font, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/4 , 350, 80);
        }
        sprintf(opt, "Quitter");
        if(textures->font != 0){
            apply_text(renderer, 150, 255, 150, opt , textures->font, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/4, 350, 80);
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
            monde->etat_jeu = 1;
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
            monde->etat_jeu = -1;
        }
    }
}

/**
 * \brief gestion des évènements avant le rafraichissement
 * \param event contient les événements
 * \param monde les données du monde
 */

void evenements(SDL_Event* event, monde_t * monde){
  const Uint8* keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent( event )) {
        /*!< Menu */
        if(monde->etat_jeu == 0){
            evenements_menu(event, monde);
        }
        /*!< Jeu en cours */
        if(monde->etat_jeu == 1){
            if(event->key.keysym.sym == SDLK_LEFT) {
                a_gauche(monde->joueur->combattant);
            }
            if(event->key.keysym.sym == SDLK_RIGHT){
                a_droite(monde->joueur->combattant);
            }
            if(event->key.keysym.sym == SDLK_UP){
                en_haut(monde->joueur->combattant);
            }
            if(event->key.keysym.sym == SDLK_DOWN){
                en_bas(monde->joueur->combattant);
            }
        }

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
        if(keystates[SDL_SCANCODE_ESCAPE] ){
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
    }

    SDL_PumpEvents();
}
