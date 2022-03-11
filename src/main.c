/**
*\file main.c
*\brief programme principal
*\author Anna Beranger
*\date 17/02/2022
*/

#include "../lib/jeu.h"
#include "../lib/images.h"
#include "../lib/sdl2_fonctions.h"

int taille_fenetre[2];

/**
 *  \brief programme principal qui implémente la boucle du jeu
 */
int main(){
    SDL_Event event; // déclaration des évenements
    monde_t* monde;
    images_t textures;
    SDL_Renderer *screen;
    SDL_Window *window;
    srand(time(NULL));

    monde = creer_monde();
    int tick=5;
    int tick_monstre=5;
    //mise en place du jeu (l'écran, le monde de jeu et les textures. )
    init(&window,&screen, &textures, monde);

    //TO DO boucle du jeu avec mise à jour jeu, évènement (handle event) et rafraichissement
    while(monde->etat_jeu != -1){
      evenements(&event,monde);
      rafraichir(screen, monde, &textures,&tick,&tick_monstre);
    }

    // Nettoyer et quitter SDL
    printf("On teste de la libérer allouée à la SDL\n");
    clean(window, screen, &textures, monde);
    printf("Réussite de la libération de la mémoire ?\n");

    printf("On teste de libérer la mémoire du monde\n");
    printf("Le problème ne vient pas du monde\n");

    printf("'Pas de pb(en tout cas visible)' avant le clean, vérifier la libération de la mémoire allouée\n");

    printf("largeur de la fenêtre: %d \n hauteur de la fenêtre: %d\n", taille_fenetre[0], taille_fenetre[1]);

    return 0;
}
