#ifndef CARRE_H
#define CARRE_H

#include "Couleur.h"
#include "Fenetre.h"

class Carre
{
protected :
    int m_x, m_y; // Les coordonées du coin supérieur gauche du carré
    int m_cote; // La longueur d'un cote
    Couleur m_coul; // La couleur du carré
    void dessiner(Couleur, Fenetre&) const; //Permet de dessiner dans une fenetre
public :
    Carre(const Carre&); //Constructeur de copie
    Carre(); // Constructeur par défaut
    Carre(int,int, int, Couleur = Couleur(0,0,0));
    void placer(int, int); // Place le carré en un point
    int coordX() const; // Retourne la coordonée en X du carré
    int coordY() const; // Retourne la coordonée en Y du carré
    void dimensionner(int l); // Definit la longueyur du carré
    int cote() const; // Retourne la longueur du cote du carre
    void definirCouleur(int, int, int); // Definit la couleur du carré
    void definirCouleur(Couleur coul); // Definit la couleur du carré
    Couleur couleur() const; // Retourne la couleur du carré
    void afficher (Fenetre&) const; // Afficher le carre dans la fenetre f
    void effacer (Fenetre&) const; // Efface le carre de la fenetre
    bool touche(int, int) const; // Determine si un point est dans le carré


};


#endif // CARRE_H


