#include "SingletonDirecteurIut.h"

string SingletonDirecteurIut::nom ="";
string SingletonDirecteurIut::prenom ="";
SingletonDirecteurIut* SingletonDirecteurIut::_instance = NULL;

SingletonDirecteurIut::SingletonDirecteurIut()
{
    //ctor
}

SingletonDirecteurIut::~SingletonDirecteurIut()
{
    //dtor
}

void SingletonDirecteurIut::kill_instance() {
    if (_instance != NULL)
    {
        delete _instance;
        _instance = NULL;
    }
}

SingletonDirecteurIut* SingletonDirecteurIut::get_instance() {
    if (_instance != NULL)
    {
        _instance = new SingletonDirecteurIut();
    }
    return _instance;
 }

