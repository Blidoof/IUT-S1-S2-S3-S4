#include <iostream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

void calculMoyenneSimple (string nomSysFichierDonne)
{
    //VARIABLES
    UnFichierTexte nomLogiqueFic; //Le nom logique du fichier choisi
    unsigned int nbVal; // Le nombre de valeurs pluviométriques dans le fichier
    unsigned int somme; // La somme des valeurs pluviométriques dans le fichier
    float moyenne; // La moyenne des valeurs dans le fichier
    bool finFic; // Indique si la recherche a atteint la fin du fichier
    int val; // La valeur du fichier courante

    //TRAITEMENTS

    //Préparer le fichier et initialiser
    nbVal = 0;
    somme = 0;
    finFic = false;
    associer(nomLogiqueFic, nomSysFichierDonne);
    ouvrir(nomLogiqueFic, consultation);

    //Calcul de la moyenne
    for ( ; ; )
    {
        lireMot(nomLogiqueFic, val, finFic);

        if (finFic)
        {
            break;
        }

        somme += val;
        nbVal += 1;
    }

    if ( nbVal > 0 )
    {
        moyenne = float(somme) / float(nbVal);
    }
    fermer(nomLogiqueFic);

    //Afficher résultat

    if (nbVal > 0)
    {
        cout << "La moyenne des valeurs de ce fichier est : " << moyenne;
    }
    else
    {
        cout << " pas de moyenne, fichier vide !";
    }

}

void calculMoyenneOuArret (string nomSysFichierDonne)
/*
Soit un fichier texte de nombres entiers, éventuellement vide et possiblement corrompu, dont le nom système est fourni par le paramètre nomSysFichierDonne.
Le programme affiche à l'écran, lorsque le fichier est correct, le nombre de hauteurs pluviométriques contenues dans le fichier et,
lorsque cela est possible, leur moyenne.
Lorsque le fichier est corrompu, le programme s'arrête après avoir affiché la raison du non calcul :
- la nature du PREMIER problème rencontré
- et l'endroit dans le fichier (=rang de la valeur problématique) où il a été rencontré
*/
{

    //VARIABLES
    UnFichierTexte nomLogiqueFic; //Le nom logique du fichier choisi
    unsigned int nbVal; // Le nombre de valeurs pluviométriques dans le fichier
    unsigned int somme; // La somme des valeurs pluviométriques dans le fichier
    float moyenne; // La moyenne des valeurs dans le fichier
    bool finFic; // Indique si la recherche a atteint la fin du fichier
    int val; // La valeur du fichier courante
    bool pbRencontre;//Indique si le programme a rencontre une erreur lors de la lecture

    //TRAITEMENTS

    //Préparer le fichier et initialiser
    nbVal = 0;
    somme = 0;
    finFic = false;
    associer(nomLogiqueFic, nomSysFichierDonne);
    ouvrir(nomLogiqueFic, consultation);

    //Calcul de la moyenne
    try
    {
        for ( ; ; )
        {
            lireMot(nomLogiqueFic, val, finFic);

            if (finFic)
            {
                break;
            }

            somme += val;
            nbVal += 1;
        }

        if ( nbVal > 0 )
        {
            moyenne = float(somme) / float(nbVal);
        }
    }

    catch (string s)
    {
        cerr << s << "!" << endl;
        pbRencontre = true;
    }

    fermer(nomLogiqueFic);

    //Afficher résultat
    if (pbRencontre)
    {
        cout << "erreur rencontree a la valeur " << nbVal;
    }
    else
    {
        if (nbVal > 0)
        {
            cout << "La moyenne des valeurs de ce fichier est : " << moyenne << endl;
            cout << "Le nombre de valeurs est : " << nbVal;
        }
        else
        {
            cout << " pas de moyenne, fichier vide !";
        }
    }

}


void calculMoyenneOuFichierLog (string nomSysFichierDonne)
{
    cout << "calculMoyenneOuFichierLog, non encore developpe" << endl;
}
