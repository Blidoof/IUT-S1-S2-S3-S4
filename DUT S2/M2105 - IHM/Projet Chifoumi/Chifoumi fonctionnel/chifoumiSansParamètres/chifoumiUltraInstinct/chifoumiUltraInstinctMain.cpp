/***************************************************************
 * Name:      chifoumiUltraInstinctMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Carduino ()
 * Created:   2019-05-28
 * Copyright: Carduino ()
 * License:
 **************************************************************/

#include "chifoumiUltraInstinctMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Principale)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Principale)
const long Principale::ID_LABELJ1 = wxNewId();
const long Principale::ID_LABELJ2 = wxNewId();
const long Principale::ID_SCOREJ1 = wxNewId();
const long Principale::ID_SCOREJ2 = wxNewId();
const long Principale::ID_BOUTONCISEAUX = wxNewId();
const long Principale::ID_IDSIGNE2 = wxNewId();
const long Principale::ID_SIGNEJ1 = wxNewId();
const long Principale::ID_LOGOVERSUS = wxNewId();
const long Principale::ID_BOUTONFEUILLE = wxNewId();
const long Principale::ID_BOUTONPIERRE = wxNewId();
const long Principale::ID_BUTTONNOUVELLEPARTIE = wxNewId();
//*)

BEGIN_EVENT_TABLE(Principale,wxFrame)
    //(*EventTable(Principale)
    //*)
END_EVENT_TABLE()

///*Constructeur
Principale::Principale(wxWindow* parent,wxWindowID id)
{
    //Mise en place du contrôleur
    this->jeu = new Jeu();
    this->jeu->setVue(this);

    //(*Initialize(Principale)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(456,422));
    labelJ1 = new wxStaticText(this, ID_LABELJ1, _("Vous"), wxPoint(64,16), wxDefaultSize, 0, _T("ID_LABELJ1"));
    wxFont labelJ1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    labelJ1->SetFont(labelJ1Font);
    labelJ2 = new wxStaticText(this, ID_LABELJ2, _("La machine"), wxPoint(320,16), wxDefaultSize, 0, _T("ID_LABELJ2"));
    wxFont labelJ2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    labelJ2->SetFont(labelJ2Font);
    scoreJ1 = new wxStaticText(this, ID_SCOREJ1, _("0"), wxPoint(80,48), wxDefaultSize, 0, _T("ID_SCOREJ1"));
    wxFont scoreJ1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    scoreJ1->SetFont(scoreJ1Font);
    scoreJ2 = new wxStaticText(this, ID_SCOREJ2, _("0"), wxPoint(368,48), wxDefaultSize, 0, _T("ID_SCOREJ2"));
    wxFont scoreJ2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    scoreJ2->SetFont(scoreJ2Font);
    boutonCiseaux = new wxBitmapButton(this, ID_BOUTONCISEAUX, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\ciseau.gif"))), wxPoint(320,240), wxSize(104,112), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BOUTONCISEAUX"));
    signeJ2 = new wxStaticBitmap(this, ID_IDSIGNE2, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\rien.gif")).Rescale(wxSize(104,112).GetWidth(),wxSize(104,112).GetHeight())), wxPoint(320,88), wxSize(104,112), wxSIMPLE_BORDER, _T("ID_IDSIGNE2"));
    signeJ1 = new wxStaticBitmap(this, ID_SIGNEJ1, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\rien.gif")).Rescale(wxSize(104,112).GetWidth(),wxSize(104,112).GetHeight())), wxPoint(32,88), wxSize(104,112), wxSIMPLE_BORDER, _T("ID_SIGNEJ1"));
    imageVersus = new wxStaticBitmap(this, ID_LOGOVERSUS, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\versus.gif")).Rescale(wxSize(104,112).GetWidth(),wxSize(104,112).GetHeight())), wxPoint(176,126), wxSize(104,112), wxSIMPLE_BORDER, _T("ID_LOGOVERSUS"));
    boutonPapier = new wxBitmapButton(this, ID_BOUTONFEUILLE, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\papier.gif"))), wxPoint(176,240), wxSize(104,112), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BOUTONFEUILLE"));
    boutonPierre = new wxBitmapButton(this, ID_BOUTONPIERRE, wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\pierre.gif"))), wxPoint(32,240), wxSize(104,112), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BOUTONPIERRE"));
    boutonNouvellePartie = new wxButton(this, ID_BUTTONNOUVELLEPARTIE, _("Nouvelle Partie"), wxPoint(328,384), wxSize(112,24), 0, wxDefaultValidator, _T("ID_BUTTONNOUVELLEPARTIE"));

    Connect(ID_BOUTONCISEAUX,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Principale::OnClickboutonCiseaux);
    Connect(ID_BOUTONFEUILLE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Principale::OnClickboutonPapier);
    Connect(ID_BOUTONPIERRE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Principale::OnClickboutonPierre);
    Connect(ID_BUTTONNOUVELLEPARTIE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Principale::OnClickboutonNouvellePartie);
    //*)

    //Mise en place des sizers

    //SizerJ1
    sizerJ1 = new wxBoxSizer (wxVERTICAL); //Création du sizer
    sizerJ1->Add(labelJ1, 0, wxALIGN_CENTER_HORIZONTAL); // Ajout labelJ1
    sizerJ1->Add(scoreJ1,0, wxALIGN_CENTER_HORIZONTAL); // Ajout score J1
    sizerJ1->Add(signeJ1,0, wxALIGN_CENTER_HORIZONTAL); // Ajout signe J1

    //SizerJ2
    sizerJ2 = new wxBoxSizer (wxVERTICAL); //Création du sizer
    sizerJ2->Add(labelJ2, 0, wxALIGN_CENTER_HORIZONTAL); // Ajout labelJ2
    sizerJ2->Add(scoreJ2,0, wxALIGN_CENTER_HORIZONTAL); // Ajout scoreJ2
    sizerJ2->Add(signeJ2,0, wxALIGN_CENTER_HORIZONTAL); // Ajout signeJ2

    //SizerAffichage
    sizerAffichage = new wxBoxSizer (wxHORIZONTAL);
    sizerAffichage->Add(sizerJ1,1,wxALIGN_LEFT|wxALL, 10);
    sizerAffichage->Add(imageVersus,0,wxALIGN_CENTER_HORIZONTAL|wxTOP, 55);
    sizerAffichage->Add(sizerJ2,1,wxALIGN_RIGHT|wxALL, 10);

    //SizerBoutonsSignes
    sizerSignes = new wxStaticBoxSizer (wxHORIZONTAL, this, wxT("Pour jouer, cliquez sur une des images ci-dessous :"));
    sizerSignes->Add(boutonPierre,0, wxALIGN_LEFT|wxALL, 5);
    sizerSignes->Add(boutonPapier,0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    sizerSignes->Add(boutonCiseaux,0, wxALIGN_RIGHT|wxALL, 5);


    //TopSizer
    topSizer = new wxBoxSizer (wxVERTICAL);
    topSizer->Add(sizerAffichage, 1 , wxALIGN_CENTER_HORIZONTAL|wxEXPAND);
    topSizer->Add(sizerSignes,0,wxALIGN_CENTER_HORIZONTAL);
    topSizer->Add(boutonNouvellePartie,0,wxALIGN_RIGHT|wxALIGN_BOTTOM|wxALL, 10);


    //Paramètrage topSizer
    SetSizer(topSizer); // Définition du sizer principal
    topSizer->Fit(this); // Adaptation au sizer
    topSizer->SetSizeHints(this);

    //Paramètrage topSizer
    SetSizer(topSizer); // Définition du sizer principal
    topSizer->Fit(this); // Adaptation au sizer
    topSizer->SetSizeHints(this);



}

Principale::~Principale()
{
    //(*Destroy(Principale)
    //*)
}

void Principale::OnClickboutonNouvellePartie(wxCommandEvent& event)
{
    this->jeu->demandeNouvellePartie();
}

void Principale::OnClickboutonCiseaux(wxCommandEvent& event)
{
    this->jeu->jouer(3);
}

void Principale::OnClickboutonPapier(wxCommandEvent& event)
{
    this->jeu->jouer(2);
}

void Principale::OnClickboutonPierre(wxCommandEvent& event)
{
    this->jeu->jouer(1);
}

void Principale::afficherScores()
{
    wxString scoreJ1;
    scoreJ1 << this->jeu->getScoreJ1();
    wxString scoreJ2;
    scoreJ2 << this->jeu->getScoreJ2();

    this->scoreJ1->SetLabel(scoreJ1);
    this->scoreJ2->SetLabel(scoreJ2);
}

void Principale::effacerScores()
{
    this->scoreJ1->SetLabel(wxT("0"));
    this->scoreJ2->SetLabel(wxT("0"));
}

void Principale::MajSignes()
{
    //Affichage du signe du joueur 1
    if (this->jeu->getSigneJ1() == Jeu::pierre)
    {
        this->signeJ1->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\pierre.gif"))));
    }
    else
    {
        if (this->jeu->getSigneJ1() == Jeu::feuille)
        {
            this->signeJ1->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\papier.gif"))));
        }
        else
        {
            if (this->jeu->getSigneJ1() == Jeu::ciseaux)
            {
                this->signeJ1->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\ciseau.gif"))));
            }
        }
    }

    //Affichage du signe du joueur 2
    if (this->jeu->getSigneJ2() == Jeu::pierre)
    {
        this->signeJ2->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\pierre.gif"))));
    }
    else
    {
        if (this->jeu->getSigneJ2() == Jeu::feuille)
        {
            this->signeJ2->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\papier.gif"))));
        }
        else
        {
            if (this->jeu->getSigneJ2() == Jeu::ciseaux)
            {
                this->signeJ2->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\ciseau.gif"))));
            }
        }
    }

}

void Principale::effacerSignes()
{
    this->signeJ1->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\rien.gif"))));
    this->signeJ2->SetBitmap(wxBitmap(wxImage(_T("E:\\Desktop\\IHM\\ProjetChifoumi\\chifoumiUltraInstinct\\rien.gif"))));
}

Jeu* Principale::getJeu()
{
    return this->jeu;
}

void Principale::setJeu(Jeu* jeu)
{
    this->jeu = jeu;
}
