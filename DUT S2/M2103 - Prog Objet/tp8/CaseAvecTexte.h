#include "Fenetre.h"
#include "CaseACocher.h"

class CaseAvecTexte : public CaseACocher{
protected :
    char* m_texte; // Texte dans la case
public :
    CaseAvecTexte (const CaseAvecTexte&);
    CaseAvecTexte (CaseACocher = CaseACocher(), const char* = "Sans texte");
    ~CaseAvecTexte();
    void definirTexte(const char*);
    void afficher (Fenetre&) const;
    void effacer(Fenetre&) const;
};


