/*
  Programme : Incrementation de valeurs negatives
  But : incrementer de 1 les valeurs négatives d'un tableau
  Date de dernière modification : 10/10/2018
  Auteur : A. MURILLO
  Remarques : Code basé sur un parcour complet avec traitement conditionnel.
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    //VARIABLES
    const unsigned short int NBCASES = 10; // Le nombre de cases du tableau.
    short int tab[NBCASES] = {1, 4, -7, 98, -47, -999, 5, 7, -3, 10}; // le tableau de taille NBCASES.
    unsigned short int dernierIndice; //L'indice de la derniere case de tab.

    //TRAITEMENTS

    //NBCASES > determiner dernier indice > dernierIndice

    dernierIndice = NBCASES - 1;

    //Incrementation
    for (unsigned short int i = 0 ; i <= dernierIndice ; i++ ) // i est l'indice de la case dans laquelle la saisie est réalisée.
    {
        if(tab[i] < 0)
        {
            tab[i]++;
        }
        cout << tab[i] << ",";
    }

    return 0;
}
