/*
  Programme :�change valeurs
  But : �changer 2 valeurs saisies � l'aide d'un sous programme echangerValeurs
  Date de derni�re modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : /
*/

#include <iostream>
using namespace std;


int main (void)
{
    //DECLARATION DES SOUS PROGRAMMES
    void echangerValeurs (long double& val1,long double& val2);
    //Ce sous programme �change 2 nombres

    //VARIABLES
    long double resultat1 = 25.658; // R�sultat d'une op�ration pr�c�demment effectu�e
    long double resultat2 = 1.4; // deuxieme r�sultat d'une op�ration precedemment effectu�e
    //TRAITEMENTS

    //Appel du sous programme echangerValeurs
    echangerValeurs (resultat1, resultat2);

    cout << resultat1 << endl << resultat2;

    return 0;
}
void echangerValeurs (long double& val1,long double& val2)
{
    //d�claration variable
    long double copieVal1 ; //Variable copiant la valeur de val1 pour r�aliser l'�change

    //Echanger valeurs
    copieVal1 = val1;
    val1 = val2;
    val2= copieVal1;
}
