#ifndef CHAINES_H
#define CHAINES_H

#include <iostream>
using namespace std;

/*DECLARATION DES SOUS PROGRAMMES MIS A DISPOSITION
PAR LE MODULE */

unsigned short int remplacerCaractere(char carCherche, char carSubstitution, string& mot);
/* But : Permet, dans une cha�ne de caract�res "mot" de remplacer un caract�re carCherch� par un autre, 
carSubstitution. Retourne le nombre de changements effectu�s */

unsigned int getNbMots (const string& phrase, string separateurs);
// But : compte le nombre de mots dans une phrase � partir d'une liste de s�parateurs de mots

void chiffrementPhrase (unsigned short int cle, string& phrase, string separateurs);
/* But : Chiffre une phrase selon la m�thode du chiffre de Cesar � partir d'une cl� de chiffrage, 
et d'une liste de s�parateurs de mots qui ne doivent pas �tre crypt�s */

void dechiffrementPhrase (unsigned short int cle, string& phrase, string separateurs);
/*But : Dechiffre une phrase selon la m�thode du chiffre de Cesar � partir d'une cl� de d�chiffrage, 
et d'une liste de s�parateurs de mots qui ne doivent pas �tre d�crypt�s */

#endif // CHAINES_H
