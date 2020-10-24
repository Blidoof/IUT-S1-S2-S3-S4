#include "Carre.h"
#include "Couleur.h"
#include "Fenetre.h"

void Carre::placer(int x, int y)   // Place le carré en un point
{
    this->m_x = x;
    this->m_y = y;
}

int Carre::coordX() const   // Retourne la coordonée en X du carré
{
    return this->m_x;
}

int Carre::coordY() const    // Retourne la coordonée en Y du carré
{
    return this->m_y;
}

void Carre::dimensionner(int l)  // Definit la longueyur du carré
{
    this->m_cote = l;
}

int Carre::cote() const   // Retourne la longueur du cote du carre
{
    return this->m_cote;
}

void Carre::definirCouleur(int r, int v, int b)   // Definit la couleur du carré
{
    this->m_coul.definir(r,v,b);
}

void Carre::definirCouleur(Couleur coul)   // Definit la couleur du carré
{
    this->m_coul.definir(coul.rouge(), coul.vert(), coul.bleu());
}

Couleur Carre::couleur() const   // Retourne la couleur du carré
{
    return this->m_coul;
}

void Carre::dessiner(Couleur coul, Fenetre& f) const //Permet de dessiner dans une fenetre
{
    f.choixCouleurTrace(coul);
    f.traceLigne(this->m_x, this->m_y, (this->m_x)+this->m_cote,(this->m_y));
    f.traceLigne(this->m_x, this->m_y, (this->m_x),(this->m_y)+this->m_cote);
    f.traceLigne((this->m_x)+this->m_cote, this->m_y, (this->m_x)+this->m_cote,(this->m_y)+this->m_cote);
    f.traceLigne((this->m_x), this->m_y+this->m_cote, (this->m_x)+this->m_cote,(this->m_y)+this->m_cote);

}

void Carre::afficher (Fenetre& f) const   // Afficher le carre dans la fenetre f
{
    this->dessiner(this->m_coul, f);
}
void Carre::effacer (Fenetre& f) const   // Efface le carre de la fenetre
{
   this->dessiner(f.couleurFond(), f);
}
bool Carre::touche(int x, int y) const   // Determine si un point est dans le carré
{
    if ( x >=(this->m_x) && x <= ((this->m_x)+this->m_cote) && y >=(this->m_y) && y <= ((this->m_y)+this->m_cote))
    {
        return true;
    }
    else
    {
        return false;
    }
}


