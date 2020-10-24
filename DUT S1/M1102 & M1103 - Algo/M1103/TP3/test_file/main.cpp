#include <iostream>
#include "../jeu51/file.h"

using namespace std;

int main(void)
{
    //Declaration et initialisation de la file
    UneFile maFile;
    initialiser(maFile);

    //Ajout d'éléments dans la file
    enfiler (maFile, 0); enfiler(maFile, 1);
    enfiler (maFile, 2); enfiler(maFile, 3);
    enfiler (maFile, 4); enfiler(maFile, 5);

    //Declarer et initialiser tableau d'entiers
    const unsigned int TAILLE = 5; //Taille du tableau
    unsigned int tab[TAILLE] = {10,20,30,40,50};

    //Ajouter dans la file les elements du tableau
    for (unsigned short int i = 0;i<=TAILLE-1 ; i++ )
    {
        enfiler (maFile, tab[i]);
    }

    //Afficher contenu de la file
    while ( !estVide(maFile))
    {
        cout << premier(maFile) <<"...";
        defiler(maFile);
    }
    return 0;
}
