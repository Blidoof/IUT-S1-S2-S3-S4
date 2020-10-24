#include "FenetreDessin.h"
#include "Souris.h"
#include "Cercle.h"
#include "Carre.h"
#include "ElementGraphique.h"
#include "CaseACocher.h"
#include "CaseAvecTexte.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    int x,y,b; // position souris et bouton cliqué
    FenetreDessin f("Test", 400, 400);
    Souris s(f);
    int pos; // Position de l'element dans le tableau d'elements graphiques
    bool estBleu = false; // Definit la couleur de l'élement

    for ( ; ; )
    {
        //Attente clic bouton
        while (!(s.testeBoutons(x,y,b))) {}


        if (b == 3)
        {
            //Clic droit -> fin programme
            break;
        }

        if (b == 2)
        {
            pos = f.touche(x,y);

            //Si clic dans zone librede la fenetre -> ajout carré
            if(pos == -1)
            {
                f.ajouter (new Carre(x,y,20,Couleur(0,0,0)));
            }

            //Si clic sur un element -> changer de couleur
            else
            {
                //Effacer
                f.element(pos)->effacer(f);

                if (estBleu)
                {
                    //Change la couleur
                    f.element(pos)->definirCouleur(Couleur(0,0,255));

                    //Indiquer changement couleur
                    estBleu =! estBleu;
                }

                else
                {
                    //Change la couleur
                    f.element(pos)->definirCouleur(Couleur(0,0,0));

                    //Indiquer changement couleur
                    estBleu =! estBleu;
                }

                //Afficher a nouveau element
                f.element(pos)->afficher(f);
            }

        }


        if (b == 1)
        {
            pos = f.touche(x,y);

            //Clic gauche dans zone libre ->afficher un cercle
            if (pos == -1)
            {
                f.ajouter(new CaseAvecTexte(CaseACocher(x,y,40,Couleur(0,0,0),'C'),"Txt"));
            }

            //Clic gauche sur un element -> changer sa position par celle cliquée
            else
            {
                if ((f.element(pos)->quiSuisJe().find("CaseAvecTexte")) != string::npos )
                {
                    f.element(pos)->effacer(f);
                    CaseACocher* cac = (CaseACocher*) f.element(pos);
                    cac->definirEtat(cac->etat() == 'C' ? 'N' : 'C');
                    f.element(pos)->afficher(f);
                }
            }

        }

    }

    f.disparait();

    return 0;
}
