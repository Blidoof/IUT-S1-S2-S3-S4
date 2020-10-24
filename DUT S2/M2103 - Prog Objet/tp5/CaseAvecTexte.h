#include "Fenetre.h"
#include "CaseACocher.h"

class CaseAvecTexte : public CaseACocher{
protected :
    char* m_texte; // Texte dans la case
public :
    CaseAvecTexte (const CaseAvecTexte&);
    CaseAvecTexte (CaseACocher = CaseACocher(), char* = "Sans texte");
    ~CaseAvecTexte();
    void definirTexte(char*);
    void afficher (Fenetre&) const;
    void effacer(Fenetre&) const;
};


