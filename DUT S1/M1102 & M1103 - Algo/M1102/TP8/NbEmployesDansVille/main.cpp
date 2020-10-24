/*
  Programme : Nombre d'habitants dans une ville donéne
  But : Affiche le nombre de personnes contenues dans un tableau habitant dans la meme ville
  Date de dernière modification : 26/10/2018
  Auteur : A. MURILLO
  Remarques : recherche du nombre de personnes habitant dans la meme ville délégué à un sous programme nbMemeVille
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
unsigned int nbMemeVille (const Personne tab[], unsigned int nbCases, unsigned int codeCherche);
//But : calcule le nombre de personnes parmi tab de taille nbCases ayant le meme code postal que codeCherche

int main (void)
{
    //VARIABLES
    unsigned int nbEmployes = 3; //Le nombre d'employes contenus dans le tableau
    Personne employesIUT[nbEmployes] = {{"Etchevery", "Patrick", {"2","Rue de la République", 64100, "Bayonne"}}, {"Bruyere","Marie",{"4","Place Martin",64600,"Anglet"}},{"Aniorte","Philippe",{"9","Boulevard Merise",64100,"Bayonne"}}}; // Les employes de l'IUT
    unsigned int adressePareille; // Le nombre d'employés ayant la même adresse
    unsigned int codeATrouver; // Le code dpostal que l'on veut trouver

    //TRAITEMENTS
    //Saisir le code à chercher
    cout << "Saisir le code postal que vous desirez trouver :";
    cin >> codeATrouver;

    //trouverNombrePersonneMemeVille
    adressePareille = nbMemeVille (employesIUT, nbEmployes, codeATrouver);

    //AfficherResultat
    if (adressePareille == 0)
    {
        cout << "Personne n'habite ici !";
    }
    else
    {
        cout << adressePareille << " personne(s) habitent dans la ville dont le code postal est " << codeATrouver << "." << endl;
        cout << "Cette(ces) personnne(s) est(sont) : " << endl;

        for (unsigned int i = 0 ; i <= (nbEmployes-1) ; i++ )
        {
            if (employesIUT[i].adresse.codePostal == codeATrouver)
                {
                    cout << " - " << employesIUT[i].nom << " " << employesIUT[i].prenom << endl ;
                }
        }
    }


}

//DEFINITION DES SOUS PROGRAMMES
unsigned int nbMemeVille (const Personne tab[], unsigned int nbCases, unsigned int codeCherche)
{
    //VARIABLES
    unsigned int memeVille; //Le nombre de personnes habitant dans le meme ville

    //ChercherCode
    memeVille = 0;

    for (unsigned int i = 0 ; i <= (nbCases-1) ; i++ )
    {
        if (tab[i].adresse.codePostal == codeCherche)
        {
            memeVille += 1;
        }
    }

    //retournerValeur

    return memeVille;
}
