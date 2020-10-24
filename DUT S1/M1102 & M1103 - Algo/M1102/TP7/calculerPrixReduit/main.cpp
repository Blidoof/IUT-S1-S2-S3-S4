/*
  Programme : calculer Prix R�duit
  But :permet de calculer un prix r�duit en faisant appel � un sous programme calculerPrixReduit.
  Date de derni�re modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : Code faux ( avertissement du compilateur ): La variable prixReduit est pass�e par valeur et non pas par r�f�rence.
*/

#include <iostream>
using namespace std;


int main (void)
{
    //DECLARATION DES SOUS PROGRAMMES
    void calculerPrixReduit (float prixInit, unsigned short int reduction, float& prixReduit);
    /*ce sous programme calcule un prix r�duit (prixReduit) � partir d'un prix initial prixInit, et d'une
    r�duction exprim�e en pourcentage */


    //VARIABLES
    float prixOrdinateur; // Le prix de l'ordinateur achet� par le client
    unsigned short int reductionFidelite; // La r�duction � appliquer au prix de l'appareil
    float prixAPayer; // Le prix r�duit � payer par l'utilisateur

    //TRAITEMENTS
    //Saisir prixOrdinateur et pourcentage

    cout << "Saisir le prix de l'ordinateur choisi :";
    cin >> prixOrdinateur;
    cout << "Merci de saisir le pourcentage de reduction dont ebneficie le client :";
    cin >> reductionFidelite;

    //Appel du sous programme calculerPrixReduit
    calculerPrixReduit (prixOrdinateur, reductionFidelite, prixAPayer);

    //Afficher r�sultat
    cout << "le prix � payer est : " << prixAPayer;

    return 0;
}
void calculerPrixReduit (float prixInit, unsigned short int reduction, float& prixReduit)
{
    prixReduit = prixInit * ((100-float(reduction))/100);/*On d�clare temporairement r�duction en type "float" car on
                                                            y applique une division par 100 dont le r�sulatt est un nombre � virgule*/
}
