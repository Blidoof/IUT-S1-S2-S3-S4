#include <iostream>

using namespace std;

int main()
{
   // VARIABLES
    double rayonCercle; // La valeur du rayon du cercle choisi, sans unité.
    double aireCercle; // La valeur finale de l'air du cercle de rayon rayonCercle.
    const double pi = 3.14; // La valeur du chiffre π, utilisée pour le calcul de l'aire.

   // TRAITEMENTS

   // clavier >> saisirValeurRayon >> rayonCercle
    cout << "Entrez la valeur du rayon choisie :  ";
    cin >> rayonCercle;

   // rayonCercle, pi >> calculerAire >> aireCercle
    aireCercle = rayonCercle*rayonCercle * pi;

   // aireCercle >> afficherAire >> écran
    cout << "La valeur de l'aire du cercle est egale a " << aireCercle << endl;

    return 0;
}
