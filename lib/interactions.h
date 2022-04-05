/**
  * \file interactions.h
  * \brief header des intéractions
  * \author Anna Béranger, Arthur Fabre, Alex Choux
  * \date 03/03/2022
*/

#ifndef _INTERACTIONS_H
#define _INTERACTIONS_H

//Récompense en or d'un combat
#define RECOMPENSE_COMBAT 50

#include "deplacements.h"


void interaction_nonCombattant(SDL_Event* event, monde_t * monde);

void evenements_combat(SDL_Event * event, monde_t * monde);

#endif
