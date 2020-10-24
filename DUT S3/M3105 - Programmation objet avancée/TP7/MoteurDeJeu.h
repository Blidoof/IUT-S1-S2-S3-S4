#ifndef MOTEURDEJEU_H_INCLUDED
#define MOTEURDEJEU_H_INCLUDED
/******************
// MOTEUR DU JEU
******************/
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "ElementsDeJeu.h"

// DECLARATION DES DIRECTIVES RECONNUES AU CLAVIER
#define DIRECTIVE_STOP   '5'
#define DIRECTIVE_DROITE '6'
#define DIRECTIVE_GAUCHE '4'
#define DIRECTIVE_HAUT   '8'
#define DIRECTIVE_BAS    '2'
#define DIRECTIVE_ACCELERER '+'
#define DIRECTIVE_RALENTIR  '-'
#define DIRECTIVE_NULLE char (NULL)

// DEFINITION DES DEPLACEMENTS RELATIFS DE LA TÊTE DU SERPENT
// Note : le coin supérieur gauche de l'écran est (0, 0)
#define STOP   0
#define DROITE 1
#define GAUCHE 2
#define HAUT   3
#define BAS    4
int deltaX[] = {0, 1, -1, 0, 0};
int deltaY[] = {0, 0, 0, -1, 1};

// DEFINITION DES REPRESENTATIONS GRAPHIQUES
#define APPARENCE_TETE  '@'  // POUR LE serpent
#define APPARENCE_CORPS 'o'  // POUR LE serpent
#define APPARENCE_CADRE '*'  // POUR LE cadre

// DEFINITION DES BORNES DE VITESSE POUR LE serpent
#define VITESSE_MAX 9
#define VITESSE_MIN 1
#define GRAIN_DE_TEMPS 100 // qui s'écoule en millisecondes entre 2 déplacements

using namespace std;

/*
-- DEFINITION DU MoteurDejeu
*/
class MoteurDeJeu {

private: /// COMPOSANTS DU MoteurDeJeu
    Cadre*   cadre;   // dans lequel s'inscrit le jeu
    Serpent* serpent; // que le joueur déplace vers la cible
    Cible*   cible;   // qui se régénère et rapporte du crédit dès quelle est touchée

private: /// PARAMETRES DU MoteurDeJeu
    int direction;    // STOP, HAUT, BAS, DROITE,GAUCHE vers laquelle se dirige le serpent
    int vitesse;      // VITESSE_MIN..VITESSE_MAX a laquelle se déplace le serpent
    int score;        // que cumule le sepent en touchant les cibles

public:

    /// CONSTRUCTEUR MoteurDeJeu
    MoteurDeJeu () {

        // INITIALISATION DES PARAMETRES DU MoteurDeJeu
        direction = STOP;
        vitesse = VITESSE_MIN;
        score = 0;

        // CREATION DU COMPOSANT cadre
        cadre = new Cadre (APPARENCE_CADRE);

        // CREATION DU COMPOSANT serpent
        serpent = new Serpent (getRandomCoordonnees(), APPARENCE_CORPS, APPARENCE_TETE);

        // CREATION DU COMPOSANT cible
        Coordonnees xy; // les coordonnées xy ou placer la cible doivent différere du serpent
        do {
            xy = getRandomCoordonnees ();
        } while (serpent->coincider(xy));
        // création de la cible avec ses coordonnées et sa valeur comprise entre 1 et 9
        cible = new Cible (xy, (1 + random() % 9));
    } /// FIN CONSTRUCTEUR MoteurDeJeu

public: /// METHODES POUR installer, jouer ET terminer UN JEU

    /// METHODE installer
    void installer () {
        // EFFACER L'ECRAN ET AFFICHER LE cadre
        system("CLS");  cadre->afficher();
        // AFFICHER LE serpent ET LA cible
        serpent->afficher(); cible->afficher();
    }

    /// METHODE jouer
    void jouer () {

        // VARIABLES LOCALES POUR GERER LE DEPLACEMENT DU serpent
        Coordonnees coordTete, futureCoordTete;

        // VARIABLES LOCALES POUR GERER LE DEPLACEMENT DE LA cible
        Coordonnees futureCoordCible;
        unsigned int futureValeurCible;

        /// BOUCLE DU JEU DONT ON SORT QUAND LA TETE DU serpent
        /// TOUCHE LE cadre OUBIEN TOUCHE SON PROPRE CORPS
        for (;;) {
            // AFFICHER LES PARAMETRES DU jeu
            gotoxy (Coordonnees (1, 24)); cout << "Vitesse (" << DIRECTIVE_ACCELERER << "/" << DIRECTIVE_RALENTIR << ") :";
            gotoxy (Coordonnees (17, 24)); cout << vitesse;
            gotoxy (Coordonnees (30, 24)); cout << "Score : " << score;
            gotoxy (Coordonnees (50, 24)); cout << " H/" << DIRECTIVE_HAUT << "  B/" << DIRECTIVE_BAS << "  D/" << DIRECTIVE_DROITE << "  G/" << DIRECTIVE_GAUCHE << "  S/" << DIRECTIVE_STOP;

            // CONNAITRE LES coordTete ACTUELLES DU serpent
            coordTete = *(serpent->corps.begin());

            // LIRE ET INTERPRETER LA directive SAISIE AU CLAVIER
            switch (lireDirective()) {
                case DIRECTIVE_NULLE: break; // rien n'a été saisi
                case DIRECTIVE_ACCELERER: (vitesse == VITESSE_MAX ? vitesse : vitesse++); break;
                case DIRECTIVE_RALENTIR:  (vitesse > VITESSE_MIN ? vitesse-- : vitesse); break;
                case DIRECTIVE_STOP:   direction = STOP;   break;
                case DIRECTIVE_DROITE: direction = DROITE; break;
                case DIRECTIVE_GAUCHE: direction = GAUCHE; break;
                case DIRECTIVE_HAUT:   direction = HAUT;   break;
                case DIRECTIVE_BAS:    direction = BAS;    break;
            }

            // ETABLIR LES futureCoordTete DU SERPENT
            futureCoordTete.first = coordTete.first + deltaX [direction];
            futureCoordTete.second =  coordTete.second + deltaY [direction];

            // CAS OU LES futureCoordTete TOUCHENT LE cadre OU TOUCHENT LE serpent : ON SORT DE LA BOUCLE DE JEU
            if (cadre->coincider (futureCoordTete) || (serpent->coincider (futureCoordTete) && direction != STOP)) {
                break;
            }


            // CAS OU LES futureCoordTete TOUCHENT LA cible
            if(cible->coincider(futureCoordTete)) {

                // 1. crediter le score du joueur
                score += cible->valeur;

                // 2. crediter le serpent de la longueur a ralonger
                serpent->creditLongueur += cible->valeur;

                // 3. établir les nouvelles coordonnées de la cible
                do
                {
                    futureCoordCible = getRandomCoordonnees();
                } while (cadre->coincider(futureCoordCible) || serpent->coincider(futureCoordCible) || futureCoordCible == futureCoordTete);


                // 4. établir la valeur de la cible : elle doit valoir entre 1 et 9
                futureValeurCible = (random() % 9) + 1;

                // 5. effacer la cible
                cible->effacer();

                // 6. redéfinir les propriétés de la cible
                cible->definir(futureCoordCible, futureValeurCible);

                // 7. afficher la cible
                cible->afficher();
            }

            // DEPLACER LE serpent SI NECESSAIRE
            if (futureCoordTete != coordTete) {
                    serpent->effacer();
                    serpent->avancerEn(futureCoordTete);
                    serpent->afficher();
            }


            // TEMPORISER
            for (int nbDeGrains = 0 ; nbDeGrains < (VITESSE_MAX - vitesse) ; nbDeGrains++) {
                    Sleep (GRAIN_DE_TEMPS);
            }
        }
    }  /// FIN METHODE jouer

    /// METHODE terminer
    void terminer () {
        gotoxy (Coordonnees (10, 30)); cout << "     P E R D U !!   ";
        cout << "taper un caractere pour recommencer      "; char c; cin >> c;
    }

private: /// METHODE UTILES AU TRAITEMENT

    /// METHODE gotoxy : positionne le curseur en xy - repère cartésien (0,0) en bas à gauche
    void gotoxy (const Coordonnees xy) {
        //assert(xy.first > 0 && xy.first < LARGEUR_CADRE && xy.second > 0 && xy.second < HAUTEUR_CADRE);
        COORD coord;
        coord.X = xy.first;
        coord.Y = xy.second;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    /// METHODE lireDirective : retourne l'éventuel caractère saisi au clavier
    char lireDirective() {
        return (kbhit() ? char (getch()) : DIRECTIVE_NULLE);
    }

    /// METHODE getRandomCoordonnees : retourne des coordonnees inscrites dans le cadre
    Coordonnees getRandomCoordonnees () {
        Coordonnees xy;
        xy.first = 1 + random() % (LARGEUR_CADRE - 1);
        xy.second = 1 + random() % (HAUTEUR_CADRE - 1);
        return xy;
    }

    /// METHODE random : retourne une valeur aléatoire
    int random () {
        srand (time (NULL));
        return rand ();
    }
};
#endif // MOTEURDEJEU_H_INCLUDED
