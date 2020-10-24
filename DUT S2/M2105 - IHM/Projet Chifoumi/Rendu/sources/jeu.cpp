/***************************************************************
 * Name:      Jeu.cpp
 * Purpose:   Code du jeu Chifoumi
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/

#include "jeu.h"
#include <stdlib.h>
#include <time.h>


Jeu::Jeu()
{
    this->initialiserControleur();
    srand(time(NULL));
}

Jeu::~Jeu()
{
    //Destructeur
}

void Jeu::initialiserControleur()
{
    this->setScoreJ1(0);
    this->setScoreJ2(0);
	this->setEtatSys(Jeu::initial);
}

Jeu::UnEtat Jeu::getEtatSys ()
{
	return this->etatSysteme;
}

void Jeu::setEtatSys (Jeu::UnEtat etat)
{
	this->etatSysteme = etat;
}

int Jeu::getScoreJ1()
{
    return this->scoreJ1;
}

void Jeu::setScoreJ1(int score)
{
    this->scoreJ1 = score;
}

int Jeu::getScoreJ2()
{
    return this->scoreJ2;
}

void Jeu::setScoreJ2(int score)
{
    this->scoreJ2 = score;
}

Principale* Jeu::getVue()
{
    return this->laVue;
}

void Jeu::setVue (Principale* vue)
{
    this->laVue = vue;
}

Jeu::UnSigne Jeu::getSigneJ1()
{
    return this->signeJ1;
}

void Jeu::setSigneJ1(UnSigne signe)
{
    this->signeJ1 = signe;
}

Jeu::UnSigne Jeu::getSigneJ2()
{
    return this->signeJ2;
}

void Jeu::setSigneJ2(UnSigne signe)
{
    this->signeJ2 = signe;
}

void Jeu::demandeNouvellePartie()
{
    this->initialiserControleur(); //On réinitialise le controleur (scores et etat)
	this->laVue->changerEtatBouton(false); //On désactive le bouton
    this->laVue->effacerScores();
    this->laVue->effacerSignes();
}

void Jeu::jouer(int valeurSigneJ1)
{
	if (this->getEtatSys() == Jeu::initial)
	{
		this->setEtatSys(Jeu::partieEnCours);
		this->laVue->changerEtatBouton(true); //On réactive le bouton
	}

    this->setSigneJ1(this->determinerSigne(valeurSigneJ1)); // Determiner signe J1

    this->setSigneJ2(this->genererUnsigne()); // Generer signe J2

    int resultat = this->determinerLeGagnant(); // comparer les signes

    this->actualiserScores(resultat); // Actualiser le score

    //Mettre a jour
    this->laVue->MajSignes();
    this->laVue->afficherScores();
}

int Jeu::genererNombre(int min, int max)
{
    return rand()%(max-min) + min; // Genere un nombre dans l'intervalle [min ; max [
}


Jeu::UnSigne Jeu::genererUnsigne()
{
    UnSigne valeurGeneree; //La valeur qui sera retournée
    unsigned int nbAleatoire; //Nombre généré qui permettra de determiner le signe (entre 1 et 3)
    nbAleatoire = genererNombre(1,4);//Génération du nombre
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = pierre;
        break;
    case 2 :
        valeurGeneree = feuille;
        break;
    case 3 :
        valeurGeneree = ciseaux;
        break;
    }
    return valeurGeneree;
}

Jeu::UnSigne Jeu::determinerSigne (int operande)
{
    //1 = pierre, 2 = feuille, 3 = ciseaux
    switch (operande)
    {
    case 1 : return Jeu::pierre;
        break;

    case 2 : return Jeu::feuille;
        break;

    case 3 : return Jeu::ciseaux;
        break;
    }
}

int Jeu::determinerLeGagnant ()
{
    // Si J1 gagne, on retourne 1, si J2 gagne on retourne 2, si il y a égalité on retourne 0

    if ((this->signeJ1 == pierre) && (this->signeJ2 == feuille))
    {
        return 2;
    }
    else
    {
        if ((this->signeJ1 == pierre) && (this->signeJ2 == ciseaux))
        {
            return 1;
        }
        else
        {
            if ((this->signeJ1 == feuille) && (this->signeJ2 == pierre))
            {
                return 1;
            }
            else
            {
                if ((this->signeJ1 == feuille) && (this->signeJ2 == ciseaux))
                {
                    return 2;
                }
                else
                {
                    if ((this->signeJ1 == ciseaux) && (this->signeJ2 == pierre))
                    {
                        return 2;
                    }
                    else
                    {
                        if ((this->signeJ1 == ciseaux) && (this->signeJ2 == feuille))
                        {
                            return 1;
                        }
                        else
                        {
                                return 0;
                        }
                    }
                }
            }
        }
    }
}

void Jeu::actualiserScores(int resultat)
{
    //Si J1 gagne on augmente le score de 1 point, pareil pour J2
    switch (resultat)
    {
    case 1 : this->scoreJ1++;
        break;
    case 2 : this->scoreJ2++;
        break;
    case 0: //on ne fait rien si égalité
        break;
    }

}

void Jeu::demandeInfos()
{
    this->laVue->afficherInfos();
}

void Jeu::demandeParametres()
{
    this->laVue->ouvrirFenetreParametres();
}

void Jeu::demandeQuitter()
{
    this->laVue->Close();
}


