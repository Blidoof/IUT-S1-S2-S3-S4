#ifndef JEU_H
#define JEU_H

#include "Principale.h"


class Principale;

class Jeu {

///*Modele
public:
    ///*Type de carte (pour pouvoir y faire reference dans d'autres classes
    enum UnSigne{pierre = 1, feuille, ciseaux, chuck};

protected:

    ///*attributs métier
    int scoreJ1; // Score du joueur 1 (utilisateur)
    int scoreJ2; // Score du joueur 2 (machine)


    UnSigne signeJ1; //Carte jouée par le joueur 1
    UnSigne signeJ2; //Carte jouée par le joueur 2

public:

    ///*méthodes métier
    Jeu(); //Constructeur de la classe
    ~Jeu(); //Destructeur de la classe


    int getScoreJ1(); //Renvoie le score du joueur 1

    void setScoreJ1(int score); //Définit le score du joueur 1

    int getScoreJ2(); // Renvoie le score du joueur 2

    void setScoreJ2(int score);  //Définit le score du joueur 2

    UnSigne getSigneJ1(); //Renvoie le signe utilisé par le joueur 1

    void setSigneJ1(UnSigne signe); // Définit le signe utilisé par le joueur 1

    UnSigne getSigneJ2(); //Renvoie le signe utilisé par le joueur 2

    void setSigneJ2(UnSigne signe); // Définit le signe utilisé par le joueur 2

    UnSigne determinerSigne (int); //Determine le signe correspondant à l'entier passé en paramètre


///*Controleur
public:
    ///*Etats du système
    enum UnEtat{initial,partieEnCours};

    ///*Methodes du controlleur

    //Gestion des etats du système
    UnEtat getEtat(); // Retourne l'état actuel du système
    void setEtat(UnEtat etat); // Définit l'état du système
    void initialiserControleur(); //Met le controleur dans son état initial

    //Gestion des evenements

    void demandeNouvellePartie(); //Ordonne a la vue de se mettre a jour en remettant les scores à zero.

    void jouer(int valeurSigne); /*
    Traite la demande de jeu pour le paramètre carteJoueur passé par valeur.
    Le type int est une valeur arbitraire attribuée a la carte dans la vue et  analysée dans le contrôleur. On peut également directement y attribuer une valeur de type UnSigne.
    Ce que fait le contrôleur :
        Détermine le signe passé en paramètre et modifie signeJ1 en conséquence (1 = pierre, 2 = feuille, 3 = ciseaux).
        Détermine de manière aléatoire un chiffre entre 1 et 3 et modifie signeJ2 en conséquence.
        Compare les deux signes joués et détermine le gagnant.
        Actualise les scores
        Ordonne à la vue de se mettre à jour
    */

    ///*Fonction nécéssaires au fonctionnement

    int genererNombre(int min, int max); // Genère un nombre dans l'intervalle [1-4[ en s'appuyant sur la fonction srand

    UnSigne genererUnsigne(); //Gènere le signe joué par la machine en s'appuyant sur la fonction genererNombre

    int determinerLeGagnant(); //Compare les signes des deux joueurs et détermine le gagnant ou eventuellement l'égalité

    void actualiserScores(int resultat); // Actualise les scores des joueurs en fonction du résultat retourné par determienrLeGagnant


    //Gestion du lien entre le modèle et la vue
    Principale* getVue(); //Renvoie la vue liée au controleur (pointeur)
    void setVue (Principale*); //Définit la vue liée au controleur


protected:
    ///*Attributs liés au controleur

    Principale* laVue; //Vue liée au controleur
    UnEtat etatSysteme; //Etat actuel du système

};


#endif
