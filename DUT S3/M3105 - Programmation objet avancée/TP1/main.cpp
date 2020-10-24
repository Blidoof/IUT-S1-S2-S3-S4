#include <iostream>
#include "Individu.h"
#include "Voiture.h"

using namespace std;

int main()
{
    Voiture* voit1 = new Voiture("RenaultClio", "123AB64");
    Voiture* voit2 = new Voiture("Peugeot106", "678CD96");
    Voiture* voit3 = new Voiture("CitroenPicasso", "456EF75");

    Individu* ind1 = new Individu("Marcel", "Durant");
    Individu* ind2 = new Individu("Emma", "Auzi");
    Individu* ind3 = new Individu("Manon", "Darget");

    voit1->setPilote(ind1);

    ind1->setVoiture(voit1);

    cout << ind1->toStringAndLink();


return 0;
}
