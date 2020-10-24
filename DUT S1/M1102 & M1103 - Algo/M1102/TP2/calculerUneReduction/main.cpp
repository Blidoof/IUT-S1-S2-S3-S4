/*
 Programme : CalculerUneR�duction
 But :  Calcule une r�duction � partir d'un prix de base et d'un pourcentage.
 Date de derni�re modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double prixInitial; // Le prix sans r�duction du produit choisi.
    int reduction; // La r�duction, en pourcentage, � appliquer � prixInitial.
    double prixFinal; // le prix avec r�duction � payer.

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
