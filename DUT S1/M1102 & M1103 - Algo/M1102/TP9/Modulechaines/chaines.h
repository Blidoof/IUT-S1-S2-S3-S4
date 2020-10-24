#ifndef CHAINES_H
#define CHAINES_H

#include <iostream>
using namespace std;

/*DECLARATION DES SOUS PROGRAMMES MIS A DISPOSITION
PAR LE MODULE */

unsigned short int remplacerCaractere(char carCherche, char carSubstitution, string& mot);
/* But : Permet, dans une chaîne de caractères "mot" de remplacer un caractère carCherché par un autre, 
carSubstitution. Retourne le nombre de changements effectués */

unsigned int getNbMots (const string& phrase, string separateurs);
// But : compte le nombre de mots dans une phrase à partir d'une liste de séparateurs de mots

void chiffrementPhrase (unsigned short int cle, string& phrase, string separateurs);
/* But : Chiffre une phrase selon la méthode du chiffre de Cesar à partir d'une clé de chiffrage, 
et d'une liste de séparateurs de mots qui ne doivent pas être cryptés */

void dechiffrementPhrase (unsigned short int cle, string& phrase, string separateurs);
/*But : Dechiffre une phrase selon la méthode du chiffre de Cesar à partir d'une clé de déchiffrage, 
et d'une liste de séparateurs de mots qui ne doivent pas être décryptés */

#endif // CHAINES_H
