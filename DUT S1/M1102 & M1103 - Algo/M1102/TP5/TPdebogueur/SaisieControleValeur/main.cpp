/*
  Programme : Saisie contrôlée d'une valeur
  But : Ce programme demande une valeur à l'utilisateur jusqu'à ce que celui entre la valeur 10.
  Le programme indique ensuite le nombre de saisies réalisées.

  Date de création : 3 novembre 2013
  Date de dernière modification : 05 / 10 / 2018
  Auteur : P. Etcheverry
  Remarques : Programme erroné. Utilisé pour illustrer les techniques de déboggage.
*/

#include <iostream>
using namespace std;

int main (void)
{
    int valeurSaisie; // la valeur saisie par l'utilisateur
    unsigned short int nbSaisies; // le nombre de saisies réalisées

    nbSaisies = 0;
    do
    {
        cout << "Entrer une valeur : ";
        cin >> valeurSaisie;
        nbSaisies ++;
    }
    while (!(valeurSaisie == 10));

    cout << "Nombre de saisies : " << nbSaisies << endl;
    return 0;
}
