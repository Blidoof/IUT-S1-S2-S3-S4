#include "FenetreDessin.h"

bool FenetreDessin::estPleine () const
{
    return (this->m_nb == TAILLEMAX);
}
void FenetreDessin::ajouter (ElementGraphique* e)
{
    if (!this->estPleine())
    {
        this->m_tab[m_nb] = e;
        this->m_nb++;
    }

    e->afficher(*this);
}

void FenetreDessin::ajouter (ElementGraphique& e)
{
    this->ajouter(&e);
}

void FenetreDessin::enlever (int element)
{
    int i;

    if ( this ->m_nb >= 1)
    {
        for (i = element ; i <= ((this->m_nb)-1) ; i++)
        {
            this->m_tab[i] = this->m_tab[i+1];
        }

        this->m_nb --;
    }

}

int FenetreDessin::touche (int x, int y) const
{


    bool trouve;
    int i = 0;
    int bsup = this->m_nb-1;

    for ( ; ; )
    {
        if (this->m_nb == 0)
        {
            break;
        }

        if (this->m_tab[i]->touche(x,y))
        {
            trouve = true;
            break;
        }

        if ( i >= bsup)
        {
            break;
        }

        i++;
    }

    if (trouve)
    {
        return i;
    }
    else
    {
        i = -1;
        return i;
    }
}

ElementGraphique* FenetreDessin::element(int e) const
{
    if ( e <= this->m_nb && e >= 0)
    {
        return this->m_tab[e];
    }
    else
        return NULL;
}

int FenetreDessin::nbElements() const
{
    return this->m_nb;
}

FenetreDessin::FenetreDessin() :
    Fenetre(),
    m_nb(0) {}

FenetreDessin::FenetreDessin(const char * texte, int l , int h, int x /* = 0 */ , int y /* = 0 */, int r /*= 255 */, int v /*= 255 */, int b /*= 255 */) :
    Fenetre (texte, l, h, x, y, r ,v ,b ),
    m_nb(0) {}

FenetreDessin::FenetreDessin (const FenetreDessin& original) :
    Fenetre(original),
    m_nb(original.m_nb)
{

    for (int i = 0 ; i <= original.m_nb ; i++)
    {
        this->m_tab[i] = original.m_tab[i];
    }

}
