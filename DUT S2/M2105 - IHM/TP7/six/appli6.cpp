#include "appli6.h"
#include "principale6.h"

// Permet � wxWidgets de cr��er l'instance d'application
IMPLEMENT_APP(Appli)

// Impl�mentation de la m�thode OnInit()
   bool Appli::OnInit()
   {
       // Cr�ation de la fen�tre principale de l'application
       Principale *maFen = new Principale(wxT("Principale 1 : Addition d'entiers (ArthurMurillo)"));
       // Rendre la fen�tre visible
       maFen -> Show(true);

       // D�marre la boucle des messages
       return true;
    }
