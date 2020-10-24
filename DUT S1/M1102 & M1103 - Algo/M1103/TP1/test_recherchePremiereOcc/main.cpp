#include <iostream>
#include "../bibliothequeTableaux.h"

using namespace std;

int main()
{
    const int NBCASES = 9; // Nombre de cases du tableau
    int tableau[NBCASES] = {5547,4280,3456,1000,1000,1000,3,2,1}; // Un tableau
    int valCherchee; //La valeur a chercher dans le tableau

    afficherTableauEntiers(tableau, NBCASES);

    //Demander saisie de valeur cherchée
    cout << "saisir la valeur a chercher dans le tableau : ";
    cin >> valCherchee;

    recherchePremiereOcc(tableau, NBCASES, valCherchee);
}
