/*
  Programme : Moyenne des valeurs d'un tableau
  But : Calculer la moyenne de toutes les notes saisies dans un tableau
  Date de dernière modification : 10/10/2018
  Auteur : A. MURILLO
  Remarques : Code basé sur un parcour complet avec traitement systématique.
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    //VARIABLES
    const unsigned short int NBCASES = 10; // Le nombre de cases du tableau.
    unsigned short int tab[NBCASES] = {1, 3, 5, 14, 16, 12, 18, 8, 10, 10}; // le tableau de taille NBCASES.
    unsigned short int totNotes; // La somme des notes du tableau.
    float moy; // La moyenne des valeurs du tableau.

    //TRAITEMENTS

    //nbCases > CalculerMoyenne > moy

    //Initialisation
    totNotes = 0;

    //totNotes > DeterminerTotalNotes > totNotes
    for (unsigned short int i = 0 ; i <= (NBCASES - 1) ; i++ ) // i est l'indice de la case dans laquelle la saisie est réalisée.
    {
        totNotes += tab[i];
    }

    //totNotes > CalculerResultat > moy
    moy = float(totNotes)/NBCASES; // on considère totNotes comme un nombre à virgule le temps du calcul de la moyenne pour avoir une valeur correcte.
    cout << moy;

    return 0;
}
