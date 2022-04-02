/**
  * \file entitee.h
  * \brief header des entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
#ifndef ENTITEE_H
#define ENTITEE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAILLE_INVENTAIRE 6
#define NB_EQUIPEMENT 2

//Type du combattant
#define JOUEUR 1
#define MONSTRE 0

//Etat des monstres
#define VIVANT 1
#define MORT 0



/**
  * \struct combattant_t
  * \brief représentation d'une entitee combattante
*/
typedef struct{
  int pvMax; /**< nombre de point de vie max */
  int pvCour; /**< nombre de point de vie actuelle*/
  int attaque; /**< valeur de ses points d'attaques */
  int vitesse;
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
  int niveau; /**< niveau du combattant */
  int type; /**< type du combattant: monstre ou joueur*/
} combattant_t;

/**
  * \struct objet_t
  * \brief représentation d'un objet
*/
typedef struct{
  int id; /**< id de l'objet */
  int attaque_sup; /**< attaque de l'objet */
  int mana_sup; /**< mana de l'objet */
  int vie_sup; /**< vie de l'objet */
  int nb_obj;
  char* nom; /**< nom de l'objet */
  char* description; /**< description de l'objet */
} objet_t;


/**
  * \struct joueur_t
  * \brief représentation du joueur
*/
typedef struct{
  combattant_t* combattant; /**< points de vie et position */
  objet_t * inventaire; /**< id des objets en possession du joueur */
  objet_t * objet_equipe; /**< id des objets équipés par le joueur */
  int nb_obj_inventaire;
  int nb_obj_equip;
  int zone;
  int salle;
  int manaMax;
  int manaCour;
  int or;
}joueur_t;

/**
  * \struct monstre_t
  * \brief représentation d'un monstre
*/
typedef struct{
  combattant_t* combattant; /**< points de vie et position */
  int type; /**< correspond à son type 0=normal 1=boss */
  int x;
  int y;
  int dir;
  int dist;
  int etat; /**< Correspond à l'état du monstre: vivant ou mort*/
  int agro;
} monstre_t;

/**
  * \struct nonCombattant_t
  * \brief représentation d'une entitee non combattante
*/
typedef struct{
  int id; /**< id des entités coffre: 0, pnj n°1: 1, pnj n°2: 2 */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
  int visite; /**< 1: le joueur a déjà intéragi avec l'entité */
} nonCombattant_t;

/**
  * \fn void a_gauche(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à gauche selon un PAS.
*/
void a_gauche(combattant_t* entitee);
/**
  * \fn void a_droite(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à droite selon un PAS.
*/
void a_droite(combattant_t* entitee);
/**
  * \fn void en_bas(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en bas selon un PAS.
*/
void en_bas(combattant_t* entitee);
/**
  * \fn void en_haut(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en haut selon un PAS.
*/
void en_haut(combattant_t* entitee);

joueur_t * creer_joueur();

monstre_t * creer_monstre();

nonCombattant_t * creer_nonCombattant();

void init_joueur(joueur_t * joueur,int niveau, int zone, int pv_M, int pv_C, int mana_M, int mana_C, int atk, int or, int nb_inv, int nb_equip);

void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse, int niveau,int type);

void init_nonCombattant(nonCombattant_t* nonCombattant, int id, float x, float y,int visite);

void detruire_joueur(joueur_t ** player);

void detruire_monstre(monstre_t ** monster);

void detruire_nonCombattant(nonCombattant_t ** nonCombat);

objet_t * creer_objet();

objet_t * objet_initialiser(objet_t * objet,int id,int attaque_sup, int mana_sup,int vie_sup,char*nom,char*description);

void detruire_objet(objet_t**objet);

void initialiser_biblio(objet_t tableau[]);

int objet_present(joueur_t* joueur, objet_t* biblio, int ind);

void ajout_objet(joueur_t* joueur,  objet_t* biblio, int ind);

void equipement_desequipement_objet(joueur_t * joueur, int i_tab_inv, int i_obj_equipe);





#endif
