#include "Fenetre.h"
#include "Souris.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "M3202.h"
using namespace std;

Matrice operator*(Matrice a, Matrice b)
{

    Matrice resultat(a.nbLignes(),b.nbColonnes(),0); // On prepare la matrice resultat

    double coefij = 0;

    for (int i = 1; i <= a.nbLignes() ; i++ ) //Parcours des lignes de A
    {
        for (int j = 1; j <= b.nbColonnes() ; j++ ) //Parcours des colonnes de B
        {
            for (int k = 1 ; k <= b.nbLignes() ; k++) //calcul du coefficient
            {
                coefij += a(i,k)*b(k,j);
            }
            resultat(i,j) = coefij;
            coefij = 0;
        }
    }

    return resultat;
}


int main(int argc, char* argv[])
{
    /*
      Matrice A(3,3,1);
      Matrice B(3,2,2);
      Matrice C = A * B;

      cout << "Matrice A : " << endl << A;

      cout << "Matrice B : " << endl << B;

      cout << "Matrice C : " << endl << C;
    */

    gtk_init(&argc, &argv);

    Fenetre f("Rotations par produits de matrices", 400, 400);
    Souris s(f);
    Couleur bleu(0,0,255);
    int x,y,b;

    Polygone rect; // le rectangle
    rect.ajouter(Point (100,150));
    rect.ajouter(Point(250,150));
    rect.ajouter(Point(250,250));
    rect.ajouter(Point(100,250));

    for (;;)
    {
        // on affiche le rectangle en bleu
        rect.dessiner(f, bleu);

        // attente du clique pour déterminer l'axe de rotation
        while (!s.testeBoutons(x, y, b));

        // on construit la matrice de translation : depuis l'axe vers l'origine
        Matrice translate(3,3,0);

        translate(1,1) = 1;
        translate(2,2) = 1;
        translate(3,3) = 1;
        translate(1,3) = -x;
        translate(2,3) = -y;

        // on construit la matrice de translation inverse : depuis l'origine vers l'axe
        Matrice remettre (3,3,0);
        remettre(1,1) = 1;
        remettre(2,2) = 1;
        remettre(3,3) = 1;
        remettre(1,3) = x;
        remettre(2,3) = y;

        // On définit l'angle de rotation : 20 degrés
        int angle = 20;

        // On construit la matrice de rotation
        Matrice rotation(3,3,0);
        rotation(3,3) = 1;
        rotation(1,1) = cos(angle);
        rotation(2,1) = -(sin(angle));
        rotation(1,2) = sin(angle);
        rotation(2,2) = cos(angle);

        // On efface le rectangle
        rect.dessiner(f, f.couleurFond());

        // On va tourner un à un les points du rectangle
        for (int i = 0 ; i < rect.nbPoints() ; i++)
        {
            // On transforme le point en coordonnées homogènes
            Matrice coordHomogenes(3,1,1);

            coordHomogenes(1,1) = rect[i].x();
            coordHomogenes(2,1) = rect[i].y();


            // On effectue la rotation
            coordHomogenes = remettre * rotation * translate * coordHomogenes;

            // On modifie le point avec les nouvelles coordonnées

            Point p(coordHomogenes(1,1), coordHomogenes(2,1));

            rect[i] = p;

        }

        // On affiche à nouveau le rectangle en bleu
        rect.dessiner(f, bleu);
    }
    // On attend un peu
    f.delai(9000);

    // c'est fini
    f.disparait();



    return 0;
}
