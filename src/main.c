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
    monde_t monde;
    images_t textures;
    SDL_Renderer *screen;
    SDL_Window *window;
    int fin = 0;

    //mise en place du jeu (l'écran, le monde de jeu et les textures. )
    init(&window,&screen, &textures, &monde);

    //TO DO boucle du jeu avec mise à jour jeu, évènement (handle event) et rafraichissement
    while(fin == 0){
      rafraichir(screen, &monde, &textures);
      printf("diff de 0 pour fermer la fenêtre: ");
      scanf("%d",&fin);
    }

    // Nettoyer et quitter SDL
    clean(window, screen, &textures, &monde);

    return 0;
}
