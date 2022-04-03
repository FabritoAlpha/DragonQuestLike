#include <stdio.h>
#include "../lib/entite.h"
/**
  * \file test_entite.c
  * \brief Test les fonctions d'entites
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
    //printf("Pas d'erreur de saisi\n");
    init_joueur(PlayerOne,pvMax,pvCour,attaque,vitesse,x,y,niveau);
    printf("Affichage des valeurs du joueur \n");
    printf("Les pv max du joueur sont %d\n",PlayerOne->combattant->pvMax);
    printf("Les pv actuels du joueur sont %d\n",PlayerOne->combattant->pvCour);
    printf("L'attaque du joueur est %d\n",PlayerOne->combattant->attaque);
    printf("La vitesse du joueur est %d\n",PlayerOne->combattant->vitesse);
    printf("La coordonnée x du joueur est %f\n",PlayerOne->combattant->x);
    printf("La coordonnée y du joueur est %f\n",PlayerOne->combattant->y);
    printf("Le niveau du joueur est %d\n",PlayerOne->combattant->niveau);
    printf("Destruction du joueur\n");
    printf("\n***\n");
    detruire_joueur(&PlayerOne);
    printf("\n***\n");
    printf("Création de l'entitée monstre");
    monstre_t * MonsterOne ;
    int type;
    MonsterOne = creer_monstre();
    printf("Initialisation du joueur\n");
    printf("Saisir le type du monstre");
    scanf("%d",&type);
    init_monstre(MonsterOne,pvMax,pvCour,attaque,vitesse,x,y,niveau,type);
    printf("Affichage des valeurs du joueur \n");
    printf("Les pv max du joueur sont %d\n",MonsterOne->combattant->pvMax);
    printf("Les pv max du joueur sont %d\n",MonsterOne->combattant->pvCour);
    printf("Les pv max du joueur sont %d\n",MonsterOne->combattant->attaque);
    printf("Les pv max du joueur sont %d\n",MonsterOne->combattant->vitesse);
    printf("Les pv max du joueur sont %f\n",MonsterOne->combattant->x);
    printf("Les pv max du joueur sont %f\n",MonsterOne->combattant->y);
    printf("Les pv max du joueur sont %d\n",MonsterOne->combattant->niveau);
    printf("Les pv max du joueur sont %d\n",MonsterOne->type);
    printf("Déstruction du monstre\n");
    printf("\n***\n");
    detruire_monstre(&MonsterOne);
    printf("\n***\n");
















}
