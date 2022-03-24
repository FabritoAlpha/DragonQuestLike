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

    detruire_monde(&monde);

    clean_images(textures);

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
    init_monde_menu(monde);
    init_sdl(window, renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ttf();
    init_images(*renderer,textures);
}

/*
La fonction charger_combat sert à actualiser l'état du jeu afin de mettre le jeu en version "combat"

#define COMBAT 57

void charger_combat(monde_t * monde){
  monde->etat_jeu = COMBAT;
}

*/
void changement_salle(joueur_t * j, int changement_salle){
	j->salle = (j->salle) + changement_salle;
	
	switch(j->salle){
		case 0:
			j->combattant->x = SCREEN_WIDTH - 150;
			j->combattant->y = (SCREEN_HEIGHT/2) - (HAUTEUR_PERSONNAGE/2);
			break;
		case 1: 
			j->combattant->x = LARGEUR_PERSONNAGE + 30;
			j->combattant->y = (SCREEN_HEIGHT/2) - (HAUTEUR_PERSONNAGE/2);
			break;
		case 2: 
			j->combattant->x = (SCREEN_WIDTH/2) - (LARGEUR_PERSONNAGE/2);
			j->combattant->y = HAUTEUR_PERSONNAGE + 30;
			break;
		case 3: 
			j->combattant->x = SCREEN_WIDTH - 150;
			j->combattant->y = (SCREEN_HEIGHT/2) - (HAUTEUR_PERSONNAGE/2);
			break;
	
	}
}

void changement_zone(joueur_t * j){
	(j->zone)++;
	j->salle = 0;
	
	j->combattant->x = (SCREEN_WIDTH/2) - (LARGEUR_PERSONNAGE/2);
	j->combattant->y = HAUTEUR_PERSONNAGE + 30;
}

int collision_combattant_ecran(combattant_t * combattant, monde_t * monde){


    if(combattant->type == JOUEUR){

        if( (monde->joueur->salle == 0) && (combattant->y >= ENTREE_HAUT_SALLE_1) && (combattant->y + HAUTEUR_PERSONNAGE <= ENTREE_BAS_SALLE_1) && (combattant->x  + LARGEUR_PERSONNAGE >= SCREEN_WIDTH) ){
          changement_salle(monde->joueur, +1);
    		  return(PAS_COLLISION);
    	  }

        if( (monde->joueur->salle == 1) && (combattant->y >= ENTREE_HAUT_SALLE_1) && (combattant->y + HAUTEUR_PERSONNAGE <= ENTREE_BAS_SALLE_1) && (combattant->x <= 0) ){
          changement_salle(monde->joueur, -1);
    		  return(PAS_COLLISION);
    	  }

    	  if( (monde->joueur->salle == 1) && (combattant->x >= ENTREE_GAUCHE_ZONE_SUIVANTE) && (combattant->x + LARGEUR_PERSONNAGE <= ENTREE_DROITE_ZONE_SUIVANTE) && (combattant->y + HAUTEUR_PERSONNAGE >= SCREEN_HEIGHT - 100) ){
    		  changement_zone(monde->joueur);
    		  return(PAS_COLLISION);
    	  }

        if(combattant->x + LARGEUR_PERSONNAGE  > SCREEN_WIDTH ){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_PERSONNAGE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
    }

    if(combattant->type == MONSTRE){
        if(combattant->x + LARGEUR_MONSTRE  > SCREEN_WIDTH ){

            return(COLLISION);
        }
        if(combattant->y + HAUTEUR_MONSTRE > SCREEN_HEIGHT - 100){

            return(COLLISION);
        }
    }
    if(combattant->x  < 100.0){

        return(COLLISION);
    }
    if(combattant->y < 100.0){

        return(COLLISION);
    }


    return(PAS_COLLISION);
}

int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre/*monde_t * monde */){

    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_MONSTRE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_MONSTRE) ){

        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
        return(COLLISION);
    }
    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_MONSTRE) && (joueur->y  >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_MONSTRE) ){

        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_MONSTRE) && (joueur->y >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_MONSTRE) ){

        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_MONSTRE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_MONSTRE) ){

        return(COLLISION);
        /*
        charger_combat(monde);
        return(PAS_COLLISION);
        */
    }
    return(PAS_COLLISION);
}


int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj){

  if( (combattant->x + LARGEUR_PERSONNAGE >= pnj->x) && (combattant->x + LARGEUR_PERSONNAGE <= pnj->x + LARGEUR_PERSO_NN_JOUEUR) && (combattant->y + HAUTEUR_PERSONNAGE >= pnj->y) && (combattant->y + HAUTEUR_PERSONNAGE <= pnj->y + HAUTEUR_PERSO_NN_JOUEUR) ){

    return(COLLISION);
  }
  if( (combattant->x + LARGEUR_PERSONNAGE >= pnj->x) && (combattant->x + LARGEUR_PERSONNAGE <= pnj->x + LARGEUR_PERSO_NN_JOUEUR) && (combattant->y  >= pnj->y) && (combattant->y <= pnj->y + HAUTEUR_PERSO_NN_JOUEUR) ){

    return(COLLISION);
  }
  if( (combattant->x >= pnj->x) && (combattant->x <= pnj->x + LARGEUR_PERSO_NN_JOUEUR) && (combattant->y >= pnj->y) && (combattant->y <= pnj->y + HAUTEUR_PERSO_NN_JOUEUR) ){

    return(COLLISION);
  }
  if( (combattant->x >= pnj->x) && (combattant->x <= pnj->x + LARGEUR_PERSO_NN_JOUEUR) && (combattant->y + HAUTEUR_PERSONNAGE >= pnj->y) && (combattant->y + HAUTEUR_PERSONNAGE <= pnj->y + HAUTEUR_PERSO_NN_JOUEUR) ){

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

int collision_combattant(combattant_t * combattant, salle_t * salle, int indice_monstre, joueur_t * joueur, monde_t * monde){
    int i;

    if(collision_combattant_ecran(combattant, monde)){
      return(COLLISION);
    }

    if(combattant->type == JOUEUR){
      for(i = 0; i < NB_MONSTRES_SALLE; i++){
        if(collision_joueur_monstre(combattant, salle->monstres[i]->combattant)){
            return(COLLISION);
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
      if(collision_joueur_monstre(joueur->combattant, combattant)){
        return(COLLISION);
      }
    }

    for(i = 0; i < NB_PERSO_SALLE; i++){
      if(collision_combattant_pnj(combattant,salle->perso[i])){
        return(COLLISION);
      }
    }

    if(collision_combattant_coffre(combattant, salle->coffre)){
      return(COLLISION);
    }

    return(PAS_COLLISION);
}



int deplacement_droit(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j, monde_t * monde){
    entitee->x = (entitee->x)+entitee->vitesse;
    if(collision_combattant(entitee, salle, indice_monstre, j, monde)){

        a_gauche(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_gauche(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j, monde_t * monde){
    entitee->x = (entitee->x)-entitee->vitesse;
    if(collision_combattant(entitee, salle, indice_monstre, j, monde)){

        a_droite(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_haut(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j, monde_t * monde){
    entitee->y = (entitee->y)-entitee->vitesse;
    if(collision_combattant(entitee, salle, indice_monstre, j, monde)){

        en_bas(entitee);
        return(1);
    }else{
      return(0);
    }
}

int deplacement_bas(combattant_t * entitee, salle_t *salle, int indice_monstre, joueur_t * j, monde_t * monde){
    entitee->y = (entitee->y)+entitee->vitesse;
    if(collision_combattant(entitee, salle, indice_monstre, j, monde)){

        en_haut(entitee);
        return(1);
    }else{
      return(0);
    }
}

int distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre){// renvoie la distance entre deux combattants.
  int distance;
  int xa=joueur->combattant->x;
  int ya=joueur->combattant->y;
  int xb=monstre->combattant->x;
  int yb=monstre->combattant->y;
  distance=sqrt(pow(xb-xa,2)+pow(yb-ya,2));
  return distance;
}

void deplacement_monstre(monstre_t * monstre,monde_t * m){
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
    if(monstre->dir==-1){
      direction=rand()%nb_direction;
      do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
      monstre->dir=direction;
      monstre->dist=distance;
      monstre->x=monstre->combattant->x;
      monstre->y=monstre->combattant->y;
    }
    if(monstre->dir==0 && (monstre->combattant->x)>(monstre->x-monstre->dist)){ // Si le monstre va à gauche
      valColision = deplacement_gauche(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur, m);
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
      valColision = deplacement_droit(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur, m);
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
      valColision = deplacement_haut(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur, m);
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
      valColision = deplacement_bas(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur, m);
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
      valColision = deplacement_gauche(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur,m);
    }
    if(m->joueur->combattant->x > monstre->combattant->x){
      valColision = deplacement_droit(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur,m);
    }
    if(m->joueur->combattant->y < monstre->combattant->y){
      valColision = deplacement_haut(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur,m);
    }
    if(m->joueur->combattant->y > monstre->combattant->y){
      valColision = deplacement_bas(monstre->combattant, m->zones[0]->salles[0], 0, m->joueur,m);
    }
  }
}

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */
void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures,int * next_tick,int *next_tick_monstre){

    int time_sec=(SDL_GetTicks()/10);
    //on vide le renderer
    clear_renderer(renderer);

    fond_position(renderer, textures, monde->etat_jeu, monde->joueur->zone, monde->joueur->salle);
    printf("On ne plante pas avant le premier if de rafraichir\n\n\n");
    if(monde->etat_jeu == 0 || monde->etat_jeu == 4){
      printf("Dans le premier if on ne plante pas avant affichage du menu\n\n\n");
      affichage_menu(renderer, monde, textures);
      printf("Dans le premier if on ne plante pas pdt affichage du menu\n\n\n");
    }
    if(monde->etat_jeu == 3){
      affichage_inventaire(renderer, monde, textures);
    }

    printf("On ne plante pas avant le second if de rafraichir\n\n\n");
    if(monde->etat_jeu == 1){
      printf("On ne plante pas avant joueur_position dans le second if de rafraichir\n\n\n");
      joueur_position(renderer, textures, monde->joueur);

      for(int i = 0; i < NB_MONSTRES_SALLE ; i++){
        int suivaleatoir;
        monstre_position(renderer, textures, monde->zones[0]->salles[0]->monstres[i]);
        if(time_sec>(*next_tick_monstre)){
          if(monde->zones[0]->salles[0]->monstres[i]->combattant->vitesse==1){
            monde->zones[0]->salles[0]->monstres[i]->combattant->vitesse=0;
          }else{
            monde->zones[0]->salles[0]->monstres[i]->combattant->vitesse=1;
          }
          do{
            suivaleatoir=rand()%500;
          }while(suivaleatoir<200||suivaleatoir>500);
          (*next_tick_monstre)+=suivaleatoir;
        }

        if(time_sec>(*next_tick)){
          (*next_tick)+=1;
          deplacement_monstre(monde->zones[0]->salles[0]->monstres[i], monde);
        }

      }

    }

    update_screen(renderer);

}

void sauvegarde(monde_t* monde){
    FILE * fichier;
    if(monde->partie == 1){
        fichier = fopen("./rsrc/txt/partie1.txt","w");
        fprintf(fichier, "%d\n%d", monde->joueur->combattant->niveau, monde->joueur->zone);
        fclose(fichier);
    }
    if(monde->partie == 2){
      fichier = fopen("./rsrc/txt/partie2.txt","w");
      fprintf(fichier, "%d\n%d", monde->joueur->combattant->niveau, monde->joueur->zone);
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
            if(event->key.keysym.sym == SDLK_LEFT) {
                deplacement_gauche(monde->joueur->combattant, monde->zones[0]->salles[0], 0, NULL,monde);
            }
            if(event->key.keysym.sym == SDLK_RIGHT){
                deplacement_droit(monde->joueur->combattant, monde->zones[0]->salles[0], 0, NULL,monde);
            }
            if(event->key.keysym.sym == SDLK_UP){
                deplacement_haut(monde->joueur->combattant, monde->zones[0]->salles[0], 0, NULL,monde);
            }
            if(event->key.keysym.sym == SDLK_DOWN){
                deplacement_bas(monde->joueur->combattant, monde->zones[0]->salles[0], 0, NULL,monde);
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
