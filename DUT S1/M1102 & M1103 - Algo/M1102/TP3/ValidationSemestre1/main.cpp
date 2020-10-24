/*
 Programme : validationSemestre1
 But : Détermine si un élève a validé son premier semestre.
 Date de dernière modification : 23/09/2018
 Auteur : Arthur Murillo
 Remarques : notes entre 0 et 20
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float moyInf; // La moyenne dans l'UE informatique
    float moyComp; // La moyenne dans l'UE complémentaire
    float moyGene; // La moyenne générale du semestre de l'étudiant

    //TRAITEMENTS

    // (clavier )> saisirMoyennes > moyInf, moyComp
    cout << "Saisir la moyenne dans l'Unité d'Enseignement informatique :";
    cin >> moyInf;
    cout << "Saisir la moyenne dans l'Unité d'Enseignement complémentaire :";
    cin >> moyComp;

    // moyInf, moyComp > calculerMoyenneGenerale > moyGene
    moyGene = (moyInf+moyComp)/2;


    // moyGene > determinerPassationDuTrimestre > ( écran )
    if (moyGene < 8)
    {
        cout << "Semestre un non valide";
    }
    else
    {
        if (moyGene >= 8 && moyGene <10)
        {
            cout << "Semestre compensable";
        }
        else
        {
            cout << "Semestre Valide";
        }
    }

return 0;
}
