/**
  * \file interactions.h
  * \brief header des intéractions
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _INTERACTIONS_H
#define _INTERACTIONS_H

//Récompense en or
#define RECOMPENSE_COMBAT 50
#define RECOMPENSE_COFFRE 100

//Prix des OBJETS
#define COUT_POTION 20
#define COUT_OBJ_DIAM 250
#define COUT_OBJ_PIERRE 100


#include "deplacements.h"


void interaction_nonCombattant(SDL_Event* event, monde_t * monde);

void evenements_combat(SDL_Event * event, monde_t * monde);

#endif
