/**
  * \file entitee.h
  * \brief header des entitées
  * \author Anna Béranger, Arthur Fabre, Alex Choux
*/

#include <stdlib.h>
#include <stdio.h>

/**
  * \struct t_entitee
  * \brief représentation d'une entitee combattante
*/
typedef struct{
  int pv; /**< nombre de point de vie */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
} t_entitee;

/**
  * \struct t_joueur
  * \brief représentation du joueur
*/
typedef struct{
  t_entitee entitee; /**< points de vie et position */
  int inventaire[10]; /**< objets en possession du joueur */
}t_joueur;

/**
  * \struct t_monstre
  * \brief représentation d'un monstre
*/
typedef struct{
  t_entitee entitee; /**< points de vie et position */
  int niveau; /**< niveau du monstre */
  int en_vie; /**< mort: 0, en vie: 1 */
} t_monstre;

/**
  * \struct t_entitee
  * \brief représentation d'une entitee non combattante
*/
typedef struct{
  int type; /**< coffre: 0, pnj n°1: 1, pnj n°2: 2 */
  float x; /**< possition sur l'axe des abscisses */
  float y; /**< position sur l'axe des ordonnées */
}t_nonCombattant;

/**
  * \fn void a_gauche(t_entitee* entitee)
  * \param entitee entitée à déplacer
  * \brief déplacement d'une entitée à gauche
*/
void a_gauche(t_entitee* entitee);

void a_droite(t_entitee* entitee);

void en_bas(t_entitee* entitee);

void en_haut(t_entitee* entitee);
