/**
  * \file menu.c
  * \brief gestion des menus
  * \author Anna Beranger, Alex Choux, Arthur Fabre
  * \date 03/03/2022
*/

#include <stdio.h>
#include  "../lib/menu.h"

/**
  * \fn void quitter_carte_aide(SDL_Event* event, monde_t * monde)
  * \brief gère la fermeture du menu aide et de la carte
  * \param event les évènements claviers
  * \param monde les données du monde
*/
void quitter_carte_aide(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    //on quitte l'affichage des cmmandes
    if(event->type == SDL_KEYDOWN){
        if(keystates[SDL_SCANCODE_RETURN]){
                monde->etat_jeu = ETAT_JEU_PRINCIPAL;
        }
    }
}

/**
  * \fn void choix_partie(SDL_Event* event, monde_t * monde)
  * \brief gère les options du menu de choix de partie
  * \param event les évènements claviers
  * \param monde les données du monde
*/
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
          monde->etat_jeu = ETAT_JEU_PRINCIPAL;
        }
        //partie 2
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
          //on initialise la partie
          init_monde_jeu(monde,"./rsrc/txt/partie2.txt"); //TO DO utiliser sauvegarde de différentes parties
          monde->partie = 2;
          printf("partie2");
          //on commence le jeu
          monde->etat_jeu = ETAT_JEU_PRINCIPAL;
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
              monde->etat_jeu = ETAT_JEU_PRINCIPAL;
            }
            //nouvelle partie sur l'emplacement partie 2
            if(keystates[SDL_SCANCODE_RETURN] && monde->option2 == 2){
              //on initialise la partie
              init_monde_jeu(monde,"./rsrc/txt/init.txt");
              monde->partie = 2;
              monde->etat_jeu = ETAT_JEU_PRINCIPAL;
            }
            //annuler le chargement d'une nouvelle partie
            if(keystates[SDL_SCANCODE_RETURN] && monde->option2 == 3){
              monde->option2 = 0;
            }
        }
        //retour
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 4){
          //on retourne au menu précedent
          monde->etat_jeu = ETAT_MENU_1;
        }
    }
}

/**
  * \fn void evenements_menu(SDL_Event* event, monde_t * monde)
  * \brief gère les options du menu principal
  * \param event les évènements claviers
  * \param monde les données du monde
*/
void evenements_menu(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if(event->type == SDL_KEYDOWN){
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
            printf("On appuie sur jouer\n");
            //on entre dans un menu avec le choix de la partie
            monde->etat_jeu = ETAT_MENU_2;
            monde->option = -1;
            printf("monde->etat_jeu = %d\n", monde->etat_jeu);
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
            monde->etat_jeu = ETAT_QUITTER;
        }
    }

}

/**
  * \fn void evenements_inventaire(SDL_Event* event, monde_t * monde)
  * \brief gère les options de l'inventaire
  * \param event les évènements claviers
  * \param monde les données du monde
*/
void evenements_inventaire(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
      //printf("Debut Nb obj equip = %d\n", monde->joueur->nb_obj_equip);
        if(keystates[SDL_SCANCODE_DOWN]){
          switch(monde->option){
            case INVENTAIRE :
              monde->option=EPEE_PIERRE;
              break;//
            case EPEE_PIERRE :
              monde->option=BOUCLIER_PIERRE;
              break;//1
            case EPEE_DIAM :
              monde->option=BOUCLIER_DIAM;
              break;//2
            case BOUCLIER_PIERRE :
              monde->option=INVENTAIRE;
              break;//3
            case BOUCLIER_DIAM :
              monde->option=EPEE_DIAM;
              break;//4
            case POTION_PV :
              monde->option=POTION_MANA;
              break;//6
            case POTION_MANA :
              monde->option=POTION_PV;
              break;//7
            default:
              monde->option=INVENTAIRE;
              break;
          }
        }
        if(keystates[SDL_SCANCODE_UP]){
          switch(monde->option){
            case INVENTAIRE :
              monde->option=BOUCLIER_PIERRE;
              break;//
            case EPEE_PIERRE :
              monde->option=INVENTAIRE;
              break;//1
            case EPEE_DIAM :
              monde->option=BOUCLIER_DIAM;
              break;//2
            case BOUCLIER_PIERRE :
              monde->option=EPEE_PIERRE;
              break;//3
            case BOUCLIER_DIAM :
              monde->option=EPEE_DIAM;
              break;//4
            case POTION_PV :
              monde->option=POTION_MANA;
              break;//6
            case POTION_MANA :
              monde->option=POTION_PV;
              break;//7
            default:
              monde->option=INVENTAIRE;
              break;
          }
        }
        if(keystates[SDL_SCANCODE_LEFT]){
          switch(monde->option){
            case INVENTAIRE :
              break;//
            case EPEE_PIERRE :
              monde->option=POTION_PV;
              break;//1
            case EPEE_DIAM :
              monde->option=EPEE_PIERRE;
              break;//2
            case BOUCLIER_PIERRE :
              monde->option=POTION_MANA;
              break;//3
            case BOUCLIER_DIAM :
              monde->option=BOUCLIER_PIERRE;
              break;//4
            case POTION_PV :
              monde->option=EPEE_DIAM;
              break;//6
            case POTION_MANA :
              monde->option=BOUCLIER_DIAM;
              break;//7
            default:
              monde->option=INVENTAIRE;
              break;
          }
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
          switch(monde->option){
            case INVENTAIRE :
              break;//
            case EPEE_PIERRE :
              monde->option=EPEE_DIAM;
              break;//1
            case EPEE_DIAM :
              monde->option=POTION_PV;
              break;//2
            case BOUCLIER_PIERRE :
              monde->option=BOUCLIER_DIAM;
              break;//3
            case BOUCLIER_DIAM :
              monde->option=POTION_MANA;
              break;//4
            case POTION_PV :
              monde->option=EPEE_PIERRE;
              break;//6
            case POTION_MANA :
              monde->option=BOUCLIER_PIERRE;
              break;//7
            default:
              monde->option=INVENTAIRE;
              break;
          }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == EPEE_PIERRE){
            equipement_desequipement_objet(monde->joueur, 0, 0);
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == EPEE_DIAM){
            //Epee en diamant équipée
            equipement_desequipement_objet(monde->joueur, 1, 0);
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == BOUCLIER_PIERRE){
            //Bouclier en bois
            equipement_desequipement_objet(monde->joueur, 2, 1);
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == BOUCLIER_DIAM){
            //Bouclier en diamant
            equipement_desequipement_objet(monde->joueur, 3, 1);
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == POTION_PV){
            if(monde->joueur->inventaire[INDICE_POTION_PV].id==ID_POTION_PV && monde->joueur->inventaire[INDICE_POTION_PV].nb_obj>0 && (monde->joueur->combattant->pvCour < monde->joueur->combattant->pvMax)){ // Si il y'a une potion dans l'inventaire
                monde->joueur->combattant->pvCour+=monde->joueur->inventaire[INDICE_POTION_PV].vie_sup;
                if(monde->joueur->combattant->pvCour>monde->joueur->combattant->pvMax){ // empeche d'avoir plus de pv que le pv max
                    monde->joueur->combattant->pvCour=monde->joueur->combattant->pvMax;
                }
                monde->joueur->inventaire[INDICE_POTION_PV].nb_obj--; // Enleve une potion de l'inventaire
                if(monde->joueur->inventaire[INDICE_POTION_PV].nb_obj==0){ // Si il n'y à plus de potions on l'enleve de l'inventaire.
                    monde->joueur->inventaire[INDICE_POTION_PV].id=0;
                }

            }
        }
        if(keystates[SDL_SCANCODE_RETURN] && monde->option == POTION_MANA){
            if(monde->joueur->inventaire[INDICE_POTION_MANA].id==ID_POTION_MANA && monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj>0 && (monde->joueur->manaCour < monde->joueur->manaMax)){ // Si il y'a une potion dans l'inventaire
                monde->joueur->manaCour+=monde->joueur->inventaire[INDICE_POTION_MANA].mana_sup;
                if(monde->joueur->manaCour>monde->joueur->manaMax){ // empeche d'avoir plus de mana que le mana max
                    monde->joueur->manaCour=monde->joueur->manaMax;
                }
                monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj--; // Enleve une potion de l'inventaire
                if(monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj==0){ // Si il n'y à plus de potions on l'enleve de l'inventaire.
                    monde->joueur->inventaire[INDICE_POTION_MANA].id=0;
                }

            }
        }

    }

    //printf("Fin Nb obj equip = %d\n", monde->joueur->nb_obj_equip);
}

/**
  * \fn void evenements_fin_partie(SDL_Event* event, monde_t * monde)
  * \brief gère leretour au menu pendant l'écran de victoire
  * \param event les évènements claviers
  * \param monde les données du monde
*/
void evenements_fin_partie(SDL_Event* event, monde_t * monde){
  const Uint8* keystates = SDL_GetKeyboardState(NULL);

  if(event->type == SDL_KEYDOWN){
    if(keystates[SDL_SCANCODE_RETURN]){
      monde->etat_jeu = ETAT_QUITTER;
    }
  }
}
