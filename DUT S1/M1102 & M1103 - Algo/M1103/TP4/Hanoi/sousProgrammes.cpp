#include <iostream>
#include "sousProgrammes.h"

using namespace std;


void afficherTour (UnePile p)
{
    while (!estVide(p))
    {
        cout  << sommet(p);
        depiler(p);

        if (estVide(p))
        {
            break;
        }

        cout  << ", " ;

    }
}

/* A vous de choisir la version souhaitée
void afficherTour (const UnePile& p)
{
    // à compléter
}

void afficherTour (UnePile& p)
{
    // à compléter
}

*/

void deplacerSommet (UnePile& tSource, UnePile& tCible)
{
    /* à compléter */
}

void deplacerPetit  (UnePile& t1, UnePile& t2, UnePile& t3, unsigned short int& posPetit, char choix)
/*Déplace le petit disque vers une autre tour selon la DIRECTIVE donnée par deplacementPetit
*/
{
    if (choix =='a' || choix =='A')
    {
        switch (posPetit)
        {
        case 1 :
            empiler(t2,sommet(t1));
            depiler(t1);
            posPetit = 2;
            break;
        case 2 :
            empiler(t3,sommet(t2));
            depiler(t2);
            posPetit = 3;
            break;
        case 3 :
            empiler(t1,sommet(t3));
            depiler(t3);
            posPetit = 1;
            break;
        }
    }
    else if (choix =='b' || 'B')
    {
        switch (posPetit)
        {
        case 1 :
            empiler(t3,sommet(t1));
            depiler(t1);
            posPetit = 3;
            break;
        case 2 :
            empiler(t1,sommet(t2));
            depiler(t2);
            posPetit = 1;
            break;
        case 3 :
            empiler(t2,sommet(t3));
            depiler(t3);
            posPetit = 2;
            break;
        }
    }
}

void deplacerAutre (UnePile& t1, UnePile& t2, UnePile& t3, unsigned short int posPetit)
{
    unsigned int cas;   /* indenticateur. Résultat de la table de vérité.
                            Indique le déplacement à faire sur le disque
                            'Autre que le petit' :
                            12 --> déplacement de t1 --> t2
                            23 --> déplacement de t2 --> t3
                            31 --> déplacement de t3 --> t1
                            21 --> déplacement de t2 --> t1
                            32 --> déplacement de t3 --> t2
                            13 --> déplacement de t1 --> t3
							0  --> pas de déplacement
                         */


    /** Etape 1 :
    deplacementPetit, t1, t2, t3 >> identifier le mouvement à faire >> cas  */

    if (posPetit == 1)
    {
        /* le petit est sur la tour t1.
           L'autre mouvement sera donc : t2 -> t3 ou t3 -> t2 */
        if (estVide (t3) && !estVide(t2))
        {
            /* le petit est sur la tour t1
               et t3 est vide, t2 ne l'est pas :  transfert t2 -> t3 */
            cas = 23;
        }
        else if (!estVide (t3) && estVide(t2))
        {
            /* le petit est sur la tour t1
               et t2 est vide, t3 ne l'est pas : transfert t3 -> t2  */
            cas = 32;
        }
        else if (!estVide (t3) && !estVide(t2))
        {
            /* le petit est sur t1,
                t2 et t3 non vides ==> comparaison des sommets */
            if (sommet(t2) < sommet(t3))
            {
                /* transfert de t2 vers t3 */
                cas = 23;
            }
            else
            {
                /* transfert de t3 vers t2 */
                cas = 32;
            }
        }
        else
        {
            /* le petit est sur t1,
               t2 et t3  vides ==> rien */
            cas = 0;
        }
    }
    else if (posPetit == 2)
    {
        /* le petit est sur la tour t2.
           L'autre mouvement sera donc : t1 -> t3 ou t3 -> t1 */

        if (estVide (t1) && !estVide(t3))
        {
            /* le petit est sur la tour t2
               et t1 est vide, t3 ne l'est pas :  transfert t1 -> t3 */
            cas = 31;
        }
        else if (!estVide (t1) && estVide(t3))
        {
            /* le petit est sur la tour t1
               et t2 est vide, t3 ne l'est pas : transfert t3 -> t1  */
            cas = 13;
        }
        else if (!estVide (t1) && !estVide(t3))
        {
            /* le petit est sur t1,
                t1 et t3 non vides ==> comparaison des sommets */
            if (sommet(t1) < sommet(t3))
            {
                /* transfert de t1 vers t3 */
                cas = 13;
            }
            else
            {
                /* transfert de t3 vers t1 */
                cas = 31;
            }
        }
        else
        {
            /* le petit est sur t2,
               t1 et t3  vides ==> rien */
            cas = 0;

        }
    }
    else //deplacementPetit == 3
        /* le petit est sur la tour t3.
           L'autre mouvement sera donc : t1 -empiler(t2,sommet(t1));
        depiler(t1);> t2 ou t2 -> t1  */

        if (estVide (t1) && !estVide(t2))
        {
            /* le petit est sur la tour t3
               et t1 est vide, t2 ne l'est pas :  transfert t2 -> t1 */
            cas = 21;
        }
        else if (estVide (t2) && !estVide(t1))
        {
            /* le petit est sur la tour t3
               et t2 estempiler(t2,sommet(t1));
            depiler(t1); vide, t1 ne l'est pas : transfert t1 -> t2  */
            cas = 12;
        }
        else if (!estVide (t2) && !estVide(t1))
        {
            /* le petit est sur t3,
                t2 et t1 non vides ==> comparaison des sommets */
            if (sommet(t2) < sommet(t1))
            {
                /* transfert de t2 vers t1 */
                cas = 21;
            }
            else
            {
                /* transfert de t1 vers t2 */
                cas = 12;
            }
        }
        else
        {
            /* le petit est sur t3,
               t2 et t3  vides ==> rien */
            cas = 0;

        }

    //-------- fin étape 1

    /** Etape 2 :
    cas, t1, t2, t3 >> traiter le cas = faire le mouvement  >> t1, t2, t3  */

    switch (cas)
    {
    case 12 :
        empiler(t2,sommet(t1));
        depiler(t1);
        break;
    case 21 :
        empiler(t1,sommet(t2));
        depiler(t2);
        break;
    case 31 :
        empiler(t1,sommet(t3));
        depiler(t3);
        break;
    case 13 :
        empiler(t3,sommet(t1));
        depiler(t1);
        break;
    case 23 :
        empiler(t3,sommet(t2));
        depiler(t2);
        break;
    case 32 :
        empiler(t2,sommet(t3));
        depiler(t3);
        break;
    }
}
