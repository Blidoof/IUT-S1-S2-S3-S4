#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int b, x, y;

    f.apparait("Test TP1",500,400,0,0,100,100,100);
    s.associerA(f);

    f.choixCouleurTrace(255,100,100);

    f.ecrit(10,100,"Bravo, vous avez bien parametre votre environnement !!");

    f.choixCouleurTrace(0,0,0);

    f.ecrit(100,240,"CLIQUER POUR QUITTER");

    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
