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
  //pnj de la salle 2
  if(monde->joueur->salle == 2){
      //marchand
      if(distance_pnj_coffre(monde->joueur, monde->zones[monde->joueur->zone]->salles[2]->perso[0]) <= 75)
          return 2;
  }
  if(distance_pnj_coffre(monde->joueur, monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre) <= 75)
      return 3;
  return 0;
}

void affichage_dialogue(SDL_Renderer *renderer, images_t *textures, monde_t * monde, TTF_Font * police){
    char parole[150] = "";
    // si c'est un pnj non marchand
    if(nonCombattant_proche(monde) == 1){
        if(monde->joueur->zone == 0){
          sprintf(parole, "Bonjour!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 594 + (taille_fenetre[1]/2) - 350 , 90, 20);
          sprintf(parole, "Comment allez-vous?");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 634 + (taille_fenetre[1]/2) - 350 , 180, 20);
          sprintf(parole, "Moi je vais bien.");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 674 + (taille_fenetre[1]/2) - 350 , 125, 20);
        }
        if(monde->joueur->zone == 1){
          sprintf(parole, "Bonjour!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 750 - 156 + (taille_fenetre[1]/2) - 350 , 90, 20);
        }
        if(monde->joueur->zone == 2){
          sprintf(parole, "Bonjour!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 750 - 156 + (taille_fenetre[1]/2) - 350 , 90, 20);
        }
    }
    // si c'est un marchand
    if(nonCombattant_proche(monde) == 2){

        //afficher l'or en possession du joueur
        sprintf(parole, "%d", monde->joueur->or);
        apply_text(renderer, 0, 0, 0, parole , police, 800 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350 , 75, 60);
        or_position(renderer, textures, 865 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350);

        sprintf(parole, "Bonjour! Que voulez-vous acheter?");
        apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 750 - 156 + (taille_fenetre[1]/2) - 350 , 270, 20);

        //icones objet
        if(monde->joueur->zone == 2){
          icone_boutique_position(renderer, textures, 440 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 5);
          icone_boutique_position(renderer, textures, 630 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 6);
        } else{
          icone_boutique_position(renderer, textures, 440 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 3);
          icone_boutique_position(renderer, textures, 630 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 4);
        }
        icone_boutique_position(renderer, textures, 60 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 1);
        icone_boutique_position(renderer, textures, 250 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 2);


        //nom des objets
        if(monde->joueur->zone == 2){
          sprintf(parole, "epee en diamant");
          apply_text(renderer, 0, 0, 0, parole , police, 480 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 110, 20);
          sprintf(parole, "bouclier en diamant");
          apply_text(renderer, 0, 0, 0, parole , police, 670 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 140, 20);
        }else{
          sprintf(parole, "epee en pierre");
          apply_text(renderer, 0, 0, 0, parole , police, 480 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 110, 20);
          sprintf(parole, "bouclier en pierre");
          apply_text(renderer, 0, 0, 0, parole , police, 670 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 140, 20);
        }
        sprintf(parole, "potion de vie");
        apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 100, 20);
        sprintf(parole, "potion de mana");
        apply_text(renderer, 0, 0, 0, parole , police, 290 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 120, 20);

        //prix
        if(monde->joueur->zone == 2){
          sprintf(parole, "200");
          apply_text(renderer, 0, 0, 0, parole , police, 480 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 27, 20);
          apply_text(renderer, 0, 0, 0, parole , police, 670 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 27, 20);
        }else{
          sprintf(parole, "100");
          apply_text(renderer, 0, 0, 0, parole , police, 480 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 27, 20);
          apply_text(renderer, 0, 0, 0, parole , police, 670 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 27, 20);
        }
        sprintf(parole, "20");
        apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 18, 20);
        apply_text(renderer, 0, 0, 0, parole , police, 290 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 18, 20);


        //icone or
        icone_boutique_position(renderer, textures, 105 + (taille_fenetre[0]/2) - 500, 642 + (taille_fenetre[1]/2) - 350 , 7);
        icone_boutique_position(renderer, textures, 295 + (taille_fenetre[0]/2) - 500, 642 + (taille_fenetre[1]/2) - 350 , 7);
        icone_boutique_position(renderer, textures, 493 + (taille_fenetre[0]/2) - 500, 642 + (taille_fenetre[1]/2) - 350 , 7);
        icone_boutique_position(renderer, textures, 683 + (taille_fenetre[0]/2) - 500, 642 + (taille_fenetre[1]/2) - 350 , 7);

        //Annuler
        sprintf(parole, "Rien,");
        apply_text(renderer, 0, 0, 0, parole , police, 880 + (taille_fenetre[0]/2) - 500, 630 + (taille_fenetre[1]/2) - 350 , 36, 20);
        sprintf(parole, "merci!");
        apply_text(renderer, 0, 0, 0, parole , police, 875 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350 , 45, 20);

        //affichage sélection d'option
        sprintf(parole, "X");
        if(monde->option == 1)
            apply_text(renderer, 0, 0, 0, parole , police, 140 + (taille_fenetre[0]/2) - 500, 680 + (taille_fenetre[1]/2) - 350 , 9, 20);
        if(monde->option == 2)
            apply_text(renderer, 0, 0, 0, parole , police, 330 + (taille_fenetre[0]/2) - 500, 680 + (taille_fenetre[1]/2) - 350 , 9, 20);
        if(monde->option == 3)
            apply_text(renderer, 0, 0, 0, parole , police, 520 + (taille_fenetre[0]/2) - 500, 680 + (taille_fenetre[1]/2) - 350 , 9, 20);
        if(monde->option == 4)
            apply_text(renderer, 0, 0, 0, parole , police, 710 + (taille_fenetre[0]/2) - 500, 680 + (taille_fenetre[1]/2) - 350 , 9, 20);
        if(monde->option == 5)
            apply_text(renderer, 0, 0, 0, parole , police, 900 + (taille_fenetre[0]/2) - 500, 680 + (taille_fenetre[1]/2) - 350 , 9, 20);


    }
    if(nonCombattant_proche(monde) == 3){
        sprintf(parole, "Recompense");
        apply_text(renderer, 0, 0, 0, parole , police, (taille_fenetre[0]/2) - 325, (taille_fenetre[1]/2) - 100 , 650, 80);
        sprintf(parole, "500");
        apply_text(renderer, 0, 0, 0, parole , police, (taille_fenetre[0]/2) - 300, (taille_fenetre[1]/2) , 200, 60);
        or_position(renderer, textures, (taille_fenetre[0]/2) - 100, (taille_fenetre[1]/2) + 30);
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
                monde->etat_jeu = 1;
            }

        }
        // si c'est un coffre
        if(nonCombattant_proche(monde) == 3){
            if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite == 0){
                monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->coffre->visite = 1;
                monde->joueur->or = monde->joueur->or + 500;
            }
            if(keystates[SDL_SCANCODE_RETURN]){
                monde->etat_jeu = 1;
            }
        }
    }
}

void affichage_aide(SDL_Renderer *renderer, TTF_Font * police){
    char aide[150] = "";
    //largeur: 20 par caractère
    sprintf(aide, "ENTREE - Quitter le menu d'aide");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 85 + (taille_fenetre[1]/2) - 350 , 620, 50);
    sprintf(aide, "M - Retour au menu principal");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 155 + (taille_fenetre[1]/2) - 350 , 560, 50);
    sprintf(aide, "FLECHES - Naviguer");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 225 + (taille_fenetre[1]/2) - 350 , 360, 50);
    sprintf(aide, "ENTREE - Valider l'option");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 295 + (taille_fenetre[1]/2) - 350 , 500, 50);
    sprintf(aide, "O - Ouvrir le coffre");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 365 + (taille_fenetre[1]/2) - 350 , 400, 50);
    sprintf(aide, "I - Ouvrir ou fermer l'inventaire");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 435 + (taille_fenetre[1]/2) - 350 , 660, 50);
    sprintf(aide, "C - Afficher la carte");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350 , 420, 50);
    sprintf(aide, "P - Parler");
    apply_text(renderer, 0, 0, 0, aide , police, 150 + (taille_fenetre[0]/2) - 500, 575 + (taille_fenetre[1]/2) - 350 , 200, 50);

}

void revenir_au_jeu(SDL_Event* event, monde_t * monde){
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    //on quitte l'affichage des cmmandes
    if(event->type == SDL_KEYDOWN){
        if(keystates[SDL_SCANCODE_RETURN]){
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


  if( (coffre->x + LARGEUR_COFFRE >= combattant->x) && (coffre->x + LARGEUR_COFFRE <= combattant->x + LARGEUR_PERSONNAGE) && (coffre->y + HAUTEUR_COFFRE >= combattant->y) && (coffre->y + HAUTEUR_COFFRE <= combattant->y + HAUTEUR_PERSONNAGE) ){

    return(COLLISION);
  }
  if( (coffre->x + LARGEUR_COFFRE >= combattant->x) && (coffre->x + LARGEUR_COFFRE <= combattant->x + LARGEUR_PERSONNAGE) && (coffre->y  >= combattant->y) && (coffre->y <= combattant->y + HAUTEUR_PERSONNAGE) ){

    return(COLLISION);
  }
  if( (coffre->x >= combattant->x) && (coffre->x <= combattant->x + LARGEUR_PERSONNAGE) && (coffre->y >= combattant->y) && (coffre->y <= combattant->y + HAUTEUR_PERSONNAGE) ){

    return(COLLISION);
  }
  if( (coffre->x >= combattant->x) && (coffre->x <= combattant->x + LARGEUR_PERSONNAGE) && (coffre->y + HAUTEUR_COFFRE >= combattant->y) && (coffre->y + HAUTEUR_COFFRE <= combattant->y + HAUTEUR_PERSONNAGE) ){

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
      if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat == VIVANT){
        if(collision_joueur_monstre(combattant,monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->combattant, monde)){
          return(COLLISION);
        }
      }
    }
    else{
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
  if(distancejoueurmonstre(m->joueur,monstre)>distance_agro && monstre->agro==1){
    monstre->agro=0;
    monstre->dir=-1;
  }
  if(distancejoueurmonstre(m->joueur,monstre)<distance_agro && monstre->agro==0){
    monstre->agro=1;
  }
  if(monstre->agro==0){ // Etat du monde dans lequel il se déplace de manière aléatoire
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
  if(monstre->agro==1){// Etat du monstre dans lequel il fonce vers le joueur
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
    if(salle->num_salle == 2)
        nonCombattant_position(renderer, textures, salle->perso[0]);
    coffre_position(renderer, textures, salle->coffre);
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
    int time_sec=(SDL_GetTicks()/10);

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
        dialogue_position(renderer, textures);
        affichage_dialogue(renderer, textures, monde, police);
    }
    if(monde->etat_jeu == ETAT_COFFRE){
        affichage_dialogue(renderer, textures, monde, police);
    }
    if(monde->etat_jeu == ETAT_AIDE){
        affichage_aide(renderer, police);
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

      affichage_nonCombattants(renderer,textures,monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]);

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
          (*next_tick)++;
          //printf("On déplace le monstre");
          //deplacement_monstre(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre, monde);
        }
        else{
          (*next_tick)-= 2;
        }

      }

    }

    //On actualise l'affichage
    //(*next_tick)+=1;
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
        fprintf(fichier, "%d\n", nb_obj_inv);
        for(i = 0; i < TAILLE_INVENTAIRE; i++){
          //Si un objet est présent à l'indice i du tableau
          if(monde->joueur->inventaire[i].id != 0){
            printf("i = %d\n", i);
            printf("id = %d\n", monde->joueur->inventaire[i].id);
            printf("desc = %s\n", monde->joueur->inventaire[i].description);
            fprintf(fichier, "%d\n", i);
            //fprintf(fichier, "%d\n", monde->joueur->inventaire[i].id);
            fprintf(fichier, "%d\n", monde->joueur->inventaire[i].nb_obj);
          }
        }
        fprintf(fichier, "%d\n", nb_obj_equip);
        printf("nb obj equip : %d\n", nb_obj_equip);
        for(i = 0; i < nb_obj_equip; i++){
          printf("i2 = %d\n", i);
          fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
          fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].nb_obj);
        }
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

        printf("nb obj inv : %d\n", nb_obj_inv);

        //Sauvegarde des objets équipés

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
        if(monde->joueur->inventaire[i].id != 0){
          printf("i = %d\n", i);
          printf("id = %d\n", monde->joueur->inventaire[i].id);
          printf("desc = %s\n", monde->joueur->inventaire[i].description);
          //fprintf(fichier, "%d\n", i);
          fprintf(fichier, "%d\n", monde->joueur->inventaire[i].id);
          fprintf(fichier, "%d\n", monde->joueur->inventaire[i].nb_obj);
        }
        //free(monde->joueur->inventaire[i].nom);
        //monde->joueur->inventaire[i].nom=NULL;
        //free(monde->joueur->inventaire[i].description);
        //monde->joueur->inventaire[i].description=NULL;
      }
      //Sauvegarde des objets équipés
      fprintf(fichier, "%d\n", nb_obj_equip);
      for(i = 0; i < nb_obj_equip; i++){
        fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
        fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].nb_obj);
        //free(monde->joueur->inventaire[i].nom);
        //monde->joueur->inventaire[i].nom=NULL;
        //free(monde->joueur->inventaire[i].description);
        //monde->joueur->inventaire[i].description=NULL;
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
            printf("On rentre dans evenements menu\n");
            evenements_menu(event, monde);
        }
        if(monde->etat_jeu == 4){
            choix_partie(event,monde);
            if(monde->partie == 1 || monde->partie == 2){
              //Après avoir choisi le fichier où sauvegarder on écrase la sauvegarde avec soit l'initialisation soit le fichier chargé qui était sauvegardé
              sauvegarde(monde);
            }
            printf("menu partie\n");
        }
        /*!< Jeu en cours */
        if(monde->etat_jeu == 1){
            //si on appuie sur A on affiches les commandes et la map
            if(event->key.keysym.sym == SDLK_a){
              monde->etat_jeu = ETAT_AIDE;
            }
            //si on appuie sur M on retour au menu principal
            if(event->key.keysym.sym == SDLK_m){
              monde->option = 1;
              monde->etat_jeu= 0;
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
        if(monde->etat_jeu == ETAT_AIDE){
          revenir_au_jeu(event, monde);
        }

        if(monde->etat_jeu == ETAT_DIALOGUE || monde->etat_jeu == ETAT_COFFRE){
          interaction_nonCombattant(event, monde);
        }

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //sauvegarde(monde);
            //On indique la fin du jeu
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
        if(keystates[SDL_SCANCODE_ESCAPE] ){
            //sauvegarde(monde);
            monde->etat_jeu = -1;
            printf("fin du jeu");
        }
    }

    SDL_PumpEvents();
}
