#include "Cercle.h"
#include "Couleur.h"
#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    Couleur c = Couleur (255,0,0);
    Cercle cer (40,40,30, c);
    Fenetre f ("testTd2", 400,400);
    Souris s;
    int x,y,b; // Coordonées x et y du clic de la souris et indicateur du bouton cliqué
    bool estRouge = true; // Definit la couleur qui sera affichée en fonction de son état

    //Preparation de la fenetre
    s.associerA(f);
    cer.afficher(f);

    //Analyse et action en fonction du bouton cliqué
    for ( ; ; )
    {
        //Attente du clic
        while (!(s.testeBoutons(x,y,b)))
        {
        }

        //Analyser le clic
        if (b == 3)
        {
            break;
        }

        if (b == 1)
        {
            if (cer.touche(x,y))
            {
                cer.effacer(f);
                if(estRouge)
                {
                    cer.definirCouleur(0,0,255);
                }
                else
                {
                    cer.definirCouleur(255,0,0);
                }

                //Afficher la nouvelle couleur et préparer le prochain changement
                cer.afficher(f);
                estRouge = !estRouge;
            }
        }

    }

    //Fermer la fenetre
    f.effacer();

    return 0;

}
