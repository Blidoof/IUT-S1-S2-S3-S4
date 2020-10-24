/*
 Programme : TourDeRouesSurUneDistance
 But : D�termine le nombre de tours qu'une roue fera pour une distance donn�e.
 Date de derni�re modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double distance; // la distance a parcourir qui sera convertie en mm.
    long double rayon; //le rayon de la roue du v�lo en mm.
    const float PI = 3.14; // La valeur de pi servant a calculer le perimetre.
    long double nbTours; // Le nombre de tours effectu�s par le v�lo sur la distance choisie.

    //TRAITEMENTS

    // (clavier) >> saisirValeursInitiales >> distance,rayon
    cout << "Saisir la valeur de la distance a parcourir en km :";
    cin >> distance;
    cout << "Saisir la valeur du rayon de la roue du velo en mm :";
    cin >> rayon;

    // distance,rayon,pi >> determinerNombreTours >> nbTours
    nbTours = (distance * 1000000) / (2 * PI * rayon);

    // nbTours >> Afficher >> (�cran)
    cout << "Le nombre de tours effectues par la roue est : " << nbTours;

return 0;
}
