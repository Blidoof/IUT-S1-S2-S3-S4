/***************************************************************
 * Name:      chifoumiMain.h
 * Purpose:   Code for Application Class
 * Author:    P.Dagorret ()
 * Created:   2017-05-19
 * Copyright: P.Dagorret ()
 **************************************************************/
#ifndef CHIFOUMI_H
#define CHIFOUMI_H
#include <iostream>
#include <iostream>

using namespace std;

class Chifoumi
{
    ///* ---- PARTIE MOD�LE ---------------------------

        ///* Une d�finition de type �num�r�
    public:
        enum UnCoup {pierre, papier, ciseau, rien};

        ///* M�thodes du Mod�le
    public:
        Chifoumi();
        virtual ~Chifoumi();

        // Getters
        UnCoup getCoupJoueur();
            /* retourne le dernier coup jou� par le joueur */
        UnCoup getCoupMachine();
            /* retourne le dernier coup jou� par le joueur */
        unsigned int getScoreJoueur();
            /* retourne le score du joueur */
        unsigned int getScoreMachine();
            /* retourne le score de la machine */
        char determinerGagnant();
            /* d�termine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
               en fonction du dernier coup jou� par chacun d'eux */
        string getPrenomJoueur();
            /* retourne le prenom du joueur (INUTILE ICI, ok pour la version 2
                sans classe Joueur) */

         ///* M�thodes utilitaires du Mod�le
    private :
        UnCoup genererUnCoup();
    /* retourne une valeur al�atoire = pierre, papier ou ciseau.
       Utilis�e pour faire jouer la machine */

        // Setters
    public:
        void setCoupJoueur(UnCoup p_coup);
            /* initialise l'attribut coupJoueur avec la valeur
               du param�tre p_coup */
        void setCoupMachine(UnCoup p_coup);
             /* initialise l'attribut coupmachine avec la valeur
               du param�tre p_coup */
        void setScoreJoueur(unsigned int p_score);
            /* initialise l'attribut scoreJoueur avec la valeur
               du param�tre p_score */
        void setScoreMachine(unsigned int p_score);
             /* initialise l'attribut coupMachine avec la valeur
               du param�tre p_score */
        void majScores(char p_gagnant);
            /* met � jour le score du joueur ou de la machine ou aucun
               en fonction des r�gles de gestion du jeu*/
        void initScores();
            /* initialise � 0 les attributs scoreJoueur et scoreMachine
               NON indispensable */
        void initCoups();
            /* initialise � rien les attributs coupJoueur et coupMachine
               NON indispensable */
        void setPrenomJoueur(string nom);
            /* initialise le pr�nom du joueur
               MODIFI� si classe Joueur */


         ///* Attributs du Mod�le
     private:
        unsigned int scoreJoueur;   // score actuel du joueur
        unsigned int scoreMachine;  // score actuel de la Machine
        UnCoup coupJoueur;          // dernier coup jou� par le joueur
        UnCoup coupMachine;         // dernier coup jou� par la machine
        string prenomJoueur;        // pr�nom du joueur. INUTILE ICI, ok pour version 2
                                    // devient POINTEUR sur joueur si classe Joueur
};

#endif // CHIFOUMI_H
