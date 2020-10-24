#ifndef ADDITIONNEUR_H
#define ADDITIONNEUR_H
#include <iostream>
#include "principale6.h"
using namespace std;

class Principale;



class Additionneur
{
    ///* Partie 'métier'
    public:

        Additionneur(); // Constructeur
        virtual ~Additionneur(); // Destructeur

        int getOpG(); // retourne l'opérande gauche de l'opération opG + opD
        int getOpD(); // retourne l'opérande droit de l'opération opG + opD
        void setOpG(int p_op); // définit l'opérande gauche de l'opération opG + opD
        void setOpD(int p_op);  // définit l'opérande droit de l'opération opG + opD

        int getSomme(); // retourne le résultat de l'opération p_opG+p_opD

        enum UnEtat {saisiesEnCours, erreur}; // Valeurs possibles pour l'état du système

    protected:
        ///* attributs métier
        int opG; // opérande Gauche de l'opération opG + opD
        int opD; // opérande Droit de l'opération opG + opD

    ///* Partie liée au Contrôleur
    public :
        ///* Méthodes
        // Pour gérer la logique de fonctionnement du système
        UnEtat getEtat(); // Retourne l'état du système
        void setEtat(UnEtat p_etat); // Permet de définir l'état du système
        void initisalisationControleur(); // met à jour tous les attributs du contrôleur au démarrage du programme
        //(en l'occurence, l'état).

        // Pour gérer les liens entre le Contrôleur et la Vue selon le pattern Stratégie
        void demandeAddition(string p_opG, string p_opD);
        /* Traite la demande d'addition pour les paramètres p_opG et p_opD textuels.
           Le type string des paramètres a été préféré pour son côté *universel*
           Ce que fait le contrôleur :
               - si les paramètres p_opG et p_opD correspondent à des entiers,
               calcule la somme, fait éventellement changer le système d'état et ordonne à la vue de se mettre à jour
               - sinon, fait changer le système d'état et ordonne à la vue de se mettre à jour
        */
        void accepteNotification(); // traite l'acceptation par l'utilisateur du message de notification d'erreur
        void demandeEffacement(); // traite la demande d'effacement faite par l'utilisateur


        /* Pour gérer le lien entre le Modèle(Sujet) et la Vue(Observateur) */
        /*  selon le pattern Observateur :
           La vue s'enregistre auprès du Modèle.
           Le modèle va notifier la vue de ses changements.
        */
        Principale* getVue();   // retourne la vue liée au controlleur
        void setVue(Principale* p_vue); // Permet de lier (enregistrer) la vue au controleur
        void notifierVue(UnEtat p_etat); // Ordonne (notifie) à la vue de se metre à jour en fonction de l'état du système


    ///* Attributs liés au contrôleur et à la vue (en tant que Observateur du Sujet=Modèle)
    protected:

        Principale* laVue; //Pour faire référence à la vue
        UnEtat etat;    // pour mémoriser l'état du système
};

#endif // ADDITIONNEUR_H
