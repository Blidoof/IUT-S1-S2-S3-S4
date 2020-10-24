#include "Fenetre.h"
#include "Souris.h"
#include "Couleur.h"
#include "Image.h"

int main (int argc, char **argv)
{

    gtk_init(&argc, &argv);

    //Exercice 2
    /*
    //VARIABLES
    Fenetre f;

    f.apparait("testTD");
    f.choixCouleurTrace(0,0,0);

    f.traceLigne(0,0, f.largeur(), f.hauteur());
    f.traceLigne(f.largeur(), 0, 0, f.hauteur());

    f.delai(6000);
    f.disparait();
    */

    //Exercice 3
    /*
        //VARIABLES
        Fenetre f; // La fenetre dans laquelle apaprait le programme
        Souris s; // La souris
        int b, x, y; // Les coordonées du click de la souris, et le bouton utilisé

        //Initialiser
        f.apparait("testTD");
        int baseX =0;
        int baseY =0;
        s.associerA(f);

        //Tracer Points
        for ( ; ; )
        {

            //Saisir click
            if (s.testeBoutons(x,y,b))
            {
                //Choisir l'action à effectuer en fonction du bouton cliqué
                if (b == 1)
                {
                    f.traceLigne(baseX, baseY, x, y);
                    baseX = x;
                    baseY = y;
                }
                if (b ==3 )
                {
                    break;
                }
            }
        }
    */

    //EXERCICE 4

    //VARIABLES
    Fenetre f; // La fenetre dans laquelle apaprait le programme
    Souris s; // La souris
    int b, x, y; // Les coordonées du click de la souris, et le bouton utilisé
    int tabX[50]; // Stocke les coordonées en X des points cliqués
    int tabY[50]; // Stocke les coordonées en Y des points cliqués
    int i =0;// Indique le numéro du point dont on veut connaitre les coordonées

    //Initialiser la fenetre
    f.apparait("testTD");
    s.associerA(f);
    f.choixFonte("times",50,true);

    //Tracer Points
    for ( ; ; )
    {
        //Saisir click
        while(!(s.testeBoutons(x,y,b)));

        if (b == 1)
        {
            f.choixCouleurTrace(0, 0, 0); // On fait un trait noir puisque on ne veut pas effacer un point

            //Enregistrer coordonées
            tabX[i] = x;
            tabY[i] = y;

            if (i > 0)
            {
                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1);//On trace la ligne à partir du point précédent
            }
            i++;//On passe au point suivant

        }
        else if (b == 2)
        {
            f.choixCouleurTrace(f.couleurFond()); // On fait un trait blanc puisque on veut effacer un point

            if (i > 0)
            {
                i--; // On retourne au point précédent

                f.traceLigne(tabX[i-1],tabY[i-1],tabX[i],tabY[i],1);//On trace la ligne blanche à partir du point précédent
            }

        }
        else
        {
            break;
        }
    }



    return 0;
}


