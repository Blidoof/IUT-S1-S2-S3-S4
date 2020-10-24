/*
 Programme : convertionHeuresEnSecondes
 But : A partir d'un temps donné en heures et en minutes, calcule la durée en seconde correspondante
 Date de dernière modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nbHeures; // Le nombre d'heures à convertir
    int nbMinutes; // Le nombre de minutes à convertir
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

    // nbSecondes >> Afficher >> (écran)
    cout << "La duree est de :" << nbSecondes << " secondes" << endl;

    return 0;
}
