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

/**
  * \fn joueur_t creer_joueur()
  * \brief La fonction créer le joueur.
*/
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
void init_joueur(joueur_t* joueur, int pvMax, int pvCour, int attaque, int vitesse, int x, int y){
  joueur->combattant->pvMax=pvMax;
  joueur->combattant->pvCour=pvCour;
  joueur->combattant->attaque=attaque;
  joueur->combattant->vitesse=vitesse;
  joueur->combattant->x=x;
  joueur->combattant->y=y;
  joueur->combattant->niveau=1;
}
