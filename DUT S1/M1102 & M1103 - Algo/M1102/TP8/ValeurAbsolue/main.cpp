/*
  Programme : Valeur Absolue d'un nombre
  But : Calcule et affiche la valeur absolue d'un nombre saisi
  Date de dernière modification : 24/10/18
  Auteur : A. MURILLO
  Remarques : la calcul de la valeur absolue est délégué à la fonction valAbsolue
*/

#include <iostream>
using namespace std;

//DECLARATION DES SOUS-PROGRAMMES
long double valAbsolue (long double nombre);
// But : Retourne la valeur absolue d'un nombre

int main (void)
{
    //VARIABLES
    int nb; // Un nombre

    //TRAITEMENTS
    //Saisir le nombre dont on va calculer la valeur absolue
    cout << "Saisir le nombre : ";
    cin >> nb;

    //calcul de la valeur absolue
    nb = valAbsolue (nb);

    //Afficher valeur absolue de nb
    cout << "la valeur absolue est : " << nb;

    return 0;
}
//DEFINITION DES SOUS PROGRAMMES
long double valAbsolue (long double nombre)
{
    return (nombre < 0 ? -nombre : nombre );
}
