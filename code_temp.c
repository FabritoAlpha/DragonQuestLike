//Fichier temportaire pour les fonction de déplacement du monstre
// Le but étant de ne pas entrer en conflit avec vos push le temps d'avoir une version stable.
// et étant donné le fait que je ne peux pas vérifier que mon code fonctionne à cause de l'érreur d'initialisation de la sdl.

// La distance sur un repère orthonormé ce calcule grance à la formule suivante:
// AB = sqrt(pow(xb-xa)+pow(yb-ya))
// le problème c'est que nous ne nous situons pas dans un repère orthonormé classique
// je travail donc sur la rédaction d'une formule qui fonctionne avec le repère de la sdl
// d'apres des forums la formule fonctionnerai.
#include "maths.h"
float distance(combattant_t * joueur,combattant_t * monstre){// renvoie la distance entre deux combattants.
  int distance;
  xa=joueur->combattant->x;
  ya=joueur->combattant->y;
  xb=monstre->combattant->x;
  yb=monstre->combattant->y;
  distance=sqrt(pow(xb-xa,2)+pow(yb-ya,2));
  return distance;
}
