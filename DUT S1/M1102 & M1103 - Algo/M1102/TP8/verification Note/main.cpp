/*
  Programme :Verification d'une note
  But : Verifie qu'un nombre saisi est une note ( ie est compris entre 0 et 20 )
  Date de dernière modification : 24 /10 /2018
  Auteur : A. MURILLO
  Remarques : la vérification est effectuée par une fonction estNote
*/

#include <iostream>
using namespace std;

//DECLARATION DES SOUS PROGRAMMES
bool estNote (long double nombre);
// But : determiner si un nombre est compris entre 0 et 20

int main (void)
{
    //VARIABLES
    long double nb; // Un nombre
    bool noteValide; // Indicateur de la validité d'une note

    //TRAITEMENTS
    //saisir nb
    cout << "Veuillez saisir un nombre :";
    cin >> nb;

    //verifier si nb est une note
    noteValide = estNote(nb);

    //Afficher résultat
    if (noteValide == true)
    {
        cout << "Le nombre est une note.";
    }
    else
    {
        cout << "Le nombre n'est pas une note.";
    }
    return 0;
}

//DEFINITION DES SOUS PROGRAMMES

bool estNote (long double nombre)
{
    return ((0<= nombre && nombre <= 20) ? true : false );
}
