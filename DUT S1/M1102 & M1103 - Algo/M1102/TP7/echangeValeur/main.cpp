/*
  Programme :échange valeurs
  But : échanger 2 valeurs saisies à l'aide d'un sous programme echangerValeurs
  Date de dernière modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : /
*/

#include <iostream>
using namespace std;


int main (void)
{
    //DECLARATION DES SOUS PROGRAMMES
    void echangerValeurs (long double& val1,long double& val2);
    //Ce sous programme échange 2 nombres

    //VARIABLES
    long double resultat1 = 25.658; // Résultat d'une opération précédemment effectuée
    long double resultat2 = 1.4; // deuxieme résultat d'une opération precedemment effectuée
    //TRAITEMENTS

    //Appel du sous programme echangerValeurs
    echangerValeurs (resultat1, resultat2);

    cout << resultat1 << endl << resultat2;

    return 0;
}
void echangerValeurs (long double& val1,long double& val2)
{
    //déclaration variable
    long double copieVal1 ; //Variable copiant la valeur de val1 pour réaliser l'échange

    //Echanger valeurs
    copieVal1 = val1;
    val1 = val2;
    val2= copieVal1;
}
