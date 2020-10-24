#include "principale2.h"

//Peuplement de la table d'evenements
BEGIN_EVENT_TABLE(Principale, wxFrame)
    EVT_CLOSE( Principale::siQuitter)
END_EVENT_TABLE()

Principale::Principale(const wxString& title) : wxFrame (NULL,
                                                wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                title)  // titre de la fenêtre
{

// Creation des textes statiques
wxStaticText * Textex = new wxStaticText(this, wxID_ANY, "X = ", wxPoint(10,10));
wxStaticText * Textey = new wxStaticText(this, wxID_ANY, "Y = ", wxPoint(10,50));
wxStaticText * TexteAdd = new wxStaticText(this, wxID_ANY, "X + Y = ", wxPoint(10,100));

//Creation des formulaires
wxTextCtrl * controlX = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 10));
wxTextCtrl * controlY = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 50));

//Creation du bouton
wxButton * boutonAdd = new wxButton (this, wxID_ANY, wxT("Addition !"), wxPoint (200,100));

//Boite de dialogue au démarrage
wxMessageBox( wxT("Le site est toujours en construction"), wxT("Bienvenue"));
}

//Boite de dialogue
void Principale::siQuitter(wxCloseEvent& event)
    {
        int answer = wxMessageBox( wxT("Etes vous sur de vouloir quitter ?"), wxT("Confirmation de fermerture"), wxYES_NO);

        if (answer == wxYES)
        {
            Destroy();
        }
    }


Principale::~Principale()
{
    //Destructeur
}

