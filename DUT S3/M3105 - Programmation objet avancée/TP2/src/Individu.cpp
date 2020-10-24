#include "Individu.h"

Individu::Individu(string n, string p, int a)
{
    this->prenom = p;
    this->nom = n;
    this->anneeNaissance = a;
    this->o = new Outils();
}

Individu::~Individu()
{
    //dtor
}

int Individu::get_age() {

int age = o->anneeActuelle() - this->anneeNaissance;

return age;

}
