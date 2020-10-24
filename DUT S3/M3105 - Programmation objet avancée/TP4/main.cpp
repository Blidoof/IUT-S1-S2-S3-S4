#include <iostream>
#include <map>
#include "Produits.h"
#include <list>
#include <algorithm>
#include "Pieces.h"

using namespace std;

string referenceRecherchee = "47D";

bool estRefCherchee(Produits prod) {

    return (prod.Getreference() == referenceRecherchee ? true : false);

}

void afficher(Pieces* unePiece) {

    cout <<"[ref] " << unePiece->ref << " [libelle] " << unePiece->libelle << " [poids] " << unePiece->poids << " [prix] " << unePiece->prix << endl << endl;

}

void surPoids(Pieces* unePiece) {

    if (unePiece->poids > 80) {
        unePiece->prix = unePiece->prix *1.1;
    }

}

bool tropCestTrop(Pieces* unePiece) {

    return (unePiece->prix >= 100 ? true : false);

}

bool cMegaCher(Pieces* unePiece) {

    if (unePiece->prix >= 100)
    {
        cout <<"[ref] " << unePiece->ref << " [libelle] " << unePiece->libelle << " [poids] " << unePiece->poids << " [prix] " << unePiece->prix << endl << endl;
        return true;
    }
    else {
        return false;
    }

}


int main()
{
    /* Partie 1

    typedef string codeBarre;
    typedef string libelle;
    typedef double prix;

    typedef pair<libelle,prix> article;
    typedef map < codeBarre, article > mapProduitsCommercialise;

     mapProduitsCommercialise laMap;

     article p1("Roger Rabite", 4.7), p2("La cave aux merveilles", 78), p3("Les boules de Roger", 52.4);

     string code1("47A"),code2("70B"),code3("29C");

     laMap.insert(mapProduitsCommercialise::value_type(code1, p1));
     laMap.insert(mapProduitsCommercialise::value_type(code2, p2));
     laMap.insert(mapProduitsCommercialise::value_type(code3, p3));

     mapProduitsCommercialise::iterator monIterateur;

     monIterateur = laMap.find("47B");

     if (monIterateur != laMap.end())
     {
         cout << "[code] " << monIterateur->first << " [libelle] " << monIterateur->second.first << " [prix] " << monIterateur->second.second;
     }
     else {
        cout << "Echec de recherche";
     }
     */

     /* Partie 2

     typedef list<Produits> lProd;

     lProd laListe;

     Produits p("47A", "Roger rabite", 4.7);

     laListe.push_back(lProd::value_type("47A", "Roger rabite", 4.7));
     laListe.push_back(lProd::value_type("70B", "La cave aux merveilles", 78));
     laListe.push_back(lProd::value_type("29C", "Les boules de Roger", 52.4));

     lProd::iterator result = find_if(laListe.begin(), laListe.end(),estRefCherchee);

     if (result != laListe.end())
     {
         cout << "[code] " << result->Getreference() << " [libelle] " << result->Getlibelle() << " [prix] " << result->Getprix();
     }
     else {
        cout << "Echec de recherche";
     }
     */

     Pieces p1("47A", "Roger rabite", 0.5, 100);
     Pieces p2("70B", "La cave aux merveilles", 1, 78);
     Pieces p3("29C", "Les boules de Roger", 81, 100);
     Pieces p4("63D", "Casquette MAGA", 0.2, 12);

     typedef list<Pieces*> listeP;
     listeP leShop;

     leShop.push_back(listeP::value_type(&p1));
     leShop.push_back(listeP::value_type(&p2));
     leShop.push_back(listeP::value_type(&p3));
     leShop.push_back(listeP::value_type(&p4));


     //Q6
     //for_each(leShop.begin(), leShop.end(), surPoids); //FONCTIONNE !!!


     //Q7
     //partition(leShop.begin(), leShop.end(), tropCestTrop); //FONCTIONNE !!!


     //Q8
     //for_each(leShop.begin(), leShop.end(), cMegaCher); //FONCTIONNE !!!

     listeP::iterator monIterateur;

     monIterateur = leShop.begin();

     while (monIterateur != leShop.end())
     {
         afficher(*monIterateur);
         monIterateur++;
     }



}
