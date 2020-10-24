#include "Cercle.h"
#include "Couleur.h"
#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //VARIABLES
    Cercle cer;
    Fenetre f;
    Souris s;
    int x,y,b; // Coordonées x et y du clic de la souris et indicateur du bouton cliqué
    bool estRouge = true; // Definit la couleur qui sera affichée en fonction de son état

    //Preparation de la fenetre

    s.associerA(f);
    f.apparait("test");
    cer.definirCouleur(255,0,0);
    cer.placer(40,40);
    cer.dimensionner(30);
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
