#include "Fenetre.h"
#include "CaseAvecTexte.h"
#include <cstring>

CaseAvecTexte::CaseAvecTexte (const CaseAvecTexte& original) :
    CaseACocher (original)
{
    this->m_texte = new char[strlen(original.m_texte)+1];
    strcpy(this->m_texte, original.m_texte);
}

CaseAvecTexte::CaseAvecTexte (CaseACocher cac, const char* texte) :
    CaseACocher (cac)
{
    this->m_texte = new char [strlen(texte)+1];
    strcpy(this->m_texte, texte);
}

CaseAvecTexte::~CaseAvecTexte()
{
    delete [] this->m_texte;
}

void CaseAvecTexte::definirTexte(const char* texte)
{
    delete [] this->m_texte;
    this->m_texte = new char[strlen(texte)+1];
    strcpy(this->m_texte, texte);
}

void CaseAvecTexte::afficher (Fenetre& f) const
{
    this->CaseACocher::afficher(f);
    f.ecrit(this->coordX()+this->cote() + 25, this->coordY() + 25, this->m_texte);
}
void CaseAvecTexte::effacer(Fenetre& f) const
{
    this->CaseACocher::effacer(f);
    f.ecrit(this->coordX()+this->cote() + 25, this->coordY() + 25, this->m_texte);
}

string CaseAvecTexte::quiSuisJe() const
{
    return "CaseAvecTexte-CaseACocher-Carre-ElementGraphique";
}
