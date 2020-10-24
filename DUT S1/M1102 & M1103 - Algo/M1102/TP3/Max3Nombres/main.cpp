/*
 Programme : maximum3Nombres
 But : Determine le plus grand nombre parmis 2 saisis.
 Date de dernière modification : 23/09/2018
 Auteur : Arthur Murillo
 Remarques : Non terminé : erreur de condition ligne 67.
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb1; // Le premier nombre saisi.
    double nb2; // Le deuxième nombre saisi.
    double nb3; // Le troisième nombre saisi.
    double nbmax; // La valeur maximum parmis les deux nombres.

    //TRAITEMENTS

    // (clavier) > saisirValeursInitiales > nb1, nb2, nb3
    cout << "Saisissez le premier nombre :";
    cin >> nb1;
    cout << "Saisissez le deuxieme nombre :";
    cin >> nb2;
    cout << "Saisissez le troisieme nombre :";
    cin >> nb3;

    // nb1, nb2 > Determiner max nb1 et nb2 > nbmax, egalite1

    if (nb1 < nb2)
    {
        nbmax = nb2;
    }
    else
    {
        if (nb1 == nb2)
        {
            nbmax = nb1;
        }
        else
        {
            nbmax = nb1;
        }
    }

    // nbmax, nb3 > Determiner max nbmax et nb3 > nbmax, egalite2

    if (nbmax < nb3)
    {
        nbmax = nb3;
    }
    else
    {
        if (nbmax == nb3)
        {
            nbmax = nb3;
        }
        else
        {
            nbmax = nbmax;
        }
    }

    // nbmax, nb1, nb2, nb3 > afficherResultats > ( écran )
    if(nbmax == nb1 || == nb2 || == nb3)
    {
        cout << nbmax << " est le plus grand nombre mais il a été saisi deux fois";

    }
    else
    {
        if (nbmax == nb1 && nbmax == nb2 && nbmax == nb3)
        {
            cout << nbmax << " est le plus grand nombre mais il a été saisi trois fois";
        }
        else
        {
        cout << nbmax << "est le plus grand nombre";
        }
    }


return 0;
}
