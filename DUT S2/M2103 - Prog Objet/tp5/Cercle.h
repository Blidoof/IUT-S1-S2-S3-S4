#ifndef CERCLE_H
#define CERCLE_H

#include "Couleur.h"
#include "Fenetre.h"

class Cercle
{
protected :
    int m_x, m_y; // Les coordonées du centre du cercle
    int m_rayon; // La longueur du rayon
    Couleur m_coul; // La couleur du cercle
public :
    Cercle(); // Defaut
    Cercle(const Cercle&); //Copie
    Cercle (int,int,int, Couleur = Couleur (0,0,255));
    void placer(int, int); // Place le cercle en un point
    int coordX() const; // Retourne la coordonée en X du centre du cercle
    int coordY() const; // Retourne la coordonée en Y du centre du cercle
    void dimensionner(int); // Definit la longueyur du rayon du cercle
    int rayon() const; // Retourne la longueur du rayon du cercle
    void definirCouleur(int, int, int); // Definit la couleur du carré
    void definirCouleur(Couleur); // Definit la couleur du carré
    Couleur couleur() const; // Retourne la couleur du cercle
    void afficher (Fenetre&) const; // Afficher le cercle dans la fenetre f
    void effacer (Fenetre&) const; // Efface le cercle de la fenetre
    bool touche(int, int) const; // Determine si un point est dans le cercle

};


#endif // CERCLE_H
