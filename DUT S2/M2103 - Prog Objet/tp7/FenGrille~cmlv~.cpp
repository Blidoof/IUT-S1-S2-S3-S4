#include "FenGrille.h"

void FenGrille::dessinerQuadrillage()
{
    this->choixCouleurTrace(220,220,220);

    for (unsigned short int i = 0 ; i < this->largeur() ; i+= this->m_l)
    {
        this->traceLigne(i,0,i,this->hauteur());
    }

    for (unsigned short int i = 0 ; i < this->hauteur() ; i+= this->m_h)
    {
        this->traceLigne(0,i,this->largeur(),i);
    }

}

FenGrille::FenGrille (int h, int l) :
    Fenetre (),
    m_h(h),
    m_l(l) {}

FenGrille::FenGrille (const char * nom, int l_fenetre, int h_fenetre, int x , int y, int r, int v, int b, int h_grille, int l_grille) :
    Fenetre (nom, l_fenetre, h_fenetre, x, y, r, v, b),
    m_h(h_grille),
    m_l(l_grille)
{
    this->dessinerQuadrillage();
}

FenGrille::FenGrille ( const FenGrille& original) :
    Fenetre (original),
    m_h(original.m_h),
    m_l(original.m_l) {}


void FenGrille::apparait (const char* nom, int l_fenetre, int h_fenetre, int x, int y, int r, int v, int b)
{
    this->Fenetre::apparait(nom, l_fenetre, h_fenetre, x, y, r, v, b);
    this->dessinerQuadrillage();
}

void FenGrille::effacer()
{
    this->Fenetre::effacer();
    this->dessinerQuadrillage();
}

void FenGrille::afficherCase (const CaseACocher& cac)
{
    cac.afficher(*this);
}
