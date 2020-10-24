#ifndef PRINCIPALE_H
#define PRINCIPALE_H

// Header central de wxWidgets incluant les widgets les plus utilisés
/* par exemple :
#include "wx/event.h"
#include "wx/app.h"
#include "wx/utils.h"
#include "wx/stream.h"
#include "wx/memory.h"
#include "wx/math.h"
#include "wx/stopwatch.h"
#include "wx/module.h"

#if wxUSE_GUI
#include "wx/window.h"
#include "wx/containr.h"
#include "wx/panel.h"
#include "wx/toplevel.h"
#include "wx/frame.h"
#include "wx/gdicmn.h"
#include "wx/gdiobj.h"
#include "wx/region.h"
#include "wx/bitmap.h"
#include "wx/image.h"
#include "wx/colour.h"
#include "wx/font.h"
#include "wx/dc.h"
#include "wx/dcclient.h"
#include "wx/dcmemory.h"
#include "wx/dcprint.h"
#include "wx/dcscreen.h"
#include "wx/button.h"
#include "wx/menuitem.h"
#include "wx/menu.h"
#include "wx/pen.h"
#include "wx/brush.h"
#include "wx/palette.h"
#include "wx/icon.h"
#include "wx/cursor.h"
#include "wx/dialog.h"
#include "wx/timer.h"
#include "wx/settings.h"
#include "wx/msgdlg.h"
#include "wx/cmndata.h"
#include "wx/dataobj.h"

#include "wx/control.h"
#include "wx/checkbox.h"
#include "wx/checklst.h"
#include "wx/scrolbar.h"
#include "wx/stattext.h"
#include "wx/statbox.h"
#include "wx/listbox.h"
#include "wx/radiobox.h"
#include "wx/radiobut.h"
#include "wx/textctrl.h"
#include "wx/slider.h"
#include "wx/scrolwin.h"
#include "wx/toolbar.h"
#include "wx/combobox.h"
#include "wx/layout.h"
#include "wx/sizer.h"
#include "wx/mdi.h"
#include "wx/statusbr.h"
....
*/
#include <wx/wx.h>

// Définition de la classe MaPrincipale
class Principale : public wxFrame
{
private :

    //Objets de la fenetre
    wxStaticText * Textex; // pour demander saisie de la variable X
    wxStaticText * Textey; // pour demander saisie de la variable Y
    wxStaticText * TexteAdd; // Pour préciser là ou sera affiché le résultat del'addition X+Y
    wxStaticText * TexteResultat; // Résultat de X+Y
    wxTextCtrl * controlX; // Formulaire de saisie de la variable X
    wxTextCtrl * controlY; // Formulaire de saisie de la variable Y
    wxButton * boutonAdd; // Bouton pour déclencher l'addition
    wxButton * boutonEffacer; // Bouton pour vider les formulaires et effacer le résultat de l'addition

    //ID des objets
    const int ID_BOUTON_ADD = wxNewId(); // Identifiant du bouton addition
    const int ID_BOUTON_EFFACER = wxNewId(); // Identifiant du bouton effacer


    //Sizers
    wxBoxSizer *ligneX; // Sizer de la ligne textex + controlX
    wxBoxSizer *ligneY; // Sizer de la ligne textey + controlY
    wxBoxSizer *ligneResultat; // Sizer de la ligne X+Y= et résultat
    wxBoxSizer *ligneBoutons; // Sizer de la ligne bouton addition + effacer
    wxBoxSizer *colonneObjets; // Sizer pour aligner verticalement ligneX + ligneY + ligneResultat + ligneBoutons

public:

    // Le constructeur
    Principale(const wxString& title);

    //Gestionnaires d'evenements
    void onClickEffacer(wxCommandEvent& event); // Si clic sur effacer
    void onClickAddition (wxCommandEvent& event); // Si clic sur addition
    void onClose(wxCloseEvent& evt); // Si fermeture fenetre

    // Le destructeur
    virtual ~Principale();

    DECLARE_EVENT_TABLE()
};
#endif // PRINCIPALE_H
