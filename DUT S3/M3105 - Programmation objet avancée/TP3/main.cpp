#include <iostream>
#include<list>
#include <map>

using namespace std;

void listeSimple()
{
    typedef list<string> listeS;
    listeS uneListeS;

    uneListeS.push_back("Pantxika");
    uneListeS.push_back("Patrick");
    uneListeS.push_back("Philippe");
    uneListeS.push_back("Yann");

    listeS::iterator monIterateur;

    monIterateur = uneListeS.begin();

    while (monIterateur != uneListeS.end())
    {
        cout << *monIterateur << endl;
        monIterateur++;
    }

}

void listePaires() {

    typedef list< pair<string,string> > listeP;
    listeP uneListeP;

    uneListeP.push_back(listeP::value_type("Pantxika", "06.01.01.01.01"));
    uneListeP.push_back(listeP::value_type("Patrick", "06.02.02.02.02"));
    uneListeP.push_back(listeP::value_type("Philippe", "06.03.03.03.03"));
    uneListeP.push_back(listeP::value_type("Yann", "06.04.04.04.04"));

    listeP::iterator monIterateur;

    monIterateur = uneListeP.begin();

    while (monIterateur != uneListeP.end())
    {
        cout << monIterateur->first << " " <<  monIterateur->second << endl;
        monIterateur++;
    }

}

void leMap() {

    typedef map<string,string> annuaire;
    annuaire unAnnuraire;

    unAnnuraire.insert(annuaire::value_type("Patrick", "06.01.01.01.01"));
    unAnnuraire.insert(annuaire::value_type("Pantxika", "06.02.02.02.02"));
    unAnnuraire.insert(annuaire::value_type("Philippe", "06.03.03.03.03"));
    unAnnuraire.insert(annuaire::value_type("Yann", "06.04.04.04.04"));

    annuaire::iterator monIterateur;

    monIterateur = unAnnuraire.begin();

    while (monIterateur != unAnnuraire.end())
    {
        cout << monIterateur->second << endl;
        monIterateur++;
    }

    monIterateur = unAnnuraire.find("Philippe");

    cout << monIterateur->second;
}

int main()
{
    leMap();
}
