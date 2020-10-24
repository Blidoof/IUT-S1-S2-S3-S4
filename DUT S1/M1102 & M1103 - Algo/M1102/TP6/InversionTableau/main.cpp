/*
  Programme : Inversion d'un tableau
  But : Inverser les cases d'un tableau
  Date de derni�re modification : 12/10/2018
  Auteur : A. MURILLO
  Remarques : se base sur un parcours complet avec traitement syst�matique
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES

    //VARIABLES
    const unsigned short int NBCASES = 10; // Le nombre de cases du tableau
    unsigned short int tab[NBCASES] = {4,5,63,1,4,7,6,1,2,9}; // La tableau dont els valeurs sont � �changer
    unsigned short int valEchange; // Valeur qui sert d'intermediaire pour �changer la valeur des cases du tableau tab

    //TRAITEMENTS
    //Echanger Cases
    for (unsigned short int i = 0; i <= ((NBCASES-1) / 2) ; i++ )
    {
        valEchange = tab[i];
        tab[i] = tab[NBCASES-1-i];
        tab[NBCASES-1-i] = valEchange;
        cout << tab[i];

    }

    return 0;
}
