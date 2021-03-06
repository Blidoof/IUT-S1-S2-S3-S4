/***************************************************************
 * Name:      fenetreJoueur.cpp
 * Purpose:   Code de la fenetre enfant fenetreParametres
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/
 
/***************************************************************

A L'ATTENTION DU CORRECTEUR :

Cette vue n'a pas �t� cr�e � l'aide de wxSmith mais manuellement,
il n'y a donc pas de fichier .wxs associ�.

 **************************************************************/

#include "fenetreJoueur.h"
#include "Principale.h"
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

//Constructeur de la fen�tre
fenetreJoueur::fenetreJoueur(wxWindow* parent,wxWindowID id)
{
	this->fenetrePrincipale = (Principale*) parent; //On lie la fenetre enfant � la fenetre principale (pass�e en param�tre (parent) lors de l'instanciation de la fenetre enfant)
	
    //Cr�ation de la fen�tre
    Create(parent, wxID_ANY, "Personnaliser joueur", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	
	wxString ancienNom;
	
	ancienNom = this->fenetrePrincipale->getNomJ1(); //On recup�re le nom actuel du joueur 1 qu'on met dans ancienNom pour le passer en param�tres lors de la cr�ation du label labelNomJ1
	
    //Creation des labels
    labelActuel = new wxStaticText(this,ID_LABELACTUEL,"Actuel :",wxPoint(10,100));
    labelNomJ1= new wxStaticText(this,ID_LABELNOMJ1, ancienNom, wxPoint(10,100));
    labelNouveau = new wxStaticText(this,ID_LABELNOUVEAU,"Nouveau :",wxPoint(45,100));

    //Creation du formulaire
    formulaireNom = new wxTextCtrl(this,ID_FORMULAIRENOM,wxEmptyString, wxPoint (50, 10));

    //Cr�ation des boutons
    boutonValider = new wxButton(this,ID_BOUTONVALIDER, wxT("Valider"),wxPoint (295,100));
    boutonAnnuler = new wxButton(this,ID_BOUTONANNULER, wxT("Annuler"),wxPoint (295,100));

    //Connection des boutons aux gestionnaires d'evenements
    Connect(ID_BOUTONVALIDER,wxEVT_BUTTON,(wxObjectEventFunction)&fenetreJoueur::OnClickboutonValider);
    Connect(ID_BOUTONANNULER,wxEVT_BUTTON,(wxObjectEventFunction)&fenetreJoueur::OnClickboutonAnnuler);


    //Mise en place des sizers

    //Sizer actuel
    sizerActuel = new wxBoxSizer (wxHORIZONTAL);
    sizerActuel->Add(labelActuel, 0, wxALIGN_LEFT);
    sizerActuel->Add(labelNomJ1, 0, wxALIGN_RIGHT|wxLEFT, 23);

    //Sizer Nouveau
    sizerNouveau = new wxBoxSizer (wxHORIZONTAL);
    sizerNouveau->Add(labelNouveau, 0, wxALIGN_LEFT|wxALL, 5);
    sizerNouveau->Add(formulaireNom, 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 5);

    //SizerPrenom
    sizerPrenom = new wxStaticBoxSizer (wxVERTICAL, this, wxT("Prenom"));
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


    //Param�trage topSizer
    SetSizer(topSizer); // D�finition du sizer principal
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
    wxString nouveauNom = this->formulaireNom->GetValue(); // On r�cup�re la valeur �crite (pas de contr�le de la valeur pour ne recuperer que des caract�res)

    this->fenetrePrincipale->setNomJ1(nouveauNom); //On modifiue dans la fentre principale

    this->labelNomJ1->SetLabel(nouveauNom); //On modifie dans la fenetre modale
}

void fenetreJoueur::OnClickboutonAnnuler(wxCommandEvent& event)
{
    Destroy(); //On ferme la fen�tre
}

void fenetreJoueur::setFenetrePrincipale(Principale* princp)
{
    this->fenetrePrincipale = princp;
}
