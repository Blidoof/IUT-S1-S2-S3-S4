#include "Fenetre.h"
#include "Souris.h"
#include "CaseACocher.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    int x,y,b;
    Fenetre f ("TestExo2", 400,400);
    Souris s;
    Couleur c;
    CaseACocher cac ((f.largeur()/2)-30, (f.hauteur()/2)-30, 30, c, 'N');

    //TRAITEMENTS

    //Preparer fenetre
    s.associerA(f);
    f.choixCouleurTrace(0,0,0);
    cac.afficher(f);

    //Attendre clic et agir

    for ( ; ; )
    {
        while (!(s.testeBoutons(x,y,b)))
        {
        }

        if (b==3)
        {
            break;
        }

        if (b == 1)
        {

            if (cac.cadre().touche(x,y))
            {
                cac.effacer(f);
                if (cac.etat()=='N')
                {
                    cac.definirEtat('C');
                }
                else
                {
                    cac.definirEtat('T');
                }

                cac.afficher(f);
            }
        }
    }


    return 0;

}
