/**
  * \file monde.h
  * \brief header du monde
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>
#include "entitee.h"

typedef struct{
	monstre_t ** monstres;
	nonCombattant_t ** coffre;
	nonCombattant_t ** personnages;
	int largeur;
	int longueur;
} t_salle;

typedef struct{

} t_zone;

typedef struct{

} t_monde;
