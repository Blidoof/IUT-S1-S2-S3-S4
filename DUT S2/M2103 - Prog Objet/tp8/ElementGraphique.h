#ifndef ELEMENT_H
#define ELEMENT_H

#include "Fenetre.h"
#include "Couleur.h"

class ElementGraphique {
public :
    virtual void afficher (Fenetre &) const = 0;
    virtual void effacer  (Fenetre &) const = 0;
    virtual bool touche ( int, int) const = 0;
    virtual void placer ( int, int) = 0;
    virtual void definirCouleur (Couleur) =0;
    virtual Couleur couleur() const = 0;
    virtual ~ElementGraphique() {}

    };

#endif
