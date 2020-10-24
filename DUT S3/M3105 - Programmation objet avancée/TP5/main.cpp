#include <iostream>
#include "SingletonDirecteurIut.h"
using namespace std;

int main()
{
    SingletonDirecteurIut* directeur;
    SingletonDirecteurIut* leChef;

    directeur = SingletonDirecteurIut::get_instance();
    directeur->Setnom("Nodemot");

    leChef = SingletonDirecteurIut::get_instance();

    cout << leChef->Getnom();

    return 0;
}
