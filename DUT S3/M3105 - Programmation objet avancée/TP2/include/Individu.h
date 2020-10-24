#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Outils.h"
#include <iostream>
using namespace std;

class Outils;

class Individu
{
    public:
        /** Default constructor */
        Individu(string n, string p, int a);
        /** Default destructor */
        virtual ~Individu();

        /** Access nom
         * \return The current value of nom
         */
        string Getnom() { return nom; }
        /** Set nom
         * \param val New value to set
         */
        void Setnom(string val) { nom = val; }
        /** Access prenom
         * \return The current value of prenom
         */
        string Getprenom() { return prenom; }
        /** Set prenom
         * \param val New value to set
         */
        void Setprenom(string val) { prenom = val; }
        /** Access anneeNaissance
         * \return The current value of anneeNaissance
         */
        int GetanneeNaissance() { return anneeNaissance; }
        /** Set anneeNaissance
         * \param val New value to set
         */
        void SetanneeNaissance(int val) { anneeNaissance = val; }
        /** Access o
         * \return The current value of o
         */
        Outils* Geto() { return o; }
        /** Set o
         * \param val New value to set
         */
        void Seto(Outils* val) { o = val; }

        virtual int get_age();

    protected:

    private:
        string nom; //!< Member variable "nom"
        string prenom; //!< Member variable "prenom"
        int anneeNaissance; //!< Member variable "anneeNaissance"
        Outils* o; //!< Member variable "o"
};

#endif // INDIVIDU_H
