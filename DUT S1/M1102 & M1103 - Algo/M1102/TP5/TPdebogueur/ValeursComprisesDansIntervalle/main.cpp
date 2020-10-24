/*
  Programme : Valeur entre 10 et -10
  But : Ce programme affiche tous les entiers compris dans l'intervalle 10 à -10

  Date de création : 3 novembre 2013
  Date de dernière modification :
  Auteur : P. Etcheverry
  Remarques : Programme erroné. Utilisé pour illustrer les techniques de déboggage.
*/

#include <iostream>
using namespace std;

int main (void)
{
  const int VALEURDEPART = 10;
  const int VALEURARRIVEE = -10;


  for (unsigned int i = VALEURDEPART ; i >= VALEURARRIVEE ; i--)
  {
      cout << i << " ";
  }

  return 0;
}
