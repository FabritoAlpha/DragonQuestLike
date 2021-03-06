/**
* \file affichage.c
* \brief affichage des différents états du jeu
* \author Anna Beranger, Alex Choux, Arthur Fabre
* \date 03/03/2022
*/

#include  "../lib/affichage.h"

/**
	* \fn void affichage_carte(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur)
	* \brief affichage de la carte avec la position du joueur
  * \param renderer le renderer
  * \param police la police du texte affiché
  * \param textures les textures du jeu
  * \param joueur le joueur
*/
void affichage_carte(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur){
    int n_zone = joueur->zone;
    int n_salle = joueur->salle;
    int x;
    int y;

    //coordonnées du point à l'écran
    if(n_salle == 1 || n_salle == 2)
        x = joueur->combattant->x/2 + 500;
    else
        x = joueur->combattant->x/2;
    if(n_salle == 2 || n_salle == 3)
        y = joueur->combattant->y/2 + 350;
    else
        y = joueur->combattant->y/2;

    //affichage carte
    carte_position(renderer, textures, n_zone);

    joueur_position(renderer, textures, joueur, x, y);

    //affichage indication pour quitter
    char indication[100] = "ENTREE pour quitter";
    apply_text(renderer, 0, 0, 0, indication , police, 600 + (taille_fenetre[0]/2) - 500, 650 + (taille_fenetre[1]/2) - 350, 380, 50);
}

/**
	* \fn void affichage_aide(SDL_Renderer *renderer, TTF_Font * police)
	* \brief affichage du menu d'aide
  * \param renderer le renderer
  * \param police la police du texte affiché
*/
void affichage_aide(SDL_Renderer *renderer, TTF_Font * police){
    char aide[150] = "";
    //largeur: 20 par caractère
    sprintf(aide, "ENTREE - Quitter le menu d'aide");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 85 + (taille_fenetre[1]/2) - 350 , 620, 50);
    sprintf(aide, "M - Retour au menu principal");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 155 + (taille_fenetre[1]/2) - 350 , 560, 50);
    sprintf(aide, "FLECHES - Naviguer");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 225 + (taille_fenetre[1]/2) - 350 , 360, 50);
    sprintf(aide, "ENTREE - Valider l'option");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 295 + (taille_fenetre[1]/2) - 350 , 500, 50);
    sprintf(aide, "O - Ouvrir le coffre");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 365 + (taille_fenetre[1]/2) - 350 , 400, 50);
    sprintf(aide, "I - Ouvrir ou fermer l'inventaire");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 435 + (taille_fenetre[1]/2) - 350 , 660, 50);
    sprintf(aide, "C - Afficher la carte");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350 , 420, 50);
    sprintf(aide, "P - Parler");
    apply_text(renderer, 255, 255, 255, aide , police, 150 + (taille_fenetre[0]/2) - 500, 575 + (taille_fenetre[1]/2) - 350 , 200, 50);

}

/**
	* \fn void affichage_nonCombattants(SDL_Renderer *renderer, images_t *textures, zone_t* zone, salle_t* salle)
	* \brief affichage des personnages non joueur et des coffres
  * \param renderer le renderer
  * \param textures les textures du jeu
  * \param zone la zone affichée à l'écran
  * \param salle la salle affichée à l'écran
*/
void affichage_nonCombattants(SDL_Renderer *renderer, images_t *textures, zone_t* zone, salle_t* salle){
  int n_zone = zone->num_zone;
  int n_salle = salle->num_salle;
  switch(n_zone){
      case 0:
          switch(n_salle){
              case 0:
                  nonCombattant_position(renderer, textures, salle->perso[0], 0);
                  nonCombattant_position(renderer, textures, salle->perso[1], 4);
              break;
              case 2:
                  nonCombattant_position(renderer, textures, salle->perso[0], 3);
              break;
          }
      break;
      case 1:
          switch(n_salle){
              case 0:
                  nonCombattant_position(renderer, textures, salle->perso[0], 1);
                  nonCombattant_position(renderer, textures, salle->perso[1], 3);
              break;
              case 2:
                  nonCombattant_position(renderer, textures, salle->perso[0], 4);
              break;
          }
      break;
      case 2:
          switch(n_salle){
              case 0:
                  nonCombattant_position(renderer, textures, salle->perso[0], 2);
                  nonCombattant_position(renderer, textures, salle->perso[1], 4);
              break;
              case 2:
                  nonCombattant_position(renderer, textures, salle->perso[0], 3);
              break;
          }
      break;
  }
  if(salle->coffre->visite == 0)
    coffre_position(renderer, textures, salle->coffre, 0);
  else
    coffre_position(renderer, textures, salle->coffre, 1);
}

/**
	* \fn void interactions(SDL_Renderer *renderer, images_t *textures, monde_t * monde, TTF_Font * police)
	* \brief affichage d'une conversation ou de l'ouverture d'un coffre
  * \param renderer le renderer
  * \param textures les textures du jeu
  * \param monde le monde du jeu
  * \param police la police du texte affiché
*/
void interactions(SDL_Renderer *renderer, images_t *textures, monde_t * monde, TTF_Font * police){
    char parole[150] = "";

    //affichage des personnages et du fond des dialogues
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
                    // si c'est un marchand
                    if(nonCombattant_proche(monde) == 2)
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
                    // si c'est un marchand
                    if(nonCombattant_proche(monde) == 2)
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
                    // si c'est un marchand
                    if(nonCombattant_proche(monde) == 2)
                        dialogue_position(renderer, textures, 3);
                break;
            }
        break;
    }

    // si c'est un pnj non marchand
    if(nonCombattant_proche(monde) == 1){
        if(monde->joueur->zone == 0){
          //10 en largeur par caractère
          sprintf(parole, "Le grand sorcier se dirige vers votre maison!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 619 + (taille_fenetre[1]/2) - 375 , 450, 20);
          sprintf(parole, "Depechez vous! Vos amis sont en danger!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 659 + (taille_fenetre[1]/2) - 375 , 390, 20);
          sprintf(parole, "Faites attention, il a laisse des monstres sur son passage...");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 699 + (taille_fenetre[1]/2) - 375 , 610, 20);
        }
        if(monde->joueur->zone == 1){
          sprintf(parole, "Faites vite! Le sorcier semblait furieux!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 619 + (taille_fenetre[1]/2) - 375 , 410, 20);
          sprintf(parole, "Il est passe par notre jardin.");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 659 + (taille_fenetre[1]/2) - 375 , 300, 20);
          sprintf(parole, "Esperons que vos amis vont bien...");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 699 + (taille_fenetre[1]/2) - 375 , 340, 20);
        }
        if(monde->joueur->zone == 2){
          sprintf(parole, "Le sorcier est dans votre maison!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 619 + (taille_fenetre[1]/2) - 375 , 330, 20);
          sprintf(parole, "Il detient vos amis!");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 659 + (taille_fenetre[1]/2) - 375 , 200, 20);
          sprintf(parole, "Il va vous falloir de nouvelles armes.");
          apply_text(renderer, 0, 0, 0, parole , police, 100 + (taille_fenetre[0]/2) - 500, 699 + (taille_fenetre[1]/2) - 375 , 380, 20);
        }
    }
    // si c'est un marchand
    if(nonCombattant_proche(monde) == 2){

        //afficher l'or en possession du joueur
        sprintf(parole, "%d", monde->joueur->or);
        apply_text(renderer, 0, 0, 0, parole , police, 800 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350 , 75, 60);
        grand_icone_position(renderer, textures, 865 + (taille_fenetre[0]/2) - 500, 505 + (taille_fenetre[1]/2) - 350,1);

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
          sprintf(parole, "250");
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
    //si un coffre est proche
    if(nonCombattant_proche(monde) == 3){
        sprintf(parole, "Recompense");
        apply_text(renderer, 255, 255, 255, parole , police, (taille_fenetre[0]/2) - 325, (taille_fenetre[1]/2) - 100 , 650, 80);
        sprintf(parole, "100");
        apply_text(renderer, 255,255, 255, parole , police, (taille_fenetre[0]/2) - 300, (taille_fenetre[1]/2) , 200, 60);
        grand_icone_position(renderer, textures, 400 + (taille_fenetre[0]/2) - 500, 375 + (taille_fenetre[1]/2) - 375, 1);
    }
}

/**
	* \fn void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police)
	* \brief affichage d'un combat
  * \param renderer le renderer
  * \param monde le monde du jeu
  * \param textures les textures du jeu
  * \param police la police du texte affiché
*/
void affichage_combat(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font* police){

    //Menus ave choix des actions

    char opt[20];
    //printf("début affichage combats : %d\n", monde->num_menu_comb);
    if(monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstre->etat == VIVANT && monde->joueur->combattant->pvCour > 0){
        //On affiche le monstre et le personnage

        joueur_position(renderer, textures, monde->joueur, 180, 600);

        //récupéation de l'information via la zone et la salle du joueur
        switch(monde->joueur->zone){
            case 0:
                apply_texture(&textures->monstre, renderer, SCREEN_WIDTH - 180, 600);
                break;
            case 1:
                apply_texture(&textures->monstre_zone1, renderer, SCREEN_WIDTH - 180, 600);
                break;
            case 2:
                switch(monde->joueur->salle){
                    case 0:
                        apply_texture(&textures->monstre_zone2, renderer, SCREEN_WIDTH - 180, 600);
                        break;
                    case 1:
                        apply_texture(&textures->monstre_zone2, renderer, SCREEN_WIDTH - 180, 600);
                        break;
                    case 2:
                        apply_texture(&textures->monstre_zone2, renderer, SCREEN_WIDTH - 180, 600);
                        break;
                    case 3:
                        apply_texture(&textures->boss, renderer, SCREEN_WIDTH - 180, 591);
                        break;
                }
            break;
        }

        //On affiche les statistiques du joueur:
        snprintf(opt, 20, "%d", monde->joueur->combattant->attaque);
        apply_text(renderer, 0, 0, 0, opt , police, 75 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
        icone_boutique_position(renderer, textures,  135 + (taille_fenetre[0]/2) - 500, 30 + (taille_fenetre[1]/2) - 375, 3);

        affichage_statistiques(renderer, police, textures, monde->joueur);

        //Si on affiche le menu 1
        if(monde->num_menu_comb == MENU1){
            //chaînes de caractères du texte
            char atq[10];
            char fuite[10];

            //Les cases dans lesquelles le texte se trouve
            apply_texture(&textures->case_combat, renderer, 100, 320);
            apply_texture(&textures->case_combat, renderer, 600, 320);
            switch(monde->option){
              case ATTAQUE:
                apply_texture(&textures->surbrillance_combat, renderer, 100, 320);
                break;
              case FUITE:
                apply_texture(&textures->surbrillance_combat, renderer, 600, 320);
                break;
            }


            //Texte à afficher
            sprintf(atq, "Attaque");
            sprintf(fuite, "Fuite");

            switch(monde->option){
                case RIEN:
                    apply_text(renderer, 0, 255, 255, atq, police, 100 + 100, 320+20,100,30);

                    apply_text(renderer, 0, 255, 255, fuite, police, 600 + 100, 320+20, 100,30);
                    break;
                case ATTAQUE:
                    apply_text(renderer, 255, 0, 0, atq, police, 100 + 100, 320 + 20,100, 30);

                    apply_text(renderer, 0, 255, 255, fuite, police, 600 + 100, 320 + 20,100, 30);
                    break;
                case FUITE:
                    apply_text(renderer, 0, 255, 255, atq, police,100+100, 320 + 20,100, 30);

                    apply_text(renderer, 255, 0, 0, fuite, police, 600+100, 320 + 20,100, 30);
                    break;
            }
        }
        else{
          //Si on affiche le menu 2
          if(monde->num_menu_comb == MENU2){

              char epee[10];
              char sort[10];
              char arc[10];
              char retour[10];

              //Chaînes de caractères utiles pour afficher le texte
              sprintf(epee, "Epee");
              sprintf(sort, "Sort");
              sprintf(arc, "Objets");
              sprintf(retour, "Retour");

              //case pour le choix coup d'épée
              apply_texture(&textures->case_combat, renderer, 100, 320);
              //case pour le choix sort
              apply_texture(&textures->case_combat, renderer, 600, 320);
              //case pour le choix tir Ã  l'arc
              apply_texture(&textures->case_combat, renderer, 100, 440);
              //case pour le choix retour
              apply_texture(&textures->case_combat, renderer, 600, 440);

              //on affiche la boule de feu et la larme qui représente le coût
              grand_icone_position(renderer, textures, 630, 320, 4);
              grand_icone_position(renderer, textures, 790, 320, 3);
              //On affiche le coût du sort
              apply_text(renderer, 0, 0, 255, "10", police, 820 + 30, 330,40,50);
              //On affiche une petite épée
              icone_boutique_position(renderer, textures, 320, 336, 3);
              //On affiche deux petites potions
              icone_boutique_position(renderer, textures, 320, 456, 1);
              icone_boutique_position(renderer, textures, 336, 456, 2);

              switch(monde->option){
                case EPEE:
                  apply_texture(&textures->surbrillance_combat, renderer, 100, 320);
                  break;
                case SORT:
                  apply_texture(&textures->surbrillance_combat, renderer, 600, 320);
                  break;
                case OBJETS:
                  apply_texture(&textures->surbrillance_combat, renderer, 100, 440);
                  break;
                case RETOUR:
                  apply_texture(&textures->surbrillance_combat, renderer, 600, 440);
                  break;
              }

              switch(monde->option){
                  case RIEN:
                    apply_text(renderer, 0, 255, 255, epee, police, 100+100, 320+20,100,30);
                    apply_text(renderer, 0, 255, 255, sort, police, 600+100, 320+20,100,30);
                    apply_text(renderer, 0, 255, 255, arc, police, 100+100, 440+20,100,30);
                    apply_text(renderer, 0, 255, 255, retour, police, 600+100, 440+20,100,30);
                    break;
                  case EPEE:
                      apply_text(renderer, 255, 0, 0, epee, police, 100+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, sort, police, 600+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, arc, police, 100+100, 440+20,100,30);
                      apply_text(renderer, 0, 255, 255, retour, police, 600+100, 440+20,100,30);
                      break;
                  case SORT:
                      apply_text(renderer, 0, 255, 255, epee, police, 100+100, 320+20,100,30);
                      apply_text(renderer, 255, 0, 0, sort, police, 600+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, arc, police, 100+100, 440+20,100,30);
                      apply_text(renderer, 0, 255, 255, retour, police, 600+100, 440+20,100,30);
                      break;
                  case OBJETS:
                      apply_text(renderer, 0, 255, 255, epee, police, 100+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, sort, police, 600+100, 320+20,100,30);
                      apply_text(renderer, 255, 0, 0, arc, police, 100+100, 440+20,100,30);
                      apply_text(renderer, 0, 255, 255, retour, police, 600+100, 440+20,100,30);
                      break;
                  case RETOUR:
                      apply_text(renderer, 0, 255, 255, epee, police, 100+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, sort, police, 600+100, 320+20,100,30);
                      apply_text(renderer, 0, 255, 255, arc, police, 100+100, 440+20,100,30);
                      apply_text(renderer, 255, 0, 0, retour, police, 600+100, 440+20,100,30);
                      break;
              }
          }
      }

      if(monde->num_menu_comb == MENU3){
        //On doit afficher trois cases
        char potion_pv[20];
        char potion_mana[20];
        char retour[20];
        char nb_pot_pv[4];
        char nb_pot_pm[4];

        //Récupération des chaînes de caractères
        sprintf(potion_pv, "Potion de vie");
        sprintf(potion_mana, "Potion de mana");
        sprintf(retour, "Retour");

        //case pour la potion de vie
        apply_texture(&textures->case_combat, renderer, 100, 320);
        //case pour la potion de mana
        apply_texture(&textures->case_combat, renderer, 600, 320);
        //case pour retourner en arrière
        apply_texture(&textures->case_combat, renderer, 350, 440);

        //On affiche deux petites potions
        icone_boutique_position(renderer, textures, 100 + 200, 336, 1);
        icone_boutique_position(renderer, textures, 800, 336, 2);

        //On affiche combien le joueur possède de potions dans chacune des cases
        snprintf(nb_pot_pv, 4, "%d", monde->joueur->inventaire[INDICE_POTION_PV].nb_obj);
        snprintf(nb_pot_pm, 4, "%d", monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj);

        apply_text(renderer, 0, 255, 255, potion_pv, police, 100+100, 320+20,100,30);
        apply_text(renderer, 0, 255, 255, potion_mana, police, 600+100, 320+20,100,30);

        apply_text(renderer, 0, 0, 0, nb_pot_pv, police, 100+250, 320+20,40,30);
        apply_text(renderer, 0, 0, 0, nb_pot_pm, police, 600+250, 320+20,40,30);


        switch(monde->option){
          case CHOIX_POTION_PV:
            apply_texture(&textures->surbrillance_combat, renderer, 100, 320);
            break;
          case CHOIX_POTION_MANA:
            apply_texture(&textures->surbrillance_combat, renderer, 600, 320);
            break;
          case RETOUR:
            apply_texture(&textures->surbrillance_combat, renderer, 350, 440);
            break;
        }

        switch(monde->option){
            case RIEN:
              apply_text(renderer, 0, 255, 255, potion_pv, police, 100+100, 320+20,100,30);
              apply_text(renderer, 0, 255, 255, potion_mana, police, 600+100, 320+20,100,30);
              apply_text(renderer, 0, 255, 255, retour, police, 350+100, 440+20,100,30);
              break;
            case CHOIX_POTION_PV:
                apply_text(renderer, 255, 0, 0, potion_pv, police, 100+100, 320+20,100,30);
                apply_text(renderer, 0, 255, 255, potion_mana, police, 600+100, 320+20,100,30);
                apply_text(renderer, 0, 255, 255, retour, police, 350+100, 440+20,100,30);
                break;
            case CHOIX_POTION_MANA:
                apply_text(renderer, 0, 255, 255, potion_pv, police, 100+100, 320+20,100,30);
                apply_text(renderer, 255, 0, 0, potion_mana, police, 600+100, 320+20,100,30);
                apply_text(renderer, 0, 255, 255, retour, police, 350+100, 440+20,100,30);
                break;
            case RETOUR:
                apply_text(renderer, 0, 255, 255, potion_pv, police, 100+100, 320+20,100,30);
                apply_text(renderer, 0, 255, 255, potion_mana, police, 600+100, 320+20,100,30);
                apply_text(renderer, 255, 0, 0, retour, police, 350+100, 440+20,100,30);
                break;
        }

      }
    }
    if(monde->joueur->combattant->pvCour <= 0){
        //Si le joueur est mort alors on affiche une image de game over
        //Il faudra appuyez sur une touche pour sortir du jeu
        apply_texture(&textures->game_over, renderer, (taille_fenetre[0]/2) - 500, (taille_fenetre[1]/2) - 375);
        apply_text(renderer, 255, 255, 255, "PERDU!", police, 380 + (taille_fenetre[0]/2) - 500, 250 + (taille_fenetre[1]/2) - 375, 240, 100);
        //affichage indication pour quitter
        apply_text(renderer, 255, 255, 255, "ENTREE pour reapparaitre" , police, 260 + (taille_fenetre[0]/2) - 500, 370 + (taille_fenetre[1]/2) - 375, 480, 50);

    }
}

/**
	* \fn void affichage_victoire(SDL_Renderer* renderer, images_t * textures, TTF_Font* police)
	* \brief affichage lorsque le joueur a gagné
  * \param renderer le renderer
  * \param police la police du texte affiché
*/
void affichage_victoire(SDL_Renderer* renderer, TTF_Font* police){
  apply_text(renderer, 255, 255, 255, "VICTOIRE", police, 340 + (taille_fenetre[0]/2) - 500, 250 + (taille_fenetre[1]/2) - 375, 320, 100);
  //affichage indication pour quitter
  apply_text(renderer, 255, 255, 255, "ENTREE pour quitter" , police, 600 + (taille_fenetre[0]/2) - 500, 675 + (taille_fenetre[1]/2) - 375, 380, 50);

}

/**
	* \fn void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font * police)
	* \brief affichage de l'inventaire du joueur
  * \param renderer le renderer
  * \param monde le monde du jeu
  * \param textures les textures du jeu
  * \param police la police du texte affiché
*/
void affichage_inventaire(SDL_Renderer *renderer, monde_t * monde, images_t *textures, TTF_Font * police){
    char opt[20] = "";
    char opt2[20] = "";
    int couleur=0; // Couleur 1 d'un item non selectionné
    int couleur2=255; //Couleur 2 d'un item normal

    // Affichage du mana, de l'or et des pv
    affichage_statistiques(renderer, police, textures, monde->joueur);

    // Affichage des degats
    snprintf(opt, 20, "%d", monde->joueur->combattant->attaque);
    apply_text(renderer, 0, 0, 0, opt , police, 75 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    icone_boutique_position(renderer, textures,  135 + (taille_fenetre[0]/2) - 500, 30 + (taille_fenetre[1]/2) - 375, 3);

        // Affichage Inventaire
        if(monde->option==1){
            couleur=COULEUR_1_SELECTION;
        }else{
            couleur=0;
        }
        sprintf(opt, "inventaire");
        apply_text(renderer, couleur, 255, 0, opt , police, SCREEN_WIDTH/6 , SCREEN_HEIGHT/6 , LARGEUR_TEXT, HAUTEUR_TEXT);
        //Objet1
        if(monde->option==2){
            couleur=COULEUR_1_SELECTION;
            apply_texture(&textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            couleur=0;
            apply_texture(&textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        if(monde->joueur->objet_equipe[INDICE_EPEE].id==monde->joueur->inventaire[INDICE_EPEE_PIERRE].id&&monde->joueur->inventaire[INDICE_EPEE_PIERRE].id!=0){
            apply_texture(&textures->equipe, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }

        if(monde->joueur->inventaire[INDICE_EPEE_PIERRE].id!=0){// Si l'objet est dans l'inventaire
            snprintf(opt2, 20, "%s", monde->joueur->inventaire[INDICE_EPEE_PIERRE].nom);
            apply_texture(&textures->epee1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
            apply_text(renderer, couleur, 255, 0 , opt2 , police,POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        }
        //Objet 2
        if(monde->option==3){
            couleur=COULEUR_1_SELECTION;
            apply_texture(&textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }else{
            couleur=0;
            apply_texture(&textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }
        if(monde->joueur->objet_equipe[INDICE_EPEE].id==monde->joueur->inventaire[INDICE_EPEE_DIAM].id&&monde->joueur->inventaire[INDICE_EPEE_DIAM].id!=0){
            apply_texture(&textures->equipe, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
        }

        if(monde->joueur->inventaire[INDICE_EPEE_DIAM].id!=0){
            snprintf(opt2, 20, "%s", monde->joueur->inventaire[INDICE_EPEE_DIAM].nom);
            apply_texture(&textures->epee2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H);
            apply_text(renderer, couleur, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L , POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H, TEXT_OBJET_L, TEXT_OBJET_H);
        }
        //Objet 3
        if(monde->option==4){
            couleur=COULEUR_1_SELECTION;
            apply_texture(&textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            couleur=0;
            apply_texture(&textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        if(monde->joueur->objet_equipe[INDICE_BOUCLIER].id==monde->joueur->inventaire[INDICE_BOUCLIER_BOIS].id&&monde->joueur->inventaire[INDICE_BOUCLIER_BOIS].id!=0){
            apply_texture(&textures->equipe, renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }

        if(monde->joueur->inventaire[INDICE_BOUCLIER_BOIS].id!=0){
            snprintf(opt2, 20, "%s", monde->joueur->inventaire[INDICE_BOUCLIER_BOIS].nom);
            apply_texture(&textures->bouclier1,renderer, POSITION_INVENTAIRE_IMG_L*0.3+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
            apply_text(renderer, couleur, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*0.3+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+125, TEXT_OBJET_L, TEXT_OBJET_H);
        }
        //Objet 4
        if(monde->option==5){
            couleur=COULEUR_1_SELECTION;
            apply_texture(&textures->selection_active, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }else{
            couleur=0;
            apply_texture(&textures->selection_inactive, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        if(monde->joueur->objet_equipe[INDICE_BOUCLIER].id==monde->joueur->inventaire[INDICE_BOUCLIER_DIAM].id&&monde->joueur->inventaire[INDICE_BOUCLIER_DIAM].id!=0){
            apply_texture(&textures->equipe, renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
        }
        if(monde->joueur->inventaire[INDICE_BOUCLIER_DIAM].id!=0){
            snprintf(opt2, 20, "%s", monde->joueur->inventaire[INDICE_BOUCLIER_DIAM].nom);
            apply_texture(&textures->bouclier2,renderer, POSITION_INVENTAIRE_IMG_L*1.2+DECALAGE_IMG_TEXT_L, POSITION_INVENTAIRE_IMG_H*2);
            apply_text(renderer, couleur, 255, 0, opt2 , police, POSITION_INVENTAIRE_L*1.2+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+125, TEXT_OBJET_L, TEXT_OBJET_H);
        }
        //Objet 6 Potion Santée
        if(monde->option==6){
            couleur=COULEUR_1_SELECTION;
        }else{
            couleur=COULEUR_2_VIDE;
        }
        if(monde->joueur->inventaire[INDICE_POTION_PV].id!=0){
          couleur2=COULEUR_1_SELECTION;
        }else{
          couleur2=COULEUR_2_VIDE;
        }
        sprintf(opt, "Potion de vie");
        apply_text(renderer, couleur, couleur2, 0 , opt , police,POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(&textures->potion_pv, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L-3, POSITION_INVENTAIRE_IMG_H);
        snprintf(opt, 20, "%d", monde->joueur->inventaire[INDICE_POTION_PV].nb_obj);
        apply_text(renderer, couleur, couleur2, 0 , opt , police,POSITION_INVENTAIRE_L*0.15+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H+DECALAGE_TEXT_IMG_H , TEXT_OBJET_L/5, TEXT_OBJET_H);
        //Objet 7 Potion Mana
        if(monde->option==7){
            couleur=COULEUR_1_SELECTION;
        }else{
            couleur=0;
        }
        if(monde->joueur->inventaire[INDICE_POTION_MANA].id!=0){
          couleur2=COULEUR_1_SELECTION;
        }else{
          couleur2=COULEUR_2_VIDE;
        }
        sprintf(opt, "Potion de mana");
        apply_text(renderer, couleur, couleur2, 0, opt , police, POSITION_INVENTAIRE_L*0.001+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+125, TEXT_OBJET_L, TEXT_OBJET_H);
        apply_texture(&textures->potion_mana, renderer, POSITION_INVENTAIRE_IMG_L*0.001+DECALAGE_IMG_TEXT_L-3, POSITION_INVENTAIRE_IMG_H*2);
        snprintf(opt, 20, "%d", monde->joueur->inventaire[INDICE_POTION_MANA].nb_obj);
        apply_text(renderer, couleur, couleur2, 0, opt , police, POSITION_INVENTAIRE_L*0.15+DECALAGE_TEXT_IMG_L, POSITION_INVENTAIRE_H*1.5+DECALAGE_TEXT_IMG_H+125, TEXT_OBJET_L/5, TEXT_OBJET_H);
}

/**
	* \fn void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police)
	* \brief affichage des menus de début de jeu
  * \param renderer le renderer
  * \param monde le monde du jeu
  * \param police la police du texte affiché
*/
void affichage_menu(SDL_Renderer *renderer, monde_t * monde, TTF_Font * police){
    char opt[20] = "";

    //menu de base
    if(monde->etat_jeu == ETAT_MENU_1){

        apply_text(renderer, 255, 255, 255, "Dragon Quest Like" , police, 50 , 50 , 900, 80);

        //jouer
        if(monde->option == 1){
            sprintf(opt, "Jouer");
            if(police != 0){
                apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
            }
        } else{
            sprintf(opt, "Jouer");
            if(police != 0){
                apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/3 , 350, 80);
            }
        }
        //quitter
        if(monde->option == 2){
            sprintf(opt, "Quitter");
            if(police != 0){
                apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
            }
        } else{
            sprintf(opt, "Quitter");
            if(police != 0){
                apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , 2*SCREEN_HEIGHT/3, 350, 80);
            }
        }
    }

    //menu choix de partie
    if(monde->etat_jeu == ETAT_MENU_2){
        //Partie 1
        if(monde->option == 1){
            sprintf(opt, "Partie 1");
            if(police != 0){
                apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
            }
        } else{
            sprintf(opt, "Partie 1");
            if(police != 0){
                apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , SCREEN_HEIGHT/5 , 350, 80);
            }
        }
        //Partie 2
        if(monde->option == 2){
            sprintf(opt, "Partie 2");
            if(police != 0){
                apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
            }
        } else{
            sprintf(opt, "Partie 2");
            if(police != 0){
                apply_text(renderer, 255, 255, 255 , opt , police, SCREEN_WIDTH/3, 2*SCREEN_HEIGHT/5 , 350, 80);
            }
        }
        //Nouvelle partie
        if(monde->option == 3){
            //si on a pas enclenché le nouveau menu de nouvelle partie
            if(monde->option2 == 0){
                //l'affichage de l'option nouvelle partie est affichée sélectionnée
                sprintf(opt, "Nouvelle partie");
                if(police != 0){
                    apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
                }
            //sinon on affiche la sélection du nouveau menu
            } else{
                sprintf(opt, "Nouvelle partie");
                if(police != 0){
                    apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
                }
                sprintf(opt, "Effacer:");
                if(police != 0){
                    apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 - 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                }
                if(monde->option2 == 1){
                    sprintf(opt, "Partie1");
                    if(police != 0){
                        apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Partie1");
                    if(police != 0){
                        apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
                if(monde->option2 == 2){
                    sprintf(opt, "Partie2");
                    if(police != 0){
                        apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 + 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Partie2");
                    if(police != 0){
                        apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 + 180, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
                if(monde->option2 == 3){
                    sprintf(opt, "Annuler");
                    if(police != 0){
                        apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 + 360, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                } else {
                    sprintf(opt, "Annuler");
                    if(police != 0){
                        apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 + 360, 3*SCREEN_HEIGHT/5 + 90, 175, 40);
                    }
                }
            }
        } else{
            sprintf(opt, "Nouvelle partie");
            if(police != 0){
                apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , 3*SCREEN_HEIGHT/5, 350, 80);
            }
        }
        //Retour
        if(monde->option == 4){
            sprintf(opt, "Retour");
            if(police != 0){
                apply_text(renderer, 255, 0, 0, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
            }
        } else{
            sprintf(opt, "Retour");
            if(police != 0){
                apply_text(renderer, 255, 255, 255, opt , police, SCREEN_WIDTH/3 , 4*SCREEN_HEIGHT/5, 350, 80);
            }
        }
    }
}

/**
	* \fn void affichage_statistiques(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur)
	* \brief affichage des statistiques de pv, mana et or du joueur
  * \param renderer le renderer
  * \param police la police du texte affiché
  * \param textures les textures du jeu
  * \param joueur le joueur
*/
void affichage_statistiques(SDL_Renderer *renderer, TTF_Font * police, images_t *textures, joueur_t * joueur){
    int nb;
    char nb_aff[4];
    char max[4] = "max";

    //affichage de l'or
    nb = joueur->or;
    sprintf(nb_aff, "%d", nb);
    apply_text(renderer, 0, 0, 0, nb_aff , police, 220 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    grand_icone_position(renderer, textures, 270 + (taille_fenetre[0]/2) - 500, 15 + (taille_fenetre[1]/2) - 375, 1);

    //affichage du mana
    nb = joueur->manaCour;
    sprintf(nb_aff, "%d", nb);
    apply_text(renderer, 0, 0, 0, nb_aff , police, 365 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    grand_icone_position(renderer, textures, 415 + (taille_fenetre[0]/2) - 500, 15 + (taille_fenetre[1]/2) - 375, 3);
    nb = joueur->manaMax;
    sprintf(nb_aff, "%d", nb);
    apply_text(renderer, 0, 0, 0, nb_aff , police, 510 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    grand_icone_position(renderer, textures, 560 + (taille_fenetre[0]/2) - 500, 15 + (taille_fenetre[1]/2) - 375, 3);
    apply_text(renderer, 0, 0, 255, max , police, 615 + (taille_fenetre[0]/2) - 500, 50 + (taille_fenetre[1]/2) - 375 , 30, 17);

    //affichage des pv
    nb = joueur->combattant->pvCour;
    sprintf(nb_aff, "%d", nb);
    apply_text(renderer, 0, 0, 0, nb_aff , police, 655 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    grand_icone_position(renderer, textures, 705 + (taille_fenetre[0]/2) - 500, 15 + (taille_fenetre[1]/2) - 375, 2);
    nb = joueur->combattant->pvMax;
    sprintf(nb_aff, "%d", nb);
    apply_text(renderer, 0, 0, 0, nb_aff , police, 800 + (taille_fenetre[0]/2) - 500, 20 + (taille_fenetre[1]/2) - 375 , 60, 50);
    grand_icone_position(renderer, textures, 850 + (taille_fenetre[0]/2) - 500, 15 + (taille_fenetre[1]/2) - 375, 2);
    apply_text(renderer, 255, 0, 0, max , police, 910 + (taille_fenetre[0]/2) - 500, 50 + (taille_fenetre[1]/2) - 375 , 30, 17);
}
