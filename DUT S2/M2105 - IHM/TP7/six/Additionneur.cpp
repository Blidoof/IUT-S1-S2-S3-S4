#include "additionneur.h"
#include "principale6.h"

Additionneur::Additionneur()
{
    this->initisalisationControleur(); // Met le controleur dans son état initial
    this->laVue->setAdditionneur(this); //Permet à la vue de se lier au controleur
}

Additionneur::~Additionneur()
{
    // Destructeur
}

void Additionneur::setOpG(int p_op)
{
    this->opG = p_op;
}

void Additionneur::setOpD(int p_op)
{
    this->opD = p_op;
}

int Additionneur::getSomme()
{
    return ((this->opG) + (this->opD)); // retourne opG+opD
}
Additionneur::UnEtat Additionneur::getEtat()
{
    return this->etat; // Rtourne l'état du systeme selon la liste énumérée de Additionneur.h
}

void Additionneur::setEtat(UnEtat p_etat)
{
    this->etat = p_etat;
}

void Additionneur::initisalisationControleur()
{
    this->setEtat(saisiesEnCours); // Etat initial : attenteSaisie
}

void Additionneur::demandeAddition(string p_opG, string p_opD)
{
    //Variables contenant p_opG et p_opD une fois la convertionr réussie
    long int gauche;
    long int droite;

    //Variables contenant p_opG et p_opD que l'on convertira en nombres grâce à la méthode dédiée
    wxString x = p_opG;
    wxString y = p_opD;

    if (x.ToLong(&gauche) && y.ToLong(&droite)) // Convertion des wxString en long int
    {
        this->setOpG(gauche); // opG prend prend la valeur de p_opG maintenant convertie
        this->setOpD(droite); // opD prend prend la valeur de p_opD maintenant convertie
        this->notifierVue(this->getEtat()); // On notifie la vue qu'une action pouvant potentiellement changer son état a été effectuée
    }
    else
    {
        this->setEtat(erreur); // Convertion ratée : on passe en état d'erreur
        this->notifierVue(this->getEtat()); // On notifie la vue qu'une action pouvant potentiellement changer son état a été effectuée
    }
}

void Additionneur::accepteNotification()
{
    this->setEtat(saisiesEnCours); // On remet l'additionneur à l'état initial une fois la notification de l'erreur acceptée
}

void Additionneur::demandeEffacement()
{
    this->laVue->effacerZonesSaisie(); // En cas de demande d'effacement on informe la vue qu'elle doit effacer les zones de texte
}

Principale* Additionneur::getVue()
{
    return this->laVue; // On retourne la vue liée
}

void Additionneur::setVue(Principale* p_vue)
{
    this->laVue = p_vue; // On définir la vue
}

void Additionneur::notifierVue(UnEtat p_etat)
{

    switch (p_etat)
    {
    case saisiesEnCours :

        this->laVue->afficherResultat(this->getSomme()); // Si on est pas en situation d'erreur, on veut afficher le résultat
        break;

    case erreur:
        this->laVue->afficherEtatErreur(); // Si on est en situation d'erreur, on demande à la vue d'afficher le résultat adequat
        break;
    }

}
