#ifndef PRINCIPALE_H
#define PRINCIPALE_H
#include "principale6.h"
#include "additionneur.h"

#include <wx/wx.h>

class Additionneur;

class Principale : public wxFrame
{
    ///* Méthodes et attributs 'classiques' de la Vue
    public:
        // Le constructeur
        Principale(const wxString& title);

        // Le destructeur
        virtual ~Principale();

    private:

        ///* Gestionnaires d'événements
        void onClickAddition (wxCommandEvent& event); // Notifie le Contôleur que l'utilisateur a demandé le calcul

        void onClickEffacer (wxCommandEvent& event); // Notifie le Contrôleur que l'utilisateur a demandé l'effacement

        ///* Attributs membres

        // Attributs utilisés dans les méthodes OnClicBtonAddition et OnClicBtonEffacer
        wxTextCtrl * controlX; // Formulaire de saisie de la variable X
        wxTextCtrl * controlY; // Formulaire de saisie de la variable Y
        wxStaticText *TexteResultat; // Texte statique affichant le résultat

        // les autres
        wxStaticText * Textex; // pour demander saisie de la variable X
        wxStaticText * Textey; // pour demander saisie de la variable Y
        wxStaticText * TexteAdd; // Pour préciser là ou sera affiché le résultat del'addition X+Y
        wxButton * boutonAdd; // Bouton pour déclencher l'addition
        wxButton * boutonEffacer; // Bouton pour vider les formulaires et effacer le résultat de l'addition

        // les sizers
        wxBoxSizer *ligneX; // Sizer de la ligne textex + controlX
        wxBoxSizer *ligneY; // Sizer de la ligne textey + controlY
        wxBoxSizer *ligneResultat; // Sizer de la ligne X+Y= et résultat
        wxBoxSizer *ligneBoutons; // Sizer de la ligne bouton addition + effacer
        wxBoxSizer *colonneObjets; // Sizer pour aligner verticalement ligneX + ligneY + ligneResultat + ligneBoutons

        //Identifiants des objets de la fenêtre
        const long ID_BOUTON_ADD = wxNewId();       // identifiant du bouton bouton Addition
        const long ID_BOUTON_EFFACER = wxNewId();   // identifiant du bouton bouton Effacer



    public:

        // Méthodes de mise à jour de la Vue

        void effacerZonesSaisie(); // efface le contenu des 2 champs de saisie
        void afficherResultat(int p_res); // afficher l'entier dans la zone label_res
        void afficherEtatErreur(); // affiche la vue de l'application lorsqu'elle est en état d'erreur


    public:

        // Méthodes pour faire le lien avec le Contrôleur

        Additionneur* getAdditionneur();
        void setAdditionneur (Additionneur* p_add);

    private:

        // Attribut pour faire le lien avec le Contrôleur

        Additionneur* additionneur;
};
#endif // PRINCIPALE_H
