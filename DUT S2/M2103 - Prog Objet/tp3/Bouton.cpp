#include "Fenetre.h"
#include "Cercle.h"
#include "Couleur.h"
#include "Bouton.h"


void Bouton::definir (int x,int y,int taille ,int rouge,int vert,int bleu, bool estAllume)
{
    this->m_cercle.placer(x,y);
    this->m_cercle.dimensionner(taille);
    this->m_cercle.definirCouleur(rouge,vert,bleu);
    this->m_estActif = estAllume;
}
void Bouton::definir (int x ,int y,int taille ,Couleur c, bool estAllume)
{
    this->definir(x,y,taille, c.rouge(),c.vert(),c.bleu(), estAllume);
}
void Bouton::activer()
{
    this->m_estActif = true;
}
void Bouton::desactiver()
{
    this->m_estActif = false;
}
bool Bouton::actif()  const
{
    return this->m_estActif;
}
int Bouton::coordX() const
{
    return this->m_cercle.coordX();
}
int Bouton::coordY() const
{
    return this->m_cercle.coordY();
}
int Bouton::rayon() const
{
    return this->m_cercle.rayon();
}
Couleur Bouton::couleur() const
{
    return this->m_cercle.couleur();
}
void Bouton::definirCouleur(Couleur coul)
{
    this->m_cercle.definirCouleur(coul);
}

void Bouton::dessinerBouton (Couleur couleurBouton, Fenetre& f) const
{
    if(this->m_estActif)
    {
        f.choixCouleurTrace(couleurBouton);
        f.remplitEllipse(this->coordX()-this->rayon()/2, this->coordY()-this->rayon()/2, this->rayon(), this->rayon());
    }
}
void Bouton::afficher (Fenetre& f) const
{
    this->m_cercle.afficher(f);

    this->dessinerBouton(this->couleur(), f);
}
void Bouton::effacer (Fenetre& f) const
{
    this->m_cercle.effacer(f);

    this->dessinerBouton(f.couleurFond(), f);
}
bool Bouton::touche(int x,int y) const
{
    return this->m_cercle.touche(x,y);
}
