/*
  Programme : Afficher prix r�duit
  But : permet de calculer et afficher un prix r�duit en faisant appel � un sous programme
  Date de derni�re modification : 17/10/2018
  Auteur : A. MURILLO
  Remarques : Fait appel � un sous programme
*/

#include <iostream>
using namespace std;


int main (void)
{
    // DECLARATION DES SOUS PROGRAMMES
    void afficherPrixReduit (float prixInit, unsigned short int reduction);
    /*Ce sous programme permet d'afficher un prix r�duit � l'aide d'un prix initial prixInit et d'une r�duction
      exprim�e en pourcentage */

    //VARIABLES
    float prixOrdinateur; // Le prix de l'ordinateur achet� par le client
    unsigned short int reductionFidelite; // La r�duction � appliquer au prix de l'appareil

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
    float montantReduction; //Reduction � appliquer � prixInit
    float prixReduit; //Prix apres r�duction

    //Calcul de montantReduction
    montantReduction = prixInit*(float(reduction)/100); /*On d�clare temporairement r�duction en type "float" car on
                                                            y applique une division par 100 dont le r�sulatt est un nombre � virgule*/
    //calcul de prix r�duit
    prixReduit = prixInit - montantReduction;

    //Affichage r�sultat
    cout << "Le prix reduit est " << prixReduit;
}
