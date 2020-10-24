/*
 Programme : signeNombre
 But : Determiner le signe d'un nombre saisi.
 Date de dernière modification : 21/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb; // Le nombre saisi dont le signe est à déterminer.

    //TRAITEMENTS

    // (clavier) > saisirNombre > nb

    cout << "Saisir le nombre :";
    cin >> nb;

    // nb > determinerSigne > (écran )

    if (nb < 0)
    {
        cout << "Le nombre est negatif";
    }
    else
    {
        if (nb == 0)
        {
            cout << "le nombre est 0";
        }
        else
        {
            cout << "Le nombre est positif";
        }
    }
return 0;
}
