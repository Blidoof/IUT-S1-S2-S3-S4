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
    unsigned int bSup; //Borne sup�rieure de l'intervalle dans lequel la recherche est effectu�e
    unsigned int bInf; //Borne inf�rieure de l'intervalle dans lequel la recgherche est effectu�e
    bool trouve; //Indique si val a �t� trouv�e ou non dans tab
    unsigned int milieu; // Milieu de l'intervalle dans lequel est effect�ue la recherche
    unsigned int pos; // La position courante de la recherche



    //TRAITEMENTS
    //initialiser la recherche
    //Calcul Borne inf�rieure et borne sup�rieure
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

    //Afficher r�sultat
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
    unsigned int bSupTab = nbCases-1; // La borne sup�rieure du tableau
    unsigned int bInfTab = 0; // La borne inf�rireure du tableau
    unsigned int bSup; // La borne sup�rieure de la recherche dichotomique de val
    unsigned int bInf; // La borne inf�rireure de la recherche dichotomique de val
    unsigned int premiereOcc; // Position de la premiere occurence de val
    unsigned int derniereOcc; //position de la derneire occurence de val
    int milieu; //Le milieu utilis� dans la recherche dichotomique de premiere occurence
    unsigned int posCourante; // Position actuelle de la recherche

    //TRAITEMENTS

    //Chercher la valeur dans le tableau

        //Calcul Borne inf�rieure et borne sup�rieure
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
        //Parcourir le tableau � gauche et � droite de la valeur pour chercher d'autres occurences
        //Chercher � gauche

            //Initialiser recherche
            premiereOcc = milieu; //On part de l'hypoth�se que la valeur est unique pour chercher apr�es les doublons
            derniereOcc = milieu; //On part de l'hypoth�se que la valeur est unique pour chercher apr�es les doublons

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
        //Chercher � droite

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

        //Afficher r�sultat
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

    //Parcourir le tableau � gauche et � droite de la valeur pour chercher d'autres occurences

    //Chercher � gauche

        //Initialiser recherche
        posCourante = premiereOcc-1;




}
