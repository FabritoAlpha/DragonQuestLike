/**
  * \file entitee.h
  * \brief header des entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int pv;
  float x;
  float y;
} t_entitee;

typedef struct{
  t_entitee entitee;
  int inventaire[10];
}t_joueur;

typedef struct{
  t_entitee entitee;
  int niveau;
  int en_vie;
} t_monstre;

typedef struct{
  int type;
  float x;
  float y;
}t_nonCombattant;

void a_gauche(t_entitee* entitee);

void a_droite(t_entitee* entitee);

void en_bas(t_entitee* entitee);

void en_haut(t_entitee* entitee);
