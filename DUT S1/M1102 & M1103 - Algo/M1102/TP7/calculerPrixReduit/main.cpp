/*
  Programme : calculer Prix Réduit
  But :permet de calculer un prix réduit en faisant appel à un sous programme calculerPrixReduit.
  Date de dernière modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : Code faux ( avertissement du compilateur ): La variable prixReduit est passée par valeur et non pas par référence.
*/

#include <iostream>
using namespace std;


int main (void)
{
    //DECLARATION DES SOUS PROGRAMMES
    void calculerPrixReduit (float prixInit, unsigned short int reduction, float& prixReduit);
    /*ce sous programme calcule un prix réduit (prixReduit) à partir d'un prix initial prixInit, et d'une
    réduction exprimée en pourcentage */


    //VARIABLES
    float prixOrdinateur; // Le prix de l'ordinateur acheté par le client
    unsigned short int reductionFidelite; // La réduction à appliquer au prix de l'appareil
    float prixAPayer; // Le prix réduit à payer par l'utilisateur

    //TRAITEMENTS
    //Saisir prixOrdinateur et pourcentage

    cout << "Saisir le prix de l'ordinateur choisi :";
    cin >> prixOrdinateur;
    cout << "Merci de saisir le pourcentage de reduction dont ebneficie le client :";
    cin >> reductionFidelite;

    //Appel du sous programme calculerPrixReduit
    calculerPrixReduit (prixOrdinateur, reductionFidelite, prixAPayer);

    //Afficher résultat
    cout << "le prix à payer est : " << prixAPayer;

    return 0;
}
void calculerPrixReduit (float prixInit, unsigned short int reduction, float& prixReduit)
{
    prixReduit = prixInit * ((100-float(reduction))/100);/*On déclare temporairement réduction en type "float" car on
                                                            y applique une division par 100 dont le résulatt est un nombre à virgule*/
}
