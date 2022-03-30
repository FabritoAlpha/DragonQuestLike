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



void combat(joueur_t * joueur, monstre_t * monstre, images_t * textures, SDL_Renderer * renderer, SDL_Event * event, monde_t * monde, TTF_Font* police){

	//char nom_monstre[10];
  char opt[10];
  const Uint8* keystates = SDL_GetKeyboardState(NULL);

  //Les 2 apply textures servent à afficher le monstre et le joueur

	apply_texture(textures->joueur,renderer, 1*SCREEN_WIDTH/8, 1*SCREEN_HEIGHT/8);
	//apply_texture la bonne image de monstre -->
	//récupéation de l'information via la zone et la salle du joueur
	switch(monde->joueur->zone){
		case 0:
      //Renommer monstre_zone0
      printf("Le monstre s'affiche\n");
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

	//Après avoir fait l'affichage de l'arène du joueur et du monstre engagé dans le combat on affiche les pts de vie du monstre en haut et les pts de vie du joueur en bas

	char pv_j[3];
	char pv_m[3];
  char mana_j[3];

	int num_menu_cour = MENU1;

	int option_menu_1 = RIEN;
	int option_menu_2 = RIEN;

	sprintf(pv_j, "%d", (monde->joueur->combattant->pvCour));
	sprintf(pv_m, "%d", (monstre->combattant->pvCour));
  sprintf(mana_j, "%d", (monde->joueur->manaCour));

  //Il faut afficher la barre de point de vie du joueur et du monstre ainsi que la barre de mana du joueur

  //Trois apply_texture à faire
  //->un pour chaque barre

  //sprintf(opt, pv_j);
  apply_text(renderer, 0, 255, 0, pv_j, police, 1*SCREEN_WIDTH/8, 2*SCREEN_HEIGHT/8,(2*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  //sprintf(opt, pv_m);
  apply_text(renderer, 0, 255, 0, pv_m, police, 7*SCREEN_WIDTH/8, 2*SCREEN_HEIGHT/8,(2*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  //sprintf(opt, mana_j);
  apply_text(renderer, 0, 255, 0, mana_j, police, 1*SCREEN_WIDTH/8, 3*SCREEN_HEIGHT/8,(2*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));


	//Mettre une condition sur le numéro du menu


	//IF NUM_MENU_COUR == MENU1
  if(num_menu_cour == 1){
  	//On doit afficher les cases nécessaires pour l'attaque et la fuite

  	//Après les pv du j et du m on affiche un menu avec les options du joueur: attaque ou fuite


    //Il faut apv_policeint de vie du joueur et du monstre ainsi que la barre de mana du joueur

    //switch(option_menupv_mwitch(option_mepolicech(option_menu_1mana_j/J'ai besoin d'une case avec attaque à  l'intérieur et une case avec fuite à  l'intérieur

  	//--> ça c'est à  mettre avant le choix du menu
  	//case pour le choix policey_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);
  	//case pour le choix fuite
  	apply_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 6*SCREEN_HEIGHT/8);
    apply_texture(textures->case_combat, renderer, 5*SCREEN_WIDTH/8, 6*SCREEN_HEIGHT/8);

  	//Peut-ÃƒÂªtre mettre un if(police != 0) Ãƒ  voir

  	sprintf(opt, "Attaque");
  	apply_text(renderer, 0, 255, 0, opt, police, 3*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));

  	sprintf(opt, "Fuite");
  	apply_text(renderer, 0, 255, 0, opt, police, 6*SCREEN_WIDTH/8, 8*SCREEN_HEIGHT/10,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/16));

  	//On doit dorÃƒÂ©navant permettre la saisie du coup

  	if(event->type == SDL_KEYDOWN){
  		if(keystates[SDL_SCANCODE_LEFT]){
  			switch(option_menu_1){
  				//On dÃ©cale le curseur vers la case Ã  gauche
  				case RIEN:
  					option_menu_1 = ATTAQUE;
  					break;
  				case ATTAQUE:
  					option_menu_1 = FUITE;
  					break;
  				case FUITE:
  					option_menu_1 = ATTAQUE;
  					break;
  			}
  		}
  		if(keystates[SDL_SCANCODE_RIGHT]){
  			switch(option_menu_1){
  				//On dÃ©cale le curseur vers la case Ã  droite
  				case RIEN:
  					option_menu_1 = FUITE;
  					break;
  				case ATTAQUE:
  					option_menu_1 = FUITE;
  					break;
  				case FUITE:
  					option_menu_1 = ATTAQUE;
  					break;
  			}
  		}
  		if(keystates[SDL_SCANCODE_RETURN] && option_menu_1 != RIEN){
  			switch(option_menu_1){
  				case ATTAQUE:
  					//On change le numÃƒÂ©ro menu courrant pour afficher celui des attaques dispos
  					num_menu_cour = MENU2;
  					break;
  				case FUITE:
  					//On quitte le combat
  					//On modifie l'ÃƒÂ©tat du jeu afin de retourner Ãƒ  la carte principale
  					monde->etat_jeu = 1;
  					break;

  			}
  		}
  	}
  }
	//Il faut vérifier qu'on a bien choisi d'afficher le menu2 et pas de fuire
	//IF NUM_MENU_COUR == MENU2
  if(num_menu_cour == MENU2){
  	//On doit afficher les cases nÃƒÂ©cessaires pour l'epee, le sort et le tir Ãƒ  l'arc


  	//J'ai besoin d'une case avec epee Ãƒ  l'intÃƒÂ©rieur, une case avec sort Ãƒ  l'intÃƒÂ©rieur, une case avec arc Ãƒ  l'intÃƒÂ©rieur et une case Retour

  	//--> ÃƒÂ§a c'est Ãƒ  mettre avant le choix du menu
  	//case pour le choix coup d'Ã©pÃ©Ã©
  	apply_texture(textures->case_combat, renderer, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);
  	//case pour le choix sort
  	apply_texture(textures->case_combat, renderer, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);
  	//case pour le choix tir Ã  l'arc
  	apply_texture(textures->case_combat, renderer, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);
  	//case pour le choix retour
  	apply_texture(textures->case_combat, renderer, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8);

  	//Peut-être mettre un if(police != 0) à  voir

  	//Affichage du "Epee"
  	sprintf(opt, "Epee");
  	apply_text(renderer, 0, 255, 0, opt, police, 1*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  	//Affichage du "Sort"
  	sprintf(opt, "Sort");
  	apply_text(renderer, 0, 255, 0, opt, police, 3*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  	//Affichage du "Arc"
  	sprintf(opt, "Arc");
  	apply_text(renderer, 0, 255, 0, opt, police, 5*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  	//Affichage du "Retour"
  	sprintf(opt, "Retour");
  	apply_text(renderer, 0, 255, 0, opt, police, 7*SCREEN_WIDTH/8, 7*SCREEN_HEIGHT/8,(1*SCREEN_WIDTH/8),(SCREEN_HEIGHT/10));

  	//On doit dorénavant permettre la saisie du coup

  	if(event->type == SDL_KEYDOWN){
  		if(keystates[SDL_SCANCODE_LEFT]){
  			switch(option_menu_2){
  				//On dÃ©cale le curseur vers la case Ã  gauche
  				case RIEN:
  					option_menu_2 = EPEE;
  					break;
  				case EPEE:
  					option_menu_2 = RETOUR;
  					break;
  				case SORT:
  					option_menu_2 = EPEE;
  					break;
  				case ARC:
  					//Si on a assez de mana on va sur la case sort sinon on va sur la case epee
  					if(joueur->manaCour >=5){
  						option_menu_2 = SORT;
  					}
  					else{
  						option_menu_2 = EPEE;
  					}
  					break;
  				case RETOUR:
  					option_menu_2 = ARC;
  					break;
  			}
  		}
  		if(keystates[SDL_SCANCODE_RIGHT]){
  			switch(option_menu_2){
  				//On décale le curseur vers la case Ã  droite
  				case RIEN:
  					option_menu_2 = RETOUR;
  					break;
  				case EPEE:
  					//Si on a assez de manas on va sur sort sinon on va sur arc car on ne peut pas utiliser le sort
  					if(joueur->manaCour >=5){
  						option_menu_2 = SORT;
  					}
  					else{
  						option_menu_2 = ARC;
  					}
  					break;
  				case SORT:
  					option_menu_2 = ARC;
  					break;
  				case ARC:
  					option_menu_2 = RETOUR;
  					break;
  				case RETOUR:
  					option_menu_2 = EPEE;
  					break;
  			}
  		}
  		if(keystates[SDL_SCANCODE_RETURN] && option_menu_2 != RIEN){
  			switch(option_menu_2){
  				//Action lorsqu'on clique sur entrer en Ã©tant sur une des actions possibles
  				case EPEE:
  					//On inflige des dégâts au monstre
  					//Actualise ses pts de vie
  					monstre->combattant->pvCour -= joueur->combattant->attaque;
  					//Finit le combat si pv du monstre <= 0
  					if(monstre->combattant->pvCour <= 0){
  						monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
  						monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
              joueur->or += 30;
            }
  					break;
  				case SORT:
  					//On inflige des dégâts au monstre
  					//Actualise ses pts de vie
  					monstre->combattant->pvCour -= joueur->combattant->attaque;
  					//
  					//Finit le combat si pv du monstre <= 0
  					if(monstre->combattant->pvCour <= 0){
  						monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
  						monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
              joueur->or += 30;
            }
  					break;
  				case ARC:
  					//On inflige des dÃ©gÃ¢ts au monstre
  					//Actualise ses pts de vie
  					monstre->combattant->pvCour -= joueur->combattant->attaque;
  					//Finit le combat si pv du monstre <= 0
  					if(monstre->combattant->pvCour <= 0){
  						monde->etat_jeu = 1;//On retourne sur la carte du monde si le monstre est mort
  						monstre->etat = MORT;//On indique que le monstre est mort -->utile pour l'affichage et les collisions
              joueur->or += 30;
            }
  					break;
  				case RETOUR:
  					//Si on appuie sur "Retour" on affiche de nouveau le menu1
  					option_menu_2 = MENU1;
  					break;
  			}
  		}
  	}
  }
	//Après avoir saisi le coup du joueur c'est au monstre de jouer
	//Il faut vÃ©rifier que le monstre est vivant et qu'on n'a pas choisi soit : - de fuir, soit d'afficher le menu 1

	if(monstre->etat == VIVANT && num_menu_cour != MENU1 && monde->etat_jeu != 1){
		//Le monstre inflige des dégâts basiquement au joueur
		joueur->combattant->pvCour -= monstre->combattant->attaque;

		if( joueur->combattant->pvCour <= 0){
			//S'il tue le joueur on affiche game over
			apply_texture(textures->game_over, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
			//Il doit cliquer sur une touche en dehors de escape afin de le passer
			while(!(event->type == SDL_KEYDOWN) || keystates[SDL_SCANCODE_ESCAPE]){
			}
			//On recharge au dÃ©but de la zone
			//pv au max, mana au max, retour Ã  la premiÃ¨re salle de la zone
			joueur->combattant->pvCour = joueur->combattant->pvMax;
			joueur->manaCour = joueur->manaMax;
			joueur->salle = 0;

			//On réinitialise la zone
			init_zone(monde->zones[joueur->zone], joueur->zone);

			//On divise son or par 2
			//Retour à  la carte du monde
			monde->etat_jeu = 1;
		}
	}

}

void changement_salle(joueur_t * j, int changement_salle){
	j->salle = (j->salle) + changement_salle;

	switch(j->salle){
		case 0:
      //Si le personnage revient à gauche, on le met tout à droite de la salle sans changer sa hauteur
			j->combattant->x = SCREEN_WIDTH - j->combattant->vitesse - LARGEUR_PERSONNAGE;
			break;
		case 1:
      //S'il arrive de la gauche, on ne change pas sa hauteur et on le met tout à gauche
			if(changement_salle == 1){
        j->combattant->x = j->combattant->vitesse;
      }
      else{
        j->combattant->y = SCREEN_HEIGHT - 100 - j->combattant->vitesse;
      }
      break;
		case 2:
      //S'il arrive d'en haut on le met tout en haut sans changer son placement latéral
			if(changement_salle == 1){
        j->combattant->y = 100 + j->combattant->vitesse;
      }
      else{
        j->combattant->x = j->combattant->vitesse;
      }
      break;
		case 3:
      //S'il va vers la gauche même cas que pour le cas 0
			j->combattant->x = SCREEN_WIDTH - j->combattant->vitesse - LARGEUR_PERSONNAGE;
			break;
	}
}

void changement_zone(monde_t * monde){
	(monde->joueur->zone)++;
	monde->joueur->salle = 0;

	monde->joueur->combattant->x = (SCREEN_WIDTH/2) - (LARGEUR_PERSONNAGE/2);
	monde->joueur->combattant->y = 100 + 10;

  sauvegarde(monde);
}

int collision_combattant_ecran(combattant_t * combattant, monde_t * monde){

    if(combattant->type == JOUEUR){

        switch(monde->joueur->salle){
          case 0:
            if(combattant->x + LARGEUR_PERSONNAGE >= SCREEN_WIDTH){
              changement_salle(monde->joueur, +1);
    		      return(PAS_COLLISION);
            }
            break;
          case 1:
            if(combattant->x <= 0){
              changement_salle(monde->joueur, -1);
    		      return(PAS_COLLISION);
    	      }

    	      if((combattant->x >= ENTREE_GAUCHE_ZONE_SUIVANTE) && (combattant->x + LARGEUR_PERSONNAGE <= ENTREE_DROITE_ZONE_SUIVANTE) && (combattant->y + HAUTEUR_PERSONNAGE >= SCREEN_HEIGHT - 100)){
              changement_salle(monde->joueur, +1);
    		      return(PAS_COLLISION);
    	      }
            break;
          case 2:
            if((combattant->x >= ENTREE_GAUCHE_ZONE_SUIVANTE) && (combattant->x + LARGEUR_PERSONNAGE <= ENTREE_DROITE_ZONE_SUIVANTE) && (combattant->y <= 100.0)){
              changement_salle(monde->joueur, -1);
    		      return(PAS_COLLISION);
    	      }

    	      if(combattant->x <= 0.0){
              changement_salle(monde->joueur, +1);
    		      return(PAS_COLLISION);
            }
            break;
          case 3:
            if(combattant->x + LARGEUR_PERSONNAGE>= SCREEN_WIDTH){
              changement_salle(monde->joueur, -1);
    		      return(PAS_COLLISION);
    	      }

    	      if((combattant->x >= ENTREE_GAUCHE_ZONE_SUIVANTE) && (combattant->x + LARGEUR_PERSONNAGE <= ENTREE_DROITE_ZONE_SUIVANTE) && (combattant->y + HAUTEUR_PERSONNAGE >= SCREEN_HEIGHT - 100)){
              changement_zone(monde);
    		      return(PAS_COLLISION);
            }
            break;
        }

    }

    switch(monde->joueur->salle){
      case 0:
        if(combattant->x  < 100.0){

          return(COLLISION);
        }
        if(combattant->y < 100.0){

          return(COLLISION);
        }
        if(combattant->x + LARGEUR_PERSONNAGE  > SCREEN_WIDTH ){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
        break;
      case 1:
        if(combattant->x  < 0.0){

          return(COLLISION);
        }
        if(combattant->y < 100.0){

          return(COLLISION);
        }
        if(combattant->x + LARGEUR_PERSONNAGE  > SCREEN_WIDTH - 100.0){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
        break;
      case 2:
        if(combattant->x  < 0.0){

          return(COLLISION);
        }
        if(combattant->y < 100.0){

          return(COLLISION);
        }
        if(combattant->x + LARGEUR_PERSONNAGE  > SCREEN_WIDTH - 100){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
        break;
      case 3:
        if(combattant->x  < 100.0){

          return(COLLISION);
        }
        if(combattant->y < 100.0){

          return(COLLISION);
        }
        if(combattant->x + LARGEUR_PERSONNAGE  > SCREEN_WIDTH ){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
        break;
    }

    return(PAS_COLLISION);
}

int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre, monde_t * monde ){

    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
        monde->option = RIEN;
        return(COLLISION);
    }
    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y  >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    return(PAS_COLLISION);
}


int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj){

  if((combattant->x + LARGEUR_PERSONNAGE >= pnj->x) && (combattant->x + LARGEUR_PERSONNAGE <= pnj->x + LARGEUR_PERSONNAGE) && (combattant->y + HAUTEUR_PERSONNAGE >= pnj->y) && (combattant->y + HAUTEUR_PERSONNAGE <= pnj->y + HAUTEUR_PERSONNAGE)){

    return(COLLISION);
  }

  if((combattant->x + LARGEUR_PERSONNAGE >= pnj->x) && (combattant->x + LARGEUR_PERSONNAGE <= pnj->x + LARGEUR_PERSONNAGE) && (combattant->y  >= pnj->y) && (combattant->y <= pnj->y + HAUTEUR_PERSONNAGE) ){

    return(COLLISION);
  }

  if((combattant->x >= pnj->x) && (combattant->x <= pnj->x + LARGEUR_PERSONNAGE) && (combattant->y >= pnj->y) && (combattant->y <= pnj->y + HAUTEUR_PERSONNAGE)){

    return(COLLISION);
  }

  if( (combattant->x >= pnj->x) && (combattant->x <= pnj->x + LARGEUR_PERSONNAGE) && (combattant->y + HAUTEUR_PERSONNAGE >= pnj->y) && (combattant->y + HAUTEUR_PERSONNAGE <= pnj->y + HAUTEUR_PERSONNAGE) ){

    return(COLLISION);
  }

  return(PAS_COLLISION);
}

int collision_combattant_coffre(combattant_t * combattant, nonCombattant_t * coffre){


  if( (combattant->x + LARGEUR_PERSONNAGE >= coffre->x) && (combattant->x + LARGEUR_PERSONNAGE <= coffre->x + LARGEUR_COFFRE) && (combattant->y + HAUTEUR_PERSONNAGE >= coffre->y) && (combattant->y + HAUTEUR_PERSONNAGE <= coffre->y + HAUTEUR_COFFRE) ){

    return(COLLISION);
  }
  if( (combattant->x + LARGEUR_PERSONNAGE >= coffre->x) && (combattant->x + LARGEUR_PERSONNAGE <= coffre->x + LARGEUR_COFFRE) && (combattant->y  >= coffre->y) && (combattant->y <= coffre->y + HAUTEUR_COFFRE) ){

    return(COLLISION);
  }
  if( (combattant->x >= coffre->x) && (combattant->x <= coffre->x + LARGEUR_COFFRE) && (combattant->y >= coffre->y) && (combattant->y <= coffre->y + HAUTEUR_COFFRE) ){

    return(COLLISION);
  }
  if( (combattant->x >= coffre->x) && (combattant->x <= coffre->x + LARGEUR_COFFRE) && (combattant->y + HAUTEUR_PERSONNAGE >= coffre->y) && (combattant->y + HAUTEUR_PERSONNAGE <= coffre->y + HAUTEUR_COFFRE) ){

    return(COLLISION);
  }

  return(PAS_COLLISION);

}

int collision_combattant(combattant_t * combattant, int indice_monstre, monde_t * monde/*, int indice_salle, int indice_zone*/){
    int i;

    if(collision_combattant_ecran(combattant, monde)){
      return(COLLISION);
    }

    if(combattant->type == JOUEUR){
      for(i = 0; i < NB_MONSTRES_SALLE; i++){
        if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->etat == VIVANT){
          if(collision_joueur_monstre(combattant,monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->combattant, monde)){
            return(COLLISION);
          }
        }
      }
    }

    if(combattant->type == MONSTRE){
      for(i = 0; i < NB_MONSTRES_SALLE; i++){
        if(indice_monstre != i){
          /*if(collision_monstre(combattant, salle->monstres[i]->combattant)){
            return(COLLISION);
          }*/
        }
      }
      if(collision_joueur_monstre(monde->joueur->combattant, combattant, monde)){
        return(COLLISION);
      }
    }

    for(i = 0; i < NB_PERSO_SALLE; i++){
      if(collision_combattant_pnj(combattant,monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->perso[i])){
        return(COLLISION);
      }
    }

    if(collision_combattant_coffre(combattant, monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre)){
      return(COLLISION);
    }

    return(PAS_COLLISION);
}



int deplacement_droit(combattant_t * entitee, int indice_monstre, monde_t * monde){
    entitee->x = (entitee->x)+entitee->vitesse;
    if(collision_combattant(entitee, indice_monstre, monde)){

        a_gauche(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_gauche(combattant_t * entitee, int indice_monstre, monde_t * monde){
    entitee->x = (entitee->x)-entitee->vitesse;
    if(collision_combattant(entitee, indice_monstre, monde)){

        a_droite(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_haut(combattant_t * entitee, int indice_monstre, monde_t * monde){
    entitee->y = (entitee->y)-entitee->vitesse;
    if(collision_combattant(entitee, indice_monstre, monde)){

        en_bas(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_bas(combattant_t * entitee, int indice_monstre, monde_t * monde){
    entitee->y = (entitee->y)+entitee->vitesse;
    if(collision_combattant(entitee, indice_monstre, monde)){

        en_haut(entitee);
        return(1);
    }else{
      return(0);
    }
}
/**
	*\fn distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre)
	*\brief renvoie la distance entre deux type combattant, ici utile entre le joueur et le monstre
	*\param joueur entitée combattant représentant le joueur
  *\param monstre entitée combattant représentant le monstre
*/
int distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre){// renvoie la distance entre deux combattants.
  int distance;
  int xa=joueur->combattant->x;
  int ya=joueur->combattant->y;
  int xb=monstre->combattant->x;
  int yb=monstre->combattant->y;
  distance=sqrt(pow(xb-xa,2)+pow(yb-ya,2));
  return distance;
}
/**
	*\fn deplacement_monstre(monstre_t * monstre, monde_t * m)
	*\brief IA du monstre, le déplace dans son environnement.
	*\param m monde dans lequel le monstre se situe
  *\param monstre entitée qui est controlé
*/
void deplacement_monstre(monstre_t * monstre, monde_t * m){
  int valColision=0;
  int direction;
  int distance;
  int dist_min=10;// A METRE JEU.H
  int dist_max=50;// A METRE JEU.H
  int nb_direction=4; //A METRE JEU.H
  int distance_agro=400; //A METRE JEU.H
  if(distancejoueurmonstre(m->joueur,monstre)>distance_agro && monstre->etat==1){
    monstre->etat=0;
    monstre->dir=-1;
  }
  if(distancejoueurmonstre(m->joueur,monstre)<distance_agro && monstre->etat==0){
    monstre->etat=1;
  }
  //printf("%d",monstre->etat);
  if(monstre->etat==0){ // Etat du monde dans lequel il se déplace de manière aléatoire
    if(monstre->dir==-1){ // dir -1 = initialisation du monstre sur son emplacement
      direction=rand()%nb_direction;
      do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
      monstre->dir=direction;
      monstre->dist=distance;
      monstre->x=monstre->combattant->x;
      monstre->y=monstre->combattant->y;
    }
    if(monstre->dir==0 && (monstre->combattant->x)>(monstre->x-monstre->dist)){ // Si le monstre va à gauche
      valColision = deplacement_gauche(monstre->combattant, 0, m);
      if(valColision){
        monstre->dir=-1;
      }
      if((monstre->combattant->x)<=(monstre->x-monstre->dist)){
        do{direction=rand()%nb_direction;}while(direction==1);
        do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
        monstre->x=monstre->combattant->x;
        monstre->dir=direction;
      }
    }
    if(monstre->dir==1 && (monstre->combattant->x)<(monstre->x+monstre->dist)){ // Si le monstre va à droite
      valColision = deplacement_droit(monstre->combattant, 0, m);
      if(valColision){
        monstre->dir=-1;
      }
      if((monstre->combattant->x)>=(monstre->x+monstre->dist)){
        do{direction=rand()%nb_direction;}while(direction==0);
        do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
        monstre->x=monstre->combattant->x;
        monstre->dir=direction;

      }
    }
    if(monstre->dir==2 && (monstre->combattant->y)>(monstre->y-monstre->dist)){ // Si le monstre va en haut
      valColision = deplacement_haut(monstre->combattant, 0, m);
      if(valColision){
        monstre->dir=-1;
      }
      if((monstre->combattant->y)<=(monstre->y-monstre->dist)){
        do{direction=rand()%nb_direction;}while(direction==3);
        do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
        monstre->y=monstre->combattant->y;
        monstre->dir=direction;
      }
    }
    if(monstre->dir==3 && (monstre->combattant->y)<(monstre->y+monstre->dist)){ // Si le monstre va en bas
      valColision = deplacement_bas(monstre->combattant, 0, m);
      if(valColision){
        monstre->dir=-1;
      }
      if((monstre->combattant->y)>=(monstre->y+monstre->dist)){
        do{direction=rand()%nb_direction;}while(direction==2);
        do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
        monstre->y=monstre->combattant->y;
        monstre->dir=direction;
      }
    }
  }
  if(monstre->etat==1){// Etat du monstre dans lequel il fonce vers le joueur
    if(m->joueur->combattant->x < monstre->combattant->x){
      valColision = deplacement_gauche(monstre->combattant, 0,m);
    }
    if(m->joueur->combattant->x > monstre->combattant->x){
      valColision = deplacement_droit(monstre->combattant, 0,m);
    }
    if(m->joueur->combattant->y < monstre->combattant->y){
      valColision = deplacement_haut(monstre->combattant, 0,m);
    }
    if(m->joueur->combattant->y > monstre->combattant->y){
      valColision = deplacement_bas(monstre->combattant, 0,m);
    }
  }
}

void affichage_nonCombattants(SDL_Renderer *renderer, images_t *textures, salle_t* salle){
    if(salle->num_salle == 0)
        for(int i = 0; i < NB_PERSO_SALLE ; i++){
            nonCombattant_position(renderer, textures, salle->perso[i]);
        }
}

/**
	*\fn distance_pnj_coffre(joueur_t * joueur, nonCombattant_t * entite)
  *\brief renvoie la distance entre le joueur et un nonCombattant
  *\param joueur
  *\param entite
*/
int distance_pnj_coffre(joueur_t * joueur, nonCombattant_t * entite){
    int distance;
    int xa = joueur->combattant->x;
    int ya = joueur->combattant->y;
    int xb = entite->x;
    int yb = entite->y;
    distance = sqrt(pow(xb-xa,2)+pow(yb-ya,2));
    return distance;
}

/**
	*\fn nonCombattant_proche(monde_t * monde)
  *\brief renvoie 0 si aucun combattant est proche, 1 si un pnj est proche, 2 si un coffre est proche
  *\param monde
*/
int nonCombattant_proche(monde_t * monde){
  //pnj de la salle 0
  if(monde->joueur->salle == 0){
      //pnj
      if(distance_pnj_coffre(monde->joueur, monde->zones[monde->joueur->zone]->salles[0]->perso[0]) <= 75)
          return 1;
      //marchand
      if(distance_pnj_coffre(monde->joueur, monde->zones[monde->joueur->zone]->salles[0]->perso[1]) <= 75)
          return 2;
  }
  return 0;
}

void affichage_dialogue(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police){
    char parole[20] = "";
    // si c'est un pnj non marchand
    if(nonCombattant_proche(monde) == 1){
        sprintf(parole, "Bonjour!");
        apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 750 - 156 + (taille_fenetre[1]/2) - 350 , 175, 40);
    }
}

/**
	*\fn interaction_nonCombattant(SDL_Event* event, monde_t * monde)
  *\brief gestion des intéraction avec les nonCombattant: dialogue avec pnj, ouverture de coffre
  *\param monde
  *\param event
*/
void interaction_nonCombattant(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(event->type == SDL_KEYDOWN){
        // si c'est un pnj non marchand
        if(nonCombattant_proche(monde) == 1){
            if(keystates[SDL_SCANCODE_RETURN]){
                monde->etat_jeu = 1;
            }
        }

        // si c'est un marchand
    }
}

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 * \param next_tick correspond au prochain tick du jeu
 * \param next_tick_monstre correspond au prochain tick dans lequel le monstre va effectuer une action
 */
void rafraichir(SDL_Event * event, SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * next_tick,int *next_tick_monstre, TTF_Font* police){
    //printf("On rentre dans rafraichir\n");
    int time_sec=(SDL_GetTicks()/20);

    //on vide le renderer
    SDL_RenderClear(renderer);


    if(monde->etat_jeu == 0 || monde->etat_jeu == 4){

      fond(renderer, textures, monde);

      affichage_menu(renderer, monde, police);

    }
    else{
      //printf("Test affichage fond\n");
      fond(renderer, textures, monde);
    }
    if(monde->etat_jeu == 3){
      affichage_inventaire(renderer, monde, textures, police);
    }
    if(monde->etat_jeu == ETAT_COMBAT){
      affichage_combat(renderer, monde, textures, police);
    }

    if(monde->etat_jeu == ETAT_DIALOGUE){
        interaction_nonCombattant(event, monde);
        dialogue_position(renderer, textures);
        affichage_dialogue(renderer, monde, police);
    }

    if(monde->etat_jeu == 1){

      joueur_position(renderer, textures, monde->joueur);

      affichage_nonCombattants(renderer,textures,monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]);

      for(int i = 0; i < NB_MONSTRES_SALLE ; i++){
        int suivaleatoir;
        if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->etat == VIVANT){
          monstre_position(renderer, textures, monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]);
          if(time_sec>(*next_tick_monstre)){
            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->combattant->vitesse==1){
              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->combattant->vitesse=0;
            }else{
              monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i]->combattant->vitesse=1;
            }
            do{
              suivaleatoir=rand()%500;
            }while(suivaleatoir<200||suivaleatoir>500);
            (*next_tick_monstre)+=suivaleatoir;
          }

          if(time_sec>(*next_tick)){

            deplacement_monstre(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[i], monde);
          }
        }
      }

    }

    //On actualise l'affichage
    (*next_tick)+=1;
    SDL_RenderPresent(renderer);

}

// NOTE: SAUVEGARDER A CHAQUE CHANGEMENT DE ZONE PUIS REINITIALISER LE MONDE A PARTIR DU FICHIER SAUVEGARDE PREALABLEMENT SI MORT DU JOUEUR
void sauvegarde(monde_t* monde){
    FILE * fichier;
    int i;
    int nb_obj_inv = monde->joueur->nb_obj_inventaire;
    int nb_obj_equip = monde->joueur->nb_obj_equip;
    //Pour sauvegarder correctement la partie:
    /*
    -niveau du joueur --> nécessaires
    -zone du joueur --> nécessaires
    -pvMax, pvCour du joueur -->nécessaires
    -manaMax, manaCour du joueur -->nécessaires
    -Or du joueur --> nécessaires
    -Les objets possédés voire ceux équipés --> nécessaires
      -->Faire comment: premier nb le nombre d'item, les nombres suivants: les id respectifs de chaque item
    -L'etat des monstres --> pas besoin puisqu'on charge tout le temps au début de la zone donc tous les monstres sont vivants à cet instant
    */
    if(monde->partie == 1){
        fichier = fopen("./rsrc/txt/partie1.txt","w");
        //Sauvegarde du niveau et de la zone locale
        fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->niveau, monde->joueur->zone);
        //Sauvegarde des pv max et courrants
        fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->pvMax, monde->joueur->combattant->pvCour);
        //Sauvegarde du mana max et courrant
        fprintf(fichier, "%d\n%d\n", monde->joueur->manaMax, monde->joueur->manaCour);
        //Sauvegarde de l'or
        fprintf(fichier, "%d\n", monde->joueur->or);
        //Sauvegarde de l'attaque
        fprintf(fichier, "%d\n", monde->joueur->combattant->attaque);
        //Sauvegarde des objets présents dans l'inventaire
        fprintf(fichier, "%d\n", nb_obj_inv);
        for(i = 0; i < nb_obj_inv; i++){
          fprintf(fichier, "%d\n", monde->joueur->inventaire[i].id);
        }
        //Sauvegarde des objets équipés
        fprintf(fichier, "%d\n", nb_obj_equip);
        for(i = 0; i < nb_obj_equip; i++){
          fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
        }
        //On ferme le fichier
        fclose(fichier);
    }
    if(monde->partie == 2){
      fichier = fopen("./rsrc/txt/partie1.txt","w");
      //Sauvegarde du niveau et de la zone locale
      fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->niveau, monde->joueur->zone);
      //Sauvegarde des pv max et courrants
      fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->pvMax, monde->joueur->combattant->pvCour);
      //Sauvegarde du mana max et courrant
      fprintf(fichier, "%d\n%d\n", monde->joueur->manaMax, monde->joueur->manaCour);
      //Sauvegarde de l'or
      fprintf(fichier, "%d\n", monde->joueur->or);
      //Sauvegarde des objets présents dans l'inventaire
      fprintf(fichier, "%d\n", nb_obj_inv);
      for(i = 0; i < nb_obj_inv; i++){
        fprintf(fichier, "%d\n", monde->joueur->inventaire[i].id);
        free(monde->joueur->inventaire[i].nom);
        monde->joueur->inventaire[i].nom=NULL;
        free(monde->joueur->inventaire[i].description);
        monde->joueur->inventaire[i].description=NULL;
      }
      //Sauvegarde des objets équipés
      fprintf(fichier, "%d\n", nb_obj_equip);
      for(i = 0; i < nb_obj_equip; i++){
        fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
        free(monde->joueur->inventaire[i].nom);
        monde->joueur->inventaire[i].nom=NULL;
        free(monde->joueur->inventaire[i].description);
        monde->joueur->inventaire[i].description=NULL;
      }
      //On ferme le fichier
      fclose(fichier);
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
        if(event->type != SDL_KEYDOWN)
           continue;

        if(monde->etat_jeu == 0){
            evenements_menu(event, monde);
        }
        if(monde->etat_jeu == 4){
            choix_partie(event,monde);
            printf("menu partie\n");
        }
        /*!< Jeu en cours */
        if(monde->etat_jeu == 1){
            //on entre dans un dialogue
            if((nonCombattant_proche(monde) == 1  ||  nonCombattant_proche(monde) == 2) && event->key.keysym.sym == SDLK_p){
                monde->etat_jeu = ETAT_DIALOGUE;
                printf("DIALOGUE");
            }
            if(event->key.keysym.sym == SDLK_LEFT) {
                deplacement_gauche(monde->joueur->combattant, 0, monde);
            }
            if(event->key.keysym.sym == SDLK_RIGHT){
                deplacement_droit(monde->joueur->combattant, 0, monde);
            }
            if(event->key.keysym.sym == SDLK_UP){
                deplacement_haut(monde->joueur->combattant, 0, monde);
            }
            if(event->key.keysym.sym == SDLK_DOWN){
                deplacement_bas(monde->joueur->combattant, 0, monde);
            }
            if(event->key.keysym.sym == SDLK_i){// Si en jeu il ouvre l'inventaire
                monde->etat_jeu=3;
                event->key.keysym.sym =0;

            }
        }
        // Si dans l'inventaire le joueur le ferme.
        if(monde->etat_jeu==3){// si dans inventaire
          evenements_inventaire(event, monde);
          if(event->key.keysym.sym == SDLK_i){
            monde->etat_jeu=1;
          }
        }
        if(monde->etat_jeu == ETAT_COMBAT){
          evenements_combat(event, monde);
        }

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            sauvegarde(monde);
            //On indique la fin du jeu
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
        if(keystates[SDL_SCANCODE_ESCAPE] ){
            sauvegarde(monde);
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
    }

    SDL_PumpEvents();
}
