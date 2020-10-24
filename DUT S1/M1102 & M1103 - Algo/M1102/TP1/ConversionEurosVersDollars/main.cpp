/*
 Programme : ConversionEurosVersDollars
 But :  Convertit en dollars une somme en euros entrée au clavier
 Date de dernière modification : 6 septembre 2015
 Auteur : P. Etcheverry
 Remarques : Code conforme aux spécifications internes données en cours
*/
#include <iostream>
using namespace std;
int main (void)
{
    // VARIABLES
    double sommeEuros; // La somme en euros qui doit être convertie en dollars.
    double sommeDollars; // La somme en dollars résultant de la conversion.
    const double tauxEurosVersDollars = 1.3383; // Le taux de conversion utilisé pour convertir des euros en dollars.
	
    // TRAITEMENTS
	
    // clavier >> saisirSommeEuros >> sommeEuros
     cout << "Entrez la somme en euros a convertir en dollars :  ";
     cin >> sommeEuros;
	 
    // sommeEuros, tauxEurosVersDollars >> calculerSommeDollars >> sommeDollars
    sommeDollars = sommeEuros * tauxEurosVersDollars;
	
    // sommeDollars >> afficherSommeDollars >> écran
    cout << "La somme convertie est egale a " << sommeDollars << " $" << endl;
	
    return 0;
}
