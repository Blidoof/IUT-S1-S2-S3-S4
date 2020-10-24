#include "FenGrille.h"
#include "Souris.h"
#include "CaseACocher.h"
#include "CaseAvecTexte.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    FenGrille f(50,50);
    CaseACocher cac (0,0,50,Couleur(0,0,255), 'N');
    CaseAvecTexte cat(CaseACocher (0, 50, 50,Couleur(0,0,255), 'C'),
                      "testCAT");

    Souris s(f);
    int x,y,b;

    f.apparait();
    f.afficherCase(cac);
    f.afficherCase(cat);

    while (!(s.testeBoutons(x,y,b)));

}
