/*
 Programme : validationNote
 But : Fait saisir à l'utilisateur uen note et vérifie que celle ci est comprise entre 0 et 20
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
    do
    {
        // écran > saisieNote > note
        cout << "Saisir une note :";
        cin >> note;

    }
    while ( !(note >= 0 && note <= 20) );

    // affichage
        cout << "merci";

    return 0;
}

