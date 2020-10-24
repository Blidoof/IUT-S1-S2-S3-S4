#ifndef BIBLIOTHEQUETABLEAUX_H
#define BIBLIOTHEQUETABLEAUX_H
#include "definitionsTypes.h"

/** afficherTableau ------------------------------------------*/
//  plusieurs sous-programmes SURCHARG�S qui diff�rent par le type des
//  �l�ments du tableau
//  --------------
void afficherTableau  (const int tab[],
                       unsigned int nbTab);
// But : affiche � l'�cran le contenu d'un tableau tab contenant nbTab > 0 �l�ments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void afficherTableau  (const UnePersonne tab [],
                       unsigned int nbTab);
// But : affiche � l'�cran le contenu d'un tableau tab contenant nbTab > 0 �l�ments
//       si nbTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')
//=============================================================*/


/** triBulle -------------------------------------------------*/
//  plusieurs versions du sous-programme de tri CROISSANT de la bulle.
//  Ils diff�rent selon le *crit�re de tri* (selon le champ de l'enregistrement)
//  choisi pour r�aliser le tri
//  --------------
void   triBulle (int tab[],
                 const unsigned int nbTab);
// tri CROISSANT du tableau tab, contenant nbTab �l�ments entiers, selon la m�thode
// du tri BULLE

void   triBulle_nom (UnePersonne tab[],
                     const unsigned int nbTab);
// tri du tableau tab, contenant nbTab �l�ments, selon la m�thode du tri BULLE
// tri par ordre CROISSANT sur le champ nom

void   triBulle_ville (UnePersonne tab[],
                       const unsigned int nbTab);
// tri du tableau tab, contenant nbTab �l�ments, selon la m�thode de la BULLE
// tri par ordre CROISSANT sur le champ adresse.nomVille
//=============================================================*/


/** triParSelectionPlace---------------------------------------*/
    // sous-programme de tri CROISSANT selon la m�thode �ponyme
	// � compl�ter
//=============================================================*/


/** triParInsertion -------------------------------------------*/
    // sous-programme de tri CROISSANT selon la m�thode �ponyme
	// � compl�ter
//=============================================================*/

#endif        // BIBLIOTHEQUETABLEAUX_H
