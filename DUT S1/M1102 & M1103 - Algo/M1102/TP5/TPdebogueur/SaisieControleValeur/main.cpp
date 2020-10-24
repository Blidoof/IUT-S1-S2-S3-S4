/*
  Programme : Saisie contr�l�e d'une valeur
  But : Ce programme demande une valeur � l'utilisateur jusqu'� ce que celui entre la valeur 10.
  Le programme indique ensuite le nombre de saisies r�alis�es.

  Date de cr�ation : 3 novembre 2013
  Date de derni�re modification : 05 / 10 / 2018
  Auteur : P. Etcheverry
  Remarques : Programme erron�. Utilis� pour illustrer les techniques de d�boggage.
*/

#include <iostream>
using namespace std;

int main (void)
{
    int valeurSaisie; // la valeur saisie par l'utilisateur
    unsigned short int nbSaisies; // le nombre de saisies r�alis�es

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
