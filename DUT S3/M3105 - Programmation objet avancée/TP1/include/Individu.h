#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Voiture.h"
#include <iostream>

using namespace std;

class Voiture;

class Individu
{
    public:
        /** Default constructor */
        Individu(string nom, string prenom);
        /** Default destructor */
        ~Individu();

        /** Access m_nom
         * \return The current value of m_nom
         */
        string Getnom() { return m_nom; }
        /** Set m_nom
         * \param val New value to set
         */
        void Setnom(string val) { m_nom = val; }
        /** Access m_prenom
         * \return The current value of m_prenom
         */
        string Getprenom() { return m_prenom; }
        /** Set m_prenom
         * \param val New value to set
         */
        void Setprenom(string val) { m_prenom = val; }

        string toString();

        string toStringAndLink();

        void setVoiture(Voiture* voit);

        Voiture* getVoiture (){return this->maVoiture;};

        void maj_maVoiture(Voiture* voit);

        void supprimerLien();

    protected:

    private:

        string m_nom; //!< Member variable "m_nom"
        string m_prenom; //!< Member variable "m_prenom"

        Voiture* maVoiture;
};

#endif // INDIVIDU_H
