/*
  Programme : Saisir un tableau
  But : saisir un tableau de n entiers
  Date de dernière modification : 10/10/2018
  Auteur : A. MURILLO
  Remarques : Code basé sur un parcour complet avec traitement systématique.
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    //VARIABLES
    const unsigned short int NBCASES = 10; // Le nombre de cases du tableau.
    unsigned short int tab[NBCASES]; // le tableau de taille NBCASES.
    unsigned short int dernierIndice; //L'indice de la derniere case de tab.

    //TRAITEMENTS

    //nbCases > determiner dernier indice > dernierIndice

    dernierIndice = NBCASES - 1;

    // Clavier, dernierIndice > SaisirCase > tab

    for (unsigned short int i = 0; i <= dernierIndice ; i++ ) // i est l'indice de la case dans laquelle la saisie est réalisée.
    {
        cout << "Entrez la valeur pour la case " << i << " : ";
        cin >> tab[i];
        cout << tab[i];
    }

    // (null) > ConfirmerFinProgramm > écran

    cout << "Merci ! ";


    return 0;
}
