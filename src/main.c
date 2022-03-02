/**
*\file main.c
*\brief programme principal
*\author Anna Beranger
*\date 17/02/2022
*/

#include "../lib/jeu.h"
#include "../lib/images.h"
#include "../lib/sdl2_fonctions.h"

/**
 *  \brief programme principal qui implémente la boucle du jeu
 */
int main(){
    monde_t* monde;
    images_t textures;
    SDL_Renderer *screen;
    SDL_Window *window;
    int fin = 0;

    monde = creer_monde();
    
    //mise en place du jeu (l'écran, le monde de jeu et les textures. )
    init(&window,&screen, &textures, monde);

    //TO DO boucle du jeu avec mise à jour jeu, évènement (handle event) et rafraichissement
    while(fin == 0){
      rafraichir(screen, monde, &textures);
      printf("diff de 0 pour fermer la fenêtre: ");
      scanf("%d",&fin);
    }

    // Nettoyer et quitter SDL
    printf("On teste de la libérer allouée à la SDL\n");
    clean(window, screen, &textures, monde);
    printf("Réussite de la libération de la mémoire ?\n");

    printf("On teste de libérer la mémoire du monde\n");
    printf("Le problème ne vient pas du monde\n");

    printf("'Pas de pb(en tout cas visible)' avant le clean, vérifier la libération de la mémoire allouée\n");

    return 0;
}
