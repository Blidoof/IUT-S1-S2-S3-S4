/*
 Programme : CalculerUneRéduction
 But :  Calcule une réduction à partir d'un prix de base et d'un pourcentage.
 Date de dernière modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double prixInitial; // Le prix sans réduction du produit choisi.
    int reduction; // La réduction, en pourcentage, à appliquer à prixInitial.
    double prixFinal; // le prix avec réduction à payer.

    // TRAITEMENTS

    // ( clavier ) >> saisirValeursInitiales >> prixInital, reduction
    cout << "Saisir prix inital : ";
    cin >> prixInitial;
    cout << "Saisir reduction, en pourcents : ";
    cin >> reduction;

    // prixInitial, reduction >> calculer>> prixFinal
    prixFinal = prixInitial * (1-(double)reduction/100);

    // prixFinal >> Afficher >> ( ecran )
    cout << "Le prix a payer est de : " << prixFinal << " euros";

    return 0;
}
