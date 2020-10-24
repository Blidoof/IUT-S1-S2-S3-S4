#include "principale6.h"

Principale::Principale(const wxString& title) : wxFrame (NULL, //Parent
                                                wxID_ANY, // identifiant de l'objet qui sera cr��, par d�faut : wxID_ANY
                                                title)  // titre de la fen�tre
{



// D�finir l'additionneur
additionneur = new Additionneur();
this->additionneur->setVue(this); //Permet au controleur de se lier � la vue


// Creation des textes statiques

Textex = new wxStaticText(this, //Frame dans lequel cr�er
                          wxID_ANY, // Identifiant
                          "X = ", // Contenu
                          wxPoint(10,10)); // Placement

Textey = new wxStaticText(this,
                          wxID_ANY,
                          "Y = ",
                          wxPoint(10,50));

TexteAdd = new wxStaticText(this,
                             wxID_ANY,
                             "X + Y = ",
                             wxPoint(10,100));

TexteResultat = new wxStaticText(this,
                                 wxID_ANY,
                                 " ",
                                 wxPoint(50,100));

//Creation des formulaires

controlX = new wxTextCtrl (this,
                           wxID_ANY,
                           wxEmptyString,
                           wxPoint (50, 10));

controlY = new wxTextCtrl (this,
                           wxID_ANY,
                           wxEmptyString,
                           wxPoint (50, 50));

//Creation du bouton

boutonAdd = new wxButton (this,
                          ID_BOUTON_ADD,
                          wxT("Addition !"),
                          wxPoint (200,100));

boutonEffacer = new wxButton (this,
                              ID_BOUTON_EFFACER,
                              wxT("Effacer !"),
                               wxPoint (295,100));

//Connection du gestionnaire d'addition au bouton addition
Connect(ID_BOUTON_ADD, wxEVT_BUTTON, (wxObjectEventFunction)&Principale::onClickAddition);

//Connection du gestionnaire d'effacement au bouton effacer
Connect(ID_BOUTON_EFFACER, wxEVT_BUTTON, (wxObjectEventFunction)&Principale::onClickEffacer);


//Mise en place des sizers

    //Ligne de saisieX
    ligneX = new wxBoxSizer (wxHORIZONTAL); //Cr�ation du sizer
    ligneX->Add(Textex, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL); // Ajout texteX
    ligneX->Add(controlX, 1, wxEXPAND); // Ajout formulaire X

    //Ligne de saisieY
    ligneY = new wxBoxSizer (wxHORIZONTAL);
    ligneY->Add(Textey, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL);
    ligneY->Add(controlY, 1, wxEXPAND);

    //Ligne du r�sultat
    ligneResultat = new wxBoxSizer (wxHORIZONTAL);
    ligneResultat->Add(TexteAdd, 0, wxALL);
    ligneResultat->Add(TexteResultat, 0, wxALL);

    //Ligne des boutons
    ligneBoutons = new wxBoxSizer(wxHORIZONTAL);
    ligneBoutons->Add(boutonAdd, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 /*Bordure de 5 pour chaaque bouton pour qu'ils ne soient pas coll�s*/);
    ligneBoutons->Add(boutonEffacer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5);

    //Colonne des objets
    colonneObjets = new wxBoxSizer(wxVERTICAL);
    colonneObjets->Add(ligneX, 0, wxEXPAND|wxALL, 10); // bordure de 10 autour de la ligne de saisie de X avec expension horizontale possible
    colonneObjets->Add(ligneY, 0,wxEXPAND|wxALL, 10); // bordure de 10 autour de la ligne de saisie de Y avec expension horizontale possible
    colonneObjets->Add(ligneResultat, 0, wxALL, 10);  // bordure de 10 autour de la ligne d'affichage du resultat (placement fixe)
    colonneObjets->Add(ligneBoutons,0, wxALIGN_RIGHT|wxALL, 10); // bordure de 10 autour de la ligne des 2 boutons avec deplacement � droite possible si expension de la fen�tre

    // Param�trage de la colonne des objets
    SetSizer(colonneObjets); // D�finition du sizer principal
    //colonneObjets->Fit(this); // Adaptation au sizer
    colonneObjets->SetSizeHints(this);

}

Principale::~Principale()
{
    //Destructeur
}

void Principale::onClickEffacer(wxCommandEvent& event)
{
    this->additionneur->demandeEffacement(); // Demande d'effacement au controleur
}

void Principale::onClickAddition (wxCommandEvent& event)
{
    string x,y; // On cr�e deux variables pour le transtypage des valeurs recues depuis les formulaires
    x = (string) this->controlX->GetValue();
    y = (string) this->controlY->GetValue();

    this->additionneur->demandeAddition(x,y);  // Demande d'addition au controleur
}

void Principale::effacerZonesSaisie()
{
    this->controlX->SetLabel(wxEmptyString); //effacer formulaire X
    this->controlY->SetLabel(wxEmptyString); //effacer formulaire Y
    this->TexteResultat->SetLabel(wxEmptyString); //effacer formulaire X+Y
}

void Principale::afficherResultat(int p_res)
{
    wxString resultat; // On cr�e une wxString qui recevra le r�sultat pour pouvoir l'afficher
    resultat << p_res;
    this->TexteResultat->SetLabel(resultat);
}

void Principale::afficherEtatErreur()
{
    this->TexteResultat->SetLabel(wxEmptyString); // Effacer le resultat pr�c�dent
    wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"), wxT("Calcul impossible")); // On affiche le message d'erreur
    this->additionneur->accepteNotification();
}

Additionneur* Principale::getAdditionneur()
{
    return this->additionneur; //Retourner l'additionneur utilis�
}

void Principale::setAdditionneur (Additionneur* p_add)
{
    this->additionneur = p_add; // D�finir l'additionneur utilis� (utilis� dans additionneur.cpp)
}
