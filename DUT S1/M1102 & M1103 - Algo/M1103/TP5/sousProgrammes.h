#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

void affichageEcran(string nomSysFic);
// affiche � l'�cran le contenu d'un fichier de texte de nom systeme nomFic

void affichageInverseEcran(string nomSysFic);
// affiche � l'�cran le contenu d'un fichier de texte de nom systeme nomFic.
// L'affichage est � l'envers, cad :
// derni�re ligne du fichier texte --> 1ere ligne �cran
//...
// 1�re ligne du fichier texte --> derniere ligne de l'�cran

void transfertEnFin(string nomFicSource, string nomFicCible);
// transfere le contenu d'un fichier de texte nomFicSource en fin d'un autre fichier de texte nomFicCible.
// Les fichiers sont identifi�s par leurs noms syst�me

#endif
