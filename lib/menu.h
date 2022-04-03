#ifndef MENU_H
#define MENU_H

#include "monde.h"

//Choix du joueur pour le menu de l'Inventaire
#define INVENTAIRE 1
#define EPEE_PIERRE 2
#define EPEE_DIAM 3
#define BOUCLIER_PIERRE 4
#define BOUCLIER_DIAM 5
#define POTION_PV 6
#define POTION_MANA 7

void quitter_carte_aide(SDL_Event* event, monde_t * monde);

void choix_partie(SDL_Event* event, monde_t * monde);

void evenements_menu(SDL_Event* event, monde_t * monde);

void evenements_inventaire(SDL_Event* event, monde_t * monde);

void evenements_fin_partie(SDL_Event * event, monde_t * monde);

#endif
