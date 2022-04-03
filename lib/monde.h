/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#ifndef _MONDE_H
#define _MONDE_H

#include "sdl2_fonctions.h"
#include "entitee.h"

//Numéro du menu lors du combat
#define MENU1 1
#define MENU2 2

//Valeurs représentants l'état de la partie
#define VICTOIRE 1
#define PARTIE_EN_COURS 0

//Nombre de zones et de salles du monde
#define NB_SALLES 4
#define NB_ZONES 3

//Etat possible pour le jeu
#define ETAT_MENU_1 0
#define ETAT_COMBAT 12
#define ETAT_DIALOGUE 22
#define ETAT_COFFRE 21
#define ETAT_AIDE 23
#define ETAT_INVENTAIRE 3
#define ETAT_QUITTER -1
#define ETAT_MENU_2 4
#define ETAT_JEU_PRINCIPAL 1
#define ETAT_VICTOIRE 5

#define NB_MONSTRES_SALLE 1
#define NB_PERSO_SALLE 2


#define SCREEN_WIDTH 1000.0
#define SCREEN_HEIGHT 750.0
#define STATUE 0

#define HAUTEUR_PERSONNAGE 60.0
#define LARGEUR_PERSONNAGE 45.0

#define HAUTEUR_COFFRE 60.0
#define LARGEUR_COFFRE 45.0

#define ENTREE_HAUT_SALLE_1 (SCREEN_HEIGHT / 2 - 100)
#define ENTREE_BAS_SALLE_1 (SCREEN_HEIGHT / 2 + 100)

#define ENTREE_GAUCHE_ZONE_SUIVANTE (SCREEN_WIDTH / 2 - 100)
#define ENTREE_DROITE_ZONE_SUIVANTE (SCREEN_WIDTH / 2 + 100)

/**
	*\struct salle_t
	*\brief représentation d'une salle
*/
typedef struct{
	monstre_t * monstre; /**< Liste des monstres de la salle (peut être vide)*/
	//int nb_monstres; /**< Nombre de monstres que contient la salle */
	nonCombattant_t * coffre; /**< coffre de la salle (peut être vide)*/
	nonCombattant_t ** perso;/**< Liste des personnages non joueurs de la salle (peut être vide) */
	int difficulte;/**< Entier qui représente le niveau de difficulté de la salle */
	int num_salle; /**< Numéro de la salle dans la zone */
	//int largeur; à voir si on en a besoin
	//int longueur; à voir si on en a besoin
} salle_t;

/**
	*\struct zonne_t
	*\brief représentation d'une zone
*/
typedef struct{
	salle_t ** salles; /**< Liste des salles de la zone (ne peut pas être vide durant la partie)*/
	int num_zone; /**< Numéro de la zone dans le monde */
	int id; /**< Entier représentant le type de la zone : 1-Ville, 2-Plaine, 3-Donjon, ... */
} zone_t;

/**
	*\struct zone_t
	*\brief représentation d'une zone
*/
typedef struct{
	zone_t ** zones; /**< Liste des zones composant le monde */
	joueur_t* joueur; /**< joueur */
	int etat_jeu; /**< état du jeu: 0 menu, 1 jeu en cours, -1 fin de la boucle du jeu */
	int option; /**< option a sélectionner */
	int option2; /**<option 2 pour sous menus */
	int partie; /**< partie jouée, à charger et sauvegarder*/
	int num_menu_comb; /**< Numéro du menu du combat */
	objet_t biblio_objet[TAILLE_INVENTAIRE]; /**< Bibliothèque contenant chaque objet du monde*/
} monde_t;

int existe_salle(salle_t* salle);
int existe_zone(zone_t* zone);
int existe_monde(monde_t* monde);

salle_t* creer_salle();
zone_t * creer_zone();
monde_t * creer_monde();


void detruire_monde(monde_t ** monde);
void detruire_zone(zone_t ** zone);
void detruire_salle(salle_t ** salle);

/**
	*\fn void init_monde(monde_t * monde, FILE* fichier_sauvegarde)
	*\brief initialisation du monde
	*\param monde environnement global du jeu
	*\param fichier_sauvegarde fichier avec les données d'initialisation
*/
void init_monde_menu(monde_t * monde);
void init_monde_jeu(monde_t * monde, char* chemin_fichier);

/**
	*\fn void init_zone(zone_t * zone, int num_zone)
	*\brief initialisation d'une zone du monde
	*\param zone une zone du monde
	*\param num_zone numéro de la zone du monde
*/
void init_zone(zone_t * zone, int num_zone);

/**
	*\fn void init_salle(salle_t * salle, int num_salle)
	*\brief initialisation d'une salle d'une zone
	*\param salle une salle d'une zone
	*\param num_salle numéro de la salle de la zone
*/
void init_salle(salle_t * salle, int num_salle, int num_zone);

void deplacement_monstre(monstre_t * monstre, monde_t * m);
int victoire_jeu(monde_t * monde);
#endif
