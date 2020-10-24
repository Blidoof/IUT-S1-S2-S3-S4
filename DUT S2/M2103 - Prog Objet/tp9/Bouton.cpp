#include "Fenetre.h"
#include "Cercle.h"
#include "Couleur.h"
#include "Bouton.h"

Bouton::Bouton() :
    Cercle(),
    m_estActif(false) {}

Bouton::Bouton(const Bouton& original) :
    Cercle(original),
    m_estActif(original.m_estActif) {}

Bouton::Bouton(Cercle c, bool etat) :
    Cercle(c),
    m_estActif (etat) {}

void Bouton::definir (int x,int y,int taille ,int rouge,int vert,int bleu, bool estAllume)
{
    this->placer(x,y);
    this->dimensionner(taille);
    this->definirCouleur(rouge,vert,bleu);
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
    this->Cercle::afficher(f);

    this->dessinerBouton(this->couleur(), f);
}
void Bouton::effacer (Fenetre& f) const
{
    this->Cercle::effacer(f);

    this->dessinerBouton(f.couleurFond(), f);
}

string Bouton::quiSuisJe() const
{
    return "Bouton-Cercle-ElementGraphique";
}
