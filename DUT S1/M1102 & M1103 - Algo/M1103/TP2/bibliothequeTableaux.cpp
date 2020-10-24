#include "bibliothequeTableaux.h"
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
/** ZONE 1. - DéCLARATIONS des SOUS-PROGRAMMES utilisés dans la bibliothèque    */
//  les corps se trouvent en bas de ce fichier
//-------------------------------------------------------------------------------

void echanger (int& x, int& y);
// echange le contenur de deux entiers x et y

void echanger (UnePersonne& x, UnePersonne& y);
// echange le contenur de deux enregistrements x et y

/** FIN des DéCLARATIONS des SOUS-PROGRAMMES utilisés dans la bibliothèque */

void faireMonterLaBulle (int tab[], unsigned int ici, unsigned int& nbEchange);
//Selon la méthode du tri à bulle, fait remonter la plus grande valeur de tab a la position ici

void faireMonterLaBullePersonneNom (UnePersonne tab[], unsigned int ici, unsigned int& nbEchanges);
//Selon la méthode du tri à bulle, fait remonter la personne avec le nom le plus proche de z dans l'alphabet a la position ici


void faireMonterLaBullePersonneVille (UnePersonne tab[], unsigned int ici, unsigned int& nbEchanges);
//Selon la méthode du tri à bulle, fait remonter la personne avec la ville le plus proche de z dans l'alphabet a la position ici


//-------------------------------------------------------------------------
/** ZONE 2.- DéFINITIONS des SOUS-PROGRAMMES DE la bibliothèque            */
//-------------------------------------------------------------------------



/** afficherTableau ------------------------------------------*/
void afficherTableau  (const int tab[],
                       unsigned int nbTab)
{
    if (nbTab > 0)
    {
        cout << "{";
        for (unsigned int i = 0; i<nbTab-1; i++)
        {
            cout << tab[i] << ", " ;

        }        cout << tab[nbTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void afficherTableau  (const UnePersonne tab[],
                       unsigned int nbTab)
{
    if (nbTab > 0)
    {
        cout << "{"<< endl;
        for (unsigned int i = 0; i<nbTab; i++)
        {
            cout << "  {" << tab[i].nom << ", " << tab[i].prenom << ", " ;
            cout <<        tab[i].nbEnfants << ", ";
            cout <<        tab[i].adresse.numRue << " " ;
            cout <<        tab[i].adresse.nomRue << " ";
            cout <<        tab[i].adresse.codePostal << " ";
            cout <<        tab[i].adresse.nomVille ;
            cout << "}" << endl;
        };
        cout << "}" << endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}
//============================================================*/

/** triBulle -------------------------------------------------*/
// question 11
void   triBulle (int tab[], const unsigned int nbTab)
{


    //VARIABLES
    unsigned int echanges =0; // Le nombre d'échanges effectués par le tri
    unsigned int ici; //La dernière case non triée de la partie non triée du tableau
    unsigned int bDeb; //La borne de début de la zone de tri
    unsigned int bFin; //La borne de fin de la zone de tri

    //TRAITEMENTS
    //Initialisation
    bDeb = 1;
    bFin = nbTab-1;

    //Faire le tri
    for ( ici = bFin ; ici >= bDeb ; ici-- )
    {
        faireMonterLaBulle(tab, ici, echanges);
    }
    cout << echanges << " echanges ont ete effectues" <<endl<<endl;
}

// Question 13
void   triBulle_nom (UnePersonne tab[],
                     const unsigned int nbTab)
{
     //VARIABLES
    unsigned int echanges =0; // Le nombre d'échanges effectués par le tri
    unsigned int ici; //La dernière case non triée de la partie non triée du tableau
    unsigned int bDeb; //La borne de début de la zone de tri
    unsigned int bFin; //La borne de fin de la zone de tri

    //TRAITEMENTS
    //Initialisation
    bDeb = 1;
    bFin = nbTab-1;

    //Faire le tri
    for ( ici = bFin ; ici >= bDeb ; ici-- )
    {
        faireMonterLaBullePersonneNom(tab, ici, echanges);
    }
    cout << echanges << " echanges ont ete effectues" <<endl<<endl;
}

// Question 14
void   triBulle_ville (UnePersonne tab[], const unsigned int nbTab)
{
     //VARIABLES
    unsigned int echanges = 0; // Le nombre d'échanges effectués par le tri
    unsigned int ici; //La dernière case non triée de la partie non triée du tableau
    unsigned int bDeb; //La borne de début de la zone de tri
    unsigned int bFin; //La borne de fin de la zone de tri

    //TRAITEMENTS
    //Initialisation
    bDeb = 1;
    bFin = nbTab-1;

    //Faire le tri
    for ( ici = bFin ; ici >= bDeb ; ici-- )
    {
        faireMonterLaBullePersonneVille(tab, ici, echanges);
    }
    cout << echanges << " echanges ont ete effectues" <<endl<<endl;
}

//============================================================*/
/** triParSelectionPlace---------------------------------------*/
//=============================================================*/

/** triParInsertion -------------------------------------------*/
//=============================================================*/

/** FIN DES DéFINITIONS des SOUS-PROGRAMMES DE la bibliothèque  */



//--------------------------------------------------------------------------
/** ZONE 3.- DéFINITIONS des SOUS-PROGRAMMES utilisés dans la bibliothèque */
//--------------------------------------------------------------------------

void faireMonterLaBulle (int tab[], unsigned int ici, unsigned int& nbEchange)
//Selon la méthode du tri à bulle, fait remonter la plus grande valeur de tab a la position ici
{
    for (unsigned int i = 0; i <= ici ; i++ )
    {
        if ( tab[i] > tab[i+1] )
        {
            echanger(tab[i],tab[i+1]);
            nbEchange++;
        }
    }
}

void faireMonterLaBullePersonneNom (UnePersonne tab[], unsigned int ici, unsigned int& nbEchanges)
//Selon la méthode du tri à bulle, fait remonter la personne avec le nom le plus proche de z dans l'alphabet a la position ici
{
    for (unsigned int i = 0; i <= ici ; i++ )
    {
        if (tab[i].nom > tab[i+1].nom)
        {
            echanger (tab[i], tab[i+1]);
            nbEchanges++;
        }
    }
}

void faireMonterLaBullePersonneVille (UnePersonne tab[], unsigned int ici, unsigned int& nbEchanges)
//Selon la méthode du tri à bulle, fait remonter la personne avec le nom le plus proche de z dans l'alphabet a la position ici
{
    for (unsigned int i = 0; i <= ici ; i++ )
    {
        if (tab[i].adresse.nomVille[0] > tab[i+1].adresse.nomVille[0])
        {
            echanger (tab[i], tab[i+1]);
            nbEchanges++;
        }
    }
}

void echanger (int& x, int& y)
// echange le contenur de deux entiers x et y
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void echanger (UnePersonne& x, UnePersonne& y)
// echange le contenur de deux enregistrements x et y
// echange le contenur de deux entiers x et y
{
    UnePersonne temp;
    temp = x;
    x = y;
    y = temp;
}

