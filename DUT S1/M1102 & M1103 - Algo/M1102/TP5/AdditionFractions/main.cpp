/*
  Programme : Addition de 2 fractions
  But : Addtionne deux fractions de la forme A/B et affiche le résultat sous la meme forme.
  Date de dernière modification : 05/10/2018
  Auteur : A. MURILLO
  Remarques : /
*/

#include <iostream>
using namespace std;


int main (void)
{

    //TYPES / STRUCTURES
    struct Fraction
    {
        unsigned short int num; // Le numerateur de la fraction
        unsigned short int den; // Le dénominateur de la fraction
    };

    //VARIABLES
    Fraction fraction1; // la 1ere fraction saisie
    Fraction fraction2; // la 2eme fraction saisie
    Fraction resultat; // le résultat de l'addition

    //TRAITEMENTS
    //clavier > saisieDesFractions > fraction1.num, fraction 1.den, fraction2.num, fraction 2.den
    cout << "Saisir le numerateur de la 1ere fraction : ";
    cin >> fraction1.num;
    cout << "Saisir le denominateur de la 1ere fraction : ";
    cin >> fraction1.den;
    cout << "Saisir le numerateur de la 2eme fraction : ";
    cin >> fraction2.num;
    cout << "Saisir le denominateur de la 2eme fraction : ";
    cin >> fraction2.den;

    //fraction1.num, fraction 1.den, fraction2.num, fraction 2.den > calculDeL'addition > resultat.num, resultat.den
    resultat.num = fraction1.num * fraction2.den + fraction1.den * fraction2.num;
    resultat.den = 2 * fraction1.den * fraction2.den;

    //resultat.num, resultat.den > Affichage > écran
    cout << "Le resultat de l'addtion est : " << resultat.num << "/" << resultat.den;

    return 0;
}
