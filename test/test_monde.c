/**
  * \file test_monde.c
  * \brief Test l'allocation et la libération de mémoire pour les structures de monde.h
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>
#include "../lib/monde.h"


int main(){

    salle_t * salle = NULL;
    zone_t * zone = NULL;
    monde_t * monde = NULL;

    salle = creer_salle();
    if(existe_salle(salle))
        printf("création de la salle réussie\n\n");
    else
        printf("erreur lors de la création de la salle\n\n");

    zone = creer_zone();
    if(existe_zone(zone))
        printf("création de la zone réussie\n\n");
    else
        printf("erreur lors de la création de la zone\n\n");

    monde = creer_monde();
    if(existe_monde(monde))
        printf("création du monde réussie\n\n");
    else
        printf("erreur lors de la création du monde\n\n");

    detruire_salle(&salle);
    detruire_zone(&zone);
    detruire_monde(&monde);

    return 0;

}
