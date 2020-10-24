#include "Pieces.h"

Pieces::Pieces(string refe, string libel, double pds, int flouze)
{
    this->poids = pds;
    this->ref = refe;
    this->libelle = libel;
    this->prix = flouze;
}

Pieces::~Pieces()
{
    //dtor
}
