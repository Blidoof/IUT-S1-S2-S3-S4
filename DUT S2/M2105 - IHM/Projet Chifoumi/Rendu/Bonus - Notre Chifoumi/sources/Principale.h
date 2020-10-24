/***************************************************************
 * Name:      Principale.h
 * Purpose:   D�finit la fenetre principale
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/

#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include "jeu.h"
#include "fenetreJoueur.h"
#include <wx/wx.h>

class Jeu; // Pour referencer la classe

class fenetreJoueur; // Pour referencer la classe

class Principale: public wxFrame
{
public:

    ///* M�thodes et attributs de la vue

    Principale(wxWindow* parent,wxWindowID id = -1); //Constructeur
    virtual ~Principale(); //Destructeur

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


    ///* Attributs membres

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

    wxButton* boutonAppelAmi;

    wxButton* boutonNouvellePartie;

    wxStaticBitmap* imageVersus;

    wxStaticBitmap* signeJ1; //Signe jou� par j1

    wxStaticBitmap* signeJ2; //Signe jou� par j2

    wxStaticText* labelJ1; //Nom du j1

    wxStaticText* labelJ2; //Nom du j2

    wxStaticText* scoreJ1;

    wxStaticText* scoreJ2;

    //Barre de menu
    wxMenuBar* TopMenu;

    //Sizers
    wxBoxSizer* topSizer; //Sizer vertical (tout les autres sizers)

    wxBoxSizer* sizerJ1; // Label J1, scoreJ1, signeJ1

    wxBoxSizer* sizerJ2; // Label J2, scoreJ2, signeJ2

    wxBoxSizer* sizerAffichage; //SizerJ1, sizerJ2, image Versus

    wxBoxSizer* boutons; //BoutonAmi, boutonNouvellePartie

    wxStaticBoxSizer* sizerSignes; // Boutons pierre, feuille, ciseau

    ///*Nom du joueur 1 que l'on pourra modifier dans la fenetre param�tres

    wxString nomJ1;


public:

    ///*M�thodes de mises � jour de la vue

    void afficherScores(); //Affiche le score actuel de chaque joueur

    void effacerScores(); //Remet les cores � 0 pour chaque joueur

    void MajSignes(); //Affiche le dernier signe jou� par les joueurs

    void effacerSignes(); //Efface le dernier signe jou� par chaque joueur lors du d�marrage d'une nouvelle partie

	void changerEtatBouton(bool activation); //Determine en fonction du bool�en pass� en param�tre l'activation/desactivation du bouton NouvellePartie

	void ouvrirFenetreParametres(); //Lance les actions necessaires � l'ouverture de la fenetre param�tre puis l'ouvre

    void afficherInfos(); // Affiche un message pr�sentant le programme et ses auteurs

    ///*M�thodes pour faire le lien avec le controleur

    Jeu* getJeu(); //Renvoie le controleur utilis�
    void setJeu(Jeu*); //D�finit le controleur

    ///*M�thode utilis�es par la fen�tre param�tres

    void setNomJ1 (wxString nom); //D�finit le nom  du joueur 1
    wxString getNomJ1(); // renvoie le nom du joueur 1

private:

    ///*Pour faire le lien avec le controleur
    Jeu* jeu; //Pointeur sur le controleur

    ///*Pour faire le lien avec la fen�tre enfant
    fenetreJoueur* parametres; //Pointeur sur fenetre enfant

};

#endif // PRINCIPALE_H
