/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#ifndef _MONDE_H
#define _MONDE_H

#include <stdlib.h>
#include <stdio.h>
#include "entitee.h"

#define NB_SALLES 2;
#define NB_ZONES 1;

/**
	*\struct salle_t
	*\brief représentation d'une salle
*/
typedef struct{
	monstre_t ** monstres; /**< Liste des monstres de la salle (peut être vide)*/
	int nb_monstres; /**< Nombre de monstres que contient la salle */
	nonCombattant_t ** coffre; /**< Liste des coffres de la salle (peut être vide)*/
	nonCombattant_t ** persos;/**< Liste des personnages non joueurs de la salle (peut être vide) */
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
} monde_t;

/**
	*\fn void creer_monde(monde_t *)
	*\brief allocation de la mémoire nécessaire au monde
	*\param monde environnement global du jeu
*/
void creer_monde(monde_t * monde);

/**
	*\fn void creer_zone(zone_t *)
	*\brief allocation de la mémoire nécessaire à une zone
	*\param zone une zone du monde
*/
void creer_zone(zone_t * zone);

/**
	*\fn void creer_salle(salle_t *)
	*\brief allocation de la mémoire nécessaire à une salle
	*\param zone une salle d'une zone
*/
void creer_salle(salle_t * salle);

/**
	*\fn void detruire_monde(monde_t **)
	*\brief libération de la mémoire allouée au monde lorsque la partie est terminée
	*\param monde environnement global du jeu
*/
void detruire_monde(monde_t ** monde);

/**
	*\fn void detruire_zone(zone_t **)
	*\brief libération de la mémoire allouée à une zone du monde lorsque la partie est terminée
	*\param monde une zone du monde
*/
void detruire_zone(zone_t ** zone);

/**
	*\fn void detruire_salle(salle_t **)
	*\brief libération de la mémoire allouée à une salle d'une zone lorsque la partie est terminée
	*\param monde une salle d'une zone
*/
void detruire_salle(salle_t ** salle);

/**
	*\fn void init_monde(monde_t *)
	*\brief initialisation du monde
	*\param monde environnement global du jeu
*/
void init_monde(monde_t * monde);

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
void init_salle(salle_t * salle, int num_salle);

#endif