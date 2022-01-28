/**
  * \file entitee.c
  * \brief Contient les fonctions liées aux entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
#include  "../lib/entitee.h"

/**
  * \fn void a_gauche(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à gauche selon un pas.
*/
void a_gauche(combattant * entitee){
    combattant->x = (combattant->x)-conbattant->vitesse;
}
/**
  * \fn void a_droite(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à droite selon un pas.
*/
void a_droite(combattant_t* entitee){
    combattant->x = (combattant->x)+conbattant->vitesse;
}
/**
  * \fn void en_bas(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en bas selon un pas.
*/
void en_bas(combattant_t* entitee){
    combattant->y = (combattant->y)+conbattant->vitesse;
}
/**
  * \fn void en_haut(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en haut selon un pas.
*/
void en_haut(combattant_t* entitee){
    combattant->y = (combattant->y)-conbattant->vitesse;
}

int niveau
joueur_t creer_joueur(){
    joueur_t * player = NULL;
    player = malloc(sizeof(joueur_t));
    player->combattant= malloc(sizeof(combattant_t));
    player->combattant=NULL;
    player->inventaire= malloc(sizeof(int)*TAILLE_INVENTAIRE);
    player->inventaire=NULL;
    player->objet_equipe=malloc(sizeof(int)*NB_EQUIPEMENT);
    player->objet_equipe=NULL;
    return player;
}

void init_joueur(joueur_t* joueur, int pv, int attaque, int vitesse, int x, int y){
  joueur->combattant->pv=pv;
  joueur->combattant->attaque=attaque;
  joueur->combattant->vitesse=vitesse;
  joueur->combattant->x=x;
  joueur->combattant->y=y;
  joueur->combattant->niveau=1;
}