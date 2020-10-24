/*
  Programme :Recherche de 1ere voyelle
  But :Recherche la 1ere voyelle dans un mot saisi
  Date de dernière modification : 12/10/2018
  Auteur : A. MURILLO
  Remarques : se base sur la recherche de 1ere occurence
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES

    //VARIABLES
    string mot; // Le mot saisi par l'utilisateur
    bool trouve; // Indicateur du fait que la 1ere voyelle a été trouvée ou non
    unsigned short int position; // Positionnement de la recherche sur le mot donné
    unsigned short int posVoyelle; // La position de la 1ere voyelle

    //TRAITEMENTS

    //Saisir le mot
    cout << "Merci de saisir un mot :";
    cin >> mot;

    //Initialiser recherche
    position = 0;
    trouve = false;

    //Rechercher la 1ere voyelle
    while (!( position > mot.size() || trouve == true))
    {
        //Verifier si la lettre est une voyelle
        if (mot[position] == 'a' || mot[position] == 'e' || mot[position] == 'i' || mot[position] == 'o' || mot[position] == 'u' || mot[position] == 'y')
        {
            posVoyelle = position+1;
            trouve = true;
        }

        //passer au caractère suivant
        position++;
    }

    //Afficher résultat

    if (trouve == true)
    {
        cout << "La 1ere voyelle du mot saisi est a la " << posVoyelle << "eme lettre";
    }
    else
    {
        cout << "Aucune voyelle trouvee ";
    }

    return 0;
}
