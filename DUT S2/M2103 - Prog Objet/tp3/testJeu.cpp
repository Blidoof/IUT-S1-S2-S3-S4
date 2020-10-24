#include "Fenetre.h"
#include "Souris.h"
#include "Bouton.h"

void jouer (Fenetre&, Souris, Bouton, Bouton, Bouton, Bouton, Bouton, Bouton, Bouton, Bouton, Bouton, int, int ,int); // Determine si un bouton et touché, et désactive les adjacents

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    int x,y,b;
    Fenetre f;
    Souris s;
    Bouton hd, hg, m, bg, bd, mh, md, mb, mg;
    Couleur c_hd, c_hg, c_m, c_bg, c_bd, c_mh, c_md, c_mb, c_mg;

    //TRAITEMENTS

    //Preparer fenetre
    s.associerA(f);
    f.apparait("testExo3", 500, 500);
    f.choixCouleurTrace(0,0,0);

    //Afficher boutons
    m.definir(f.largeur()/2, f.hauteur()/2, 30, c_m, false);
    m.afficher(f);

    hg.definir(30, 30, 30, c_hg, false);
    hg.afficher(f);

    bd.definir(470, 470, 30, c_bd, false);
    bd.afficher(f);

    hd.definir(470, 30, 30, c_hd, false);
    hd.afficher(f);

    bg.definir(30, 470, 30, c_bg, false);
    bg.afficher(f);

    mh.definir(f.largeur()/2, 30 , 30, c_mh, false);
    mh.afficher(f);

    md.definir(f.largeur()-30, f.hauteur()/2, 30, c_md, false);
    md.afficher(f);

    mb.definir(f.largeur()/2, 470, 30, c_mb, false);
    mb.afficher(f);

    mg.definir(30, f.hauteur()/2, 30, c_mg, false);
    mg.afficher(f);



    jouer(f, s, hd,hg,m,bg,bd, mh, mb, mg, md, x,y,b);


    return 0;
}

void jouer (Fenetre& f, Souris s, Bouton hd, Bouton hg, Bouton m, Bouton bg, Bouton bd, Bouton mh, Bouton mb, Bouton mg, Bouton md, int x, int y,int b) // Determine si un bouton et touché, et désactive les adjacents
{
    for ( ; ; )
    {

        while(!(s.testeBoutons(x,y,b)))
        {
        }

        if (b == 3)
        {
            break;
        }
        if (hd.touche(x,y))
        {
            if (b == 1)
            {
                hd.effacer(f);
                mh.effacer(f);
                md.effacer(f);

                if (m.actif())
                {
                    hd.desactiver();
                    mh.desactiver();
                    md.desactiver();

                }
                else
                {
                    hd.activer();
                    mh.activer();
                    md.activer();

                }

                hd.afficher(f);
                mh.afficher(f);
                md.afficher(f);

            }
        }
    }
}
