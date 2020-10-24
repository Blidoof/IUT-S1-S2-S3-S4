#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

void affichageEcran(string nomSysFic);
// affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic

void affichageInverseEcran(string nomSysFic);
// affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic.
// L'affichage est à l'envers, cad :
// dernière ligne du fichier texte --> 1ere ligne écran
//...
// 1ère ligne du fichier texte --> derniere ligne de l'écran

void transfertEnFin(string nomFicSource, string nomFicCible);
// transfere le contenu d'un fichier de texte nomFicSource en fin d'un autre fichier de texte nomFicCible.
// Les fichiers sont identifiés par leurs noms système

#endif
