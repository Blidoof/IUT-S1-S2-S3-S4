#include <iostream>
#include "pile.h"
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

void transfertEnFin(string nomFicSource, string nomFicCible)

{
    //VARIABLES
    bool finFichier; // indique si on est positionné à la fin du fichier
    UnFichierTexte ficS; //le nom logique du fichier source associé au nom système
    UnFichierTexte ficC; //le nom logique du fichier cible associé au nom système
    string chaine; // Le contenu de la ligne analysée

    //Preparer les fichiers
    associer(ficS, nomFicSource);
    ouvrir(ficS, consultation);
    associer(ficC, nomFicCible);
    ouvrir(ficC, extension);

    //Tenter de copier une ligne du fichiuer source dans le fichier cible
    while (true)
    {
        lireLigne(ficS, chaine, finFichier);

        if (finFichier)
        {
            break;
        }

        ecrire(ficC, chaine);
    }

    fermer(ficC);
    fermer(ficS);

}

void affichageInverseEcran(string nomSysFic)
{
    //VARIABLES
    bool finFichier; // indique si on est positionné à la fin du fichier
    UnFichierTexte fic; //le nom logique du fichier associé au nom système
    string chaine; // Le contenu de la ligne analysée
    UnePile copieInverseFic; // Pile dans laquelle on stocke le contenu de fic ligne par ligne pour le lire à l'envert en définlant

    //Preparer le fichier et la pile
    initialiser(copieInverseFic);
    associer(fic, nomSysFic);
    ouvrir(fic, consultation);

    //Tenter de mettre le contenu du fichier dans la pile
    while (true)
    {
        lireLigne(fic, chaine, finFichier);
        if (finFichier)
        {
            break;
        }
        empiler(copieInverseFic, chaine);
    }

    //Lire le contenu de la pile
    while (!estVide(copieInverseFic))
    {
        cout << sommet(copieInverseFic) <<endl ;
        depiler(copieInverseFic);
    }

    fermer(fic);

}

    void affichageEcran(string nomSysFic)
    {
        //VARIABLES
        bool finFichier; // indique si on est positionné à la fin du fichier
        UnFichierTexte fic; //le nom logique du fichier associé au nom système
        string chaine; // Le contenu de la ligne analysée

        //Traitements

        //Preparer le fichier
        associer(fic, nomSysFic);
        ouvrir(fic, consultation);

        //tenter d'afficher la ligne
        while (true)
        {
            lireLigne(fic, chaine, finFichier);

            if (finFichier)
            {
                break;
            }
            cout << chaine <<endl;
        }
        fermer(fic);
    }

