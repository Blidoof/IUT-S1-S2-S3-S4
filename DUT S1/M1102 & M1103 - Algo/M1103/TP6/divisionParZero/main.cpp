#include <iostream>
#include <string>
#include "fichierTexte.h"

using namespace std;

int division (int numerateur, int denominateur);
/* si denominateur !=0, retourne l'entier numerateur/denominateur;
    Sinon, lève une exception de type string avec le message "division par zéro !" */

int main()
{

    int x; // le numérateur de la division
    int diviseur; // le dénominateur de la division
    cout << "Valeur pour x : ";
    cin >> x;

    while (true)
    {
        cout << "Valeur pour denominateur : ";
        cin >> diviseur;
        cout << x << "/" << diviseur << " = ";

        try
        {
            cout << division(x, diviseur)<< endl;
            break;
        }

        catch (string s)
        {
            cerr << "!" << s << endl;
        }

    }

    cout << endl << "au revoir" << endl;

    return 0;
}

int division (int numerateur, int denominateur)
{
    /* si denominateur !=0, retourne l'entier numerateur/denominateur;
    Sinon, lève une exception de type string avec le message "division par zéro !" */

    if (denominateur == 0)
    {
        throw string ("division par zero !...Recommencez !") ;
    }
    else
    {
        return numerateur/denominateur;
    }
}
