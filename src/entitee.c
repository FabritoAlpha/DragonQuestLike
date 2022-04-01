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
void a_gauche(combattant_t * entitee){
    entitee->x = (entitee->x)-entitee->vitesse;
}
/**
  * \fn void a_droite(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée à droite selon un pas.
*/
void a_droite(combattant_t* entitee){
    entitee->x = (entitee->x)+entitee->vitesse;
}
/**
  * \fn void en_bas(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en bas selon un pas.
*/
void en_bas(combattant_t* entitee){
    entitee->y = (entitee->y)+entitee->vitesse;
}
/**
  * \fn void en_haut(combattant_t*)
  * \param entitee entitée à déplacer.
  * \brief déplacement d'une entitée en haut selon un pas.
*/
void en_haut(combattant_t* entitee){
    entitee->y = (entitee->y)-entitee->vitesse;
}


/**
  * \fn joueur_t * creer_joueur()
  * \brief La fonction créer le joueur.
*/
joueur_t * creer_joueur(){
    joueur_t * player;
    player = malloc(sizeof(joueur_t));
    player->combattant= malloc(sizeof(combattant_t));

    player->inventaire= malloc(sizeof(objet_t)*TAILLE_INVENTAIRE);

    player->objet_equipe=malloc(sizeof(objet_t)*NB_EQUIPEMENT);

    return player;
}

/**
  * \fn monstre_t * creer_monstre()
  * \brief La fonction créer le joueur.
*/
monstre_t * creer_monstre(){
  monstre_t * monster;
  monster=malloc(sizeof(monstre_t));
  monster->combattant= malloc(sizeof(combattant_t));
  return monster;
}

/**
  * \fn nonCombattant_t * creer_nonCombattant()
  * \brief La fonction créer une entitée non combattante.
*/

nonCombattant_t * creer_nonCombattant(){
  nonCombattant_t * nonCombat;
  nonCombat = malloc(sizeof(nonCombattant_t));
  return(nonCombat);
}

/**
  * \fn void detruire_joueur(joueur_t ** player)
  * \brief La fonction détruire le joueur.
*/
void detruire_joueur(joueur_t ** player){
  int i;
  free((*player)->combattant);
  (*player)->combattant=NULL;

  free((*player)->inventaire);
  (*player)->inventaire=NULL;


  free((*player)->objet_equipe);
  (*player)->objet_equipe=NULL;

  free(*(player));
  (*player)=NULL;
}
/**
  * \fn void detruire_monstre(monstre_t ** player)
  * \brief La fonction détruire le monstre.
*/
void detruire_monstre(monstre_t ** monster){
  free((*monster)->combattant);
  (*monster)->combattant=NULL;
  free(*monster);
  (*monster)=NULL;

}
/**
  * \fn void detruire_nonCombattant(nonCombattant_t ** nonCombat)
  * \brief La fonction détruire un nonCombattant.
*/
void detruire_nonCombattant(nonCombattant_t ** nonCombat){
  free(*nonCombat);
  (*nonCombat)=NULL;
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
void init_joueur(joueur_t * joueur,int niveau, int zone, int pv_M, int pv_C, int mana_M, int mana_C, int atk, int or, int nb_inv, int nb_equip){
  joueur->combattant->pvMax=pv_M;
  joueur->combattant->pvCour=pv_C;
  joueur->manaMax=mana_M;
  joueur->manaCour=mana_C;
  joueur->combattant->attaque=atk;
  joueur->combattant->vitesse=10;
  joueur->combattant->x= 1000/10;
  joueur->combattant->y= 1000/10;
  joueur->combattant->niveau=niveau;
  joueur->combattant->type = JOUEUR;
  joueur->nb_obj_equip = nb_equip;
  joueur->nb_obj_inventaire = nb_inv;
  joueur->zone = zone;
  joueur->salle = 0;
  joueur->or = or;
}

/**
  * \fn void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse, float x, float y,int niveau)
  * \param monstre entitée à initialiser.
  * \param pvMax entitée à initialiser.
  * \param pvCour entitée à initialiser.
  * \param attaque entitée à initialiser.
  * \param vitesse entitée à initialiser.
  * \param x entitée à initialiser.
  * \param y entitée à initialiser.
  * \brief Initialisation du monstre avec des parametres.
*/
void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse,int niveau,int type){
  monster->combattant->pvMax=pvMax;
  monster->combattant->pvCour=pvCour;
  monster->combattant->attaque=attaque;
  monster->combattant->vitesse=vitesse;
  monster->combattant->x=500;
  monster->combattant->y=250;
  monster->combattant->niveau=niveau;
  monster->type=type;
  monster->x=500;
  monster->y=250;
  monster->dir=-1;
  monster->dist=-1;
  monster->combattant->type = MONSTRE;
  monster->etat = VIVANT;
}


/**
  * \fn void init_nonCombattant(nonCombattant_t * nonCombat, int id, float x, float y,int visite)
  * \param nonCombat entitée à initialiser.
  * \param x entitée à initialiser.
  * \param y entitée à initialiser.
  * \param visite entitée à initialiser.
  * \brief Initialisation du nonCombattant avec des parametres.
*/
void init_nonCombattant(nonCombattant_t * nonCombat, int id, float x, float y,int visite){
  nonCombat->id=id;
  nonCombat->x=x;
  nonCombat->y=y;
  nonCombat->visite=visite;
}


objet_t * creer_objet(){
  objet_t * objet;
  objet= malloc(sizeof(objet_t));
  objet->nom = malloc(sizeof(char)*20);
  objet->description = malloc(sizeof(char)*50);
  return(objet);
}
objet_t * objet_initialiser(objet_t * objet,int id,int attaque_sup,int mana_sup,int vie_sup,char*nom,char*description){
  objet->id=id;
  objet->attaque_sup=attaque_sup;
  objet->mana_sup=mana_sup;
  objet->vie_sup=vie_sup;
  objet->nom=nom;
  objet->description=description;
  return objet;
}

void detruire_objet(objet_t**objet){
  free((*objet)->nom);
  (*objet)->nom=NULL;
  free((*objet)->description);
  (*objet)->description=NULL;
  free(*objet);
  (*objet)=NULL;

}

void initialiser_biblio(objet_t tableau[]){
  int i_tab=0;
  objet_t * epee1 = creer_objet();
  epee1 =objet_initialiser(epee1,1,4,0,0,"Epee en pierre","Desc");
  tableau[i_tab++]=*epee1;
  objet_t * epee2 = creer_objet();
  epee2 =objet_initialiser(epee2,2,0,8,0,"Epee en diamant","Desc");
  tableau[i_tab++]=*epee2;
  objet_t * bouclier1 = creer_objet();
  bouclier1 =objet_initialiser(bouclier1,3,0,0,10,"Bouclier en pierre","Desc");
  tableau[i_tab++]=*bouclier1;
  objet_t * bouclier2 = creer_objet();
  bouclier2 =objet_initialiser(bouclier2,4,0,10,0,"Bouclier en Diamant","Desc");
  tableau[i_tab++]=*bouclier2;
  objet_t *potionvie = creer_objet();
  potionvie =objet_initialiser(potionvie,6,0,0,20,"Potion de vie","Desc");
  tableau[i_tab++]=*potionvie;
  objet_t *potionmana = creer_objet();
  potionmana =objet_initialiser(potionmana,7,0,20,0,"Potion de mana","Desc");
  tableau[i_tab++]=*potionmana;
}

int objet_present(joueur_t* joueur, objet_t* biblio, int ind){
  return joueur->inventaire[ind].id == biblio[ind].id;
}

/**
  * \fn void ajout_objet(joueur_t* joueur, int ind)
  * \param joueur jour à qui on veut remplir l'inventaire
  * \param ind indice de l'objet que l'on veut ajouter
  * \brief Ajoute un objet dans l'inventaire du joueur si il ne l'a pas encore ou incrémente le nombre de potion
*/
void ajout_objet(joueur_t* joueur, objet_t* biblio, int ind){
  if(!objet_present(joueur, biblio, ind)){ // si l'objet n'est pas dans l'inventaire
    joueur->inventaire[ind]= biblio[ind]; // on l'ajoute
  }
  //si l'objet est une potion
  if(ind == 4 || ind == 5){
    joueur->inventaire[ind].attaque_sup++; // dans tout les cas ajouter 1 (on peut avoir plusieurs potions)
  }
}
