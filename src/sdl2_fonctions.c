/**
  * \file sdl2_fonctions.c
  * \brief fonctions de gestion de la sdl2
  * \author Anna Béranger, Arthur Fabre, Alex Choux
	* \date 03/03/2022
*/

#include "../lib/sdl2_fonctions.h"



/**
  * \fn int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
  * \brief initialise la SDL, crée la fenêtre du jeu et le renderer
  * \param window la fenêtre du jeu
  * \param renderer le renderer
  * \param width largeur de l'écran de jeu
  * \param height hauteur de l'écran de jeu
  * \return -1 en cas d'erreur, 0 sinon
*/
int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height){
    if(0 != SDL_Init(SDL_INIT_VIDEO)){
        fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
        return -1;
    }

    (*window) = SDL_CreateWindow("Dragon Quest Like", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_FULLSCREEN); //SDL_WINDOW_RESIZABLE SDL_WINDOW_SHOWN SDL_WINDOW_FULLSCREEN SDL_WINDOW_MAXIMIZED

    if (window == 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    }

    (*renderer) = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
    if ((*renderer) == 0) {
         fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    }

    SDL_GetWindowSize((*window),&taille_fenetre[0],&taille_fenetre[1]);

    return 0;
}

/**
  * \fn SDL_Texture* load_image(const char* nomfichier, SDL_Renderer* renderer)
  * \brief charge une image  et renvoie la texture correspondante
  * \param path est le chemin du fichier image. Le fichier doit être obligatoirement du BMP.
  * \param renderer le renderer
  * \return la surface SDL contenant l'image, NULL si le chargement a échoué
*/
void load_image(const char* nomfichier, SDL_Renderer** renderer, SDL_Texture** text){

    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(nomfichier);
    if(NULL == tmp)
    {

        fprintf(stderr, "Erreur pendant chargement image BMP: %s", SDL_GetError());
        return ;
    }
    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
    texture = SDL_CreateTextureFromSurface(*renderer, tmp);
    SDL_FreeSurface(tmp);
    tmp = NULL;
    if(NULL == texture)
    {

        fprintf(stderr, "Erreur pendant creation de la texture liee a l'image chargee: %s", SDL_GetError());
        return ;
    }
    if(tmp != NULL)
    {

        fprintf(stderr, "Erreur freesurface: %s", SDL_GetError());
        return ;
    }
    if(texture == NULL){
      printf("Texture NULL\n");
    }
    (*text) = texture;
}

/**
  * \fn void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y)
  * \brief appliqe une texture sur le renderer à une position donnée
  * \param texture  la texture que l'on va appliquer
  * \param renderer le renderer qui va recevoir la texture
  * \param x l'abscisse sur le renderer de l'endroit où est appliquée texture (point en haut à gauche de la surface)
  * \param y l'ordonnée sur le renderer de l'endroit où est appliquée texture (point en haut à gauche de la surface)
*/
void apply_texture(SDL_Texture **texture,SDL_Renderer *renderer,float x, float y){
    SDL_Rect dst = {0, 0, 0, 0};
    SDL_QueryTexture(*texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x;
    dst.y = y;

    SDL_RenderCopy(renderer, *texture, NULL, &dst);

}

/**
  * \fn void update_screen(SDL_Renderer *renderer)
  * \brief mise à jour de l'écran avec le contenu du renderer
  * \param renderer le renderer de l'écran
*/
void update_screen(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
}

/**
  * \fn void clean_texture(SDL_Texture *texture)
  * \brief libère la mémoire d'une texture
  * \param texture la texture à nettoyer
*/
void clean_texture(SDL_Texture *texture){
    if(NULL != texture){
        SDL_DestroyTexture(texture);
    }
}

/**
  * \fn void clear_renderer(SDL_Renderer *renderer)
  * \brief vide le contenu graphique du renderer
  * \param renderer le renderer de l'écran
*/
void clear_renderer(SDL_Renderer *renderer){
    int i;
    i = SDL_RenderClear(renderer);
    //printf("Valeur du clear du renderer : %d\n",i);
}


/**
  * \fn void clean_sdl(SDL_Renderer *renderer,SDL_Window *window)
  * \brief libère la mémoire du renderer et de la fenêtre
  * \param renderer le renderer à nettoyer
  * \param window la fenêtre à nettoyer
*/
void clean_sdl(SDL_Renderer *renderer,SDL_Window *window){
    if(NULL != renderer){
        SDL_DestroyRenderer(renderer);
    }
    if(NULL != window){
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

/** SDL TTF **/

/**
  * \fn void init_ttf()
  * \brief initialisation de la ttf
*/
void init_ttf(){
    if(TTF_Init() < 0){
        TTF_GetError();
    }
}

/**
  * \fn TTF_Font* apply_font(const char* fileName, int size)
  * \brief applique l'écriture sur l'écran
  * \param  const char* fileName le nom du fichier et la taille de la police
  * \size taille
*/
TTF_Font* apply_font(const char* fileName, int size){

    TTF_Font *font = TTF_OpenFont(fileName, size);
    if(font == NULL){
        printf("Erreur chargement font: %s\n", SDL_GetError());
    }
    return font;
}

/**
* \fn void apply_text(SDL_Renderer *renderer, int r, int g, int b , const char* text, TTF_Font* font, int x, int y, int w, int h)
  * \brief applique la couleur et la texture du texte
  * \param renderer le rendere
  * \param r la couleur rouge du texte
  * \param g la couleur verte du texte
  * \param b la couleur bleue du texte
  * \param text le texte à afficher
  * \param font la police du texte
  * \param x position sur les abscisses
  * \param y position sur les ordonnées
  * \param w longueur
  * \param h hauteur
*/
void apply_text(SDL_Renderer *renderer, int r, int g, int b , const char* text, TTF_Font* font, int x, int y, int w, int h){
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

    //gérer la couleur
    SDL_Color color = { r,g,b,255 };

    //On transforme le texte en surface puis texture à afficher
    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect2 = {x, y, w, h};

    //On "ajoute" le texte à l'affichage
    SDL_RenderCopy(renderer, texture, NULL, &dstrect2);

    SDL_DestroyTexture(texture);
    texture = NULL;

    SDL_FreeSurface(surface);
    surface = NULL;
}

/**
  * \fn void clean_font(TTF_Font *font)
  * \brief libère la mémoire de la police et quitte la ttf
  * \param font la police
*/
void clean_font(TTF_Font *font){
    if(font != NULL){
        TTF_CloseFont(font);
    }
    TTF_Quit();
}
