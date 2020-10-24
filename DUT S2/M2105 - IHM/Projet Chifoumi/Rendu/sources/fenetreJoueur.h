/***************************************************************
 * Name:      fenetreJoueur.H
 * Purpose:   Définition de la fenetre enfant fenetreParametres
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/
 
/***************************************************************

A L'ATTENTION DU CORRECTEUR :

Cette vue n'a pas été crée à l'aide de wxSmith mais manuellement,
il n'y a donc pas de fichier .wxs associé.

 **************************************************************/

#ifndef FENETREJOUEUR_H
#define FENETREJOUEUR_H

#include <wx/wx.h>

class Principale;

class fenetreJoueur: public wxFrame
{
public:

    ///* Méthodes et attributs de la fenetre
    fenetreJoueur(wxWindow* parent,wxWindowID id = -1); //Constructeur
    virtual ~fenetreJoueur(); //Destructeur

private:

    ///*Gestionnaires d'evenements

    void OnClickboutonValider(wxCommandEvent& event);

    void OnClickboutonAnnuler(wxCommandEvent& event);

    ///* Attributs membres

    ///*Identifiants des objets graphiques

    //De la fenêtre
    static const long ID_BOUTONVALIDER;
    static const long ID_BOUTONANNULER;
    static const long ID_FORMULAIRENOM;
    static const long ID_LABELACTUEL;
    static const long ID_LABELNOMJ1;
    static const long ID_LABELNOUVEAU;

    ///*Objets graphiques

    //Objets
    wxButton* boutonValider;

    wxButton* boutonAnnuler;

    wxTextCtrl* formulaireNom; //Formulaire dans lequel saisir le nouveau nom

    wxStaticText* labelActuel; //"Actuel :"

    wxStaticText* labelNomJ1; //Nom actuel du joueur 1

    wxStaticText* labelNouveau; //"Nouveau : "


    //Sizers
    wxBoxSizer* topSizer; // Sizer Vertical

    wxBoxSizer* sizerActuel; //affichage Ancien nom

    wxBoxSizer* sizerNouveau; // Saisie nouveau nom

    wxBoxSizer* sizerBoutons; // Boutons annuler et valider

    wxStaticBoxSizer* sizerPrenom; // Zone de saisie du label


public:

    ///* Méthode pour faire le lien avec la fenetre principale
    void setFenetrePrincipale(Principale*);

private:

    ///*Attribut pour faire le lien avec la fenetre principale
    Principale* fenetrePrincipale; //Pointeur sur fenetre principale
};

#endif // FENETREJOUEUR_H

