#ifndef BIBLIOTHEQUETABLEAUX_H
#define BIBLIOTHEQUETABLEAUX_H

void afficherTableauEntiers  (const int tab[],
                              unsigned int nbTab);
// But : affiche à l'écran le contenu d'aun tableau tab contenant nbTab > 0 éléments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void recherchePremiereOcc (const int tab[], unsigned int taille, int val );
/* But : étant donné val, une variable entière, recherche dans le tableau tab de taille [taille] cases, strictement
ordonné décroissant, la 1ere occurence de val. Si elle est trouvée, trouve=vrai et pos= indice ou la valeur a été trouvée
sinon trouve = faux */

void determinerPremierDernier (bool& trouve, const int tab[], int val, unsigned int nbCases);
/* Determine, à partir d'un tableau tab d'entiers ordonnés décroissant et de taille nbCases, la position de la premiere
(la plus a gauche) et la derniere (la plus a droite ) occurence de val */

#endif        // BIBLIOTHEQUETABLEAUX_H
