#include "principale5.h"

BEGIN_EVENT_TABLE(Principale, wxFrame)
    EVT_CLOSE(Principale::onClose) // En cas d'evenement de fermeture de la fenetre
END_EVENT_TABLE()

//Peuplement de la table d'evenements
Principale::Principale(const wxString& title) : wxFrame (NULL, //Parent
                                                wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY
                                                title)  // titre de la fenêtre
{



// Creation des textes statiques

Textex = new wxStaticText(this, //Frame dans lequel créer
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

//Creation des bouton

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
    ligneX = new wxBoxSizer (wxHORIZONTAL); //Création du sizer
    ligneX->Add(Textex, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL); // Ajout texteX
    ligneX->Add(controlX, 1, wxEXPAND); // Ajout formulaire X

    //Ligne de saisieY
    ligneY = new wxBoxSizer (wxHORIZONTAL);
    ligneY->Add(Textey, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL);
    ligneY->Add(controlY, 1, wxEXPAND);

    //Ligne du résultat
    ligneResultat = new wxBoxSizer (wxHORIZONTAL);
    ligneResultat->Add(TexteAdd, 0, wxALL);
    ligneResultat->Add(TexteResultat, 0, wxALL);

    //Ligne des boutons
    ligneBoutons = new wxBoxSizer(wxHORIZONTAL);
    ligneBoutons->Add(boutonAdd, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 /*Bordure de 5 pour chaaque bouton pour qu'ils ne soient pas collés*/);
    ligneBoutons->Add(boutonEffacer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5);

    //Colonne des objets
    colonneObjets = new wxBoxSizer(wxVERTICAL);
    colonneObjets->Add(ligneX, 0, wxEXPAND|wxALL, 10); // bordure de 10 autour de la ligne de saisie de X avec expension horizontale possible
    colonneObjets->Add(ligneY, 0,wxEXPAND|wxALL, 10); // bordure de 10 autour de la ligne de saisie de Y avec expension horizontale possible
    colonneObjets->Add(ligneResultat, 0, wxALL, 10);  // bordure de 10 autour de la ligne d'affichage du resultat (placement fixe)
    colonneObjets->Add(ligneBoutons,0, wxALIGN_RIGHT|wxALL, 10); // bordure de 10 autour de la ligne des 2 boutons avec deplacement à droite possible si expension de la fenêtre

    // Paramétrage de la colonne des objets
    SetSizer(colonneObjets); // Permet à la fenêtre d'intégrer le sizer
    colonneObjets->SetSizeHints(this); // Autorise la modification des tailles limites de la fenêtre

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

    txtX = controlX->GetValue(); // Récupération champ saisie X
    txtY = controlY->GetValue(); // Récupération champ saisie Y

    if (txtX.ToDouble(&valeurX) && txtY.ToDouble(&valeurY)) // Si convertion réussie
    {
        txtRslt << valeurX+valeurY; // résultat = addition x + y
        TexteResultat->SetLabel(txtRslt); // Affichage résultat dans le label
    }

    else // convertion ratée
    {
        TexteResultat->SetLabel(wxEmptyString); // on efface le résultat précédent
        wxMessageBox(wxT("Un des deux operandes ne contient pas de valeur ou la saisie est invalide"), wxT("Calcul impossible")); // On affiche le message d'erreur
    }
}

void Principale::onClose(wxCloseEvent& evt)
{
    if (wxMessageBox(wxT("Voulez-vous quitter ?"), wxT("Confirmer"), wxYES_NO, this) == wxYES) // Si l'utilisateur clique sur oui
    {
        this->Destroy();
    }

}

Principale::~Principale()
{
    //Destructeur
}

