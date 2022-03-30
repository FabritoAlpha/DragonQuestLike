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
	*\param zone une zone du monde
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
  monde->num_menu_comb = MENU1;
}

void init_monde_jeu(monde_t * monde, char* chemin_fichier){
  int i; 
  int j_niveau; 
  int j_zone;
  int j_mana_max;
  int j_mana_cour;
  int j_pv_max;
  int j_pv_cour;
  int j_or;
  int j_attaque;
  int j_nb_obj_inv;
  int j_nb_obj_equip;
  //int obj_equipe[NB_EQUIPEMENT];
  //int obj_inv[TAILLE_INVENTAIRE]

  FILE * fichier;

  fichier = fopen(chemin_fichier,"r");
  fscanf(fichier,"%i", &j_niveau);
  fscanf(fichier,"%i", &j_zone);
  fscanf(fichier,"%i", &j_pv_max);
  fscanf(fichier,"%i", &j_pv_cour);
  fscanf(fichier,"%i", &j_mana_max);
  fscanf(fichier,"%i", &j_mana_cour);
  fscanf(fichier,"%i", &j_or);
  fscanf(fichier,"%i", &j_attaque);
  fscanf(fichier,"%i", &j_nb_obj_inv);

    for(i = 0; i < j_nb_obj_inv; i++){
        fscanf(fichier, "%i", &monde->joueur->inventaire[i].id);
    }
  fscanf(fichier,"%i", &j_nb_obj_equip);
  for(i = 0; i < j_nb_obj_equip; i++){
        fscanf(fichier, "%i", &monde->joueur->objet_equipe[i].id);
    }



  for(i = j_zone; i < NB_ZONES; i++){
    init_zone(monde->zones[i], i);

  }

  init_joueur(monde->joueur,j_niveau,j_zone,j_pv_max,j_pv_cour,j_mana_max,j_mana_cour,j_attaque,j_or,j_nb_obj_inv, j_nb_obj_equip);

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
    init_monstre(salle->monstres[i], 30, 30,100, 1,0,0);
  }
  if(num_salle == 0){
      int hauteur = 251;
      for(i = 0; i < NB_PERSO_SALLE; i++){
        init_nonCombattant(salle->perso[i], 0, 104, hauteur,0);
        hauteur = hauteur + 100;
      }
  }
  salle->difficulte = 0;
  salle->num_salle = num_salle;
  init_nonCombattant(salle->coffre, 0, 0, 0,0);
}
