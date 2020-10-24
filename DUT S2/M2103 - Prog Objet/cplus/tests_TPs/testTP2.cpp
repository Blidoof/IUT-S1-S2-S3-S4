 #include "Fenetre.h"
#include "Souris.h"
#include "Carre.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    Carre carre1, carre2;
    int b, x, y;

    f.apparait("Test TP2", 600,400,0,0,200,200,200 );
    f.choixCouleurTrace(0,0,0);

    carre1.placer(100,20);
    carre1.dimensionner(40);
    carre1.definirCouleur(255,0,0);
    carre2.definirCouleur(Couleur(0,255,255));
    const Carre& c1 = carre1;

    c1.afficher(f);
    c1.couleur();
    s.associerA(f);

    f.choixCouleurTrace(0,0,0);

    if (c1.coordX() == 100 && c1.coordY() == 20)
	f.ecrit(10,100,"Position : OK");
    else
	f.ecrit(10,100,"Position : PAS OK");

    if (c1.cote() == 40)
	f.ecrit(10,80,"Dimension : OK");
    else
	f.ecrit(10,80,"Dimension : PAS OK");

    if (carre1.couleur().rouge() == 255 && carre1.couleur().vert()==0 &&
	carre1.couleur().bleu() == 0 &&
	carre2.couleur().rouge() == 0 && carre2.couleur().vert()==255 &&
	carre2.couleur().bleu() == 255)
	f.ecrit(10,120,"Couleur : OK");
    else
	f.ecrit(10,120,"Couleur : PAS OK");

    if (!c1.touche(100,20) || !c1.touche(140,20) ||
	!c1.touche(100,60) || !c1.touche(140,60) ||
	c1.touche(90,30) || c1.touche(110,70))
	f.ecrit(10,140,"Touche : PAS OK");
    else
	f.ecrit(10,140,"Touche : OK");


    c1.effacer(f);
    carre1.definirCouleur(Couleur(0,0,255));
    carre1.placer (150,20);
    carre1.afficher(f);

    f.choixCouleurTrace(0,0,255);

    f.traceLigne (140,10,150,20);
    f.traceLigne (150,15,150,20);
    f.traceLigne (145,20,150,20);
   
    f.traceLigne (200,70,190,60);
    f.traceLigne (195,60,190,60);
    f.traceLigne (190,65,190,60);
   
    carre1.definirCouleur(100,255,100);
    carre1.placer (250,20);
    carre1.afficher(f);

    f.choixCouleurTrace(100,255,100);

    f.traceLigne (240,10,250,20);
    f.traceLigne (250,15,250,20);
    f.traceLigne (245,20,250,20);
   
    f.traceLigne (300,70,290,60);
    f.traceLigne (295,60,290,60);
    f.traceLigne (290,65,290,60);
   


    f.choixCouleurTrace(0,0,0);
    f.ecrit(10,180,"Si vous voyez deux carres (et pas trois) : ");
    f.ecrit(40,200, "- un bleu et un vert dont les coins coincident avec les petites fleches, alors l'affichage est OK");
 
    f.ecrit(120,260,"CLIQUER POUR QUITTER");

    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
