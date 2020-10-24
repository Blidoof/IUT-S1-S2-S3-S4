#ifndef CASEACOCHER_H
#define CASEACOCHER_H

#include "Fenetre.h"
#include "Carre.h"

class CaseACocher : public Carre {
protected :
    bool m_estCoche; // Indique si le carré est coché ou non
    void dessinerCroix(Couleur, Fenetre& f) const;
public :
    CaseACocher(); // Constructeur par défaut
    CaseACocher(const CaseACocher&); // Constructeur de copie
    CaseACocher (int,int, int, Couleur, char);
    CaseACocher (Carre, char);
    Carre cadre() const; // Retourne le carré utilisé pour constitier la case a cocher
    void definirEtat(char); // permet de cocher ou decocher une case
    char etat() const; // Retourne l'état d'une case, cochée ou non
    void afficher(Fenetre&) const; // Affiche la case a cocher
    void effacer(Fenetre&) const; // Efface la case a cocher
};



#endif // CASEACOCHER_H

