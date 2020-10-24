#ifndef SINGLETONDIRECTEURIUT_H
#define SINGLETONDIRECTEURIUT_H

#include <iostream>
using namespace std;

class SingletonDirecteurIut
{
    public:

        string Getnom() { return nom; }

        void Setnom(string val) { nom = val; }

        string Getprenom() { return prenom; }

        void Setprenom(string val) { prenom = val; }

        static SingletonDirecteurIut* get_instance();

        static void kill_instance();

    protected:

    private:

        /** Default constructor */
        SingletonDirecteurIut();
        /** Default destructor */
        virtual ~SingletonDirecteurIut();
        static string nom; //!< Member variable "nom"
        static string prenom; //!< Member variable "prenom"
        static SingletonDirecteurIut* _instance; //!< Member variable "_instance"
};

#endif // SINGLETONDIRECTEURIUT_H
