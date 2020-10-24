#ifndef DEFINITIONSTYPES
#define DEFINITIONSTYPES
#include <iostream>

using namespace std;

struct UneAdresse
{
    unsigned short int numRue;
    string nomRue;
    unsigned int codePostal;
    string nomVille;
};
struct UnePersonne
{
    string nom;
    string prenom;
    UneAdresse adresse;
    unsigned int nbEnfants;
};

#endif // DEFINITIONSTYPES
