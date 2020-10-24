#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "pile.h"

void deplacerSommet (UnePile& tSource, UnePile& tCible);
/* déplace le sommet de la pile tSource vers la pile tCible
   pré-conditions : estVide(tSource) = faux
                    OU
                    (estVide(tSource) = faux ET estVide(tCible) = faux ET (sommet(tSource) < somme(tCible )

					autrement dit :
					La procédure effectue le déplacement du sommet de le source vers la cible
					SANS vrifier que les conditions pour faire ce transfert sont remplies.
					-->
					c'est donc à vous de vérifier que les conditions du déplacement sont OK
					AVANT d'appeler le sous-programme
*/

void deplacerPetit (UnePile& t1, UnePile& t2, UnePile& t3, unsigned short int& posPetit, char choix);
/*Déplace le petit disque vers une autre tour selon la DIRECTIVE donnée par deplacementPetit
  si deplacementPetit = 12 --> le petit est sur la tour 1 et doit être placé sur la tour 2
  si deplacementPetit = 23 --> le petit est sur la tour 2 et doit être placé sur la tour 3
  si deplacementPetit = 31 --> le petit est sur la tour 3 et doit être placé sur la tour 1
  Met à jour deplacementPetit pour le prochain tour
*/

void deplacerAutre (UnePile& t1, UnePile& t2, UnePile& t3, unsigned short int posPetit);
/* Déplace un autre disque que le petit dans la tour qui reste.
   La position du petit disque est fournie par l'indicateur deplacementPetit, tel que :
   si deplacementPetit = 12 --> le petit est sur la tour 1, le mouvement concerne t2 et t3
   si deplacementPetit = 23 --> le petit est sur la tour 2, le mouvement concerne t1 et t3
   si deplacementPetit = 31 --> le petit est sur la tour 3, le mouvement concerne t1 et t2
*/

void afficherTour (UnePile p);
// affiche à l'écran le contenu de la pile

/* A vous de choisir la version souhaitée
void afficherTour (UnePile& p);
// affiche à l'écran le contenu de la pile

void afficherTour (const UnePile& p);
// affiche à l'écran le contenu de la pile

*/


#endif
