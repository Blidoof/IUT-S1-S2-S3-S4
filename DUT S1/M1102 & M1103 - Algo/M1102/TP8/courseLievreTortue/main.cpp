/*
Programme : Simulation du jeu du li�vre et de la tortue pour statistiques
But : Ce programme simule des courses entre un li�vre et une tortue en suivant les r�gles suivantes :
A chaque tour, on lance un d�. Si le 6 sort, le li�vre gagne la partie, sinon la tortue avance d'une case.
La tortue gagne quand elle a avanc� de six cases.
Date de derni�re modification : 26/10/2018
Auteur :A. MURILLO
Remarques : D�l�gue la simulation de course � un sous programme  rand

*/

#include <iostream>
#include <cstdlib> // pour la fonction rand
#include <time.h> // pour r�initialiser rand via time

using namespace std;

// DECLARATION DES SOUS-PROGRAMMES

int random (int min, int max);
// But : renvoie un entier aleatoire dans l'intervalle [min,max[

unsigned long int resultatTortue (unsigned short int valeurDe, unsigned short int position, unsigned long int nbVictoires);
//Indique, a partir d'une valeur valeurDe le nombre de courses gagn�s par la tortue

unsigned long int resultatLievre (unsigned short int valeurDe, unsigned long int nbVictoires);
//Indique, a partir d'une valeur valeurDe le nombre de courses gagn�s par le lievre



int main (void)

{

    // Dictionnaire des variables (A COMPLETER SI NECESSAIRE)
    long int nbCoursesASimuler; // Le nombre de courses � simuler.
    unsigned short int resultatDe ; // Le r�sultat de lancer de d� simul� par random
    unsigned short int positionnement = 0; // La case sur laquelle se situe la tortue
    unsigned long int nbVictoiresTortue = 0; // Le nombre de courses gagn�s par la tortue
    unsigned long int nbVictoiresLievre = 0; // Le nombre de courses gagn�s par le li�vre


    // Traitements

    // Initialisation de la fonction rand()
    srand(time(NULL)); // Laisser cette instruction, elle est n�cessaire pour g�n�rer correctement les nombres al�atoires

    // clavier >> Choisir le nombre de courses � simuler >> nbCoursesASimuler
    cout << "Entrer le nombre de courses a simuler : ";
    cin >> nbCoursesASimuler;

    //Simulation
    for (unsigned short int i = 0 ; i <= nbCoursesASimuler ; i++ )
    {
        resultatDe = random(1,7);
        nbVictoiresLievre = resultatLievre(resultatDe, nbVictoiresLievre);
        nbVictoiresTortue = resultatTortue (resultatDe, positionnement, nbVictoiresTortue);

    }

    // nbVictoiresTortue, nbVictoiresLievre >> Afficher le r�sultat final >> �cran
    cout << "Sur " << nbCoursesASimuler << " courses les resultats sont les suivants :" << endl;
    cout << "Nombre de victoires du lievre : " << nbVictoiresLievre << endl;
    cout << "Nombre de victoires de la tortue : " << nbVictoiresTortue << endl;

    return 0;

}

int random(int min, int max)

{

    return rand() % (max-min) + min;

}

unsigned long int resultatLievre (unsigned short int valeurDe, unsigned long int nbVictoires)
{
    //Retourner r�sultat
    if (valeurDe == 6 )
    {
        nbVictoires++;
    }
    return nbVictoires;

}

unsigned long int resultatTortue (unsigned short int valeurDe, unsigned short int position, unsigned long int nbVictoires)
{
    //Determiner r�sultat
    if (position == 6)
    {
        nbVictoires++;
        position = 0;
    }
    else
    {
        position++;
    }
    //retourner R�sultat
    return nbVictoires;
}


