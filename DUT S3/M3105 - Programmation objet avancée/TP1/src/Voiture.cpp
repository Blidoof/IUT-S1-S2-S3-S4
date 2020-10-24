#include "Voiture.h"

Voiture::Voiture(string marque, string plaque)
{
    this->m_marque=marque;
    this->m_plaque=plaque;
    this->monPilote = NULL;
}

Voiture::~Voiture()
{
    supprimerLien();
}

string Voiture::toString() {

    string result = "Voiture : " + this->Getmarque() + "\n" + "Plaque : " + this->Getplaque();

    return result;

}

string Voiture::toStringAndLink() {

    string result;

    if (this->monPilote != NULL) {
        result = "Voiture : " + this->Getmarque() + "\n" + "Plaque : " + this->Getplaque() + "\n" + "Pilote : " + this->monPilote->Getnom() + " "
        + this->monPilote->Getprenom();
    }
    else {
        result = "Voiture : " + this->Getmarque() + "\n" + "Plaque : " + this->Getplaque() + "\n" + "Pas de pilote enrgistre";
    }

    return result;

}

void Voiture::setPilote (Individu* pilot) {

   this->supprimerLien();

    this->maj_monPilote(pilot);

    if (this->monPilote->getVoiture() != this) {
        this->monPilote->setVoiture(this);
    }
}

void Voiture::maj_monPilote(Individu* pilot) {
    this->monPilote = pilot;
}

void Voiture::supprimerLien() {
    if (this->monPilote != NULL) {
        this->monPilote->maj_maVoiture(NULL);
        this->monPilote = NULL;
    }

}

Individu* Voiture::getPilote() {
    return this->monPilote;
}
