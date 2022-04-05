/**
* \file deplacements.c
* \brief déplacements et collisions du joueur et des monstres
* \author Anna Beranger, Alex Choux, Arthur Fabre
* \date 03/03/2022
*/

#include  "../lib/deplacements.h"

/**
	* \fn int distance_pnj_coffre(joueur_t * joueur, nonCombattant_t * entite)
  * \brief renvoie la distance entre le joueur et un non combattant, personnage ou coffre
  * \param joueur le joueur
  * \param entite l'entite, personnage ou coffre
  * \return distance
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
	* \fn int nonCombattant_proche(monde_t * monde)
  * \brief teste si un personnage, un marchand ou un coffre est proche du joueur
  * \param monde le monde du jeu
  * \return 0 si aucun non combattant est proche, sinon, 1 si c'est un personnage, 2 si c'est un marchand, 3 si c'est un coffre
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

/**
	* \fn void changement_salle(joueur_t * j, int changement_salle)
  * \brief gestion du passage du joueur dans une nouvelle salle
  * \param j le joueur
  * \param changement_salle direction aller (1) ou retour (-1)
*/
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
        j->combattant->y = SCREEN_HEIGHT - 100 -HAUTEUR_PERSONNAGE - j->combattant->vitesse;
      }
      break;
		case 2:
      //S'il arrive d'en haut on le met tout en haut sans changer son placement latéral
			if(changement_salle == 1){
        j->combattant->y = 100 + j->combattant->vitesse;
      }
      else{
        if(j->zone == 2){
          j->combattant->x = 100;
        }
        else{
            j->combattant->x = j->combattant->vitesse;
        }

      }
      break;
		case 3:
      //S'il va vers la gauche même cas que pour le cas 0
      if(j->zone == 2){

        j->combattant->x = SCREEN_WIDTH - LARGEUR_PERSONNAGE - 100 -j->combattant->vitesse;
      }else{
        j->combattant->x = SCREEN_WIDTH - j->combattant->vitesse - LARGEUR_PERSONNAGE;
      }
			break;
	}
}

/**
	* \fn void changement_zone(monde_t * monde)
  * \brief gestion du passage du joueur dans une nouvelle zone
  * \param monde le monde du jeu
*/
void changement_zone(monde_t * monde){
	(monde->joueur->zone)++;
	monde->joueur->salle = 0;

	monde->joueur->combattant->x = (SCREEN_WIDTH/2) - (LARGEUR_PERSONNAGE/2);
	monde->joueur->combattant->y = 100 + 10;

  //En changeant de zone le joueur augmente son niveau de 1 et ainsi il augmente ses statistiques de base
  monde->joueur->combattant->niveau += 1;
  monde->joueur->combattant->attaque += 5;
  monde->joueur->combattant->pvMax +=10;
  monde->joueur->combattant->pvCour += 10;
  monde->joueur->manaMax += 5;
  monde->joueur->manaCour += 5;

  sauvegarde(monde);
}

/**
	* \fn int collision_combattant_ecran(combattant_t * combattant, monde_t * monde)
  * \brief détection de collision du joueur ou d'un monstre avec le bord de la surface de jeu
  * \param combattant le joueur ou un monstre
  * \param monde le monde du jeu
  * \return collision (1), pas de collision (0)
*/
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
            if(monde->joueur->zone == 2){
              if(combattant->x <= 80.0 && combattant->y >= 250 && combattant->y + HAUTEUR_PERSONNAGE <= 490){
                changement_salle(monde->joueur, +1);
      		      return(PAS_COLLISION);
              }
            }
    	      else{
              if(combattant->x <= 0.0){
                changement_salle(monde->joueur, +1);
    		        return(PAS_COLLISION);
              }
            }
            break;
          case 3:
            if(monde->joueur->zone == 2){
              if(combattant->x + LARGEUR_PERSONNAGE>= SCREEN_WIDTH - 100 && combattant->y >= 210 && combattant->y + HAUTEUR_PERSONNAGE <= 540){
                changement_salle(monde->joueur, -1);
    		          return(PAS_COLLISION);
    	        }
            }
            else{
              if(combattant->x + LARGEUR_PERSONNAGE>= SCREEN_WIDTH){
                changement_salle(monde->joueur, -1);
    		        return(PAS_COLLISION);
    	        }
            }
    	      if((combattant->x >= ENTREE_GAUCHE_ZONE_SUIVANTE) && (combattant->x + LARGEUR_PERSONNAGE <= ENTREE_DROITE_ZONE_SUIVANTE) && (combattant->y + HAUTEUR_PERSONNAGE >= SCREEN_HEIGHT - 100) && monde->joueur->zone < 2){
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

/**
	* \fn int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre, monde_t * monde)
  * \brief détection de collision entre le joueur et un monstre
  * \param joueur le joueur
  * \param monstre un monstre
  * \param monde le monde du jeu
  * \return collision (1), pas de collision (0)
*/
int collision_joueur_monstre(combattant_t * joueur, combattant_t * monstre, monde_t * monde){

    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);
    }
    if( (joueur->x + LARGEUR_PERSONNAGE >= monstre->x) && (joueur->x + LARGEUR_PERSONNAGE <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y  >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);

    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y >= monstre->y) && (joueur->y <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);

    }
    if( (joueur->x >= monstre->x) && (joueur->x <= monstre->x + LARGEUR_PERSONNAGE) && (joueur->y + HAUTEUR_PERSONNAGE >= monstre->y) && (joueur->y + HAUTEUR_PERSONNAGE <= monstre->y + HAUTEUR_PERSONNAGE) ){

        monde->etat_jeu = ETAT_COMBAT;
        monde->option = RIEN;
        return(COLLISION);

    }
    return(PAS_COLLISION);
}

/**
	* \fn int collision_combattant_pnj(combattant_t * combattant, nonCombattant_t * pnj)
  * \brief détection de collision entre le joueur ou un monstre et un personnage non joueur
  * \param combattant le joueur ou un monstre
  * \param pnj un personnage non joueur
  * \return collision (1), pas de collision (0)
*/
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

/**
	* \fn int collision_combattant_coffre(combattant_t * combattant, nonCombattant_t * coffre)
  * \brief détection de collision entre le joueur ou un monstre et un coffre
  * \param combattant le joueur ou un monstre
  * \param coffre un coffre
  * \return collision (1), pas de collision (0)
*/
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

/**
	* \fn int collision_combattant(combattant_t * combattant, int indice_monstre, monde_t * monde)
  * \brief détection de collision entre un combattant(joueur ou monstre) et un coffre, un combattant ou un pnj
  * \param combattant le joueur ou un monstre
  * \param indice_monstre
  * \param monde le monde du jeu
  * \return collision (1), pas de collision (0)
*/
int collision_combattant(combattant_t * combattant, int indice_monstre, monde_t * monde){
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

/**
	* \fn int deplacement_droit(combattant_t * entite, int indice_monstre, monde_t * monde)
  * \brief vérifie qu'un déplacement à droite est possible
  * \param entite le joueur ou un monstre
  * \param indice_monstre
  * \param monde le monde du jeu
  * \return déplacement non possible (1), déplacement possible (0)
*/
int deplacement_droit(combattant_t * entite, int indice_monstre, monde_t * monde){
    entite->x = (entite->x)+entite->vitesse;
    //On vérifie s'il y a la collision suite au déplacement, si oui on annule le déplacement en revenant dans l'autre sens
    if(collision_combattant(entite, indice_monstre, monde)){

        a_gauche(entite);
        return(1);
    }else{
      return(0);
    }
}

/**
	* \fn int deplacement_gauche(combattant_t * entite, int indice_monstre, monde_t * monde)
  * \brief vérifie qu'un déplacement à gauche est possible
  * \param entite le joueur ou un monstre
  * \param indice_monstre
  * \param monde le monde du jeu
  * \return déplacement non possible (1), déplacement possible (0)
*/
int deplacement_gauche(combattant_t * entite, int indice_monstre, monde_t * monde){
    entite->x = (entite->x)-entite->vitesse;
    //On vérifie s'il y a la collision suite au déplacement, si oui on annule le déplacement en revenant dans l'autre sens
    if(collision_combattant(entite, indice_monstre, monde)){
        a_droite(entite);
        return(1);
    }else{
      return(0);
    }
}

/**
	* \fn int deplacement_haut(combattant_t * entite, int indice_monstre, monde_t * monde)
  * \brief vérifie qu'un déplacement en haut est possible
  * \param entite le joueur ou un monstre
  * \param indice_monstre
  * \param monde le monde du jeu
  * \return déplacement non possible (1), déplacement possible (0)
*/
int deplacement_haut(combattant_t * entite, int indice_monstre, monde_t * monde){
    entite->y = (entite->y)-entite->vitesse;
    //On vérifie s'il y a la collision suite au déplacement, si oui on annule le déplacement en revenant dans l'autre sens
    if(collision_combattant(entite, indice_monstre, monde)){
        en_bas(entite);
        return(1);
    }else{
      return(0);
    }
}

/**
	* \fn int deplacement_bas(combattant_t * entite, int indice_monstre, monde_t * monde)
  * \brief vérifie qu'un déplacement en bas est possible
  * \param entite le joueur ou un monstre
  * \param indice_monstre
  * \param monde le monde du jeu
  * \return déplacement non possible (1), déplacement possible (0)
*/
int deplacement_bas(combattant_t * entite, int indice_monstre, monde_t * monde){
    entite->y = (entite->y)+entite->vitesse;
    //On vérifie s'il y a la collision suite au déplacement, si oui on annule le déplacement en revenant dans l'autre sens
    if(collision_combattant(entite, indice_monstre, monde)){
        en_haut(entite);
        return(1);
    }else{
      return(0);
    }
}

/**
	* \fn int distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre)
	* \brief renvoie la distance entre  le joueur et un monstre
	* \param joueur le joueur
  * \param monstre un monstre
  * \return distance
*/
int distancejoueurmonstre(joueur_t * joueur,monstre_t * monstre){
  int distance;
  int xa=joueur->combattant->x;
  int ya=joueur->combattant->y;
  int xb=monstre->combattant->x;
  int yb=monstre->combattant->y;
  distance=sqrt(pow(xb-xa,2)+pow(yb-ya,2));
  return distance;
}

/**
	* \fn void deplacement_monstre(monstre_t * monstre, monde_t * m)
	* \brief IA du monstre, le déplace dans son environnement
  * \param monstre monstre qui est controlé
	* \param m le monde du jeu
*/
void deplacement_monstre(monstre_t * monstre, monde_t * m){
  int valColision=0;
  int direction;
  int distance;
  int dist_min=10;// A METRE JEU.H
  int dist_max=50;// A METRE JEU.H
  int nb_direction=4; //A METRE JEU.H
  int distance_agro=250; //A METRE JEU.H
  if(distancejoueurmonstre(m->joueur,monstre)>distance_agro && monstre->agro==1){
    monstre->agro=0;
    monstre->dir=-1;
  }
  if(distancejoueurmonstre(m->joueur,monstre)<distance_agro && monstre->agro==0){
    monstre->agro=1;
  }
  if(monstre->agro==0){ // Etat du monde dans lequel il se dÃ©place de maniÃ¨re alÃ©atoire
    if(monstre->dir==-1){ // dir -1 = initialisation du monstre sur son emplacement
      direction=rand()%nb_direction;
      do{distance=rand()%dist_max;}while(distance<dist_min||distance>dist_max);
      monstre->dir=direction;
      monstre->dist=distance;
      monstre->x=monstre->combattant->x;
      monstre->y=monstre->combattant->y;
    }
    if(monstre->dir==0 && (monstre->combattant->x)>(monstre->x-monstre->dist)){ // Si le monstre va Ã  gauche
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
    if(monstre->dir==1 && (monstre->combattant->x)<(monstre->x+monstre->dist)){ // Si le monstre va Ã  droite
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

/**
	* \fn void sauvegarde(monde_t* monde)
	* \brief sauvegarde la partie en cours
	* \param monde le monde du jeu
*/
void sauvegarde(monde_t* monde){
    FILE * fichier;
    int i;
    int nb_obj_inv = monde->joueur->nb_obj_inventaire;
    int nb_obj_equip = monde->joueur->nb_obj_equip;

    //La sauvegarde prend en compte le choix de la partie afin de sauvegarder dans le bon fichier
    if(monde->partie == 1){
        //On ouvre le fichier
        fichier = fopen("./rsrc/txt/partie1.txt","w");
        //On sauvegarde le nombre d'objets possédés pour faciliter le chargement
        fprintf(fichier, "%d\n", nb_obj_inv);
        for(i = 0; i < TAILLE_INVENTAIRE; i++){
          //Si un objet est présent à l'indice i du tableau
          if(monde->joueur->inventaire[i].id != 0){
            //On sauvegarde son indice et le nombre d'objets possédés 1 si c'est une pièce d'équipement, 1 ou plus pour un consommable
            fprintf(fichier, "%d\n", i);
            fprintf(fichier, "%d\n", monde->joueur->inventaire[i].nb_obj);
          }
        }
        //On sauvegarde ke nombre d'objets équipés pour facilier le chargement
        fprintf(fichier, "%d\n", nb_obj_equip);
        for(i = 0; i < NB_EQUIPEMENT; i++){
          //Si une épée ou un bouclier est équipée
          if(monde->joueur->objet_equipe[i].id != 0){
            //On sauvegarde l'indice dans le tableau pour savoir si c'est une épée ou un bouclier
            //On sauvegarde aussi l'id de l'objet équipé
            fprintf(fichier, "%d\n", i);
            fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
          }
        }
        //Sauvegarde du niveau du joueur et de la zone
        fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->niveau, monde->joueur->zone);

        //Sauvegarde des pv max et courrants
        fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->pvMax, monde->joueur->combattant->pvCour);

        //Sauvegarde du mana max et courrant
        fprintf(fichier, "%d\n%d\n", monde->joueur->manaMax, monde->joueur->manaCour);

        //Sauvegarde de l'or
        fprintf(fichier, "%d\n", monde->joueur->or);

        //Sauvegarde de l'attaque
        fprintf(fichier, "%d\n", monde->joueur->combattant->attaque);

        //On ferme le fichier
        fclose(fichier);
    }
    if(monde->partie == 2){
      //On ouvre le fichier
      fichier = fopen("./rsrc/txt/partie2.txt","w");
      //On sauvegarde le nombre d'objets possédés pour faciliter le chargement
      fprintf(fichier, "%d\n", nb_obj_inv);
      for(i = 0; i < TAILLE_INVENTAIRE; i++){
        //Si un objet est présent à l'indice i du tableau
        if(monde->joueur->inventaire[i].id != 0){
          //On sauvegarde son indice et le nombre d'objets possédés 1 si c'est une pièce d'équipement, 1 ou plus pour un consommable
          fprintf(fichier, "%d\n", i);
          fprintf(fichier, "%d\n", monde->joueur->inventaire[i].nb_obj);
        }
      }
      //On sauvegarde ke nombre d'objets équipés pour facilier le chargement
      fprintf(fichier, "%d\n", nb_obj_equip);
      for(i = 0; i < NB_EQUIPEMENT; i++){
        //Si une épée ou un bouclier est équipée
        if(monde->joueur->objet_equipe[i].id != 0){
          //On sauvegarde l'indice dans le tableau pour savoir si c'est une épée ou un bouclier
          //On sauvegarde aussi l'id de l'objet équipé
          fprintf(fichier, "%d\n", i);
          fprintf(fichier, "%d\n", monde->joueur->objet_equipe[i].id);
        }
      }
      //Sauvegarde du niveau du joueur et de la zone
      fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->niveau, monde->joueur->zone);

      //Sauvegarde des pv max et courrants
      fprintf(fichier, "%d\n%d\n", monde->joueur->combattant->pvMax, monde->joueur->combattant->pvCour);

      //Sauvegarde du mana max et courrant
      fprintf(fichier, "%d\n%d\n", monde->joueur->manaMax, monde->joueur->manaCour);

      //Sauvegarde de l'or
      fprintf(fichier, "%d\n", monde->joueur->or);

      //Sauvegarde de l'attaque
      fprintf(fichier, "%d\n", monde->joueur->combattant->attaque);

      //On ferme le fichier
      fclose(fichier);
    }
}
