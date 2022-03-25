/**
  * \file monde.c
  * \brief fonctions de gestion du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

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
    int i;
    salle_t * salle;
    salle = malloc(sizeof(salle_t));

    salle->monstres = malloc(sizeof(monstre_t) * NB_MONSTRES_SALLE);
    for(i = 0; i < NB_MONSTRES_SALLE; i++){
        salle->monstres[i] = creer_monstre();
    }

    salle->perso = malloc(sizeof(monstre_t) * NB_PERSO_SALLE);
    for(i = 0; i < NB_PERSO_SALLE; i++){
        salle->perso[i] = creer_nonCombattant();
    }

    salle->coffre = creer_nonCombattant();
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
    zone->salles = malloc(sizeof(salle_t) * NB_SALLES);
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
    monde_t* monde;
    monde = malloc(sizeof(monde_t));
    monde->zones = malloc(sizeof(zone_t) * NB_ZONES);
    for(int i = 0; i < NB_ZONES; i++){
        monde->zones[i] = creer_zone();
    }
    monde->joueur = creer_joueur();
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

    free((*monde)->zones);
    (*monde)->zones = NULL;

    detruire_joueur(&(*monde)->joueur);

    free(*monde);
    (*monde) = NULL;
}

/**
	*\fn void detruire_zone(zone_t **)
	*\brief libération de la mémoire allouée à une zone du monde lorsque la partie est terminée
	*\param monde une zone du monde
*/
void detruire_zone(zone_t ** zone){
    for(int i = 0; i < NB_SALLES; i++){
        detruire_salle(&((*zone)->salles[i]));
    }

    free((*zone)->salles);
    (*zone)->salles = NULL;

    free(*zone);
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
        detruire_monstre(&(*salle)->monstres[i]);
    }
    if((*salle)->num_salle == 0){
        for(i = 0; i < NB_PERSO_SALLE; i++){
            detruire_nonCombattant(&(*salle)->perso[i]);
        }
    }
    free((*salle)->monstres);
    (*salle)->monstres = NULL;

    free((*salle)->perso);
    (*salle)->perso= NULL;

    free(*salle);
    (*salle) = NULL;
}

void init_monde_menu(monde_t * monde){
  monde->etat_jeu = 0;
  monde->option = 1;
  monde->option2 = 0;
}

void init_monde_jeu(monde_t * monde, char* chemin_fichier){
  int i; int j_niveau; int j_zone;
  FILE * fichier;

  fichier = fopen(chemin_fichier,"r");
  fscanf(fichier,"%i", &j_niveau);
  fscanf(fichier,"%i", &j_zone);

  for(i = j_zone; i < NB_ZONES; i++){
    init_zone(monde->zones[i], i);

  }

  fscanf(fichier,"%i", &j_niveau);
  fscanf(fichier,"%i", &j_zone);

  init_joueur(monde->joueur,j_niveau,j_zone);

  fclose(fichier);
}

void init_zone(zone_t * zone, int num_zone){
  int i;

  zone->num_zone = num_zone;
  for(i = 0; i < NB_SALLES; i++){

    init_salle(zone->salles[i], i);

  }
}

void init_salle(salle_t * salle, int num_salle){
  int i;
  for(i = 0; i < NB_MONSTRES_SALLE; i++){
    init_monstre(salle->monstres[i], 0, 0, 0, 1,0,0);
  }
  if(num_salle == 0){
      int hauteur = 200;
      for(i = 0; i < NB_PERSO_SALLE; i++){
        init_nonCombattant(salle->perso[i], 0, 100, hauteur,0);
        hauteur = hauteur + 100;
      }
  }
  salle->difficulte = 0;
  salle->num_salle = num_salle;
  init_nonCombattant(salle->coffre, 0, 0, 0,0);
}
