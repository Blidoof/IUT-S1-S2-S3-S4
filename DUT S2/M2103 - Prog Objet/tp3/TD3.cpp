#include "Fenetre.h"
#include "Souris.h"
#include "CaseACocher.h"
#include "Bouton.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    int x,y,b;
    Fenetre f;
    Souris s;
    Bouton bout;
    Couleur c;

    //TRAITEMENTS

    //Preparer fenetre
    s.associerA(f);
    f.apparait("testExo3");
    f.choixCouleurTrace(0,0,0);
    bout.definir(f.largeur()/2, f.hauteur()/2, 30, c, false);
    bout.afficher(f);

    for ( ; ; )
    {
        while(!(s.testeBoutons(x,y,b)))
        {
        }

        if (b == 3)
        {
            break;
        }

        if (bout.touche(x,y))
        {
            if (b == 1)
            {
                bout.effacer(f);

                if (bout.actif())
                {
                    bout.desactiver();

                }
                else
                {
                    bout.activer();

                }

                bout.afficher(f);
            }
        }
    }

    return 0;
}
