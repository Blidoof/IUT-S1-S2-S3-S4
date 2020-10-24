/*
  Programme : Afficher prix réduit
  But : permet de calculer et afficher un prix réduit en faisant appel à un sous programme
  Date de dernière modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : Fait appel à un sous programme
*/

#include <iostream>
using namespace std;


int main (void)
{
    // DECLARATION DES SOUS PROGRAMMES
    void afficherPrixReduit (float prixInit, unsigned short int reduction);
    /*Ce sous programme permet d'afficher un prix réduit à l'aide d'un prix initial prixInit et d'une réduction
      exprimée en pourcentage */

    //VARIABLES
    float prixOrdinateur; // Le prix de l'ordinateur acheté par le client
    unsigned short int reductionFidelite; // La réduction à appliquer au prix de l'appareil

    //TRAITEMENTS
    //Saisir prixOrdinateur et pourcentage

    cout << "Saisir le prix de l'ordinateur choisi :"; cin >> prixOrdinateur;
    cout << "Merci de saisir le pourcentage de reduction dont ebneficie le client :"; cin >> reductionFidelite;

    // Appel du sous programme afficherPrixReduit
    afficherPrixReduit (prixOrdinateur, reductionFidelite);

    return 0;
}

void afficherPrixReduit (float prixInit, unsigned short int reduction)
{
    //Declaration
    float montantReduction; //Reduction à appliquer à prixInit
    float prixReduit; //Prix apres réduction

    //Calcul de montantReduction
    montantReduction = prixInit*(float(reduction)/100); /*On déclare temporairement réduction en type "float" car on
                                                            y applique une division par 100 dont le résulatt est un nombre à virgule*/
    //calcul de prix réduit
    prixReduit = prixInit - montantReduction;

    //Affichage résultat
    cout << "Le prix reduit est " << prixReduit;
}
