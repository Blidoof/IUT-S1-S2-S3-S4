/*
  Programme : Déterminer si un nombre est premier
  But : Ce programme détermine si un nombre saisi est premier.

  Date de création : 3 novembre 2013
  Date de dernière modification : 05/10/2018
  Auteur : P. Etcheverry
  Remarques :
*/

#include <iostream>
using namespace std;

// PROGRAMME PRINCIPAL
int main (void)
{
  long int nbre; // Le nombre qu'on analyse pour déterminer s'il est premier
  unsigned int nbDiv; // Le nombre de diviseurs de nbre
  unsigned int i; // Diviseur potentiel de nbre
  unsigned int quotient; // Quotient de nbre par i
  unsigned int reste; // Reste de la division entière de nbre par i

  // clavier >> Saisie du nombre à analyser >> nombre
  cout << "Entrez un nombre: "; cin >> nbre;

  // nombre >> Déterminer le nombre de diviseurs >> nbDiv
  nbDiv = 0;
  for (int i=nbre ; i>0 ; i--)
    {
      // Vérifier si i est un diviseur
      quotient = nbre / i; // Attention : division entière
      reste = nbre - (quotient*i);

      if (reste == 0) // on a trouvé un diviseur
      {
        nbDiv++;
      }
    }

  // nbDiv >> Déterminer si nbre est premier >> écran
  cout << nbre << (nbDiv == 2 ? " est premier" : " n'est pas premier") << endl;

  return 0;
}
