#include "Fenetre.h"
#include "Souris.h"
#include "CaseACocher.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    CaseACocher cac;
    CaseACocher cac2;
    const CaseACocher& c = cac;
    int b, x, y;


    f.apparait("Test TP3",600,400,0,0,200,200,200);
    s.associerA(f);
    f.choixCouleurTrace(0,0,0);

    cac.definirCadre(100,20,40,Couleur(255,0,0));
    cac.definirEtat('R');
    
    if ((c.cadre().cote() == 40) &&
	(c.cadre().coordX() == 100 && c.cadre().coordY() == 20) &&
	(c.cadre().couleur().rouge() == 255 && c.cadre().couleur().vert()==0 &&
	 c.cadre().couleur().bleu() == 0))
	f.ecrit(10,100,"Gestion du cadre : OK");
    else
	f.ecrit(10,100,"Gestion du cadre : PAS OK");


    cac2.definirEtat('C');

    if (c.etat() == 'N' && cac2.etat() =='C')
	f.ecrit(10,120,"Gestion de l'etat : OK");
    else
	f.ecrit(10,120,"Gestion de l'état : PAS OK");

    cac.definirCadre(150,20, 40, Couleur(0,0,255));

    c.afficher(f);

    cac2.definirCadre(20,20,40,Couleur(255,0,255));
    cac2.definirEtat('C');
    cac2.afficher(f);
    cac2.effacer(f);

    cac2.definirCadre(250,30,20,Couleur(100,255,100));
    cac2.definirEtat('C');
    cac2.afficher(f);
    cac2.definirEtat('H');
    cac2.effacer(f);

    f.choixCouleurTrace(0,0,0);
    f.ecrit(10,150,"Si vous voyez, une croix verte, ainsi qu'un case a cocher bleue initialement decochee ");

    f.ecrit (10,170,"qui se coche/decoche lorsque vous cliquez a l'interieur, alors l'affichage est OK");
 
    f.ecrit(100,240,"CLIC DROIT POUR QUITTER");

    while (!s.testeBoutons(x, y, b));
    while(b!=3){
	if (cac.cadre().touche(x,y)){
	    cac.effacer(f);
	    if (c.etat()=='N') 
		cac.definirEtat('C');
	    else
		cac.definirEtat('T');
	    cac.afficher(f);
	}
	while (!s.testeBoutons(x, y, b));			     
	
    }

    f.disparait();
   
    return 0;
}
