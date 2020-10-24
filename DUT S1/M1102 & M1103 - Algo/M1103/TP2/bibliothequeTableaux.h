#ifndef BIBLIOTHEQUETABLEAUX_H
#define BIBLIOTHEQUETABLEAUX_H
#include "definitionsTypes.h"

/** afficherTableau ------------------------------------------*/
//  plusieurs sous-programmes SURCHARGéS qui diffèrent par le type des
//  éléments du tableau
//  --------------
void afficherTableau  (const int tab[],
                       unsigned int nbTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant nbTab > 0 éléments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void afficherTableau  (const UnePersonne tab [],
                       unsigned int nbTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant nbTab > 0 éléments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')
//=============================================================*/


/** triBulle -------------------------------------------------*/
//  plusieurs versions du sous-programme de tri CROISSANT de la bulle.
//  Ils diffèrent selon le *critère de tri* (selon le champ de l'enregistrement)
//  choisi pour réaliser le tri
//  --------------
void   triBulle (int tab[],
                 const unsigned int nbTab);
// tri CROISSANT du tableau tab, contenant nbTab éléments entiers, selon la méthode
// du tri BULLE

void   triBulle_nom (UnePersonne tab[],
                     const unsigned int nbTab);
// tri du tableau tab, contenant nbTab éléments, selon la méthode du tri BULLE
// tri par ordre CROISSANT sur le champ nom

void   triBulle_ville (UnePersonne tab[],
                       const unsigned int nbTab);
// tri du tableau tab, contenant nbTab éléments, selon la méthode de la BULLE
// tri par ordre CROISSANT sur le champ adresse.nomVille
//=============================================================*/


/** triParSelectionPlace---------------------------------------*/
    // sous-programme de tri CROISSANT selon la méthode éponyme
	// à compléter
//=============================================================*/


/** triParInsertion -------------------------------------------*/
    // sous-programme de tri CROISSANT selon la méthode éponyme
	// à compléter
//=============================================================*/

#endif        // BIBLIOTHEQUETABLEAUX_H
