#include "Fenetre.h"
#include "Souris.h"
#include "CaseACocher.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    int x,y,b;
    Fenetre f;
    Souris s;
    CaseACocher cac;
    Couleur c;

    //TRAITEMENTS

    //Preparer fenetre
    s.associerA(f);
    f.apparait("testExo3");
    f.choixCouleurTrace(0,0,0);
    cac.definirCadre((f.largeur()/2)-30, (f.hauteur()/2)-30, 30, c);
    cac.definirEtat('N');
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
