#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    Fenetre f;
    Souris s;
    int b, x, y;

    //Preparer la fenetre et la souris
    f.apparait("testTP3", 1280, 720);
    s.associerA(f);
    f.afficheImage("987815.jpg");

    //Attendre la saisie du click
    for ( ; ; )
    {
        //Reperer le click
        if (s.testeBoutons(x,y,b))
        {
            //Choisir l'action à effectuer en fonction du bouton cliqué
            if (b == 1)
            {
                f.remplitEllipse(x,y,100,100);
            }
            if (b ==3 )
            {
                break;
            }
        }
    }

    return 0;
}


