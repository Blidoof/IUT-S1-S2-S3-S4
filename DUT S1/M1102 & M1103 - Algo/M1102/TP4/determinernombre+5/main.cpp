/*
 Programme : DeterminerNombre+5
 But :Affiche les 5 nombres suivant un nombre saisi.
 Date de dernière modification : 28/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    //VARIABLES
    short int nombre; //Le nombre saisi par l'utilisateur.


    //TRAITEMENTS

    // clavie > saisirNombre > nombre
    cout << "Veuillez saisir un nombre : ";
    cin >> nombre;

    //nombre > calculerEtAfficher >
    for (short int i = nombre; i <= nombre+5; i++ )
    {

        cout << "nombre suivant :" << i << endl;
    }

    return 0;
}
