#ifndef APPLI_H
#define APPLI_H

#include <wx/wx.h>

// D�finition de la classe "Appli"
class Appli : public wxApp
{
   public:
   // appel au d�marrage de l�application
   virtual bool OnInit();
};

DECLARE_APP(Appli)
#endif // APPLI_H
