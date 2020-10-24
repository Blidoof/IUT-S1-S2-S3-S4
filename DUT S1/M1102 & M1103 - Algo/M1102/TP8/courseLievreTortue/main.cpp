/*
Programme : Simulation du jeu du lièvre et de la tortue pour statistiques
But : Ce programme simule des courses entre un lièvre et une tortue en suivant les règles suivantes :
A chaque tour, on lance un dé. Si le 6 sort, le lièvre gagne la partie, sinon la tortue avance d'une case.
La tortue gagne quand elle a avancé de six cases.
Date de dernière modification : 26/10/2018
Auteur :A. MURILLO
Remarques : Délégue la simulation de course à un sous programme  rand

*/

#include <iostream>
#include <cstdlib> // pour la fonction rand
#include <time.h> // pour réinitialiser rand via time

using namespace std;

// DECLARATION DES SOUS-PROGRAMMES

int random (int min, int max);
// But : renvoie un entier aleatoire dans l'intervalle [min,max[

unsigned long int resultatTortue (unsigned short int valeurDe, unsigned short int position, unsigned long int nbVictoires);
//Indique, a partir d'une valeur valeurDe le nombre de courses gagnés par la tortue

unsigned long int resultatLievre (unsigned short int valeurDe, unsigned long int nbVictoires);
//Indique, a partir d'une valeur valeurDe le nombre de courses gagnés par le lievre



int main (void)

{

    // Dictionnaire des variables (A COMPLETER SI NECESSAIRE)
    long int nbCoursesASimuler; // Le nombre de courses à simuler.
    unsigned short int resultatDe ; // Le résultat de lancer de dé simulé par random
    unsigned short int positionnement = 0; // La case sur laquelle se situe la tortue
    unsigned long int nbVictoiresTortue = 0; // Le nombre de courses gagnés par la tortue
    unsigned long int nbVictoiresLievre = 0; // Le nombre de courses gagnés par le lièvre


    // Traitements

    // Initialisation de la fonction rand()
    srand(time(NULL)); // Laisser cette instruction, elle est nécessaire pour générer correctement les nombres aléatoires

    // clavier >> Choisir le nombre de courses à simuler >> nbCoursesASimuler
    cout << "Entrer le nombre de courses a simuler : ";
    cin >> nbCoursesASimuler;

    //Simulation
    for (unsigned short int i = 0 ; i <= nbCoursesASimuler ; i++ )
    {
        resultatDe = random(1,7);
        nbVictoiresLievre = resultatLievre(resultatDe, nbVictoiresLievre);
        nbVictoiresTortue = resultatTortue (resultatDe, positionnement, nbVictoiresTortue);

    }

    // nbVictoiresTortue, nbVictoiresLievre >> Afficher le résultat final >> écran
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
    //Retourner résultat
    if (valeurDe == 6 )
    {
        nbVictoires++;
    }
    return nbVictoires;

}

unsigned long int resultatTortue (unsigned short int valeurDe, unsigned short int position, unsigned long int nbVictoires)
{
    //Determiner résultat
    if (position == 6)
    {
        nbVictoires++;
        position = 0;
    }
    else
    {
        position++;
    }
    //retourner Résultat
    return nbVictoires;
}


