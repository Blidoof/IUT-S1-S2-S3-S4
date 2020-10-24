#include <iostream>
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    UnFichierTexte ficD;        // fichier de texte DONNEE (=a lire)
    UnFichierTexte ficR;        // fichier de texte RESULTAT (=a compl�ter)
    string nomSystemeficD ;     // nom syst�me du fichier � lire
    string nomSystemeficR ;     // nom syst�me du fichier � compl�ter
    char choix ;

    do
    {
        // afficher menu
        cout << "EXERCICE 1 " << endl;
        cout << "a : Afficher le contenu d'un fichier de texte" << endl;
        cout << "b : Ajouter le contenu d'un fichier en fin d'un autre fichier" << endl;
        cout << "c : Afficher le contenu inverse d'un fichier de texte"<< endl;
        cout << "v : Vider un fichier existant = Creer un nouveau fichier vide"<< endl;
        cout << "q : Quitter"<< endl;

       // Saisie-cerif reponse >> choix
        do
        {
            cout << endl << "votre choix ? " ;
            cin >> choix;
            cout << " " << endl;
        }
        while (!
                ((toupper(choix) == 'Q') |(toupper(choix) == 'A')|(toupper(choix) == 'B')|(toupper(choix) == 'C')|(toupper(choix) == 'V'))
              );

        // choix >> triater action demandee
        switch (toupper(choix))
        {
        case 'A' :
            // A.- Affichage � l'�cran du contenu d'un fichier texte
            // saisie du nom syst�me du fichier concern�
            cout << "A - Affichage a l'ecran du contenu d'un fichier texte" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "nom du fichier a afficher : ";
            cin >> nomSystemeficD;
            affichageEcran(nomSystemeficD);
            break;
        case 'B' :
            // B.- Ajout du contenu d'un fichier texte en fin d'un autre fichier texte
            // saisie des noms syst�me des fichiers concern�s
            cout << endl << endl << "B - Ajout d'un fichier EN FIN d'un autre fichier" << endl;
            cout <<                 "------------------------------------------------" << endl;
            cout << "nom du fichier CIBLE (a completer) : ";
            cin >> nomSystemeficR;
            cout << "nom du fichier SOURCE (a ajouter) : ";
            cin >> nomSystemeficD;
            transfertEnFin(nomSystemeficD, nomSystemeficR) ;
            break;
        case 'C' :
            // C.- Affichage � l'�cran du contenu A L'ENVERS d'un fichier de texte
            // saisie du nom syst�me du fichier concern�
            cout << endl << endl << "C - Affichage a l'ecran du contenu INVERSE d'un fichier texte" << endl;
            cout <<                 "-------------------------------------------------------------" << endl;
            cout << "nom du fichier a afficher a l'envers : ";
            cin >> nomSystemeficD;
            affichageInverseEcran(nomSystemeficD);
            break;
        case 'V' :
            // vider un fichier
            // saisie du nom syst�me du fichier concern�
            cout << "  - Vider un fichier texte" << endl;
            cout << "--------------------------" << endl;
            cout << "nom du fichier a vider / creer vide : ";
            cin >> nomSystemeficR;
            associer (ficR, nomSystemeficR); ouvrir (ficR, creation); fermer(ficR);
            break;
        }

        cout << endl << endl;

    }
    while ( !(toupper(choix) == 'Q'));

    cout << endl << endl << "...au revoir..." << endl;
    return 0;
}
