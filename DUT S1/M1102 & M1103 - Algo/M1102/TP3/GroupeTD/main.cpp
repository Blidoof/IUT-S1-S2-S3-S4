/*
 Programme : groupeTD
 But : Determiner un groupe de TD � partir d'un groupe de TP.
 Date de derni�re modification : 21/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int tp; // Le groupe de TP de l'�tudiant

    //TRAITEMENTS

    // (clavier) > saisirTP > tp
    cout << "Saisir votre groupe de TP :";
    cin >> tp;

    // tp > afficherTD > (�cran)

    if (tp == 1 || tp== 2)
    {
        cout << "TD1";
    }
    else
    {
        if (tp == 3 || tp == 4)
        {
            cout << "TD2";
        }
        else
        {
            cout << "TD3";
        }
    }

return 0;
}
