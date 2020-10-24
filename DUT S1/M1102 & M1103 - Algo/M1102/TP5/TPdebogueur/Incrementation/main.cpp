/*
  Programme : Incrémentation progressive d'une valeur
  But : Ce programme incrémente progressivement une valeur avec un pas de 2
        jusqu'à atteindre la valeur 23

  Date de création : 3 novembre 2013
  Date de dernière modification : 05/10/2018
  Auteur : P. Etcheverry
  Remarques :
*/

#include <iostream>
using namespace std;

int main (void)
{
  unsigned short int valeurAIncrementer; // la valeur à incrémenter jusqu'à 23

  valeurAIncrementer = 0;
  do
  {
      valeurAIncrementer += 2;
  }
  while (!(valeurAIncrementer = 23));

  cout << "A la fin, x = " << valeurAIncrementer << endl;
  return 0;
}
