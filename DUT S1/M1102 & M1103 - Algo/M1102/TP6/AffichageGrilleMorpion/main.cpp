/*
  Programme :Affichage grille morpion
  But : Afficher une grille de morpion
  Date de dernière modification : 12 /10 /2018
  Auteur : A. MURILLO
  Remarques : se base sur parcours complet avec traitement systématique
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    //VARIABLES
    char tab[3][3] = {{'x','o','o'},{'x','x','o'},{'o','o','x'}};

    //TRAITEMENTS
    cout << tab[0][0] << "|" << tab[0][1] << "|" << tab[0][2] << endl;
    cout << tab[1][0] << "|" << tab[1][1] << "|" << tab[1][2] << endl;
    cout << tab[2][0] << "|" << tab[2][1] << "|" << tab[2][2] << endl;

    return 0;
}
