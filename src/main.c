/**
  * \file main.c
  * \brief programme principal du jeu
  * \author Anna Beranger, Alex Choux, Arthur Fabre
  * \date 03/03/2022
*/

#include "../lib/jeu.h"

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

    TTF_Font * police = NULL;

    srand(time(NULL));

    //Allocation de la mémoire de la structure images_t contenant toutes les images utiles au jeu
    //textures = malloc(sizeof(images_t));

    //Création du monde
    monde = creer_monde();
    int tick=5;
    int tick_monstre=5;

    //Initialisation de la bibliothèque des objets
    initialiser_biblio(monde->biblio_objet);
    printf("id :%d\n", monde->biblio_objet[0].id);
    printf("Oui\n");
    printf("Nb obj = %d\n", monde->biblio_objet[0].nb_obj);
    printf("Nom obj: %s\n", monde->biblio_objet[0].nom);
    printf("\n");

    if(textures.case_combat != NULL){
      printf("Pas de textures libérés\n");
    }
    //mise en place du jeu (l'écran, le monde de jeu et les textures. )

    //Initialisation des options du menu ainsi que du menu à afficher au début de la partie
    init_monde_menu(monde);

    //Initialisation de la sdl
    init_sdl(&window,&screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Initialisation de la ttf
    init_ttf();

    //On charge toutes les images utiles au jeu
    init_images(screen, &textures);
    //On charge la police de la ttf et on choisit sa taille
    police = TTF_OpenFont("./rsrc/img/ka1.ttf", 20);

    //TO DO boucle du jeu avec mise à jour jeu, évènement (handle event) et rafraichissement
    while(monde->etat_jeu != ETAT_QUITTER){

      //Gestion des évènements durant le jeu: choix des menus, déplacements du personnage...
      evenements(&event,monde);
      /*if(monde->etat_jeu == ETAT_COMBAT){
        //printf("On rentre dans le combat\n");

        apply_texture(textures->monstre, screen, 100, 100);
        //combat(monde->joueur, monde->zones[monde->joueur->zone]->salles[monde->joueur->salle]->monstres[0], textures, screen, &event, monde, police);
      }*/
      //Rafraichissement de l'affichage de la fenêtre
      rafraichir( screen, monde, &textures,&tick,&tick_monstre,police);

    }

    // Nettoyage de la sdl et de la ttf
    //clean(window, screen, textures, monde,police);
    detruire_monde(&monde);

    clean_images(&textures, police);

    clean_sdl(screen,window);

    printf("largeur de la fenêtre: %d \n hauteur de la fenêtre: %d\n", taille_fenetre[0], taille_fenetre[1]);

    if(textures.case_combat == NULL){
      printf("textures libérés\n");
    }

    //Libération de la mémoire liée à la structure images_t
    //free(textures);
    //textures = NULL;
    //if(textures != NULL){
      //printf("Textures mal libérées\n");
    //}
    return 0;
}
