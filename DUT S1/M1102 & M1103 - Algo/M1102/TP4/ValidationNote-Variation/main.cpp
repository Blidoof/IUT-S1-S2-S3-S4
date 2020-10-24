/*
 Programme : ValidationNote - Variante
 But : Détermine si une note est comprise entre 0 et 20 avce message d'erreur le cas échéant.
 Date de dernière modification : 28/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float note; // la note saisie par l'utilisateur.

    //TRAITEMENTS

    //validationNote
    cout << "Saisir une note :";

    for ( ; ; )
    {
        // écran > saisieNote > note

        cin >> note;

        if ( note >= 0 && note <= 20 )
        {
            break;
        }
        else
        {
            cout << "La valeur doit etre comprise entre 0 et 20. Recommencez : ";
        }
    }

    // affichage
        cout << "Merci.";

    return 0;
}
