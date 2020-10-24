#ifndef APPLI_H
#define APPLI_H

#include <wx/wx.h>

// Définition de la classe "Appli"
class Appli : public wxApp
{
   public:
   // appel au démarrage de l’application
   virtual bool OnInit();
};

DECLARE_APP(Appli)
#endif // APPLI_H
