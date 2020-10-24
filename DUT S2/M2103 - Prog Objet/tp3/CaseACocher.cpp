#include "Fenetre.h"
#include "Carre.h"
#include "CaseACocher.h"

void CaseACocher::definirCadre(int x,int y,int cote,Couleur coul)  // Definit le cadre d'une case a cocher
{
    this->m_carre.placer(x,y);
    this->m_carre.dimensionner(cote);
    this->m_carre.definirCouleur(coul);
}

Carre CaseACocher::cadre() const  // Retourne le carré utilisé pour constitier la case a cocher
{
    return this->m_carre;
}

void CaseACocher::definirEtat(char c)   // permet de cocher ou decocher une case
{
    if (c == 'C')
    {
        this->m_estCoche = true;
    }
    else
    {
        this->m_estCoche = false;
    }
}

char CaseACocher::etat() const   // Retourne l'état d'une case, cochée ou non
{
    if(this->m_estCoche)
    {
        return 'C';
    }
    else
    {
        return 'N';
    }
}

void CaseACocher::dessinerCroix(Couleur, Fenetre& f) const
{
    f.traceLigne(this->m_carre.coordX(), this->m_carre.coordY(), this->m_carre.coordX()+this->m_carre.cote(), this->m_carre.coordY()+this->m_carre.cote());
    f.traceLigne(this->m_carre.coordX()+this->m_carre.cote(), this->m_carre.coordY(), this->m_carre.coordX(), this->m_carre.coordY()+this->m_carre.cote());
}

void CaseACocher::afficher(Fenetre& f) const   // Affiche la case a cocher
{
    this->m_carre.afficher(f);

    if(this->m_estCoche)
    {
        this->dessinerCroix(this->m_carre.couleur(), f);
    }
}
void CaseACocher::effacer(Fenetre& f) const   // Efface la case a cocher
{
    this->m_carre.effacer(f);

    if(this->m_estCoche)
    {
        this->dessinerCroix(f.couleurFond(), f);
    }
}

