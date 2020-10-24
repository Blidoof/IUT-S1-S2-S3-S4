#ifndef FENETRE_H
#define FENETRE_H

#define TAILLEMAX 50

#include "ElementGraphique.h"
#include "Fenetre.h"

class FenetreDessin : public Fenetre {
protected :
    ElementGraphique* m_tab [TAILLEMAX];
    int m_nb;
public :
    bool estPleine () const;
    void ajouter (ElementGraphique* ) ;
    void ajouter (ElementGraphique & ) ;
    void enlever (int) ;
    int touche (int, int) const;
    ElementGraphique* element(int) const;
    int nbElements() const ;
    FenetreDessin();
    FenetreDessin(const char *, int, int, int = 0 , int = 0, int = 255, int = 255, int = 255);
    FenetreDessin (const FenetreDessin&);
};

#endif // FENETRE_H
