#ifndef BOUTON_H
#define BOUTON_H

#include "Fenetre.h"
#include "Cercle.h"
#include "Couleur.h"

class Bouton
{
private :
    void dessinerBouton (Couleur, Fenetre&) const;
protected :
    Cercle m_cercle;
    bool m_estActif;
public :
    Bouton(); //defaut
    Bouton(const Bouton&); //Copie
    Bouton(Cercle, bool);
    void definir (int,int,int,int,int,int, bool = false);
    void definir (int,int,int,Couleur = Couleur(0,0,255), bool = false);
    void activer();
    void desactiver();
    bool actif()  const;
    int coordX() const;
    int coordY() const;
    int rayon() const;
    Couleur couleur() const;
    void definirCouleur(Couleur);
    void afficher (Fenetre&) const;
    void effacer (Fenetre&) const;
    bool touche(int,int) const;
};


#endif // BOUTON_H

