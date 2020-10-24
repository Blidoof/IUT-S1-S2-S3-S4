#include <iostream>

#include "Individu.h"
#include "IndividuMenteur.h"
#include "Outils.h"

using namespace std;

void affichageAgeIndividuParValeur(Individu ind){

cout << ind.Getnom() << " " << ind.Getprenom() << " ne.e en " << ind.GetanneeNaissance() << " indique avoir " << ind.get_age() << " ans\n";

}

void affichageAgeIndividuParReference(Individu &ind){

cout << ind.Getnom() << " " << ind.Getprenom() << " ne.e en " << ind.GetanneeNaissance() << " indique avoir " << ind.get_age() << " ans\n";

}

void affichageAgeIndividuParAdresse(Individu* ind){

cout << ind->Getnom() << " " << ind->Getprenom() << " ne.e en " << ind->GetanneeNaissance() << " indique avoir " << ind->get_age() << " ans\n";

}

int main()
{
    Individu ind1("Emma", "Auzi", 1960);
    IndividuMenteur ind2("Allaman", "Marie", 1960);
    IndividuMenteur ind3("Xabi", "Avellan", 1990);

    Outils o;

    cout << o.anneeActuelle() << "\n\n";

    cout << "Valeur\n";
    affichageAgeIndividuParValeur(ind1);
    affichageAgeIndividuParValeur(ind2);
    affichageAgeIndividuParValeur(ind3);
    cout << "\n";

    cout << "Reference\n";
    affichageAgeIndividuParReference(ind1);
    affichageAgeIndividuParReference(ind2);
    affichageAgeIndividuParReference(ind3);
    cout << "\n";

    cout << "Adresse\n";
    affichageAgeIndividuParAdresse(&ind1);
    affichageAgeIndividuParAdresse(&ind2);
    affichageAgeIndividuParAdresse(&ind3);
    cout << "\n";

}
