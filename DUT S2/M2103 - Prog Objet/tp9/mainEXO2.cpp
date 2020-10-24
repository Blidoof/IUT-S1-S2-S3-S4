#include "FenetreDessin.h"
#include "Souris.h"
#include "Cercle.h"
#include "Carre.h"
#include "ElementGraphique.h"
#include "CaseAvecTexte.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES

    //Fonctionnelles
    int outilChoisi; // Case choisie
    bool estBleu = false;

    //Fenetres
    FenetreDessin fOutils("Boite a outils", 200, 400);
    FenetreDessin fDessin("Zone de dessin", 400, 400, 250);

    //Souris
    Souris s1(fOutils);
    Souris s2(fDessin);
    int x,y,b; // position souris et bouton cliqué sur fenetre outil
    int xD,yD; // position souris  sur fenetre Dessin



    //Cases dans boite a outils
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,50,30,Couleur(0,0,0), 'N'), "Carre"));
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,100,30,Couleur(0,0,0), 'N'), "Cercle"));
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,150,30,Couleur(0,0,0), 'N'), "CaC"));
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,200,30,Couleur(0,0,0), 'N'), "Couleur"));
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,250,30,Couleur(0,0,0), 'N'), "Etat"));
    fOutils.ajouter(new CaseAvecTexte(CaseACocher(40,300,30,Couleur(0,0,0), 'N'), "Supprimer"));

    //TRAITEMENTS
    for ( ; ; )
    {
        while (!(s1.testeBoutons(x,y,b)) && !(s2.testeBoutons(xD,yD,b))) {}

        //Si clic droit -> Fin
        if (b == 3)
        {
            break;
        }

        if ( b == 1 )
        {

            //Si bouton touché dans fOutils
            if (fOutils.touche(x,y) != -1)
            {
                //Définir l'outil choisi
                outilChoisi = fOutils.touche(x,y);

                //Desactiver les autres boutons
                for (int i = 0 ; i <= fOutils.nbElements()-1 ; i++)
                {
                    fOutils.element(i)-> effacer(fOutils);
                    CaseACocher* cac = (CaseACocher*) fOutils.element(i);
                    cac->definirEtat('N');
                    fOutils.element(i)->afficher(fOutils);
                }

                //Activer le bouton touché
                fOutils.element(outilChoisi)->effacer(fOutils);
                CaseACocher* cac = (CaseACocher*) fOutils.element(outilChoisi);
                cac->definirEtat('C');
                fOutils.element(outilChoisi)->afficher(fOutils);



            }


            switch (outilChoisi)
            {
            case 0 :
                if (fDessin.touche(xD,yD) == -1)
                {
                    fDessin.ajouter(new Carre(xD,yD,40));
                }
                break;


            case 1 :
                if (fDessin.touche(xD,yD) == -1)
                {
                    fDessin.ajouter(new Cercle(xD,yD,40, Couleur(0,0,0)));
                }
                break;

            case 2 :
                if (fDessin.touche(xD,yD) == -1)
                {
                    fDessin.ajouter(new CaseACocher(xD,yD,40,Couleur(0,0,0), 'C'));
                }
                break;



            case 3 :
                if (fDessin.touche(xD,yD) != -1)
                {
                    //Effacer
                    fDessin.element(fDessin.touche(xD,yD))->effacer(fDessin);

                    if (estBleu)
                    {
                        //Change la couleur
                        fDessin.element(fDessin.touche(xD,yD))->definirCouleur(Couleur(0,0,255));

                        //Indiquer changement couleur
                        estBleu =! estBleu;
                    }

                    else
                    {
                        //Change la couleur
                        fDessin.element(fDessin.touche(xD,yD))->definirCouleur(Couleur(0,0,0));

                        //Indiquer changement couleur
                        estBleu =! estBleu;
                    }

                    //Afficher a nouveau element
                    fDessin.element(fDessin.touche(xD,yD))->afficher(fDessin);
                }
                break;

            case 4 :
                if ((fDessin.touche(xD,yD) != -1) && (fDessin.element(fDessin.touche(xD,yD))->quiSuisJe().find("CaseACocher") != string::npos))
                {
                    fDessin.element(fDessin.touche(xD,yD))->effacer(fDessin);
                    CaseACocher* cac = (CaseACocher*) fDessin.element(fDessin.touche(xD,yD));
                    cac->definirEtat(cac->etat() == 'C' ? 'N' : 'C');
                    fDessin.element(fDessin.touche(xD,yD))->afficher(fDessin);
                }
                break;

            case 5 :
                if (fDessin.touche(xD,yD) != -1)
                {
                    fDessin.enlever(fDessin.touche(xD,yD));
                }

                break;
            }

        }



    }

    return 0;
}
