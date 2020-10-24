/*
  Programme : Valeur entre 10 et -10
  But : Ce programme affiche tous les entiers compris dans l'intervalle 10 � -10

  Date de cr�ation : 3 novembre 2013
  Date de derni�re modification :
  Auteur : P. Etcheverry
  Remarques : Programme erron�. Utilis� pour illustrer les techniques de d�boggage.
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
