/*
 Programme : validationSemestre1
 But : D�termine si un �l�ve a valid� son premier semestre.
 Date de derni�re modification : 23/09/2018
 Auteur : Arthur Murillo
 Remarques : notes entre 0 et 20
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float moyInf; // La moyenne dans l'UE informatique
    float moyComp; // La moyenne dans l'UE compl�mentaire
    float moyGene; // La moyenne g�n�rale du semestre de l'�tudiant

    //TRAITEMENTS

    // (clavier )> saisirMoyennes > moyInf, moyComp
    cout << "Saisir la moyenne dans l'Unit� d'Enseignement informatique :";
    cin >> moyInf;
    cout << "Saisir la moyenne dans l'Unit� d'Enseignement compl�mentaire :";
    cin >> moyComp;

    // moyInf, moyComp > calculerMoyenneGenerale > moyGene
    moyGene = (moyInf+moyComp)/2;


    // moyGene > determinerPassationDuTrimestre > ( �cran )
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
