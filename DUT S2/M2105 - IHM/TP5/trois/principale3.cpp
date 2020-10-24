#include "principale3.h"

//Peuplement de la table d'evenements
Principale::Principale(const wxString& title) : wxFrame (NULL,
                                                wxID_ANY, // identifiant de l'objet qui sera cr��, par d�faut : wxID_ANY,
                                                title)  // titre de la fen�tre
{

// Creation des textes statiques
Textex = new wxStaticText(this, wxID_ANY, "X = ", wxPoint(10,10));
Textey = new wxStaticText(this, wxID_ANY, "Y = ", wxPoint(10,50));
TexteAdd = new wxStaticText(this, wxID_ANY, "X + Y = ", wxPoint(10,100));
TexteResultat = new wxStaticText(this, wxID_ANY, " ", wxPoint(50,100));

//Creation des formulaires
controlX = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 10));
controlY = new wxTextCtrl (this, wxID_ANY, wxEmptyString, wxPoint (50, 50));

//Creation du bouton
boutonAdd = new wxButton (this, 1, wxT("Addition !"), wxPoint (200,100));
boutonEffacer = new wxButton (this, 2, wxT("Effacer !"), wxPoint (295,100));

//Connection du gestionnaire d'addition au bouton addition
Connect(1, wxEVT_BUTTON, (wxObjectEventFunction)&Principale::onClickAddition);

//Connection du gestionnaire d'effacement au bouton effacer
Connect(2, wxEVT_BUTTON, (wxObjectEventFunction)&Principale::onClickEffacer);

}

void Principale::onClickEffacer(wxCommandEvent& event)
{
    controlX->SetLabel(wxEmptyString); //Effacer saisie X
    controlY->SetLabel(wxEmptyString); //Effacer saisie Y
    TexteResultat->SetLabel(wxEmptyString); //Effacer resultat
}

void Principale::onClickAddition (wxCommandEvent& event)
{
    double valeurX, valeurY; // Variables (nombre) contenant les valeurs saisies par l'utilisateur converties depuis une string
    wxString txtX, txtY, txtRslt; // Variables (string) reprensentant le contenu des champs de texte

    txtX = controlX->GetValue(); // R�cup�ration champ saisie X
    txtY = controlY->GetValue(); // R�cup�ration champ saisie Y

    if (txtX.ToDouble(&valeurX) && txtY.ToDouble(&valeurY)) // Si convertion r�ussie
    {
        txtRslt << valeurX+valeurY; // r�sultat = addition x + y
        TexteResultat->SetLabel(txtRslt); // Affichage r�sultat dans le label
    }

    else // convertion rat�e
    {
        TexteResultat->SetLabel(wxEmptyString); // on efface le r�sultat pr�c�dent
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"), wxT("Calcul impossible")); // On affiche le message d'erreur
    }
}

Principale::~Principale()
{
    //Destructeur
}

