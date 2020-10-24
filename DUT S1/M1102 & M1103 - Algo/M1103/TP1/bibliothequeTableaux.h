#ifndef BIBLIOTHEQUETABLEAUX_H
#define BIBLIOTHEQUETABLEAUX_H

void afficherTableauEntiers  (const int tab[],
                              unsigned int nbTab);
// But : affiche � l'�cran le contenu d'aun tableau tab contenant nbTab > 0 �l�ments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void recherchePremiereOcc (const int tab[], unsigned int taille, int val );
/* But : �tant donn� val, une variable enti�re, recherche dans le tableau tab de taille [taille] cases, strictement
ordonn� d�croissant, la 1ere occurence de val. Si elle est trouv�e, trouve=vrai et pos= indice ou la valeur a �t� trouv�e
sinon trouve = faux */

void determinerPremierDernier (bool& trouve, const int tab[], int val, unsigned int nbCases);
/* Determine, � partir d'un tableau tab d'entiers ordonn�s d�croissant et de taille nbCases, la position de la premiere
(la plus a gauche) et la derniere (la plus a droite ) occurence de val */

#endif        // BIBLIOTHEQUETABLEAUX_H
