/*
 Programme : validationNote
 But : Fait saisir � l'utilisateur uen note et v�rifie que celle ci est comprise entre 0 et 20
 Date de derni�re modification : 28/09/2018
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
        // �cran > saisieNote > note
        cout << "Saisir une note :";
        cin >> note;

    }
    while ( !(note >= 0 && note <= 20) );

    // affichage
        cout << "merci";

    return 0;
}

