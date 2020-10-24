/*
 Programme : validationModule
 But : D�termine si un �l�ve a valid� son module.
 Date de derni�re modification : 21/09/2018
 Auteur : Arthur Murillo
 Remarques : /
*/
#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float noteOral; // La note de l'�preuve orale
    float noteEcrit; // La note de l'�preuve �crite
    float moyenne; // La moyenne finale de l'�tudiant
    float coefOral; // Le coefficient de l'�preuve orale
    float coefEcrit; // Le coefficient de l'�preuve �crite

    //TRAITEMENTS

    // (clavier )> saisirValeurInitiale > noteOrale, noteEcrit, coefOral, coefEcrit
    cout << "Saisir la note orale :";
    cin >> noteOral;
    cout << "Saisir la note ecrite :";
    cin >> noteEcrit;
    cout << "Saisir le coefficient de la note orale :";
    cin >> coefOral;
    cout << "Saisir le coefficient de la note ecrite :";
    cin >> coefEcrit;
    // noteOral, noteEcrit, coefOral, coefEcrit > determinerSiRecu > ( ecran )
    moyenne = (coefOral * noteOral + noteEcrit*coefEcrit)/(coefOral+coefEcrit);

    if (moyenne < 10)
    {
        cout << "L'eleve n'est pas recu";
    }
    else
    {
        cout << "L'eleve est recu";
    }

return 0;
}
