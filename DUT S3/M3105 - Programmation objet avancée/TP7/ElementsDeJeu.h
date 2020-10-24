#ifndef ELEMENTSDEJEU_H_INCLUDED
#define ELEMENTSDEJEU_H_INCLUDED
/******************
// ELEMENTS DU JEU
******************/
#include <windows.h> // pour les valeurs al�atoires et effacer l'�cran
#include <conio.h>   // pour g�rer la saisie a la vol�e
#include <stdio.h>
#include <iostream>

#define LARGEUR_CADRE 79
#define HAUTEUR_CADRE 23

using namespace std;

typedef pair<int, int> Coordonnees; // notre jeu utilisera des coordonn�es

/*
-- DEFINITION DE Element
*/
class ElementDeJeu {

public: /// METHODES A SPECIALISER DANS LES SOUS-CLASSES
    virtual void afficher () {};
    virtual void effacer () {};
    virtual bool coincider (const Coordonnees xy) { return true; }; // par d�faut

protected: /// METHODES UTILES AU TRAITEMENT DANS LES SOUS-CLASSES

    /// METHODE gotoxy : positionne le curseur en xy - rep�re cart�sien (0,0) en bas � gauche
    void gotoxy (const Coordonnees xy) {
        COORD coord;
        coord.X = xy.first;
        coord.Y = xy.second;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
};

/*
-- DEFINITION DE Cadre
*/
class Cadre : public ElementDeJeu {
private: /// PARAMETRES DE Cadre
    char apparence; // apprence des cases du cadre

public:
    /// CONSRUCTEUR Cadre
    Cadre (char carCadre) {
        apparence = carCadre;
    }

    /// METHODE afficher POUR Cadre
    void afficher () {
        for (int i = 0; i < LARGEUR_CADRE; i++) {
            gotoxy (Coordonnees (i, 0)); cout << apparence;
            gotoxy (Coordonnees (i, HAUTEUR_CADRE)); cout << apparence;
        }
        for (int j = 0; j < HAUTEUR_CADRE; j++) {
            gotoxy (Coordonnees (0, j)); cout << apparence;
            gotoxy (Coordonnees (LARGEUR_CADRE, j)); cout << apparence;
        }
    }

    /// METHODE coincider POUR Cadre
    bool coincider (const Coordonnees xy) {
        return ((xy.first == LARGEUR_CADRE || xy.second == HAUTEUR_CADRE || xy.first == 0 || xy.second == 0) ? true : false);
    }
};

/*
-- DEFINITION DU serpent
*/
#include <list>
class Serpent : public ElementDeJeu {

private: /// PARAMETRES DE Serpent
    char apparenceCorps; // apparence du corps du serpent
    char apparenceTete;  // apprende de la t�te du serpent
    typedef list <Coordonnees> Corps; // d�finition du type Corps
public:
    Corps corps;         // le corps est une liste de coordonn�es
    unsigned int creditLongueur; // suite � la prise de cible/s

public:
    /// CONSTRUCTEUR Serpent
    Serpent (Coordonnees xy, char carCorps, char carTete) {
        corps.clear(); corps.push_front(xy); // initialise le corps l'unique coordonn�e xy
        apparenceCorps = carCorps;
        apparenceTete = carTete;
        creditLongueur = 0;
    }

    /// METHODE afficher POUR Serpent
    void afficher () {
        // afficher la t�te
        Corps::iterator iter = corps.begin();
        gotoxy (*iter); cout << apparenceTete;
        // afficher le reste du corps
        while (++iter != corps.end()) {
            gotoxy (*iter); cout << apparenceCorps;
        }
    }

   /// METHODE effacer POUR Serpent
    void effacer () {
        for (Corps::iterator iter = corps.begin(); iter != corps.end(); iter++)
            gotoxy (*iter); cout << ' ';
    }

    /// METHODE coincider POUR Serpent : vrai si son corps occupe les coordonn�es xy
    bool coincider (const Coordonnees xy) {
        for (Corps::iterator iter = corps.begin(); iter != corps.end(); iter++)
            if (*iter == xy) return true;
        return false;
    }

    /// METHODE avancerEn
    void avancerEn (const Coordonnees xy) {
        // on place les nouvelles coordonn�e xy en d�but de liste
        corps.push_front (xy);
        // s'il n'y a pas de cr�dit pour prolonger la queue du serpent
        if (creditLongueur == 0) // on retire le dernier �l�ment de la liste
            corps.pop_back ();
        // sinon il y a un cr�dit de moins et on ne retire pas le dernier �l�ment
        else  creditLongueur--;
    }
};

/*
-- DEFINITION D'UNE Cible DU JEU
*/
class Cible : public ElementDeJeu {
public: /// PARAMETRES DE Cible
    Coordonnees position; // entre (0,0) et (79,22)
    unsigned int valeur; // entre 1 et 9

public:
    /// CONSTRUCTEUR Cible
    Cible (const Coordonnees unePosition, const unsigned int unevaleur) {
        definir (unePosition, unevaleur);
    }

    /// METHODE definir : (re)d�finit les propri�t�s de la cible
    void definir (const Coordonnees unePosition, const unsigned int uneValeur) {
        position = unePosition; valeur = uneValeur;
    }

    /// METHODE afficher POUR Cible
    void afficher () {
        gotoxy (position); cout << valeur;
    }

    /// METHODE effacer POUR Cible
    void effacer () {
        gotoxy (position); cout << ' ';
    }

    /// METHODE coincider POUR Cible
    bool coincider (const Coordonnees xy){
        return (position == xy);
    }
};
#endif // ELEMENTSDEJEU_H_INCLUDED
