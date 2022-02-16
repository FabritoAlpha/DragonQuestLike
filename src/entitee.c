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
  * \fn joueur_t creer_joueur()
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
  * \fn monstre_t creer_monstre()
  * \brief La fonction créer le joueur.
*/
monstre_t * creer_monstre(){
  monstre_t * monster;
  monster=malloc(sizeof(monstre_t));
  monster->combattant= malloc(sizeof(combattant_t));
  return monster;
}

/**
  * \fn void detruire_joueur(joueur_t ** player)
  * \brief La fonction détruire le joueur.
*/
void detruire_joueur(joueur_t ** player){
  free((*player)->combattant);
  free((*player)->inventaire);
  free((*player)->objet_equipe);
  free(*(player));
}
/**
  * \fn void detruire_monstre(monstre_t ** player)
  * \brief La fonction détruire le monstre.
*/
void detruire_monstre(monstre_t ** monster){
  free((*monster)->combattant);
  free(*(monster));

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
void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse, float x, float y,int niveau,int type){
  monster->combattant->pvMax=pvMax;
  monster->combattant->pvCour=pvCour;
  monster->combattant->attaque=attaque;
  monster->combattant->vitesse=vitesse;
  monster->combattant->x=x;
  monster->combattant->y=y;
  monster->combattant->niveau=niveau;
  monster->type=type;
}
