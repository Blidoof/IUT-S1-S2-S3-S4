#include "appli6.h"
#include "principale6.h"

// Permet à wxWidgets de crééer l'instance d'application
IMPLEMENT_APP(Appli)

// Implémentation de la méthode OnInit()
   bool Appli::OnInit()
   {
       // Création de la fenêtre principale de l'application
       Principale *maFen = new Principale(wxT("Principale 1 : Addition d'entiers (ArthurMurillo)"));
       // Rendre la fenêtre visible
       maFen -> Show(true);

       // Démarre la boucle des messages
       return true;
    }
