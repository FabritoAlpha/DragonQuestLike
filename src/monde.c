/**
  * \file monde.c
  * \brief fonctions de gestion du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#include "../lib/monde.h"


/**
	* \fn int existe_salle(salle_t* salle)
	* \brief renvoie 1 si la salle existe
	* \param salle salle à tester
*/
int existe_salle(salle_t* salle){
    if(salle == NULL)
        return 0;
    return 1;
}

/**
	* \fn int existe_zone(zone_t* zone)
	* \brief renvoie 1 si la zone existe
	* \param zone zone à tester
*/
int existe_zone(zone_t* zone){
    if(zone == NULL)
        return 0;
    return 1;
}

/**
	* \fn int existe_monde(monde_t* monde)
	* \brief renvoie 1 si le monde existe
	* \param monde monde à tester
*/
int existe_monde(monde_t* monde){
    if(monde == NULL)
        return 0;
    return 1;
}

/**
	* \fn salle_t* creer_salle()
	* \brief allocation de la mémoire nécessaire à une salle
	* \return un pointeur sur une salle
*/
salle_t * creer_salle(){
    int i;
    salle_t * salle;
    salle = malloc(sizeof(salle_t));

    salle->monstre = malloc(sizeof(monstre_t));

    salle->monstre = creer_monstre();

    salle->perso = malloc(sizeof(monstre_t) * NB_PERSO_SALLE);
    for(i = 0; i < NB_PERSO_SALLE; i++){
        salle->perso[i] = creer_nonCombattant();
    }

    salle->coffre = creer_nonCombattant();
    return salle;
}

/**
	* \fn zone_t * creer_zone()
	* \brief allocation de la mémoire nécessaire à une zone
	* \return un pointeur sur une zone
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
	* \fn monde_t * creer_monde()
	* \brief allocation de la mémoire nécessaire au monde
	* \return un pointeur sur un monde
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
	* \fn void detruire_monde(monde_t **)
	* \brief libération de la mémoire allouée au monde lorsque la partie est terminée
	* \param monde environnement global du jeu
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
	* \fn void detruire_zone(zone_t **)
	* \brief libération de la mémoire allouée à une zone du monde lorsque la partie est terminée
	* \param zone une zone du monde
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
	* \fn void detruire_salle(salle_t **)
	* \brief libération de la mémoire allouée à une salle d'une zone lorsque la partie est terminée
	* \param salle une salle d'une zone
*/
void detruire_salle(salle_t ** salle){
    int i;

    free((*salle)->coffre);
    (*salle)->coffre = NULL;

    detruire_monstre(&((*salle)->monstre));

    if((*salle)->num_salle == 0){
        for(i = 0; i < NB_PERSO_SALLE; i++){
            detruire_nonCombattant(&(*salle)->perso[i]);
        }
    }
    free((*salle)->monstre);
    (*salle)->monstre = NULL;

    free((*salle)->perso);
    (*salle)->perso= NULL;

    free(*salle);
    (*salle) = NULL;
}

/**
	* \fn void init_monde_menu(monde_t * monde)
	* \brief initialise les attributs du monde nécessaires au menu
	* \param monde le monde
*/
void init_monde_menu(monde_t * monde){
  monde->etat_jeu = ETAT_MENU_1;
  monde->option = 1;
  monde->option2 = 0;
  monde->num_menu_comb = MENU1;
}

/**
	* \fn void init_monde_jeu(monde_t * monde, char* chemin_fichier)
	* \brief initialise les attributs du monde nécessaires au jeu
	* \param monde le monde
  * \param chemin_fichier le chemin du fichier de chargement de partie
*/
void init_monde_jeu(monde_t * monde, char* chemin_fichier){
  int i;
  int j;

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
  int indice_tab_inv;

  FILE * fichier;

  fichier = fopen(chemin_fichier,"r");
  fscanf(fichier,"%i", &j_nb_obj_inv);

    for(i = 0; i < j_nb_obj_inv; i++){
        fscanf(fichier, "%i", &indice_tab_inv);
        ajout_objet(monde->joueur, monde->biblio_objet ,indice_tab_inv);
        fscanf(fichier, "%i", &monde->joueur->inventaire[indice_tab_inv].nb_obj);
    }

    fscanf(fichier,"%i", &j_nb_obj_equip);
    for(i = 0; i < j_nb_obj_equip; i++){
          fscanf(fichier, "%i", &monde->joueur->objet_equipe[i].id);
          fscanf(fichier, "%i", &monde->joueur->objet_equipe[i].nb_obj);
    }

  fscanf(fichier,"%i", &j_niveau);
  fscanf(fichier,"%i", &j_zone);
  fscanf(fichier,"%i", &j_pv_max);
  fscanf(fichier,"%i", &j_pv_cour);
  fscanf(fichier,"%i", &j_mana_max);
  fscanf(fichier,"%i", &j_mana_cour);
  fscanf(fichier,"%i", &j_or);
  fscanf(fichier,"%i", &j_attaque);





  for(i = j_zone; i < NB_ZONES; i++){
    init_zone(monde->zones[i], i);
  }

  init_joueur(monde->joueur,j_niveau,j_zone,j_pv_max,j_pv_cour,j_mana_max,j_mana_cour,j_attaque,j_or,j_nb_obj_inv, j_nb_obj_equip);
    printf("On ne plante avant la copie de l'inventaire\n");
    //On copie les informations des objets dans le tableau de l'inventaire du joueur
    /*for(i = 0; i < TAILLE_INVENTAIRE; i++){
        for(j = i; j == i; j++){
            printf("j = %d\n", j);
            if(monde->joueur->inventaire[i].id == monde->biblio_objet[j].id){
                //SI les objets ont le même id, copie les informations de l'objet dans le tableau du joueur

                monde->joueur->inventaire[i].nom = malloc(sizeof(char)*20);
                monde->joueur->inventaire[i].description = malloc(sizeof(char)*50);
                strcpy(monde->joueur->inventaire[i].nom, monde->biblio_objet[j].nom);
                printf("nom biblio : %s\n", monde->biblio_objet[j].nom);
                printf("nom inv : %s\n", monde->joueur->inventaire[i].nom);
                strcpy(monde->joueur->inventaire[i].description, monde->biblio_objet[j].description);
                printf("desc biblio : %s\n", monde->biblio_objet[j].description);
                printf("desc inv : %s\n", monde->joueur->inventaire[i].description);
                monde->joueur->inventaire[i].attaque_sup = monde->joueur->inventaire[j].attaque_sup;
                monde->joueur->inventaire[i].vie_sup = monde->joueur->inventaire[j].vie_sup;
                monde->joueur->inventaire[i].mana_sup = monde->joueur->inventaire[j].mana_sup;
            }
        }
    }*/
    printf("On ne plante pas après la copie de l'inventaire\n");

    //On fait la même chose pour le tableau des objets équipés
    for(i = 0; i < j_nb_obj_equip; i++){
        for(j = 0; j < TAILLE_INVENTAIRE - 2; j++){
            if(monde->joueur->objet_equipe[i].id == monde->biblio_objet[j].id){
                //SI les objets ont le même id, copie les informations de l'objet dans le tableau du joueur
                monde->joueur->objet_equipe[i].nom = malloc(sizeof(char)*20);
                monde->joueur->objet_equipe[i].description = malloc(sizeof(char)*50);
                monde->joueur->objet_equipe[i].attaque_sup = monde->biblio_objet[j].attaque_sup;
                monde->joueur->objet_equipe[i].mana_sup = monde->biblio_objet[j].mana_sup;
                monde->joueur->objet_equipe[i].vie_sup = monde->biblio_objet[j].vie_sup;
                strcpy(monde->joueur->objet_equipe[i].nom, monde->biblio_objet[j].nom);
                strcpy(monde->joueur->objet_equipe[i].description, monde->biblio_objet[j].description);
                printf("On a copié un item de l'inventaire equipe\n");
            }
        }
    }

  fclose(fichier);
}

/**
	* \fn void init_zone(zone_t * zone, int num_zone)
	* \brief initialise une zone
	* \param zone la zone à initialiser
  * \param num_zone le numéro de la zone
*/
void init_zone(zone_t * zone, int num_zone){
  int i;

  zone->num_zone = num_zone;
  for(i = 0; i < NB_SALLES; i++){

    init_salle(zone->salles[i], i, num_zone);

  }
}

/**
	* \fn void init_salle(salle_t * salle, int num_salle, int num_zone)
	* \brief initialise une salle
	* \param salle la salle à initialiser
  * \param num_salle le numéro de la salle
*/
void init_salle(salle_t * salle, int num_salle, int num_zone){
  int i;

  //Si on est dans la dernière salle du jeu
  //On a à faire à un boss
  if(num_zone == NB_ZONES - 1 && num_salle == NB_SALLES - 1){
    init_monstre(salle->monstre, 30, 30,100, 1,0,BOSS);
  }
  //Si on est dans une autre salle c'est un monstre commun
  else{
    init_monstre(salle->monstre, 30, 30,100, 1,0,COMMUN);
  }
  if(num_salle == 0 || num_salle == 2){
    int hauteur = 251;
    for(i = 0; i < NB_PERSO_SALLE; i++){
        if(num_salle == 0){
          init_nonCombattant(salle->perso[i], 0, 104, hauteur,0);
        }
        hauteur = hauteur + 100;
    }
    if(num_salle == 2){
      init_nonCombattant(salle->perso[0], 0, 846, hauteur,0);
    }
  }
  salle->difficulte = 0;
  salle->num_salle = num_salle;
  init_nonCombattant(salle->coffre, 0, 900 - LARGEUR_COFFRE, 80,0);
}

/**
	* \fn int victoire_jeu(monde_t * monde)
	* \brief renvoie 1 si on a vaincu le boss final
	* \param monde les données du monde
*/
int victoire_jeu(monde_t * monde){
  joueur_t * j = monde->joueur;

  //Si le monstre de la zone et la salle actuelle est un boss
  // + Si c'est la dernière salle de la dernière zone
  // + si le monstre est mort
  // alors le joueur a gagné
  if(monde->zones[j->zone]->salles[j->salle]->monstre->type == BOSS && j->zone + 1 == NB_ZONES && j->salle + 1 == NB_SALLES &&monde->zones[j->zone]->salles[j->salle]->monstre->etat == MORT){
    return(VICTOIRE);
  }

  return(PARTIE_EN_COURS);
}
