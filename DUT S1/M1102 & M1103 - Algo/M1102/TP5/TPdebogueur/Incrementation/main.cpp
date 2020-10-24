/*
  Programme : Incr�mentation progressive d'une valeur
  But : Ce programme incr�mente progressivement une valeur avec un pas de 2
        jusqu'� atteindre la valeur 23

  Date de cr�ation : 3 novembre 2013
  Date de derni�re modification : 05/10/2018
  Auteur : P. Etcheverry
  Remarques :
*/

#include <iostream>
using namespace std;

int main (void)
{
  unsigned short int valeurAIncrementer; // la valeur � incr�menter jusqu'� 23

  valeurAIncrementer = 0;
  do
  {
      valeurAIncrementer += 2;
  }
  while (!(valeurAIncrementer = 23));

  cout << "A la fin, x = " << valeurAIncrementer << endl;
  return 0;
}
