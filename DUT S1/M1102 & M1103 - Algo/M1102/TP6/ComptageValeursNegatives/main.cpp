/*
  Programme : Comptage Valeurs Negatives
  But : Compter le nombre de valeurs n�gatives d'un tableau
  Date de derni�re modification : 10/10/2018
  Auteur : A. MURILLO
  Remarques : Code bas� sur un parcour complet avec traitement conditionnel.
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    //VARIABLES
    const unsigned short int NBCASES = 10; // Le nombre de cases du tableau.
    short int tab[NBCASES] = {1, 4, -7, 98, -47, -999, 5, 7, -3, 10}; // le tableau de taille NBCASES.
    unsigned short int nbNegatifs; // Le nombre de chiffres n�gatifs dans tab.

    //TRAITEMENTS

    //Initialisation
    nbNegatifs = 0;

    //tab, ,nbCases, nbNegatifs > compterNombresNgetaifs > nbNegatifs, tab
    for (unsigned short int i = 0 ; i <= (NBCASES - 1) ; i++ ) // i est l'indice de la case dans laquelle la saisie est r�alis�e.
    {
        if(tab[i] < 0)
        {
            nbNegatifs++;
        }
    }
    cout << nbNegatifs;

    return 0;
}
