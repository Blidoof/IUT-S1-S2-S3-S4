#include "bibliothequeTableaux.h"
#include <iostream>
using namespace std;

void afficherTableauEntiers  (const int tab[],
                              unsigned int nbTab)
{
    if (nbTab > 0)
    {
        cout << "{";
        for (unsigned int i = 0; i<nbTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[nbTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void recherchePremiereOcc (const int tab[], unsigned int taille, int val )
{
    //VARIABLES
    unsigned int bSup; //Borne supérieure de l'intervalle dans lequel la recherche est effectuée
    unsigned int bInf; //Borne inférieure de l'intervalle dans lequel la recgherche est effectuée
    bool trouve; //Indique si val a été trouvée ou non dans tab
    unsigned int milieu; // Milieu de l'intervalle dans lequel est effectéue la recherche
    unsigned int pos; // La position courante de la recherche



    //TRAITEMENTS
    //initialiser la recherche
    //Calcul Borne inférieure et borne supérieure
    bSup = taille - 1;
    bInf = 0;
    trouve=false;

    //Effectuer la recherche
    while (!( bInf > bSup))
    {
        //Calcul milieu
        milieu = (bSup+bInf)/2;

        if (tab[milieu] == val)
        {
            trouve = true;
            pos = milieu;
            break;
        }

        //Progresser dans l'espace de recherche
        if (tab[milieu] > val)
        {
            bInf = milieu + 1;
        }
        else
        {
            bSup = milieu - 1;
        }

    }

    //Afficher résultat
    if (trouve == true )
    {
        cout << "L'element a ete trouve a la position : " << pos+1;
    }
    else
    {
        cout << "l'element n'a pas ete trouve";
    }

}

void determinerPremierDernier (bool& trouve, const int tab[], int val, unsigned int nbCases)
{
    //VARIABLES
    unsigned int bSupTab = nbCases-1; // La borne supérieure du tableau
    unsigned int bInfTab = 0; // La borne inférireure du tableau
    unsigned int bSup; // La borne supérieure de la recherche dichotomique de val
    unsigned int bInf; // La borne inférireure de la recherche dichotomique de val
    unsigned int premiereOcc; // Position de la premiere occurence de val
    unsigned int derniereOcc; //position de la derneire occurence de val
    int milieu; //Le milieu utilisé dans la recherche dichotomique de premiere occurence
    unsigned int posCourante; // Position actuelle de la recherche

    //TRAITEMENTS

    //Chercher la valeur dans le tableau

        //Calcul Borne inférieure et borne supérieure
        bSup = nbCases - 1;
        bInf = 0;
        trouve=false;

        //Effectuer la recherche
        while ( !( bInf > bSup))
        {
            //Calcul milieu
            milieu = (bSup+bInf)/2;

            if (tab[milieu] == val)
            {
                trouve = true;
                break;
            }

            //Progresser dans l'espace de recherche
            if (tab[milieu] > val)
            {
                bInf = milieu + 1;
            }
            else
            {
                bSup = milieu - 1;
            }

        }

    if(trouve)
    {
        //Parcourir le tableau à gauche et à droite de la valeur pour chercher d'autres occurences
        //Chercher à gauche

            //Initialiser recherche
            premiereOcc = milieu; //On part de l'hypothèse que la valeur est unique pour chercher aprèes les doublons
            derniereOcc = milieu; //On part de l'hypothèse que la valeur est unique pour chercher aprèes les doublons

            posCourante = premiereOcc-1;

            //recherche
            while ((posCourante >= bInfTab))
            {
                if( !(tab[posCourante] == val) )
                {
                    premiereOcc = posCourante+1;
                    break;
                }
                else
                {
                    posCourante--;
                }
            }
        //Chercher à droite

            //initialiser recherche
            posCourante = derniereOcc+1;

            //Recherche
            while( (posCourante <= bSupTab))
            {
                if ( !(tab[posCourante] == val))
                {
                    derniereOcc = posCourante-1;
                    break;
                }
                else
                {
                    posCourante++;
                }
            }

        //Afficher résultat
        if(premiereOcc == derniereOcc)
        {
            cout << "La valeur a ete trouvee a la position : " << premiereOcc;

        }
        else
        {
            cout << " Premiere occurence de la valeur case : " << premiereOcc+1 << endl;
            cout << " Derniere occurence de la valeur case : " << derniereOcc;
        }
    }
    else
    {
        cout << "La valeur recherchee ne fait pas partie du tableau";
    }

    //Parcourir le tableau à gauche et à droite de la valeur pour chercher d'autres occurences

    //Chercher à gauche

        //Initialiser recherche
        posCourante = premiereOcc-1;




}
