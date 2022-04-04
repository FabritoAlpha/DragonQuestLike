/**
  * \file entite.c
  * \brief primitives des entités
  * \author Anna Beranger, Alex Choux, Arthur Fabre
  * \date 03/03/2022
*/
#include  "../lib/entite.h"

/**
  * \fn void a_gauche(combattant_t* entite)
  * \brief déplacement d'un combattant d'un pas à gauche
  * \param entite combattant à déplacer
*/
void a_gauche(combattant_t * entite){
    entite->x = (entite->x)-entite->vitesse;
}

/**
  * \fn void a_droite(combattant_t* entite)
  * \brief déplacement d'un combattant d'un pas à droite
  * \param entite combattant à déplacer
*/
void a_droite(combattant_t* entite){
    entite->x = (entite->x)+entite->vitesse;
}

/**
  * \fn void en_bas(combattant_t* entite)
  * \brief déplacement d'un combattant d'un pas en bas
  * \param entite combattant à déplacer
*/
void en_bas(combattant_t* entite){
    entite->y = (entite->y)+entite->vitesse;
}

/**
  * \fn void en_haut(combattant_t* entite)
  * \brief déplacement d'un combattant d'un pas en haut
  * \param entite combattant à déplacer
*/
void en_haut(combattant_t* entite){
    entite->y = (entite->y)-entite->vitesse;
}

/**
  * \fn joueur_t * creer_joueur()
  * \brief alloue de la mémoire pour un joueur
  * \return un pointeur sur le joueur
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
  * \brief alloue de la mémoire pour un monstre
  * \return un pointeur sur le monstre
*/
monstre_t * creer_monstre(){
  monstre_t * monster;
  monster=malloc(sizeof(monstre_t));
  monster->combattant= malloc(sizeof(combattant_t));
  return monster;
}

/**
  * \fn nonCombattant_t * creer_nonCombattant()
  * \brief alloue de la mémoire pour un pnj ou un coffre
  * \return un pointeur sur le non combattant
*/

nonCombattant_t * creer_nonCombattant(){
  nonCombattant_t * nonCombat;
  nonCombat = malloc(sizeof(nonCombattant_t));
  return(nonCombat);
}

/**
  * \fn void detruire_joueur(joueur_t ** player)
  * \brief libère la mémoire allouée pour le joueur
  * \param player le joueur
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
  * \fn void detruire_monstre(monstre_t ** monster)
  * \brief libère la mémoire allouée pour le monstre
  * \param monster le monstre
*/
void detruire_monstre(monstre_t ** monster){
  free((*monster)->combattant);
  (*monster)->combattant=NULL;
  free(*monster);
  (*monster)=NULL;

}

/**
  * \fn void detruire_nonCombattant(nonCombattant_t ** nonCombat)
  * \brief libère la mémoire allouée pour le non combattant
  * \param nonCombat le non combattant
*/
void detruire_nonCombattant(nonCombattant_t ** nonCombat){
  free(*nonCombat);
  (*nonCombat)=NULL;
}

/**
  * \fn void init_joueur(joueur_t * joueur,int niveau, int zone, int pv_M, int pv_C, int mana_M, int mana_C, int atk, int or, int nb_inv, int nb_equip)
  * \brief initialisation du joueur
  * \param joueur le joueur à initialiser
  * \param niveau le niveau à donner au joueur
  * \param zone la zone à donner au joueur
  * \param pvM le nombre de points de vie maximal à donner au joueur
  * \param pvC le nombre de points de vie à donner au joueur
  * \param mana_M le nombre de points de mana maximal à donner au joueur
  * \param mana_C le nombre de points de mana à donner au joueur
  * \param atk la puissance d'attaque à donner au joueur
  * \param or le nombre d'or à donner au joueur
  * \param nb_inv nombre d'objets qui seront présents dans l'inventaire
  * \param nb_equip nombre d'objets que le joueur aura d'équipés
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
  * \fn void init_monstre(monstre_t * monster, int pvMax, int pvCour, int attaque, int vitesse,int niveau,int type)
  * \brief initialisation d'un monstre
  * \param monster le monstre à initialiser
  * \param pvMax le nombre de points de vie maximal à donner au monstre
  * \param pvCour le nombre de points de vie à donner au mnstre
  * \param attaque la puissance d'attaque à donner au monstre
  * \param vitesse la vitesse à donner au monstre
  * \param niveau le niveau à donner au monstre
  * \param type le type que sera le monstre
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
  * \brief initialisation d'un non combattant
  * \param nonCombat le non combattant à initialiser
  * \param x les coordonnées en abscisses à donner à l'entité
  * \param y les coordonnées en ordonnées à donner à l'entité
  * \param id l'id à donner à l'entité
  * \param visite l'initialiser déjà visité ou non par le joueur
*/
void init_nonCombattant(nonCombattant_t * nonCombat, int id, float x, float y,int visite){
  nonCombat->id=id;
  nonCombat->x=x;
  nonCombat->y=y;
  nonCombat->visite=visite;
}

/**
  * \fn objet_t * creer_objet()
  * \brief alloue de la mémoire pour un objet
  * \return un pointeur sur l'objet créé
*/
objet_t * creer_objet(){
  objet_t * objet;
  objet = malloc(sizeof(objet_t));
  objet->nom = malloc(sizeof(char)*20);
  objet->description = malloc(sizeof(char)*50);
  return(objet);
}

/**
  * \fn objet_t * objet_initialiser(objet_t * objet, int id, int attaque_sup, int mana_sup, int vie_sup, char * nom, char * description)
  * \brief initialisation d'un objet
  * \param objet l'objet à initialisé
  * \param id l'id à donner à l'objet
  * \param attaque_sup l'attaque supplémentaire que l'objet doit apporter
  * \param mana_sup les points de mana supplémentaires que l'objet doit apporter
  * \param les points de vie supplémentaires que l'objet doit apporter
  * \param nom le nom de l'objet
  * \param description la description de l'objet
  * \return un pointeur sur l'objet initialisé
*/
objet_t * objet_initialiser(objet_t * objet, int id, int attaque_sup, int mana_sup, int vie_sup, char * nom, char * description){
  objet->id=id;
  objet->attaque_sup=attaque_sup;
  objet->mana_sup=mana_sup;
  objet->vie_sup=vie_sup;
  objet->nom=nom;
  objet->description=description;
  objet->nb_obj = 0;
  return objet;
}

/**
  * \fn void detruire_objet(objet_t**objet)
  * \brief libère la mémoire allouée pour l'objet
  * \param objet l'objet à détruire
*/
void detruire_objet(objet_t**objet){
  free((*objet)->nom);
  (*objet)->nom=NULL;
  free((*objet)->description);
  (*objet)->description=NULL;
  free(*objet);
  (*objet)=NULL;

}

/**
  * \fn void initialiser_biblio(objet_t tableau[])
  * \brief initialise une bibliothèque d'objets
  * \param tableau le tableau d'objet qui représente la bibliothèque
*/
void initialiser_biblio(objet_t tableau[]){
  int i_tab=0;
  objet_t * epee1 = creer_objet();
  epee1 =objet_initialiser(epee1,ID_EPEE_PIERRE,4,0,0,"Epee en pierre","Desc");
  tableau[i_tab++]=*epee1;
  objet_t * epee2 = creer_objet();
  epee2 =objet_initialiser(epee2,ID_EPEE_DIAM,0,8,0,"Epee en diamant","Desc");
  tableau[i_tab++]=*epee2;
  objet_t * bouclier1 = creer_objet();
  bouclier1 =objet_initialiser(bouclier1,ID_BOUCLIER_BOIS,0,0,10,"Bouclier en bois","Desc");
  tableau[i_tab++]=*bouclier1;
  objet_t * bouclier2 = creer_objet();
  bouclier2 =objet_initialiser(bouclier2,ID_BOUCLIER_DIAM,0,10,0,"Bouclier en Diamant","Desc");
  tableau[i_tab++]=*bouclier2;
  objet_t *potionvie = creer_objet();
  potionvie =objet_initialiser(potionvie,ID_POTION_PV,0,0,20,"Potion de vie","Desc");
  tableau[i_tab++]=*potionvie;
  objet_t *potionmana = creer_objet();
  potionmana =objet_initialiser(potionmana,ID_POTION_MANA,0,20,0,"Potion de mana","Desc");
  tableau[i_tab++]=*potionmana;
}

/**
  * \fn int objet_present(joueur_t* joueur, objet_t* biblio, int ind)
  * \brief vérifie qu'un objet est présent dans l'inventaire du joueur
  * \param joueur le joueur
  * \param biblio la bibliothèque qui contient tous les objets existants
  * \param ind l'indice de l'objet
  * \return objet présent dans l'inventaire (1), objet absent (0)
*/
int objet_present(joueur_t* joueur, objet_t* biblio, int ind){
  return joueur->inventaire[ind].id == biblio[ind].id;
}

/**
  * \fn void ajout_objet(joueur_t* joueur, int ind)
  * \brief ajoute un objet dans l'inventaire du joueur si il ne l'a pas encore ou incrémente le nombre de potion
  * \param joueur le joueur à qui on veut remplir l'inventaire
  * \param biblio la bibliothèque qui contient tous les objets existants
  * \param ind indice de l'objet que l'on veut ajouter
*/
void ajout_objet(joueur_t* joueur, objet_t* biblio, int ind){
  if(!objet_present(joueur, biblio, ind)){ // si l'objet n'est pas dans l'inventaire
    joueur->inventaire[ind]= biblio[ind]; // on l'ajoute
    joueur->inventaire[ind].nb_obj++;
    (joueur->nb_obj_inventaire)++;
  }
  //si l'objet est une potion
  else{
    if(ind == INDICE_POTION_PV || ind == INDICE_POTION_MANA){
      joueur->inventaire[ind].nb_obj++; // dans tout les cas ajouter 1 (on peut avoir plusieurs potions)
    }
  }
}

/**
  * \fn void equipement_desequipement_objet(joueur_t * joueur, int i_tab_inv, int i_obj_equipe)
  * \brief équipe ou déséquipe le joueur
  * \param joueur le joueur
  * \param i_tab_inv indice de l'objet dans l'inventaire du joueur
  * \param i_obj_equipe indice de l'objet parmis ses objets équipés
*/
void equipement_desequipement_objet(joueur_t * joueur, int i_tab_inv, int i_obj_equipe){
  if(joueur->inventaire[i_tab_inv].id != 0){
    //Si l'objet est présent dans l'inventaire, on actualise l'équipement courrant
    if(joueur->objet_equipe[i_obj_equipe].id != 0){
      //Si quelque chose est équipe
      //On le desequipe
      //On diminue le mana max
      joueur->manaMax -= joueur->objet_equipe[i_obj_equipe].mana_sup;
      //On vérifie que le mana courrant n'est pas supérieur au mana max
      if(joueur->manaCour > joueur->manaMax){
        joueur->manaCour = joueur->manaMax;
      }
      //On diminue les pv max
      joueur->combattant->pvMax -= joueur->objet_equipe[i_obj_equipe].vie_sup;
      //On vérifie que les pv courrants sont inférieurs ou égaux
      if(joueur->combattant->pvCour > joueur->combattant->pvMax){
        joueur->combattant->pvCour = joueur->combattant->pvMax;
      }
      joueur->combattant->attaque -= joueur->objet_equipe[i_obj_equipe].attaque_sup;
      if(joueur->objet_equipe[i_obj_equipe].id != joueur->inventaire[i_tab_inv].id){
        //Si l'objet qui était équipé est différent de l'objet que l'on veut équipper on actualise ses stats avec les nouvelles stats de l'obj et on actualise l'id
        joueur->manaMax += joueur->inventaire[i_tab_inv].mana_sup;
        joueur->combattant->pvMax += joueur->inventaire[i_tab_inv].vie_sup;
        joueur->combattant->attaque += joueur->inventaire[i_tab_inv].attaque_sup;
        //On copie l'item dans le tableau de l'équipement
        joueur->objet_equipe[i_obj_equipe] = joueur->inventaire[i_tab_inv];
      }
      else{
        //Si on désequippe l'obj, on décremente le compteur
        joueur->nb_obj_equip--;
        //On indique que l'item n'est plus présent dans les objets equipes
        joueur->objet_equipe[i_obj_equipe].id = 0;
      }
    }
    else{
      //Si rien n'est équipé on équipe juste l'objet
      joueur->manaMax += joueur->inventaire[i_tab_inv].mana_sup;
      joueur->combattant->pvMax += joueur->inventaire[i_tab_inv].vie_sup;
      joueur->combattant->attaque += joueur->inventaire[i_tab_inv].attaque_sup;
      //On copie l'item dans le tableau de l'équipement
      joueur->objet_equipe[i_obj_equipe] = joueur->inventaire[i_tab_inv];
      //On incrémente le compteur d'obj equipe
      joueur->nb_obj_equip++;
    }
  }
}


void consommer_potion(joueur_t * joueur, int indice_obj){
  joueur->combattant->pvCour += joueur->inventaire[indice_obj].vie_sup;
  joueur->manaCour += joueur->inventaire[indice_obj].mana_sup;

  if(joueur->combattant->pvCour > joueur->combattant->pvMax){
    joueur->combattant->pvCour = joueur->combattant->pvMax;
  }
  if(joueur->manaCour > joueur->manaMax){
    joueur->manaCour = joueur->manaMax;
  }

  joueur->inventaire[indice_obj].nb_obj--;
}

void reinitialiser_joueur(joueur_t * joueur, objet_t * biblio){
  int i;
  if(joueur->nb_obj_equip != 0){
    for(i = 0; i < TAILLE_INVENTAIRE - 2; i++){
      if(joueur->objet_equipe[i].id != 0){
        //Si l'objet est présent il faut le retirer
        //joueur->objet_equipe[i].id - 1 correspond à l'indice de l'objet equipe dans la bibio des objets
        if(joueur->objet_equipe[i].id == ID_EPEE_PIERRE || joueur->objet_equipe[i].id == ID_EPEE_DIAM){
          equipement_desequipement_objet(joueur, i, INDICE_EPEE);
        }
        else if(joueur->objet_equipe[i].id == ID_BOUCLIER_BOIS || joueur->objet_equipe[i].id == ID_BOUCLIER_DIAM){
          equipement_desequipement_objet(joueur, i, INDICE_BOUCLIER);
        }
      }
    }
  }
  if(joueur->nb_obj_inventaire != 0){
    for(i = 0; i < TAILLE_INVENTAIRE; i++){
      if(objet_present(joueur, biblio, i)){
        //Si l'objet est présent il faut le retirer
        joueur->inventaire[i].id = 0;
        joueur->inventaire[i].nb_obj = 0;
      }
    }
  }

}
