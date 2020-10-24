#ifndef FENGRILLE_H
#define FENGRILLE_H

#include "Fenetre.h"
#include "CaseACocher.h"
#include "Couleur.h"

class FenGrille : public Fenetre {
protected :
    int m_h, m_l; // hauteur et largeur
    void dessinerQuadrillage();
public :
    FenGrille (int = 20, int = 20); // parametres : hauteur puis largeur
    FenGrille (const char *, int, int, int=0, int=0, int=255, int=255, int=255, int = 20, int = 20); //deux derniers paramètres : hauteur puis largeur
    FenGrille ( const FenGrille& ); // copie
    void apparait (const char* ="Sans nom", int=400, int=400, int=0, int=0, int=255, int=255, int=255);
    void effacer();
    void afficherCase (const CaseACocher&) ;
};


#endif
