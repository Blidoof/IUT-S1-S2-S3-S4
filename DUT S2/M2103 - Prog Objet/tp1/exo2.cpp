#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    /*Souris s;
    int b, x, y;*/

    //Création de la fenêtre

    f.apparait("testTP2", 200, 200, 0, 0, 255, 255, 255);

    //Remplissage de la fenetre

    for ( unsigned short int i = 0 ; i < 5 ; i++ )
    {
        f.traceArc(i*20, i*20, 200-(i*40), 200-(i*40));
    }

    f.delai(6000);




    return 0;
}

