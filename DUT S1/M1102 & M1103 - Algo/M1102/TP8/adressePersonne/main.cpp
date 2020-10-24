/*
  Programme : adresse d'une personne
  But :retourne l'adresse d'une personne donnée
  Date de dernière modification : 24/10/2018
  Auteur : A. MURILLO
  Remarques : recherche de l'adresse effectuée par une fonction getAdresse
*/

#include <iostream>
using namespace std;

//DECLARATION DE TYPES
struct Adresse
    {
        string numRue; // Le numéro de la rue
        string nomRue; // Le nom de la rue
        unsigned int codePostal; //Le code postal de l'adresse
        string ville; //Le nom de la ville
    };

struct Personne
    {
        string nom; // Le nom de la personne
        string prenom; //Le nom de la personne
        Adresse adresse; // L'adresse de la personne
    };

//DECLARATION DES SOUS PROGRAMMES
Adresse getAdresse(const Personne& personne);
//But : retourne l'adresse d'une personne donnée

int main (void)
{
    //VARIABLES
    Personne jeanLuc = {"Jean-Luc", "Melenchon", {"2", "Rue de la Republique", 75000, "Paris"}}; // Une personne
    Personne marine = {"Marine", "Le pen", {"4", "Place du bucher", 75000, "Paris"}}; // Une personne
    Adresse adresseJeanLuc; // L'adresse de Jean luc Melenchon
    Adresse adresseMarine; // L'adresse de Marine Le Pen

    //TRAITEMENTS
    //Chercher l'adresse de Jean Luc
    adresseJeanLuc = getAdresse(jeanLuc);

    //Chercher l'adresse de marine
    adresseMarine = getAdresse(marine);

    //Afficher nom et adresse jeanLuc
    cout << jeanLuc.nom << " " << jeanLuc.prenom << endl;
    cout << adresseJeanLuc.numRue << ", " << adresseJeanLuc.nomRue << ", " << adresseJeanLuc.codePostal << " " << adresseJeanLuc.ville << std::endl << std:: endl;



    //Afficher nom et adresse marine
    cout << marine.nom << " " << marine.prenom << endl;
    cout << adresseMarine.numRue << ", " << adresseMarine.nomRue << ", " << adresseMarine.codePostal << " " << adresseMarine.ville;

    return 0;
}

//DEFINITION DES SOUS PROGRAMMES
Adresse getAdresse(const Personne& personne)
{
    return personne.adresse;
}
