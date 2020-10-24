/*
 Programme : maximum2Nombres
 But : Determine le plus grand nombre parmis 2 saisis.
 Date de dernière modification : 21/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nb1; // Le premier nombre saisi.
    double nb2; // Le deuxième nombre saisi.
    double maxi; // La valeur maximum parmis les deux nombres.
    bool egalite; // Un indicateur de l'égalité de nb1 et nb2

    //TRAITEMENTS

    // (clavier) > saisirValeursInitiales > nb1, nb2
    cout << "Saisissez le premier nombre :";
    cin >> nb1;
    cout << "Saisissez le deuxieme nombre :";
    cin >> nb2;

    // nb1, nb2 > Determiner max nb1 et nb2 > maxi, egalite
    egalite = false;

    if (nb1 < nb2)
    {
        maxi = nb2;
    }
    else
    {
        if (nb1 == nb2)
        {
            egalite = true;
        }
        else
        {
            maxi = nb1;
        }
    }

    // maxi, egalite > AfficherResultat > (écran )

    if ( egalite == false )
    {
        cout << maxi << " est le plus grand nombre";
    }
    else
    {
        cout << "Les deux nombres sont egaux";
    }
return 0;
}
