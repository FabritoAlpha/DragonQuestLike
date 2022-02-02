#include <stdio.h>
#include "../lib/entitee.h"
/**
  * \file test_entitee.c
  * \brief Test les fonctions d'entitees
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/
int main(){
    printf("Lancement du test unitaire pour les entitées\n");
    printf("\n***\n");
    printf("Création de l'entitée joueur");
    joueur_t * PlayerOne ;
    int pvCour,pvMax,attaque,vitesse,niveau;
    float x,y;
    PlayerOne = creer_joueur();
    printf("Initialisation du joueur\n");
    printf("Saisir pvMax,pvCour,attaque,vitesse,x,y,niveau(XP)\n");
    scanf("%d%d%d%d%f%f%d",&pvMax,&pvCour,&attaque,&vitesse,&x,&y,&niveau);
    printf("Pas d'erreur de saisi\n");
    init_joueur(PlayerOne,pvMax,pvCour,attaque,vitesse,x,y);
    printf("Affichage des valeurs du joueur \n");
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->pvMax);
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->pvCour);
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->attaque);
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->vitesse);
    printf("Les pv max du joueur sont %f\n",PlayerOne->combattant->x);
    printf("Les pv max du joueur sont %f\n",PlayerOne->combattant->y);
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->niveau);
}
