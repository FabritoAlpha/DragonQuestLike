/**
*\file jeu.c
*\brief gestion du jeu
*\author Anna Beranger
*\date 17/02/2022
*/

#include "../lib/jeu.h"
/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde, TTF_Font * police){

    detruire_monde(&monde);

    clean_images(textures, police);

    clean_sdl(renderer,window);
}

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 * \param next_tick correspond au prochain tick du jeu
 * \param next_tick_monstre correspond au prochain tick dans lequel le monstre va effectuer une action
 */
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * next_tick,int *next_tick_monstre, TTF_Font* police){
    //printf("On rentre dans rafraichir\n");
    int time_sec=(SDL_GetTicks()/15);

    //on vide le renderer
    SDL_RenderClear(renderer);


    if(monde->etat_jeu == ETAT_MENU_1 || monde->etat_jeu == ETAT_MENU_2){

      fond(renderer, textures, monde);

      affichage_menu(renderer, monde, police);

    }
    else{
      //printf("Test affichage fond\n");
      fond(renderer, textures, monde);
    }
    if(monde->etat_jeu == ETAT_INVENTAIRE){
      affichage_inventaire(renderer, monde, textures, police);
    }
    if(monde->etat_jeu == ETAT_COMBAT){
      affichage_combat(renderer, monde, textures, police);
    }

    if(monde->etat_jeu == ETAT_VICTOIRE){
      affichage_victoire(renderer,textures,police);
    }

    if(monde->etat_jeu == ETAT_DIALOGUE){
      switch(monde->joueur->zone){
          case 0:
              switch(monde->joueur->salle){
                  case 0:
                      // si c'est un pnj non marchand
                      if(nonCombattant_proche(monde) == 1)
                          dialogue_position(renderer, textures, 0);
                      // si c'est un marchand
                      if(nonCombattant_proche(monde) == 2)
                          dialogue_position(renderer, textures, 4);
                  break;
                  case 2:
                      dialogue_position(renderer, textures, 3);
                  break;
              }
          break;
          case 1:
              switch(monde->joueur->salle){
                  case 0:
                      // si c'est un pnj non marchand
                      if(nonCombattant_proche(monde) == 1)
                          dialogue_position(renderer, textures, 1);
                      // si c'est un  marchand
                      if(nonCombattant_proche(monde) == 2)
                          dialogue_position(renderer, textures, 3);
                  break;
                  case 2:
                      dialogue_position(renderer, textures, 4);
                  break;
              }
          break;
          case 2:
              switch(monde->joueur->salle){
                  case 0:
                      // si c'est un pnj non marchand
                      if(nonCombattant_proche(monde) == 1)
                          dialogue_position(renderer, textures, 2);
                      // si c'est un  marchand
                      if(nonCombattant_proche(monde) == 2)
                          dialogue_position(renderer, textures, 4);
                  break;
                  case 2:
                      dialogue_position(renderer, textures, 3);
                  break;
              }
          break;
      }
        affichage_dialogue(renderer, textures, monde, police);
    }
    if(monde->etat_jeu == ETAT_COFFRE){
        affichage_dialogue(renderer, textures, monde, police);
    }
    if(monde->etat_jeu == ETAT_AIDE){
        affichage_aide(renderer, police);
    }
    if(monde->etat_jeu == ETAT_CARTE){
        affichage_carte(renderer, police, textures, monde->joueur);
    }

    if(monde->etat_jeu == 1){
      char aide[10] = "Aide A";
      apply_text(renderer, 0, 0, 0, aide , police, 570 + (taille_fenetre[0]/2) - 250, 300 + (taille_fenetre[1]/2) , 100, 40);
      if(nonCombattant_proche(monde) == 1 || nonCombattant_proche(monde) == 2){
        char indication[150] = "Appuyer sur P pour parler";
        apply_text(renderer, 0, 0, 0, indication , police, (taille_fenetre[0]/2) - 250, 230 + (taille_fenetre[1]/2) , 500, 40);
      }
      if(nonCombattant_proche(monde) == 3){
          if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite == 0){
              char indication[150] = "Appuyer sur 0 pour ouvrir le coffre";
              apply_text(renderer, 0, 0, 0, indication , police, (taille_fenetre[0]/2) - 300, 230 + (taille_fenetre[1]/2) , 600, 40);
          }
      }

      joueur_position(renderer, textures, monde->joueur);

      affichage_nonCombattants(renderer,textures, monde->zones[monde->joueur->zone], monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]);

      int suivaleatoir;
      if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat == VIVANT){
        monstre_position(renderer, textures, monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre);
        if(time_sec>(*next_tick_monstre)){
          if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->vitesse==1){
            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->vitesse=0;
          }else{
            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->vitesse=1;
          }
          do{
            suivaleatoir=rand()%500;
          }while(suivaleatoir<200||suivaleatoir>500);
          (*next_tick_monstre)+=suivaleatoir;
        }
        //printf("time sec %d nexttick %d\n",time_sec,(*next_tick));
        if(time_sec>(*next_tick)){
          (*next_tick) = (*next_tick) + 8;
          //printf("On déplace le monstre");
          deplacement_monstre(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre, monde);
        }
        else{
          (*next_tick) = (*next_tick)-1;
        }

      }

    }
    if(victoire_jeu(monde) && monde->etat_jeu == ETAT_JEU_PRINCIPAL){
      monde->etat_jeu = ETAT_VICTOIRE;
    }

    //On actualise l'affichage
    //(*next_tick)+=1;
    SDL_RenderPresent(renderer);

}

/**
 * \brief gestion des évènements avant le rafraichissement
 * \param event contient les événements
 * \param monde les données du monde
 */
void evenements(SDL_Event* event, monde_t * monde){
  const Uint8* keystates = SDL_GetKeyboardState(NULL);


    while(SDL_PollEvent( event )) {
        if(event->type != SDL_KEYDOWN)
           continue;

        if(monde->etat_jeu == ETAT_MENU_1){
            printf("On rentre dans evenements menu\n");
            evenements_menu(event, monde);
        }
        if(monde->etat_jeu == ETAT_MENU_2){
            choix_partie(event,monde);
            if(monde->partie == 1 || monde->partie == 2){
              //Après avoir choisi le fichier où sauvegarder on écrase la sauvegarde avec soit l'initialisation soit le fichier chargé qui était sauvegardé
              sauvegarde(monde);
            }
            printf("menu partie\n");
        }
        /*!< Jeu en cours */
        if(monde->etat_jeu == ETAT_JEU_PRINCIPAL){
            //si on appuie sur A on affiche les commandes
            if(event->key.keysym.sym == SDLK_a){
              monde->etat_jeu = ETAT_AIDE;
            }
            //si on appuie sur C on affiche la map
            if(event->key.keysym.sym == SDLK_c){
              monde->etat_jeu = ETAT_CARTE;
            }
            //si on appuie sur M on retour au menu principal
            if(event->key.keysym.sym == SDLK_m){
              monde->option = 1;
              monde->etat_jeu= ETAT_MENU_1;
            }
            //le coffre s'ouvre
            if(nonCombattant_proche(monde) == 3  && event->key.keysym.sym == SDLK_o && monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite == 0){
                monde->etat_jeu = ETAT_COFFRE;
            }

            //on entre dans un dialogue
            if((nonCombattant_proche(monde) == 1  ||  nonCombattant_proche(monde) == 2) && event->key.keysym.sym == SDLK_p){
                //on initialise l'option pour les réponses au marchand
                monde->option = -1;
                monde->etat_jeu = ETAT_DIALOGUE;
            }
            if( keystates[SDL_SCANCODE_LEFT]) {
                deplacement_gauche(monde->joueur->combattant, 0, monde);
            }
            if(keystates[SDL_SCANCODE_RIGHT]){
                deplacement_droit(monde->joueur->combattant, 0, monde);
            }
            if(keystates[SDL_SCANCODE_UP]){
                deplacement_haut(monde->joueur->combattant, 0, monde);
            }
            if(keystates[SDL_SCANCODE_DOWN]){
                deplacement_bas(monde->joueur->combattant, 0, monde);
            }
            if(event->key.keysym.sym == SDLK_i){// Si en jeu il ouvre l'inventaire
                monde->etat_jeu=ETAT_INVENTAIRE;
                event->key.keysym.sym =0;

            }
        }
        // Si dans l'inventaire le joueur le ferme.
        if(monde->etat_jeu==ETAT_INVENTAIRE){// si dans inventaire
          evenements_inventaire(event, monde);
          if(event->key.keysym.sym == SDLK_i){
            monde->etat_jeu=1;
          }
        }
        if(monde->etat_jeu == ETAT_COMBAT){
          evenements_combat(event, monde);
        }

        if(monde->etat_jeu == ETAT_VICTOIRE){
          evenements_fin_partie(event, monde);
        }

        if(monde->etat_jeu == ETAT_AIDE || monde->etat_jeu == ETAT_CARTE){
          quitter_carte_aide(event, monde);
        }

        if(monde->etat_jeu == ETAT_DIALOGUE || monde->etat_jeu == ETAT_COFFRE){
          interaction_nonCombattant(event, monde);
        }

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //sauvegarde(monde);
            //On indique la fin du jeu
            monde->etat_jeu = ETAT_QUITTER;
            printf("fin du jeu");
        }
        if(keystates[SDL_SCANCODE_ESCAPE] ){
            //sauvegarde(monde);
            monde->etat_jeu = ETAT_QUITTER;
            printf("fin du jeu");
        }
    }

    SDL_PumpEvents();
}
