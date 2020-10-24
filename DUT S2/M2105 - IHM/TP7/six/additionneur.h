#ifndef ADDITIONNEUR_H
#define ADDITIONNEUR_H
#include <iostream>
#include "principale6.h"
using namespace std;

class Principale;



class Additionneur
{
    ///* Partie 'm�tier'
    public:

        Additionneur(); // Constructeur
        virtual ~Additionneur(); // Destructeur

        int getOpG(); // retourne l'op�rande gauche de l'op�ration opG + opD
        int getOpD(); // retourne l'op�rande droit de l'op�ration opG + opD
        void setOpG(int p_op); // d�finit l'op�rande gauche de l'op�ration opG + opD
        void setOpD(int p_op);  // d�finit l'op�rande droit de l'op�ration opG + opD

        int getSomme(); // retourne le r�sultat de l'op�ration p_opG+p_opD

        enum UnEtat {saisiesEnCours, erreur}; // Valeurs possibles pour l'�tat du syst�me

    protected:
        ///* attributs m�tier
        int opG; // op�rande Gauche de l'op�ration opG + opD
        int opD; // op�rande Droit de l'op�ration opG + opD

    ///* Partie li�e au Contr�leur
    public :
        ///* M�thodes
        // Pour g�rer la logique de fonctionnement du syst�me
        UnEtat getEtat(); // Retourne l'�tat du syst�me
        void setEtat(UnEtat p_etat); // Permet de d�finir l'�tat du syst�me
        void initisalisationControleur(); // met � jour tous les attributs du contr�leur au d�marrage du programme
        //(en l'occurence, l'�tat).

        // Pour g�rer les liens entre le Contr�leur et la Vue selon le pattern Strat�gie
        void demandeAddition(string p_opG, string p_opD);
        /* Traite la demande d'addition pour les param�tres p_opG et p_opD textuels.
           Le type string des param�tres a �t� pr�f�r� pour son c�t� *universel*
           Ce que fait le contr�leur :
               - si les param�tres p_opG et p_opD correspondent � des entiers,
               calcule la somme, fait �ventellement changer le syst�me d'�tat et ordonne � la vue de se mettre � jour
               - sinon, fait changer le syst�me d'�tat et ordonne � la vue de se mettre � jour
        */
        void accepteNotification(); // traite l'acceptation par l'utilisateur du message de notification d'erreur
        void demandeEffacement(); // traite la demande d'effacement faite par l'utilisateur


        /* Pour g�rer le lien entre le Mod�le(Sujet) et la Vue(Observateur) */
        /*  selon le pattern Observateur :
           La vue s'enregistre aupr�s du Mod�le.
           Le mod�le va notifier la vue de ses changements.
        */
        Principale* getVue();   // retourne la vue li�e au controlleur
        void setVue(Principale* p_vue); // Permet de lier (enregistrer) la vue au controleur
        void notifierVue(UnEtat p_etat); // Ordonne (notifie) � la vue de se metre � jour en fonction de l'�tat du syst�me


    ///* Attributs li�s au contr�leur et � la vue (en tant que Observateur du Sujet=Mod�le)
    protected:

        Principale* laVue; //Pour faire r�f�rence � la vue
        UnEtat etat;    // pour m�moriser l'�tat du syst�me
};

#endif // ADDITIONNEUR_H
