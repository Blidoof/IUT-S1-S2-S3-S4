#include "chaines.h"

//DECLARATION DES SOUS PROGRAMMES UTILISES PAR LE MODULE
bool etreSeparateur (string separateurs, char caractere);
/* Determine à partir d'une liste de séparateurs si un caractère carSaisi
est un séparateur en retournant un indicateur booléen */

char chiffrementCesar (unsigned short int cle, char lettre);
//Chiffre une lettre selon le chiffrement de Cesar, à partir d'une cle de chiffrement

char dechiffrementCesar (short int cle, char lettre);
//Dechiffre une lettre selon le chiffrement de Cesar, à partir d'une cle de chiffrement

//DEFINITION DES SOUS PROGRAMMES PROPOSES PAR LE MODULE

//remplacerCaractère
unsigned short int remplacerCaractere (char carCherche, char carSubstitution, string& mot)
{
    //Remplacer le caractère et compter le nombre de changements
    unsigned int nbChangements = 0; // Le nombre de changements effectués par remplacerCaractère
    unsigned short int nbIterations = mot.size()-1 ; // Le nombre d'itérations effectuées

    for (unsigned int i = 0; i <= nbIterations  ; i++ )
    {
        if (mot[i] == carCherche)
        {
            mot[i] = carSubstitution;
            nbChangements++;
        }
    }

    //Retourner Résultat
    return nbChangements;

}

//etreSeparateur
bool etreSeparateur (string separateurs, char caractere)
{
    //VARIABLES
    bool trouve; // Indique si le séparateur cherché a été trouvé dans la liste
    unsigned int pos; // position dans la liste de séparateurs

    //TRAITEMENTS
    //chercher séparateur
    trouve = false;
    pos = 0;

    for ( ; ; )
    {
        if (pos >= separateurs.size())
        {
            break;
        }

        if (caractere == separateurs[pos])
        {
            trouve = true;
            break;
        }
        else
        {
            pos++;
        }
    }

    //retourner résultat
        return trouve;
}

//getNbMots
unsigned int getNbMots (const string& phrase, string separateurs)
{
    //VARIABLES
    unsigned short int nbMots = 0; // Le nombre de mots dans la phrase
    unsigned int nbIterations; // Le nombre d'itérations à effectuer

    //TRAITEMENTS
    //Compter mots
    nbMots = 0;
    nbIterations = phrase.size()-2 ;

    for (unsigned short int i = 1 ; i <= nbIterations ; i++ )
    {
        if (etreSeparateur(separateurs, phrase[i]) == true && etreSeparateur (separateurs, phrase[i-1] )== false)
        {
            nbMots++;
        }
    }

    //Determiner si 1a Dernière lettre est un séparateur

    if (etreSeparateur(separateurs, phrase[phrase.size()-1])== false)
    {
        nbMots++;
    }

    //Retourner Résultat
    return nbMots;
}

//Chiffrement de Cesar
char chiffrementCesar (unsigned short int cle, char lettre)
{
    //VARIABLES
    char lettreChiffree; // La lettre apres chiffrement

    //TRAITEMENTS
    //cle, lettre >> Tester si la lettre est minuscule ou majuscule puis la dechiffrer >> lettreChiffree

    if(lettre>='A' && lettre<='Z')
    {
        lettreChiffree = (lettre - 'A' + cle)%26 + 'A';
    }
    else
    {
        lettreChiffree = (lettre - 'a' + cle)%26 + 'a';
    }

    //lettreChiffree >> Retourner Resultat >> écran
    return lettreChiffree;
}

//Dechiffrement Cesar
char dechiffrementCesar (short int cle, char lettre)
{
    //VARIABLES
    char lettreDechiffree; // La lettre apres dechiffrement

    //TRAITEMENTS
    //cle, lettre >> //Tester si la lettre est minuscule ou majuscule puis la dechiffrer >> lettreDechiffree
    cle = (-cle % 26) + 26;

    if(lettre>='A' && lettre<='Z')
    {
        lettreDechiffree = (lettre - 'A' + cle)%26 + 'A';
    }
    else
    {
        lettreDechiffree = (lettre - 'a' + cle)%26 + 'a';
    }

    //lettreDechiffree >> Retourner Resultat >> écran
    return lettreDechiffree;
}
//ChiffrementPhrase
void chiffrementPhrase (unsigned short int cle, string& phrase, string separateurs)
{
    //Chiffrer
    for ( unsigned short int i = 0 ; i <= phrase.size()-1 ; i++)
    {
        if (etreSeparateur(separateurs, phrase[i]) == false )
        {
            phrase[i] = chiffrementCesar(cle, phrase[i]);
        }
    }

    //afficher résultat
    cout << "La phrase chiffree est : " << phrase << endl;
}

//Dechiffrementcesar
void dechiffrementPhrase (unsigned short int cle, string& phrase, string separateurs)
{
    //Dechiffrer
    for ( unsigned short int i = 0 ; i <= phrase.size()-1 ; i++)
    {
        if (etreSeparateur(separateurs, phrase[i]) == false )
        {
            phrase[i] = dechiffrementCesar(cle, phrase[i]);
        }
    }

    //Afficher résultat
    cout << "La phrase dechiffree est : " << phrase << endl;
}
