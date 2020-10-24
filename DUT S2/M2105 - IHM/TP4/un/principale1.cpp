#include "principale1.h"

Principale::Principale(const wxString& title) : wxFrame (NULL,
                                                wxID_ANY, // identifiant de l'objet qui sera cr��, par d�faut : wxID_ANY,
                                                title)  // titre de la fen�tre
{
//En utilisant la m�thode du full constructor
/*
    // Creation des textes statiques
    wxStaticText * Textex = new wxStaticText(this, wxID_ANY, "X = ", wxPoint(10,10));
    wxStaticText * Textey = new wxStaticText(this, wxID_ANY, "Y = ", wxPoint(10,50));
    wxStaticText * TexteAdd = new wxStaticText(this, wxID_ANY, "X + Y = ", wxPoint(10,100));

    //Creation des formulaires
    wxTextCtrl * controlX = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 10));
    wxTextCtrl * controlY = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 50));

    //Creation du bouton
    wxButton * boutonAdd = new wxButton (this, wxID_ANY, wxT("Addition !"), wxPoint (200,100));

    //Boite de dialogue au d�marrage
    wxMessageBox( wxT("Le site est toujours en construction"), wxT("Bienvenue"));
*/

//En utilisant le constructeur par d�faut + m�thode Create

    // Creation des textes statiques
    wxStaticText * Textex = new wxStaticText;
    Textex -> Create (this, wxID_ANY, "X = ", wxPoint(10,10));

    wxStaticText * Textey = new wxStaticText;
    Textey -> Create (this, wxID_ANY, "Y = ", wxPoint(10,50));

    wxStaticText * TexteAdd = new wxStaticText;
    TexteAdd -> Create (this, wxID_ANY, "X + Y = ", wxPoint(10,100));

    //Creation des formulaires
    wxTextCtrl * controlX = new wxTextCtrl;
    controlX -> Create (this, wxID_ANY, wxEmptyString, wxPoint (50, 10));

    wxTextCtrl * controlY = new wxTextCtrl;
    controlY -> Create (this, wxID_ANY, wxEmptyString, wxPoint (50, 50));

    //Creation du bouton
    wxButton * boutonAdd = new wxButton;
    boutonAdd -> Create (this, wxID_ANY, wxT("Addition !"), wxPoint (200,100));

    //Boite de dialogue au d�marrage
    wxMessageBox( wxT("Le site est toujours en construction"), wxT("Bienvenue"));

}
    // Le destructeur
Principale::~Principale()
{
    // Destructeur
}
