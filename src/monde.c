/**
  * \file monde.c
  * \brief fonctions de gestion du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>
#include "../lib/monde.h"

/**
	*\fn int existe_salle(salle_t* salle)
	*\brief renvoie 1 si la salle existe
	*\param salle salle à tester
*/
int existe_salle(salle_t* salle){
    if(salle == NULL)
        return 0;
    return 1;
}

/**
	*\fn int existe_zone(zone_t* zone)
	*\brief renvoie 1 si la zone existe
	*\param zone zone à tester
*/
int existe_zone(zone_t* zone){
    if(zone == NULL)
        return 0;
    return 1;
}

/**
	*\fn int existe_monde(monde_t* monde)
	*\brief renvoie 1 si le monde existe
	*\param monde monde à tester
*/
int existe_monde(monde_t* monde){
    if(monde == NULL)
        return 0;
    return 1;
}

/**
	*\fn salle_t* creer_salle()
	*\brief allocation de la mémoire nécessaire à une salle
	*\return un pointeur sur un salle
*/
salle_t * creer_salle(){
    salle_t * salle;
    salle = malloc(sizeof(salle_t));
    salle->monstres = malloc(sizeof(monstre_t)*NB_MONSTRES_SALLE);
    salle->coffre = malloc(sizeof(nonCombattant_t));
    salle->perso = malloc(sizeof(nonCombattant_t)*NB_PERSO_SALLE);
    return salle;
}

/**
	*\fn zone_t * creer_zone()
	*\brief allocation de la mémoire nécessaire à une zone
	*\return un pointeur sur une zone
*/
zone_t * creer_zone(){
    zone_t * zone;
    zone = malloc(sizeof(zone_t));
    for(int i = 0; i < NB_SALLES; i++){
        zone->salles[i] = creer_salle();
    }
    return zone;
}

/**
	*\fn monde_t * creer_monde()
	*\brief allocation de la mémoire nécessaire au monde
	*\return un pointeur sur un monde
*/
monde_t * creer_monde(){
    monde_t * monde;
    monde = malloc(sizeof(monde_t));
    for(int i = 0; i < NB_ZONES; i++){
        monde->zones[i] = creer_zone();
    }
    return monde;
}

/**
	*\fn void detruire_monde(monde_t **)
	*\brief libération de la mémoire allouée au monde lorsque la partie est terminée
	*\param monde environnement global du jeu
*/
void detruire_monde(monde_t ** monde){
    for(int i = 0; i < NB_ZONES; i++){
        detruire_zone(&((*monde)->zones[i]));
    }
    free((*monde));
    (*monde) = NULL;
}

/**
	*\fn void detruire_zone(zone_t **)
	*\brief libération de la mémoire allouée à une zone du monde lorsque la partie est terminée
	*\param monde une zone du monde
*/
void detruire_zone(zone_t ** zone){
    for(int i = 0; i < NB_SALLES; i++){
        detruire_salle(&(*zone)->salles[i]);
    }
    free((*zone));
    (*zone) = NULL;
}

/**
	*\fn void detruire_salle(salle_t **)
	*\brief libération de la mémoire allouée à une salle d'une zone lorsque la partie est terminée
	*\param salle une salle d'une zone
*/
void detruire_salle(salle_t ** salle){
    int i;
    free((*salle)->coffre);
    (*salle)->coffre = NULL;
    for(i = 0; i < NB_MONSTRES_SALLE; i++){
        free((*salle)->monstres[i]);
        (*salle)->monstres[i] = NULL;
    }
    for(i = 0; i < NB_PERSO_SALLE; i++){
        free((*salle)->perso[i]);
        (*salle)->monstres[i] = NULL;
    }
    free((*salle));
    (*salle) = NULL;
}

void init_monde(monde_t * monde){

}

void init_zone(zone_t * zone, int num_zone){

}

void init_salle(salle_t * salle, int num_salle){

}
