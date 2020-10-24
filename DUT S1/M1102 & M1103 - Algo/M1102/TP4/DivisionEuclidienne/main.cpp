/*
 Programme : divisionEuclidienne
 But : A partir d'un nombre saisi et d'un facteur de division , met en place une division euclidienne et affiche le reste.
 Date de dernière modification : 29/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    short int nbSaisi; // Le nombre à diviser saisi par l'utilisateur
    short int quotient; // Le quotient saisi par l'utilisateur
    short int itteration; // Le nombre de soustraction effectuées
    float reste; // le reste de l'addition

    //TRAITEMENTS

    //Initialisations
    reste = 0;
    itteration = 0;

    //clavier > saisirNombre > nbSaisi
    cout << "Veuillez saisir un nombre a diviser :";
    cin >> nbSaisi;

    //clavier > saisirQuotient > quotient
    cout << "Veuillez saisir le nombre par lequel vous desirez diviser :";
    cin >> quotient;

    // nbSaisi, quotient, itteration, reste > calculerResultatEtReste > itteration, reste

    do
    {
        nbSaisi = nbSaisi - quotient;
        reste = nbSaisi;
        itteration = itteration + 1;
    }
    while ( !(reste < quotient));

    // reste, itteration > AfficherResultat > écran
    cout << "Le resultat est : " << itteration << "," << reste;



    return 0;
}


