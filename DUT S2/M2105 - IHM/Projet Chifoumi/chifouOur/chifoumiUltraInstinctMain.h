/***************************************************************
 * Name:      chifoumiUltraInstinctMain.h
 * Purpose:   Defines Application Frame
 * Author:    A. Murillo ()
 * Created:   2019-05-28
 * Copyright: A. Murillo ()
 * License:
 **************************************************************/

#ifndef CHIFOUMIULTRAINSTINCTMAIN_H
#define CHIFOUMIULTRAINSTINCTMAIN_H

#include "jeu.h"
#include "fenetreJoueur.h"
#include <wx/wx.h>

//Gestion du son
#include <iostream>
#include <windows.h>
#include <MMsystem.h>


class Jeu; // Pour referencer la classe

class fenetreJoueur; // Pour referencer la classe

class Principale: public wxFrame
{
public:

    ///* M�thodes et attributs de la vue

    Principale(wxWindow* parent,wxWindowID id = -1);
    virtual ~Principale();

private:

    ///*Gestionnaires d'evenements

    //Barre de menu
    void OnQuitter(wxCommandEvent& event); // Si clic sur sur quitter dans barre menu
    void OnAide(wxCommandEvent& event); //Si clic sur aide dans barre menu
    void OnParametre(wxCommandEvent& event);//Si clic sur param�trage dans barre menu

    //Boutons
    void OnClickboutonNouvellePartie(wxCommandEvent& event);

    void OnClickboutonCiseaux(wxCommandEvent& event);

    void OnClickboutonPapier(wxCommandEvent& event);

    void OnClickboutonPierre(wxCommandEvent& event);

    void OnClickboutonAmi(wxCommandEvent& event);



    ///* Attributs membres#include <wx/sound.h>

    ///*Identifiants des objets graphiques

    //De la fen�tre
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
    static const long ID_BUTTONAMI;


    //Du menu
    static const long IDMENUQUIT;
    static const long IDMENUABOUT;
    static const long IDMENUPARAM;


    ///*Objets graphiques

    //Objets
    wxBitmapButton* boutonCiseaux;

    wxBitmapButton* boutonPapier;

    wxBitmapButton* boutonPierre;

    wxButton* boutonNouvellePartie;

    wxButton* boutonAppelAmi;

    wxStaticBitmap* imageVersus;

    wxStaticBitmap* signeJ1;

    wxStaticBitmap* signeJ2;

    wxStaticText* labelJ1;

    wxStaticText* labelJ2;

    wxStaticText* scoreJ1;

    wxStaticText* scoreJ2;

    //Menu
    wxMenuBar* TopMenu;

    //Sizers
    wxBoxSizer* topSizer; //Sizer vertical (tout les autrez sizers)

    wxBoxSizer* sizerJ1; // Label J1, scoreJ1, signeJ1

    wxBoxSizer* sizerJ2; // Label J2, scoreJ2, signeJ2

    wxBoxSizer* sizerAffichage; //SizerJ1, sizerJ2, image Versus

    wxStaticBoxSizer* sizerSignes; // Boutons pierre, feuille, ciseau

    wxBoxSizer* boutons;
    ///*Nom du joueur 1 que l'on pourra modifier dans la fenetre param�tres

    wxString nomJ1;


public:

    ///*M�thodes de mises � jour de la vue

    void afficherScores(); //Affiche le score actuel de chaque joueur

    void effacerScores(); //Remet les cores � 0 pour chaque joueur

    void MajSignes(); //Affiche le dernier signe jou� par les joueurs

    void effacerSignes(); //Efface le dernier signe jou� par chaque joueur lors du d�marrage d'une nouvelle partie


    ///*M�thodes pour faire le lien avec le controleur

    Jeu* getJeu(); //Renvoie le controleur utilis�
    void setJeu(Jeu*); //D�finit le controleur

    ///*M�thode utilis�es par la fen�tre param�tres

    void setNomJ1 (wxString nom); //D�finit le nom  du joueur 1
    wxString getNomJ1(); // renvoie le nom du joueur 1

    ///*M�thodes pour faire le lien avec la fenetre enfant

    fenetreJoueur* getFenetreEnfant(); //Renvoie le controleur utilis�
    void setFenetreEnfant(fenetreJoueur*); //D�finit le controleur


private:

    ///*Pour faire le lien avec le controleur
    Jeu* jeu;

    ///*Pour faire le lien avec la fen�tre enfant
    fenetreJoueur* parametres;



};

#endif // CHIFOUMIULTRAINSTINCTMAIN_H
