/***************************************************************
 * Name:      chifoumiUltraInstinctMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carduino ()
 * Created:   2019-05-28
 * Copyright: Carduino ()
 * License:
 **************************************************************/

#ifndef CHIFOUMIULTRAINSTINCTMAIN_H
#define CHIFOUMIULTRAINSTINCTMAIN_H

#include "jeu.h"

//(*Headers(Principale)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

#include <wx/wx.h>

class Jeu;

class Principale: public wxFrame
{
public:

    ///* Méthodes et attributs de la vue
    Principale(wxWindow* parent,wxWindowID id = -1);
    virtual ~Principale();

private:

    ///*Gestionnaires d'evenements

    //(*Handlers(Principale)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnButton1Click1(wxCommandEvent& event);
    void OnClickboutonNouvellePartie(wxCommandEvent& event);
    void OnClickboutonCiseaux(wxCommandEvent& event);
    void OnClickboutonPapier(wxCommandEvent& event);
    void OnClickboutonPierre(wxCommandEvent& event);
    //*)

    ///* Attributs membres

    ///*Identifiants
    //(*Identifiers(Principale)
    static const long ID_LABELJ1;
    static const long ID_LABELJ2;
    static const long ID_SCOREJ1;
    static const long ID_SCOREJ2;
    static const long ID_BOUTONCISEAUX;
    static const long ID_IDSIGNE2;
    static const long ID_SIGNEJ1;
    static const long ID_LOGOVERSUS;
    static const long ID_BOUTONFEUILLE;
    static const long ID_BOUTONPIERRE;
    static const long ID_BUTTONNOUVELLEPARTIE;
    //*)

    ///*Objets graphiques

    //Objets
    //(*Declarations(Principale)
    wxBitmapButton* boutonCiseaux;
    wxBitmapButton* boutonPapier;
    wxBitmapButton* boutonPierre;
    wxButton* boutonNouvellePartie;
    wxStaticBitmap* imageVersus;
    wxStaticBitmap* signeJ1;
    wxStaticBitmap* signeJ2;
    wxStaticText* labelJ1;
    wxStaticText* labelJ2;
    wxStaticText* scoreJ1;
    wxStaticText* scoreJ2;
    //*)

    //Sizers

    wxBoxSizer* topSizer; //Sizer vertical (tout les autrez sizers)

    wxBoxSizer* sizerJ1; // Label J1, scoreJ1, signeJ1

    wxBoxSizer* sizerJ2; // Label J2, scoreJ2, signeJ2

    wxBoxSizer* sizerAffichage; //SizerJ1, sizerJ2, image Versus

    wxStaticBoxSizer* sizerSignes; // Boutons pierre, feuille, ciseau



public:

    ///*Méthodes de mises à jour de la vue

    void afficherScores(); //Affiche le score actuel de chaque joueur

    void effacerScores(); //Remet les cores à 0 pour chaque joueur

    void MajSignes(); //Affiche le dernier signe joué par les joueurs

    void effacerSignes(); //Efface le dernier signe joué par chaque joueur lors du démarrage d'une nouvelle partie


    ///*Méthodes pour faire le lien avec le controleur

    Jeu* getJeu(); //Renvoie le controleur utilisé
    void setJeu(Jeu*); //Définit le controleur

private:

    ///*Pour faire le lien avec le controleur
    Jeu* jeu;

    DECLARE_EVENT_TABLE()
};

#endif // CHIFOUMIULTRAINSTINCTMAIN_H
