/*
 Programme : convertionHeuresEnSecondes
 But : A partir d'un temps donn� en heures et en minutes, calcule la dur�e en seconde correspondante
 Date de derni�re modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nbHeures; // Le nombre d'heures � convertir
    int nbMinutes; // Le nombre de minutes � convertir
    const int CONVHEURES = 3600; //  Le nombre de secondes dans une heure
    const int CONVMINUTES = 60; // Le nombre de secondes dans une minute
    int nbSecondes; // Le temps saisi convertit en secondes

    // TRAITEMENTS

    // (clavier) >> saisirValeursInitiales >> nbHeures, nbMinutes
    cout << "Saisir le nombre d'heures :";
    cin >> nbHeures;
    cout << "Saisir le nombre de minutes supplementaires :";
    cin >> nbMinutes;

    // nbHeures, nbMinutes, CONVHEURES, CONVMINUTES >> Convertir >> nbSecondes
    nbSecondes = nbHeures * CONVHEURES + nbMinutes * CONVMINUTES;

    // nbSecondes >> Afficher >> (�cran)
    cout << "La duree est de :" << nbSecondes << " secondes" << endl;

    return 0;
}
