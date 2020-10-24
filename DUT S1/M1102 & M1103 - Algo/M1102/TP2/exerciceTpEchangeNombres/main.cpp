/*
 Programme : Echange de nombres
 But :  Lors de la saise de 2 nombres, �chaneg leur valeurs.
 Date de derni�re modification : 14/09/2018
 Auteur : Arthur Murillo
 Remarques : Ne pas rentrer de chiffres en toutes lettres.
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nb3 = 1; // Une variable interm�diaire aidant � l'�change des nombres.
    double nb1; // Le premeir nombre � �changer.
    double nb2; // Le deuxi�me nombre � �changer.

    // TRAITEMENTS

    // (clavier) >>saisirNombres>> nb1,nb2
    cout << "Saisir le premier nombre : ";
    cin >> nb1;
    cout << "Saisir le deuxieme nombre : ";
    cin >> nb2;

    // nb1, nb2, nb3 >> echange >> nb1, nb2
    nb3 = nb1;
    nb1 = nb2;
    nb2 = nb3;

    // nb1, nb2 >>afficherNombres>> ( �cran )
    cout << "Le nombre 1 est maintenant : " << nb1 << endl;
    cout << "Le nombre 2 est maintenant : " << nb2;

    return 0;
}
