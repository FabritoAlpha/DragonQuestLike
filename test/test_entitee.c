#include <stdio.h>
#include "../lib/entitee.h"
/**
  * \file test_entitee.c
  * \brief Test les fonctions d'entitees
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
void main(){
    printf("Lancement du test unitaire pour les entitées\n");
    printf("\n***\n");
    printf("Création de l'entitée joueur");
    joueur_t PlayerOne ;
    int pvCour,pvMax,attaque,vitesse,x,y;
    PlayerOne = creer_joueur();
    printf("Initialisation du joueur\n");
    printf("Saisir pv,attaque,vitesse,x,y\n");
    scanf("%d%d%d%d%d",&pvMax,&pvCour,&attaque,&vitesse,&x,&y);
    init_joueur(&PlayerOne,pvMax,pvCour,attaque,vitesse,x,y);
    printf("Affichage des valeurs du joueur \n");
    printf("Les pv max du joueur sont %d",PlayerOne.combattant->pvMax);

}
