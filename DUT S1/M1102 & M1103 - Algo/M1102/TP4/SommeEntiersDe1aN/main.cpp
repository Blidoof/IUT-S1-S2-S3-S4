/*
 Programme : sommeDesEntiersDe1aN
 But : Additionne les entiers de 1 à N, n étant une valeur saisie par l'utilisateur
 Date de dernière modification : 28/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    short int nbrSaisi; // Le nombre d'ittérations saisi par l'utilisateur.
    short int somme; // La somme des entiers de 1 à N.


    //TRAITEMENTS

    // initialisationSomme
    somme = 0;

    //clavier > saisirNombre > nbrSaisi
    cout << "saisir le nombre d'itterations : ";
    cin >> nbrSaisi;

    //nbrSaisi, somme > calculSomme > somme
    for (short int i = 1; i <= nbrSaisi ; i += 1 )
    {
        somme = somme + i;
    }

    // somme > afficherResultat > écran
    cout << "Resultat : " << somme;


    return 0;
}

