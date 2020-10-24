#include <iostream>
#include "pile.h"
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

void transfertEnFin(string nomFicSource, string nomFicCible)

{
    //VARIABLES
    bool finFichier; // indique si on est positionn� � la fin du fichier
    UnFichierTexte ficS; //le nom logique du fichier source associ� au nom syst�me
    UnFichierTexte ficC; //le nom logique du fichier cible associ� au nom syst�me
    string chaine; // Le contenu de la ligne analys�e

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
    bool finFichier; // indique si on est positionn� � la fin du fichier
    UnFichierTexte fic; //le nom logique du fichier associ� au nom syst�me
    string chaine; // Le contenu de la ligne analys�e
    UnePile copieInverseFic; // Pile dans laquelle on stocke le contenu de fic ligne par ligne pour le lire � l'envert en d�finlant

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
        bool finFichier; // indique si on est positionn� � la fin du fichier
        UnFichierTexte fic; //le nom logique du fichier associ� au nom syst�me
        string chaine; // Le contenu de la ligne analys�e

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

