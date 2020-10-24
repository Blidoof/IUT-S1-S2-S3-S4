/*
 Programme : MoyenneModule - Variante
 But :Determine la moyenne d'un module et affiche un message d'erreur le cas échéant.
 Date de dernière modification : 28/09/2018
 Auteur : Arthur Murillo
 Remarques : rentrer '999' pour lancer le calcul de la moyenne.
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float noteSaisie; // La note saisie par l'uilisateur.
    float moyenne; //Moyenne des notes saisie.
    short int nbNotes; // Nombre de notes saisies.
    float sommeNotes; //Somme des notes saisies.

    //TRAITEMENTS
    //Initialisations
    sommeNotes = 0;
    nbNotes = 0;

    //sommeNotes, nbNotes > determinerSommeNotesEtNombreDeNotes > nbNotes, sommeNotes

    cout << "saisir les notes :";

    for ( ; ; )
    {
        // clavier > saisirNote > noteSaisie
        cin >> noteSaisie;

        if (noteSaisie == 999)
        {
            break;
        }

        //sommeNotes, nbNotes, noteSaisie > determinerPriseEnCompteNote > sommeNotes, nbNotes

        if (noteSaisie >= 0 && noteSaisie <= 20)
        {
            nbNotes++ ;
            sommeNotes = sommeNotes + noteSaisie;
        }
        else
        {
            cout << "Erreur. La note doit etre comprise entre 0 et 20.";
        }
    }

    // nbNotes, sommeNotes > calculMoyenne > moyenne

    moyenne = sommeNotes / nbNotes;

    //moyenne > Affichages > ecran

    if (nbNotes == 0)
    {
        cout << "Erreur. Veuillez saisir une note.";
    }
    else
    {
        cout << "moyenne : " << moyenne;
    }


    return 0;
}
