#include "Produits.h"

Produits::Produits(string laRef, string lib, double prix)
{
    this->reference = laRef;
    this->libelle = lib;
    this->prix = prix;
}

Produits::~Produits()
{
    //dtor
}
