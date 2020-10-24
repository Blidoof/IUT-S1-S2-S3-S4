#include <iostream>
#include "../bibliothequeTableaux.h"

using namespace std;

int main()
{
    const unsigned int TAILLETAB = 14; // La taillme du tableau tableau
    int tableau[TAILLETAB] ={89,89,89,89,89,5,5,5,5,4,3,-4,-9,-78}; // un tableau d'entiers
    int valCherchee; // La valeur dont on veut la premiere et la derneire occurence
    bool valTrouvee; // Indique si la valeur a été trovuée ou non dans le tableau

    afficherTableauEntiers(tableau, TAILLETAB );

    cout << "rentrez la valeur a chercher : ";
    cin >> valCherchee;

    determinerPremierDernier(valTrouvee, tableau, valCherchee, TAILLETAB);
}
