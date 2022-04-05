/**
  * \file entite.h
  * \brief header des entités
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef entite_H
#define entite_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAILLE_INVENTAIRE 6
#define NB_EQUIPEMENT 2

//Type du combattant
#define JOUEUR 1
#define MONSTRE 0

//Type du monstre
#define BOSS 1
#define COMMUN 0

//Etat des monstres
#define VIVANT 1
#define MORT 0

//Id des objets
#define ID_EPEE_PIERRE 1
#define ID_EPEE_DIAM 2
#define ID_BOUCLIER_BOIS 3
#define ID_BOUCLIER_DIAM 4
#define ID_POTION_PV 6
#define ID_POTION_MANA 7

//Indice des objets dans le tableau inventaire/bilbiothèque des objets
#define INDICE_EPEE_PIERRE 0
#define INDICE_EPEE_DIAM 1
#define INDICE_BOUCLIER_BOIS 2
#define INDICE_BOUCLIER_DIAM 3
#define INDICE_POTION_PV 4
#define INDICE_POTION_MANA 5

//Indice des objets dans le tableau des objets équipés
#define INDICE_EPEE 0
#define INDICE_BOUCLIER 1

//Multiplicateur de dégâts lors de l'utilisation d'un SORT
#define PUISSANCE_MAGIQUE 1.5

/**
  * \struct combattant_t
  * \brief représentation d'une entité combattante
*/
typedef struct{
  int pvMax; /**< nombre de point de vie max */
  int pvCour; /**< nombre de point de vie actuels*/
  int attaque; /**< valeur de ses points d'attaques */
  int vitesse; /**< pas */
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
  int nb_obj; /**< quantité de l'objet */
  char* nom; /**< nom de l'objet */
  char* description; /**< description de l'objet */
} objet_t;

/**
  * \struct joueur_t
  * \brief représentation du joueur
*/
typedef struct{
  combattant_t* combattant; /**< points de vie et position */
  objet_t * inventaire; /**< objets en possession du joueur */
  objet_t * objet_equipe; /**< objets équipés par le joueur */
  int nb_obj_inventaire; /**< nombre d'objet dans l'inventaire du joueur */
  int nb_obj_equip; /**< nombre d'objets équipés par le joueur */
  int zone; /**< numéro de la zone où se trouve le joueur */
  int salle; /**< numéro de la salle où se trouve le joueur */
  int manaMax; /**< nombre de points de mana maximum que le joueur peut atteindre */
  int manaCour; /**< nombre de points de mana actuels du joeur */
  int or; /**< nombre de pièces d'or en possession du joueur */
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
  * \brief représentation d'une entité non combattante
*/
typedef struct{
  int id; /**< id des entités */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
  int visite; /**< 1: le joueur a déjà intéragi avec l'entité */
} nonCombattant_t;


void a_gauche(combattant_t* entite);

void a_droite(combattant_t* entite);

void en_bas(combattant_t* entite);

void en_haut(combattant_t* entite);

joueur_t * creer_joueur();

monstre_t * creer_monstre();

nonCombattant_t * creer_nonCombattant();

void init_joueur(joueur_t * joueur,int niveau, int zone, int pv_M, int pv_C, int mana_M, int mana_C, int atk, int or, int nb_inv, int nb_equip);

void init_monstre(monstre_t * monster, int pvMax, int attaque, int vitesse, int niveau,int type);

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

void consommer_potion(joueur_t * joueur, int indice_obj);

void reinitialiser_joueur(joueur_t * joueur, objet_t * biblio);

#endif
