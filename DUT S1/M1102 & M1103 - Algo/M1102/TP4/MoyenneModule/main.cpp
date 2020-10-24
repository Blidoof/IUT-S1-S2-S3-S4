/*
 Programme : calculerMoyenneModule
 But : à partir d'un certain nombre saisi, calcule la moyenne d'un module.
 Date de dernière modification : 28/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    short int nbNotes; // Le nombre de notes saisie
    float sommeNotes; // La somme des notes saisies
    float noteSaisie; // Une des notes saisies par l'utilisateur
    float moyenne; // La moyenne des notes saisies

    //TRAITEMENTS

    //Initialisation
    sommeNotes = 0;

    //clavier, sommeNote > determinerSommeNotes > sommeNotes

        // clavier > saisirNombreNotes > nbNotes
        cout << "Quel est le nombre de notes a saisir ? : " << endl;
        cin >> nbNotes;

        //saisirNotes
        cout << "Saisir note : " << endl;

        // sommeNotes > additionnerLesNotes > sommeNotes
        for (short int i = 1 ; i <= nbNotes ; i += 1 )
        {

            //saisirNotes
            cin >> noteSaisie;

            //Additioner
            sommeNotes = sommeNotes + noteSaisie;
        }

    //sommeNotes, nbNotes > calculerMoyenne > moyenne
    moyenne = sommeNotes / nbNotes;

    //moyenne > afficherMoyenne > écran
    cout << "moyenne : " << moyenne;


    return 0;
}


