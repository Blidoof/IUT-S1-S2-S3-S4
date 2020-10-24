#ifndef PRODUITS_H
#define PRODUITS_H
#include <iostream>
using namespace std;

class Produits
{
    public:
        Produits(string laRef, string lib, double prix);
        virtual ~Produits();

        string Getlibelle() { return libelle; }
        void Setlibelle(string val) { libelle = val; }
        string Getreference() { return reference; }
        void Setreference(string val) { reference = val; }
        double Getprix() { return prix; }
        void Setprix(double val) { prix = val; }

    protected:

    private:
        string libelle;
        string reference;
        double prix;
};

#endif // PRODUITS_H
