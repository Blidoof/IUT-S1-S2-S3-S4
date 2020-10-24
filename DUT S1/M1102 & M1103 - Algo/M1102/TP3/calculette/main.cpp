/*
 Programme : calculette
 But : Calcule un résultat a partir de 2 nombres et d'un opérateur saisi.
 Date de dernière modification : 23/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float val1; // La premiere valeur saisie.
    float val2; // la deuxieme valeur saisie.
    char oper; // L'opérateur entré par l'utilisateur.
    float resultat; // le resultat de l'opération


    //TRAITEMENTS

    // ( clavier) > saisirValeursEtOperateur > val1, val2, oper
    cout << "Veuillez saisir une premiere valeur :";
    cin >> val1;
    cout << "Veuillez saisir une deuxieme valeur :";
    cin >> val2;
    cout << "Veuillez saisir un operateur ( + ; - ; * ; / ) :";
    cin >> oper;

    // oper, val1, val2 > Effectuer l'opération demandée > resultat

    switch (oper)
    {
        case '+'  :
        resultat = val1 + val2;
        break;

        case '-'  :
        resultat = val1 - val2;
        break;

        case '*'  :
        resultat = val1 * val2;
        break;

        case '/'  :
        resultat = val1 / val2;
        break;
    }

    // resultat > afficherResultat > (écran )
    cout << "le resultat de l'operation est : " << resultat;
return 0;
}
