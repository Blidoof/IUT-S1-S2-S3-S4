/***************************************************************
 * Name:      fenetreJoueur.cpp
 * Purpose:   Code for Application Frame
 * Author:    A. Murillo ()
 * Created:   2019-05-28
 * Copyright: A. Murillo ()
 * License:
 **************************************************************/

#include "fenetreJoueur.h"
#include "chifoumiUltraInstinctMain.h"
#include <wx/msgdlg.h>

//Headers internes
#include <wx/intl.h>
#include <wx/string.h>



//Initialisation des identifiants des objets graphiques
const long fenetreJoueur::ID_BOUTONVALIDER = wxNewId();
const long fenetreJoueur::ID_BOUTONANNULER = wxNewId();
const long fenetreJoueur::ID_FORMULAIRENOM = wxNewId();
const long fenetreJoueur::ID_LABELACTUEL = wxNewId();
const long fenetreJoueur::ID_LABELNOMJ1 = wxNewId();
const long fenetreJoueur::ID_LABELNOUVEAU = wxNewId();

//Constructeur de la fenêtre
fenetreJoueur::fenetreJoueur(wxWindow* parent,wxWindowID id)
{
    //On lie la fenêtre enfant à la fenêtre parent
    this->fenetrePrincipale = (Principale*) parent;

    //Création de la fenêtre
    Create(parent, wxID_ANY, "Personnaliser Patrie", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));

    this->SetBackgroundColour(wxColor( * wxRED));

    //On prepare une variable qui contient le nom actuel du joueur 1 et utilisée dans définition du labelNomJ1
    wxString ancienNomJ1 = this->fenetrePrincipale->getNomJ1();

    //Creation des labels
    labelActuel = new wxStaticText(this,ID_LABELACTUEL,"Actuelle :",wxPoint(10,100));
    labelNomJ1= new wxStaticText(this,ID_LABELNOMJ1, ancienNomJ1,wxPoint(10,100));
    labelNouveau = new wxStaticText(this,ID_LABELNOUVEAU,"Nouvelle :",wxPoint(45,100));

    //Creation du formulaire
    formulaireNom = new wxTextCtrl(this,ID_FORMULAIRENOM,wxEmptyString, wxPoint (50, 10));

    //Création des boutons
    boutonValider = new wxButton(this,ID_BOUTONVALIDER, wxT("Valider"),wxPoint (295,100));
    boutonAnnuler = new wxButton(this,ID_BOUTONANNULER, wxT("Annuler"),wxPoint (295,100));

    //Connection des boutons aux gestionnaires d'evenements
    Connect(ID_BOUTONVALIDER,wxEVT_BUTTON,(wxObjectEventFunction)&fenetreJoueur::OnClickboutonValider);
    Connect(ID_BOUTONANNULER,wxEVT_BUTTON,(wxObjectEventFunction)&fenetreJoueur::OnClickboutonAnnuler);

    //Mise en place des sizers

    //Sizer actuel
    sizerActuel = new wxBoxSizer (wxHORIZONTAL);
    sizerActuel->Add(labelActuel, 0, wxALIGN_LEFT);
    sizerActuel->Add(labelNomJ1, 0, wxALIGN_RIGHT|wxLEFT, 15);

    //Sizer Nouveau
    sizerNouveau = new wxBoxSizer (wxHORIZONTAL);
    sizerNouveau->Add(labelNouveau, 0, wxALIGN_LEFT|wxALL, 5);
    sizerNouveau->Add(formulaireNom, 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 5);

    //SizerPrenom
    sizerPrenom = new wxStaticBoxSizer (wxVERTICAL, this, wxT("Personnaliser Patrie :"));
    sizerPrenom->Add(sizerActuel,0, wxALIGN_LEFT|wxLEFT, 10);
    sizerPrenom->Add(sizerNouveau,0, wxALIGN_LEFT|wxALL|wxEXPAND, 5);

    //SizerBoutons
    sizerBoutons = new wxBoxSizer (wxHORIZONTAL);
    sizerBoutons->Add(boutonAnnuler,0, wxRIGHT, 5);
    sizerBoutons->Add(boutonValider,0,wxLEFT, 5);

    //TopSizer
    topSizer = new wxBoxSizer (wxVERTICAL);
    topSizer->Add(sizerPrenom, 0 , wxALIGN_CENTER|wxALL, 10);
    topSizer->Add(sizerBoutons,0,wxALIGN_RIGHT|wxALL, 10);


    //Paramètrage topSizer
    SetSizer(topSizer); // Définition du sizer principal
    topSizer->Fit(this); // Adaptation au sizer
    topSizer->SetSizeHints(this);
    this->SetMaxSize(this->GetBestFittingSize()); //Pas de modification de la taille

}

fenetreJoueur::~fenetreJoueur()
{
    //Destructeur
}

void fenetreJoueur::OnClickboutonValider(wxCommandEvent& event)
{
    wxString nouveauNom = this->formulaireNom->GetValue(); // On récupère la valeur écrite (pas de contrôle de la valeur pour ne recuperer que des caractères)

    this->fenetrePrincipale->setNomJ1(nouveauNom); //On modifiue dans la fentre principale


    this->labelNomJ1->SetLabel(nouveauNom); //On modifie dans la fenetre modale


}

void fenetreJoueur::OnClickboutonAnnuler(wxCommandEvent& event)
{

    Destroy(); //On ferme la fenêtre
}

void fenetreJoueur::setFenetrePrincipale(Principale* princp)
{
    this->fenetrePrincipale = princp;
}
