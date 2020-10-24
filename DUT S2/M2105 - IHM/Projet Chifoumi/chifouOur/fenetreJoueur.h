/***************************************************************
 * Name:      fenetreJoueur.H
 * Purpose:   Defines Application Frame
 * Author:    A. Murillo ()
 * Created:   2019-05-28
 * Copyright: A. Murillo ()
 * License:
 **************************************************************/

#ifndef FENETREJOUEUR_H
#define FENETREJOUEUR_H

#include "chifoumiUltraInstinctApp.h"
#include <wx/wx.h>



class Principale;

class fenetreJoueur: public wxFrame
{
public:

    ///* Méthodes et attributs de la fenetre
    fenetreJoueur(wxWindow* parent,wxWindowID id = -1);
    virtual ~fenetreJoueur();

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

    wxTextCtrl* formulaireNom;

    wxStaticText* labelActuel;

    wxStaticText* labelNomJ1;

    wxStaticText* labelNouveau;


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
    Principale* fenetrePrincipale;
};

#endif // FENETREJOUEUR_H

