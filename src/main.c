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
    images_t* textures;
    SDL_Renderer *screen;
    SDL_Window *window;
    srand(time(NULL));
    textures = malloc(sizeof(images_t));
    monde = creer_monde();
    int tick=5;
    int tick_monstre=5;

    printf("Le programme n'a pas planté avant l'init\n\n\n");
    //mise en place du jeu (l'écran, le monde de jeu et les textures. )
    init(&window,&screen, textures, monde);
    printf("Le programme n'a pas planté après l'init et avant la boucle while\n\n\n");

    //TO DO boucle du jeu avec mise à jour jeu, évènement (handle event) et rafraichissement
    while(monde->etat_jeu != -1){
      printf("On ne plante pas dans la boucle avant evenement\n\n\n\n");
      evenements(&event,monde);
      printf("On ne plante pas dans la boucle entre evenement et rafraichir\n\n\n\n");
      rafraichir(screen, monde, textures,&tick,&tick_monstre);
      printf("On ne plante pas dans la boucle apres rafraichir\n\n\n\n");
    }

    // Nettoyer et quitter SDL
    printf("On teste de la libérer allouée à la SDL\n");
    clean(window, screen, textures, monde);
    printf("Réussite de la libération de la mémoire ?\n");

    printf("On teste de libérer la mémoire du monde\n");
    printf("Le problème ne vient pas du monde\n");

    printf("'Pas de pb(en tout cas visible)' avant le clean, vérifier la libération de la mémoire allouée\n");

    printf("largeur de la fenêtre: %d \n hauteur de la fenêtre: %d\n", taille_fenetre[0], taille_fenetre[1]);
    free(textures);
    return 0;
}
