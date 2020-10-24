#include "Cercle.h"
#include "Couleur.h"
#include "Fenetre.h"

void Cercle::placer(int x, int y)   // Place le cercle en un point
{
    this->m_x = x;
    this->m_y = y;
}

int Cercle::coordX() const   // Retourne la coordonée en X du carré
{
    return this->m_x;
}

int Cercle::coordY() const    // Retourne la coordonée en Y du cercle
{
    return this->m_y;
}

void Cercle::dimensionner(int r)  // Definit la longueyur du cercle
{
    this->m_rayon = r;
}

int Cercle::rayon() const   // Retourne la longueur du cote du Cercle
{
    return this->m_rayon;
}

void Cercle::definirCouleur(int r, int v, int b)   // Definit la couleur du cercle
{
    this->m_coul.definir(r,v,b);
}

void Cercle::definirCouleur(Couleur coul)   // Definit la couleur du cercle
{
    this->m_coul.definir(coul.rouge(), coul.vert(), coul.bleu());
}

Couleur Cercle::couleur() const   // Retourne la couleur du cercle
{
    return this->m_coul;
}

void Cercle::afficher (Fenetre& f) const   // Afficher le Cercle dans la fenetre f
{
    f.choixCouleurTrace(this->couleur());
    f.traceArc(this->coordX()-this->rayon(), this->coordY() - this->rayon(), 2*this->rayon(), 2*this->rayon());
}
void Cercle::effacer (Fenetre& f) const   // Efface le Cercle de la fenetre
{
    f.choixCouleurTrace(f.couleurFond());
    f.traceArc(this->coordX()-this->rayon(), this->coordY() - this->rayon(), 2*this->rayon(), 2*this->rayon());
}

bool Cercle::touche(int x, int y) const   // Determine si un point est dans le cercle
{
    if ((this->coordX()-x)*(this->coordX()-x) + (this->coordY()-y) * (this->coordY()-y) <= (this->rayon()*this->rayon()))
    {
        return true;
    }
    else
    {
        return false;
    }
}


