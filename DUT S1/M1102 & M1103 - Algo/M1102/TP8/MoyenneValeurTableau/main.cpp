/*
  Programme :Moyenne des valeurs d'un tableau
  But : Calcule et affiche la moyenne des valeurs d'un tableau de nombres
  Date de dernière modification : 24/10/2018
  Auteur : A. MURILLO
  Remarques :Le calcul est effectué par une fonction moyenneTableau
*/

#include <iostream>
using namespace std;

//DECLARATION DES SOUS PROGRAMMES
float moyenneTableau (const float tab[], unsigned int nbCases);
//but : Calcule la moyenne des valeurs du tableau tab de taille nbCases

int main (void)
{
    //VARIABLES
    unsigned int tailleTab = 3; // la taille du tableau
    float notesElevesS1[tailleTab] = {14,7.5,20}; // Le tableau de notes des eleves du S1
    float moyenneS1; // La moyenne des notes contenues dans notesElevesS1

    //TRAITEMENTS
    //calculer moyenne
    moyenneS1 = moyenneTableau(notesElevesS1, tailleTab);

    //Afficher moyenne
    cout << "La moyenne est :" << moyenneS1;

    return 0;
}

//DEFINITION DES SOUS PROGRAMMES
float moyenneTableau (const float tab[], unsigned int nbCases)
{
    //VARIABLES
    float totNotes; // Le total des notes du tableau tab
    float moyenne; //La moyenne des notes contenues dans tab

    //TRAITEMENTS
    //Calculer totNotes
    totNotes = 0;

    for ( unsigned short i= 0 ; i <= nbCases ; i++ )
    {
        totNotes += tab[i];
    }

    //calculerMoyenne
    moyenne = totNotes/nbCases;

    //RetournerValeur
    return moyenne;
}
