/***************************************************************
 * Name:      chifoumiUltraInstinctApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Carduino ()
 * Created:   2019-05-28
 * Copyright: Carduino ()
 * License:
 **************************************************************/

#include "chifoumiUltraInstinctApp.h"

//(*AppHeaders
#include "chifoumiUltraInstinctMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(chifoumiUltraInstinctApp);

bool chifoumiUltraInstinctApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Principale* Frame = new Principale(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
