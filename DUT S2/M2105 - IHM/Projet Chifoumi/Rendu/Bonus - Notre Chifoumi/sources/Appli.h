/***************************************************************
 * Name:      Appli.h
 * Purpose:   Definit la classe Appli
 * Author:    A. Murillo et X. Avellan ()
 * Created:   2019-05-28
 * Copyright: A. Murillo et X. Avellan ()
 * License:
 **************************************************************/

#ifndef APPLI_H
#define APPLI_H

#include <wx/app.h>

class Appli : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif //APPLI_H
