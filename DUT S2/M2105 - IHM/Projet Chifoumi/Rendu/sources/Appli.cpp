/***************************************************************
 * Name:      Appli.cpp
 * Purpose:   Code de la classe Appli
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/

#include "Appli.h"

#include "Principale.h"
#include <wx/image.h>


IMPLEMENT_APP(Appli);

bool Appli::OnInit()
{

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Principale* Frame = new Principale(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }

    return wxsOK;

}
