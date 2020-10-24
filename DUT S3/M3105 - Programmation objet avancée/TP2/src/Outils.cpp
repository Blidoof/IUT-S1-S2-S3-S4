#include "Outils.h"

Outils::Outils()
{
    //ctor
}

Outils::~Outils()
{
    //dtor
}

int Outils::anneeActuelle() {

time_t timer; // Stocke l'heure actuelle
struct tm *newTime;

//On demande l'heure
time(&timer);
newTime = localtime(&timer);
return (newTime->tm_year + 1900);
}
