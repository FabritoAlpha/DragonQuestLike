/**
  * \file entitee.c
  * \brief Contient les fonctions liées aux entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
#include <stdio.h>
#include  "../lib/entitee.h"

/**
  * \fn void a_gauche(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à gauche selon un pas.
*/
void a_gauche(combattant_t * entitee){
    entitee->x = (entitee->x)-entitee->vitesse;
}
/**
  * \fn void a_droite(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à droite selon un pas.
*/
void a_droite(combattant_t* entitee){
    entitee->x = (entitee->x)+entitee->vitesse;
}
/**
  * \fn void en_bas(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en bas selon un pas.
*/
void en_bas(combattant_t* entitee){
    entitee->y = (entitee->y)+entitee->vitesse;
}
/**
  * \fn void en_haut(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en haut selon un pas.
*/
void en_haut(combattant_t* entitee){
    entitee->y = (entitee->y)-entitee->vitesse;
}


/**
  * \fn joueur_t * creer_joueur()
  * \brief La fonction créer le joueur.
*/
joueur_t * creer_joueur(){
    joueur_t * player;
    player = malloc(sizeof(joueur_t));
    player->combattant= malloc(sizeof(combattant_t));

    player->inventaire= malloc(sizeof(int)*TAILLE_INVENTAIRE);

    player->objet_equipe=malloc(sizeof(int)*NB_EQUIPEMENT);

    return player;
}

/**
  * \fn monstre_t * creer_monstre()
  * \brief La fonction créer le joueur.
*/
monstre_t * creer_monstre(){
  monstre_t * monster;
  monster=malloc(sizeof(monstre_t));
  monster->combattant= malloc(sizeof(combattant_t));
  return monster;
}

/**
  * \fn nonCombattant_t * creer_nonCombattant()
  * \brief La fonction créer une entitée non combattante.
*/

nonCombattant_t * creer_nonCombattant(){
  nonCombattant_t * nonCombat;
  nonCombat = malloc(sizeof(nonCombattant_t));
  return(nonCombat);
}

/**
  * \fn void detruire_joueur(joueur_t ** player)
  * \brief La fonction détruire le joueur.
*/
void detruire_joueur(joueur_t ** player){
  int i;
  free((*player)->combattant);
  (*player)->combattant=NULL;
  for(i=0;i<TAILLE_INVENTAIRE;i++){
    free((*player)->inventaire[i]);
    (*player)->inventaire[i]=NULL;
  }
  free((*player)->inventaire);
  (*player)->inventaire=NULL;
  for(i=0;i<NB_EQUIPEMENT;i++){
    free((*player)->objet_equipe[i]);
    (*player)->objet_equipe[i]=NULL;
  }
  free((*player)->objet_equipe);
  (*player)->objet_equipe=NULL;
  free(*(player));
  (*player)=NULL;
}
/**
  * \fn void detruire_monstre(monstre_t ** player)
  * \brief La fonction détruire le monstre.
*/
void detruire_monstre(monstre_t ** monster){
  free((*monster)->combattant);
  (*monster)->combattant=NULL;
  free(*monster);
  (*monster)=NULL;

}
/**
  * \fn void detruire_nonCombattant(nonCombattant_t ** nonCombat)
  * \brief La fonction détruire un nonCombattant.
*/
void detruire_nonCombattant(nonCombattant_t ** nonCombat){
  free(*nonCombat);
  (*nonCombat)=NULL;
}

/**
  * \fn void init_joueur(joueur_t* joueur, int pvMax, int pvCour, int attaque, int vitesse, int x, int y)
  * \param joueur entitée à initialiser.
  * \param pvMax entitée à initialiser.
  * \param pvCour entitée à initialiser.
  * \param attaque entitée à initialiser.
  * \param vitesse entitée à initialiser.
  * \param x entitée à initialiser.
  * \param y entitée à initialiser.
  * \brief Initialisation du joueur avec des parametres.
*/
void init_joueur(joueur_t * joueur, int pvMax, int pvCour, int attaque, int vitesse, float x, float y,int niveau){
  joueur->combattant->pvMax=pvMax;
  joueur->combattant->pvCour=pvCour;
  joueur->combattant->attaque=attaque;
  joueur->combattant->vitesse=vitesse;
  joueur->combattant->x=x;
  joueur->combattant->y=y;
  joueur->combattant->niveau=niveau;
}

/**
  * \fn void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse, float x, float y,int niveau)
  * \param monstre entitée à initialiser.
  * \param pvMax entitée à initialiser.
  * \param pvCour entitée à initialiser.
  * \param attaque entitée à initialiser.
  * \param vitesse entitée à initialiser.
  * \param x entitée à initialiser.
  * \param y entitée à initialiser.
  * \brief Initialisation du monstre avec des parametres.
*/
void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse,int niveau,int type){
  monster->combattant->pvMax=pvMax;
  monster->combattant->pvCour=pvCour;
  monster->combattant->attaque=attaque;
  monster->combattant->vitesse=vitesse;
  monster->combattant->x=500;
  monster->combattant->y=250;
  monster->combattant->niveau=niveau;
  monster->type=type;
  monster->xref=500;
  monster->yref=250;
  monster->dir=-1;
  monster->dist=-1;
}


/**
  * \fn void init_nonCombattant(nonCombattant_t * nonCombat, int id, float x, float y,int visite)
  * \param nonCombat entitée à initialiser.
  * \param x entitée à initialiser.
  * \param y entitée à initialiser.
  * \param visite entitée à initialiser.
  * \brief Initialisation du nonCombattant avec des parametres.
*/
void init_nonCombattant(nonCombattant_t * nonCombat, int id, float x, float y,int visite){
  nonCombat->id=id;
  nonCombat->x=x;
  nonCombat->y=y;
  nonCombat->visite=visite;
}
/**
  * \fn void deplacement_monstre(monstre_t * monstre)
  * \param montre à déplacer.
  * \brief Déplacement d'un monstre.
  *
  *
*/
//int direction = rand()%4;
//printf("%d\n",direction);
void deplacement_monstre(monstre_t * monstre){
  //printf("X%f \n",monstre->combattant->x);
  //printf("Y%f \n",monstre->combattant->y);
  //printf("Xref %d \n",monstre->xref);
  //printf("Yref %d \n",monstre->yref);
  int direction;
  int distance;
  int dist_min=10;
  int dist_max=50;

  if(monstre->dir==-1){
    printf("dedans\n************\n");
    direction=rand()%4;
    do{distance=rand()%300;}while(distance<dist_min||distance>dist_max);
    monstre->dir=direction;
    monstre->dist=distance;
    printf("monstre dir %d \n",monstre->dir);
    printf("distance %d\n",monstre->dist);
  }
  //printf("distance: %d\n",distance);
  if(monstre->dir==0 && (monstre->combattant->x)>(monstre->xref-monstre->dist)){ // Si le monstre va à gauche
    a_gauche(monstre->combattant);
    if((monstre->combattant->x)<=(monstre->xref-monstre->dist)){
      do{direction=rand()%4;}while(direction==1);
      do{distance=rand()%300;}while(distance<dist_min||distance>dist_max);
      monstre->xref=monstre->combattant->x;
      monstre->dir=direction;
    }
  }
  if(monstre->dir==1 && (monstre->combattant->x)<(monstre->xref+monstre->dist)){ // Si le monstre va à droite
    a_droite(monstre->combattant);
    if((monstre->combattant->x)>=(monstre->xref+monstre->dist)){
      do{direction=rand()%4;}while(direction==0);
      do{distance=rand()%300;}while(distance<dist_min||distance>dist_max);
      monstre->xref=monstre->combattant->x;
      monstre->dir=direction;

    }
  }
  if(monstre->dir==2 && (monstre->combattant->y)>(monstre->yref-monstre->dist)){ // Si le monstre va en haut
    en_haut(monstre->combattant);
    if((monstre->combattant->y)<=(monstre->yref-monstre->dist)){
      do{direction=rand()%4;}while(direction==3);
      do{distance=rand()%300;}while(distance<dist_min||distance>dist_max);
      monstre->yref=monstre->combattant->y;
      monstre->dir=direction;
    }
  }
  if(monstre->dir==3 && (monstre->combattant->y)<(monstre->yref+monstre->dist)){ // Si le monstre va en bas
    en_bas(monstre->combattant);
    if((monstre->combattant->y)>=(monstre->yref+monstre->dist)){
      do{direction=rand()%4;}while(direction==2);
      do{distance=rand()%300;}while(distance<dist_min||distance>dist_max);
      monstre->yref=monstre->combattant->y;
      monstre->dir=direction;
    }
  }
}
