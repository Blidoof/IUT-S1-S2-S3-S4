#include "IndividuMenteur.h"

IndividuMenteur::IndividuMenteur(string n, string p, int a) : Individu(n,p,a)
{
    //ctor
}

IndividuMenteur::~IndividuMenteur()
{
    //dtor
}

int IndividuMenteur::get_age() {

int age = Individu::get_age();

return (age >= 30 ? age - 2 : age);

}
