#include "Fenetre.h"
#include "Carre.h"
#include "CaseACocher.h"

CaseACocher::CaseACocher() :
    Carre(),
    m_estCoche(false) {}

CaseACocher::CaseACocher(const CaseACocher& original)  :
    Carre(original),
    m_estCoche(original.m_estCoche) {}

CaseACocher::CaseACocher (int x,int y, int dimension, Couleur coul, char etat) :
    Carre(x,y,dimension,coul),
    m_estCoche(etat == 'C') {}

CaseACocher::CaseACocher (Carre carre, char etat) :
    Carre(carre),
    m_estCoche(etat == 'C') {}

Carre CaseACocher::cadre() const  // Retourne le carré utilisé pour constitier la case a cocher
{
    return (*this);
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
    f.traceLigne(this->coordX(), this->coordY(), this->coordX()+this->cote(), this->coordY()+this->cote());
    f.traceLigne(this->coordX()+this->cote(), this->coordY(), this->coordX(), this->coordY()+this->cote());
}

void CaseACocher::afficher(Fenetre& f) const   // Affiche la case a cocher
{
    this->Carre::afficher(f);

    if(this->m_estCoche)
    {
        this->dessinerCroix(this->couleur(), f);
    }
}
void CaseACocher::effacer(Fenetre& f) const   // Efface la case a cocher
{
    this->Carre::effacer(f);

    if(this->m_estCoche)
    {
        this->dessinerCroix(f.couleurFond(), f);
    }
}

string CaseACocher::quiSuisJe() const
{
    return "CaseACocher-Carre-ElementGraphique";
}

