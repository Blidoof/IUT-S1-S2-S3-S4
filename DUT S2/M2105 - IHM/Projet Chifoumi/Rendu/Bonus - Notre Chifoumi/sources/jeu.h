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

    ///*attributs m�tier
    int scoreJ1; // Score du joueur 1 (utilisateur)
    int scoreJ2; // Score du joueur 2 (machine)


    UnSigne signeJ1; //Carte jou�e par le joueur 1
    UnSigne signeJ2; //Carte jou�e par le joueur 2

public:

    ///*m�thodes m�tier
    Jeu(); //Constructeur de la classe
    ~Jeu(); //Destructeur de la classe


    int getScoreJ1(); //Renvoie le score du joueur 1

    void setScoreJ1(int score); //D�finit le score du joueur 1

    int getScoreJ2(); // Renvoie le score du joueur 2

    void setScoreJ2(int score);  //D�finit le score du joueur 2

    UnSigne getSigneJ1(); //Renvoie le signe utilis� par le joueur 1

    void setSigneJ1(UnSigne signe); // D�finit le signe utilis� par le joueur 1

    UnSigne getSigneJ2(); //Renvoie le signe utilis� par le joueur 2

    void setSigneJ2(UnSigne signe); // D�finit le signe utilis� par le joueur 2

    UnSigne determinerSigne (int); //Determine le signe correspondant � l'entier pass� en param�tre


///*Controleur
public:
    ///*Etats du syst�me
    enum UnEtat{initial,partieEnCours};

    ///*Methodes du controlleur

    //Gestion des etats du syst�me
    UnEtat getEtat(); // Retourne l'�tat actuel du syst�me
    void setEtat(UnEtat etat); // D�finit l'�tat du syst�me
    void initialiserControleur(); //Met le controleur dans son �tat initial

    //Gestion des evenements

    void demandeNouvellePartie(); //Ordonne a la vue de se mettre a jour en remettant les scores � zero.

    void jouer(int valeurSigne); /*
    Traite la demande de jeu pour le param�tre carteJoueur pass� par valeur.
    Le type int est une valeur arbitraire attribu�e a la carte dans la vue et  analys�e dans le contr�leur. On peut �galement directement y attribuer une valeur de type UnSigne.
    Ce que fait le contr�leur :
        D�termine le signe pass� en param�tre et modifie signeJ1 en cons�quence (1 = pierre, 2 = feuille, 3 = ciseaux).
        D�termine de mani�re al�atoire un chiffre entre 1 et 3 et modifie signeJ2 en cons�quence.
        Compare les deux signes jou�s et d�termine le gagnant.
        Actualise les scores
        Ordonne � la vue de se mettre � jour
    */

    ///*Fonction n�c�ssaires au fonctionnement

    int genererNombre(int min, int max); // Gen�re un nombre dans l'intervalle [1-4[ en s'appuyant sur la fonction srand

    UnSigne genererUnsigne(); //G�nere le signe jou� par la machine en s'appuyant sur la fonction genererNombre

    int determinerLeGagnant(); //Compare les signes des deux joueurs et d�termine le gagnant ou eventuellement l'�galit�

    void actualiserScores(int resultat); // Actualise les scores des joueurs en fonction du r�sultat retourn� par determienrLeGagnant


    //Gestion du lien entre le mod�le et la vue
    Principale* getVue(); //Renvoie la vue li�e au controleur (pointeur)
    void setVue (Principale*); //D�finit la vue li�e au controleur


protected:
    ///*Attributs li�s au controleur

    Principale* laVue; //Vue li�e au controleur
    UnEtat etatSysteme; //Etat actuel du syst�me

};


#endif
