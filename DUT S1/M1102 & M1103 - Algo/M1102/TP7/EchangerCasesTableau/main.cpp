/*
  Programme :échange cases tableau
  But : échanger 2 valeurs dans les cases d'un tableau
  Date de dernière modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : /
*/

#include <iostream>
using namespace std;

    //DECLARATION DES SOUS PROGRAMMES
    void echangerValeurs (unsigned short int case1,unsigned short int case2);
    //Ce sous programme échange 2 valeur de la case d'un tableau

int main (void)
{

    //VARIABLES
    unsigned short int premiereCase; // Première case à échanger
    unsigned short int deuxiemeCase; // deuxieme case à échanger
    //TRAITEMENTS

    //Saisir cases à échanger
    cout << "saisir premiere case a echanger :"; cin >>premiereCase;
    cout << "saisir deuxieme case a echanger :"; cin >> deuxiemeCase;

    //Appel du sous programme echangerValeurs
    echangerValeurs (premiereCase, deuxiemeCase);

    return 0;
}
void echangerValeurs (unsigned short int case1,unsigned short int case2)
{
    //déclaration variables
    short int tab[10] = {-4,2,6,7,5,1,24,1,0,7}; // tableau dont 2 cases sont à échanger
    long double copieCase1 ; //Variable copiant la valeur de val1 pour réaliser l'échange

    //Echanger valeurs
    copieCase1 = tab[case1];
    tab[case1] = tab[case2];
    tab[case2]= copieCase1;

    cout << tab[case1] << endl << tab[case2];
}
