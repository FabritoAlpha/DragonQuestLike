/**
  * \file interactions.c
  * \brief gestion des interactions du joueur avec les entités
  * \author Anna Beranger, Alex Choux, Arthur Fabre
  * \date 03/03/2022
*/

#include  "../lib/interactions.h"

/**
	* \fn void interaction_nonCombattant(SDL_Event* event, monde_t * monde)
  * \brief gestion des intéraction avec les nonCombattant: dialogue avec pnj, ouverture de coffre
  * \param event les évènements claviers (et souris)
  * \param monde le monde
*/
void interaction_nonCombattant(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
        // si c'est un pnj non marchand
        if(nonCombattant_proche(monde) == 1){
            if(keystates[SDL_SCANCODE_RETURN]){
                monde->etat_jeu = ETAT_JEU_PRINCIPAL;
            }
        }

        // si c'est un marchand
        if(nonCombattant_proche(monde) == 2){
            if(keystates[SDL_SCANCODE_RIGHT]){
                if(monde->option < 5)
                    monde->option++;
                else
                    monde->option = 1;
            }
            if(keystates[SDL_SCANCODE_LEFT]){
                if(monde->option > 1)
                    monde->option--;
                else
                    monde->option = 5; //5 options pour le moment
            }
            if(keystates[SDL_SCANCODE_RETURN] && monde->option == 1){
                //on achète la potion de vie
                if((monde->joueur->or)-20 >= 0){ // vérification de l'argent du joueur
                  monde->joueur->or = monde->joueur->or - 20;
                  // Ajout d'une potion de vie
                  ajout_objet(monde->joueur, monde->biblio_objet, 4);
                  monde->option = 0;
                }

            }
            if(keystates[SDL_SCANCODE_RETURN] && monde->option == 2){
                //on achète la potion de mana
                if((monde->joueur->or) -20 >= 0){ // vérification de l'argent du joueur
                  monde->joueur->or = monde->joueur->or - 20;
                  // Ajout d'une potion de mana
                  ajout_objet(monde->joueur, monde->biblio_objet, 5);
                  monde->option = 0;
                }
            }
            if(keystates[SDL_SCANCODE_RETURN] && monde->option == 3){
                //si on est dans la dernière zone
                if(monde->joueur->zone == 2){
                  //le marchand vend l'épée en diamant
                  if((monde->joueur->or) - 200 >= 0 && !objet_present(monde->joueur, monde->biblio_objet, 1)){ // vérification de l'argent du joueur
                    monde->joueur->or = monde->joueur->or - 200;
                    // Ajout d'une épée en diamant
                    ajout_objet(monde->joueur, monde->biblio_objet, 1);
                    monde->option = 0;
                  }
                } else{
                  //avant la dernière zone:
                  //le marchand vend l'épée en pierre
                  if((monde->joueur->or) - 100 >= 0 && !objet_present(monde->joueur, monde->biblio_objet, 0)){ // vérification de l'argent du joueur
                    monde->joueur->or = monde->joueur->or - 100;
                    // Ajout d'une épée en pierre
                    ajout_objet(monde->joueur, monde->biblio_objet, 0);
                    monde->option = 0;
                  }
                }
            }
            if(keystates[SDL_SCANCODE_RETURN] && monde->option == 4){
              //si on est dans la dernière zone
              if(monde->joueur->zone == 2){
                //le marchand vend le bouclier en diamant
                // vérification de l'argent du joueur et de l'absence de l'objet dans l'inventaire
                if((monde->joueur->or) - 200 >= 0 && !objet_present(monde->joueur, monde->biblio_objet, 3)){
                  monde->joueur->or = monde->joueur->or - 200;
                  // Ajout d'un bouclier en diamant
                  ajout_objet(monde->joueur, monde->biblio_objet, 3);
                  monde->option = 0;
                }
              } else{
                //avant la dernière zone:
                //le marchand vend le bouclier en pierre
                if((monde->joueur->or) - 100 >= 0 && !objet_present(monde->joueur, monde->biblio_objet, 2)){ // vérification de l'argent du joueur
                  monde->joueur->or = monde->joueur->or - 100;
                  // Ajout d'un bouclier en pierre
                  ajout_objet(monde->joueur, monde->biblio_objet, 2);
                  monde->option = 0;
                }
              }
                monde->option = 0;
            }
            if(keystates[SDL_SCANCODE_RETURN] && monde->option == 5){
                monde->option = 0;
                //on quitte la boutique
                monde->etat_jeu = ETAT_JEU_PRINCIPAL;
            }

        }
        // si c'est un coffre
        if(nonCombattant_proche(monde) == 3){
            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite == 0){
                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite = 1;
                monde->joueur->or = monde->joueur->or + 500;
            }
            if(keystates[SDL_SCANCODE_RETURN]){
                monde->etat_jeu = ETAT_JEU_PRINCIPAL;
            }
        }
    }
}

/**
	* \fn void evenements_combat(SDL_Event * event, monde_t * monde)
  * \brief gestion des combats
  * \param event les évènements claviers (et souris)
  * \param monde le monde
*/
void evenements_combat(SDL_Event * event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    int joueur_etait_vivant = (monde->joueur->combattant->pvCour > 0);
    int indice_deg = 0; //Si le joueur n'a pas attaqué vaut 0, 1 sinon
    if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat == VIVANT){
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
                            monde->etat_jeu = ETAT_JEU_PRINCIPAL;
                            //On fait spawn le monstre suffisamment loin de nous pour pouvoir fuire
                            //On place le monstre à l'opossé du joueur
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->x = SCREEN_WIDTH - monde->joueur->combattant->x;
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->y = SCREEN_HEIGHT - monde->joueur->combattant->y;
                            //On vérifie que le monstre ne soit pas bloquée dans la bordure haute de la salle
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->y < 100){
                              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->y += 100;
                            }
                            //On vérifie que le monstre ne soit pas bloquée dans la bordure basse de la salle
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){
                              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->y -= 100;
                            }
                            //On vérifie que le monstre ne soit pas bloquée dans la bordure gauche de la salle
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->x < 100){
                              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->x += 100;
                            }
                            //On vérifie que le monstre ne soit pas bloquée dans la bordure droite de la salle
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->x + LARGEUR_PERSONNAGE > SCREEN_WIDTH -100){
                              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->x -= 100;
                            }

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
                            if(monde->joueur->manaCour >= 5){
                                monde->option = SORT;
                            }
                            else{
                                monde->option = OBJETS;
                            }
                            break;
                        case SORT:
                            monde->option = EPEE;
                            break;
                        case OBJETS:
                            //Si on a assez de mana on va sur la case sort sinon on va sur la case epee
                            monde->option = RETOUR;
                            break;
                        case RETOUR:
                            monde->option = OBJETS;
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
                                monde->option = OBJETS;
                            }
                            break;
                        case SORT:
                            monde->option = EPEE;
                            break;
                        case OBJETS:
                            monde->option = RETOUR;
                            break;
                        case RETOUR:
                            monde->option = OBJETS;
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_DOWN]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  droite
                        case RIEN:
                            monde->option = RETOUR;
                            break;
                        case EPEE:
                            //Si on a assez de manas on va sur sort sinon on va sur arc car on ne peut pas utiliser le sort
                            monde->option = OBJETS;
                            break;
                        case SORT:
                            monde->option = RETOUR;
                            break;
                        case OBJETS:
                            monde->option = EPEE;
                            break;
                        case RETOUR:
                            if(monde->joueur->manaCour >= 5){
                              monde->option = SORT;
                            }
                            else{
                              monde->option = EPEE;
                            }
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_UP]){
                    switch(monde->option){
                        //On décale le curseur vers la case Ã  droite
                        case RIEN:
                            monde->option = EPEE;
                            break;
                        case EPEE:
                            //Si on a assez de manas on va sur sort sinon on va sur OBJETS car on ne peut pas utiliser le sort
                            monde->option = OBJETS;
                            break;
                        case SORT:
                            monde->option = RETOUR;
                            break;
                        case OBJETS:
                            monde->option = EPEE;
                            break;
                        case RETOUR:
                            if(monde->joueur->manaCour >= 5){
                              monde->option = SORT;
                            }
                            else{
                              monde->option = EPEE;
                            }
                            break;
                    }
                }
                if(keystates[SDL_SCANCODE_RETURN] && monde->option != RIEN){
                    switch(monde->option){
                        //Action lorsqu'on clique sur entrer en Ã©tant sur une des actions possibles
                        case EPEE:
                            //On inflige des dégâts au monstre
                            //Actualise ses pts de vie
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->pvCour -=monde->joueur->combattant->attaque;
                            monde->num_menu_comb = MENU1;
                            monde->option = ATTAQUE;
                            //Finit le combat si pv du monstre <= 0
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->pvCour <= 0){
                                monde->etat_jeu = ETAT_JEU_PRINCIPAL;//On retourne sur la carte du monde si le monstre est mort
                                //monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
                                monde->joueur->or += 30;
                                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat = MORT;
                            }
                            indice_deg++;//On indique que le joueur a attaqué
                            break;
                        case SORT:
                            //On inflige des dégâts au monstre
                            //Actualise ses pts de vie
                            monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->pvCour -=monde->joueur->combattant->attaque;
                            //On réduit de 5 ses points de mana
                            monde->joueur->manaCour -= 5;
                            monde->num_menu_comb = MENU1;
                            monde->option = ATTAQUE;
                            //Finit le combat si pv du monstre <= 0
                            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->pvCour <= 0){
                                monde->etat_jeu = ETAT_JEU_PRINCIPAL;//On retourne sur la carte du monde si le monstre est mort
                                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
                                monde->joueur->or += 30;
                            }
                            indice_deg++;
                            break;
                        case OBJETS:
                            //Si on choisit d'utiliser un objet, on ouvre un troisième menu avec la possibilité d'utiliser une potion de pv ou une potion de mana
                            monde->num_menu_comb = MENU3;
                            monde->option = RETOUR;
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
        else if(monde->num_menu_comb == MENU3){
          if(event->type == SDL_KEYDOWN){
              if(keystates[SDL_SCANCODE_LEFT]){
                  switch(monde->option){
                      //On décale le curseur vers la case à gauche
                      case RIEN:
                          monde->option = RETOUR;
                          break;
                      case CHOIX_POTION_PV:
                          if(monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj > 0){
                            monde->option = CHOIX_POTION_MANA;
                          }
                          break;
                      case CHOIX_POTION_MANA:
                          if(monde->joueur->inventaire[INDICE_POTION_PV].nb_obj > 0){
                            monde->option = CHOIX_POTION_PV;
                          }
                          break;
                  }
              }
            if(keystates[SDL_SCANCODE_RIGHT]){
              switch(monde->option){
                //On décale le curseur vers la case à droite
                case RIEN:
                    monde->option = RETOUR;
                    break;
                case CHOIX_POTION_PV:
                    if(monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj > 0){
                      monde->option = CHOIX_POTION_MANA;
                    }
                    break;
                case CHOIX_POTION_MANA:
                    if(monde->joueur->inventaire[INDICE_POTION_PV].nb_obj > 0){
                      monde->option = CHOIX_POTION_PV;
                    }
                    break;
              }
            }
            if(keystates[SDL_SCANCODE_UP]){
              switch(monde->option){
                case RIEN:
                  monde->option = RETOUR;
                  break;
                case CHOIX_POTION_PV:
                  monde->option = RETOUR;
                  break;
                case CHOIX_POTION_MANA:
                  monde->option = RETOUR;
                  break;
                case RETOUR:
                  //On vérifie qu'on a des potions avant de sélectionner l'option
                  if(monde->joueur->inventaire[INDICE_POTION_PV].nb_obj > 0){
                    monde->option = CHOIX_POTION_PV;
                  }
                  else if(monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj > 0){
                    monde->option = CHOIX_POTION_MANA;
                  }
                  break;
              }
            }
            if(keystates[SDL_SCANCODE_DOWN]){
              switch(monde->option){
                case RIEN:
                  monde->option = RETOUR;
                  break;
                case CHOIX_POTION_PV:
                  monde->option = RETOUR;
                  break;
                case CHOIX_POTION_MANA:
                  monde->option = RETOUR;
                  break;
                case RETOUR:
                  //On vérifie qu'on a des potions avant de sélectionner l'option
                  if(monde->joueur->inventaire[INDICE_POTION_PV].nb_obj > 0){
                    monde->option = CHOIX_POTION_PV;
                  }
                  else if(monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj > 0){
                    monde->option = CHOIX_POTION_MANA;
                  }
                  break;
              }
            }
            if(keystates[SDL_SCANCODE_RETURN]){
              switch(monde->option){
                case RETOUR:
                  monde->num_menu_comb = MENU2;
                  break;
                case CHOIX_POTION_PV:
                  if(monde->joueur->combattant->pvCour < monde->joueur->combattant->pvMax){
                    consommer_potion(monde->joueur, INDICE_POTION_PV);
                    monde->num_menu_comb = MENU1;
                    monde->num_menu_comb = OBJETS;
                    indice_deg++;
                  }
                  break;
                case CHOIX_POTION_MANA:
                  if(monde->joueur->manaCour < monde->joueur->manaMax){
                    consommer_potion(monde->joueur, INDICE_POTION_MANA);
                    monde->num_menu_comb = MENU1;
                    monde->option = OBJETS;
                    indice_deg++;
                  }
                  break;
              }
            }
        }
    }
    if(!joueur_etait_vivant){
        while(event->type != SDL_KEYDOWN){
            printf("Boucle\n");
        }
        printf("Sortie de boucle\n");
        monde->num_menu_comb = MENU1;
        monde->etat_jeu = ETAT_JEU_PRINCIPAL;
        reinitialiser_joueur(monde->joueur, monde->biblio_objet);
	    if(monde->partie == 1){
            init_monde_jeu(monde, "./rsrc/txt/partie1.txt");
            printf("initialise bien à partir du fichier texte\n");
        }
        else{
            init_monde_jeu(monde, "./rsrc/txt/partie2.txt");
        }
    }
    //Le monstre attaque si le joueur a attaqué

    else if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat == VIVANT && monde->etat_jeu != ETAT_JEU_PRINCIPAL && indice_deg == 1){
		    //Le monstre inflige des dégâts basiquement au joueur
		    monde->joueur->combattant->pvCour -= monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant->attaque;

		    if( monde->joueur->combattant->pvCour <= 0 && joueur_etait_vivant == 1){
          printf("Joueur mort\n");
			    //S'il tue le joueur on affiche game over
			    //apply_texture(textures->game_over, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
		      //Il doit cliquer sur une touche en dehors de escape afin de le passer
		    }
	  }
    //On réinitialise la valeur de menu sur celle du premier pour le ré-afficher par la suite
    if(monde->num_menu_comb != MENU2 && monde->num_menu_comb != MENU3){
        monde->num_menu_comb = MENU1;
    }
  }
  //printf("Fin d'evenements combats : %d\n", monde->num_menu_comb);
}
