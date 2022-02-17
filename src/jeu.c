/**
*\file jeu.c
*\brief gestion du jeu
*\author Anna Beranger
*\date 17/02/2022
*/

#include "../lib/monde.h"
#include "../lib/images.h"
#include "../lib/sdl2_fonctions.h"
#include "../lib/jeu.h"

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/
void clean(SDL_Window *window, SDL_Renderer * renderer, images_t *textures, monde_t * monde){
    detruire_monde(&monde);
    clean_images(textures);
    clean_sdl(renderer,window);
}

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param wordl le monde
 */
void init(SDL_Window **window, SDL_Renderer **renderer, images_t *textures, monde_t * monde){
    init_sdl(window, renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_monde(monde);
    init_images(*renderer,textures);
}

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void rafraichir(SDL_Renderer *renderer, monde_t * monde, images_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
    fond_position(renderer, textures);
}
