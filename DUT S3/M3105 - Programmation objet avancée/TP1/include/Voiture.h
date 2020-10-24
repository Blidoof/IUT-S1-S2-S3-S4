#ifndef VOITURE_H
#define VOITURE_H

#include "Individu.h"

#include <iostream>

using namespace std;

class Individu;

class Voiture
{
    public:
        /** Default constructor */
        Voiture(string marque, string plaque);
        /** Default destructor */
        virtual ~Voiture();

        /** Access m_plaque
         * \return The current value of m_plaque
         */
        string Getplaque() { return m_plaque; }
        /** Set m_plaque
         * \param val New value to set
         */
        void Setplaque(string val) { m_plaque = val; }
        /** Access m_marque
         * \return The current value of m_marque
         */
        string Getmarque() { return m_marque; }
        /** Set m_marque
         * \param val New value to set
         */
        void Setmarque(string val) { m_marque = val; }

        string toString();

        string toStringAndLink();

        void setPilote (Individu* pilot);

        void maj_monPilote(Individu* pilot);

        void supprimerLien();

        Individu* getPilote();

    protected:

    private:
        string m_plaque; //!< Member variable "m_plaque"
        string m_marque; //!< Member variable "m_marque"
        Individu* monPilote;
};

#endif // VOITURE_H
