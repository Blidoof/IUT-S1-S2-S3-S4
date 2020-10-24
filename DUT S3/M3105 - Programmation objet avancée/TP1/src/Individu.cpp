#include "Individu.h"

Individu::Individu(string nom, string prenom)
{
    this->m_nom=nom;
    this->m_prenom=prenom;
    this->maVoiture = NULL;
}

Individu::~Individu()
{
    supprimerLien();
}

string Individu::toString() {

    string result = "Nom : " + this->Getnom() + "Prenom : " + this->Getprenom();

    return result;

}

string Individu::toStringAndLink() {

    string result;

    if (this->maVoiture != NULL) {
        result = "Nom : " + this->Getnom()+ "\n" + "Prenom : " + this->Getprenom()+ "\n" + "Voiture : " + this->maVoiture->Getmarque() + "\n"
        + "Plaque voiture : " + this->maVoiture->Getplaque()+ "\n";
    }
    else {
        result = "Nom : " + this->Getnom()+ "\n" + "Prenom : " + this->Getprenom()+ "\n" + "Pas de voiture enregistree" + "\n";
    }


    return result;

}

void Individu::setVoiture(Voiture* voit) {

    this->supprimerLien();

    this->maj_maVoiture(voit);

    if (this->maVoiture->getPilote() != this) {
        this->maVoiture->setPilote(this);
    }

}

void Individu::maj_maVoiture(Voiture* voit) {
    this->maVoiture = voit;
}

void Individu::supprimerLien() {
            if (this->maVoiture != NULL) {
               this->maVoiture->maj_monPilote(NULL);
               this->maj_maVoiture(NULL);
            }
}
