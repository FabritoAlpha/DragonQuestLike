#ifndef _INTERACTIONS_H
#define _INTERACTIONS_H


#include "deplacements.h"


void interaction_nonCombattant(SDL_Event* event, monde_t * monde);

void evenements_combat(SDL_Event * event, monde_t * monde);

#endif
