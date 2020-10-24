/*
  Programme : Effectif d'un groupe de TD
  But : Afficher l'effectif d'un groupe de td
  Date de dernière modification : 12/10/2018
  Auteur : A. MURILLO
  Remarques : se base sur un parcours complet avec
*/

#include <iostream>
using namespace std;

int main (void)
{

    //TYPES / STRUCTURES
    struct UnEtudiant
    {
        string nom; //nom de l'étudiant
        string prenom; // prénom de l'étudiant
        unsigned short int td; // numéro de TD auquel appartient l'étudiant
        unsigned short int tp; // numéro de TP auquel appartient l'étudiant
    };

    //VARIABLES
    unsigned short int tpSaisi; //Le group de tp dont on doit chercher les membres
    const unsigned int EFFECTIFS1 = 85; // Nomùbre d'étudiants inscrits en Semestre 1
    UnEtudiant malo = {"Lemestre", "Malo", 2, 4};
    UnEtudiant xabi = {"Avellan", "Xabi", 2, 4};
    UnEtudiant arthur = {"Muril lo", "Arthur", 2, 4};
    UnEtudiant manon = {"Darget", "Manon", 1, 1};
    UnEtudiant killian = {"Pichard", "Killian", 2, 4};
    UnEtudiant etudS1[EFFECTIFS1] = {malo, xabi, arthur, manon ,killian}; // Tableau regroupant les étudiants de Semestre 1

    //TRAITEMENTS

    // clavier > saisirTp > tpSaisi
    cout << "Merci de saisir un groupe de tp :";
    cin >> tpSaisi;

    //tpSaisi, etudS1 > AfficherEtudiantsDuTpSaisi > écran

    for (unsigned short int i = 0; i <= (EFFECTIFS1 - 1) ; i++ )
    {
        if ( tpSaisi == etudS1[i].tp )
        {
            cout << etudS1[i].nom << " " << etudS1[i].prenom << endl;
        }
    }


    return 0;
}
