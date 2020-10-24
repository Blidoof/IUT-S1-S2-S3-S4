/*
  Programme : Representation et manipulation de date
  But : Comparer 2 dates et indiquer si celles ci sont égales ou laquelle est la + grande.
  Date de dernière modification : 05/10/2018
  Auteur : A. MURILLO
  Remarques :
*/

#include <iostream>
using namespace std;


int main (void)
{
    //VARIABLES
    bool dateEgales; // L'indicateur de l"galité des deux dates.
    enum Mois {janvier = 1, fevrier, mars, avril, mai, juin, juillet, aout,septembre, octobre, novembre, decembre}; // janvier = 1, Car les mois vont de 1 à 12.
    struct Date
    {
        unsigned short int numJour; // le jour de la date, compris entre 0 et 31.
        Mois mois; //Le mois de la date
        short int numAnnee; // L'année de la date.
    };
    Date dateAncienne; // La date la plus ancienne des deux considérées.

    //Choix des dates
    Date date1; // Premiere date a comparer
    date1.numJour = 11;
    date1.mois = juillet;
    date1.numAnnee = 2000;

    Date date2; // Premiere date a comparer
    date2.numJour = 1;
    date2.mois = mars;
    date2.numAnnee = 1999;

    //TRAITEMENTS

    //Initialisation
    dateEgales = false;

    //Comparaison années
    if (date1.numAnnee > date2.numAnnee)
    {
        dateAncienne = date2;
    }
    else
    {
        if (date1.numAnnee < date2.numAnnee)
        {
            dateAncienne = date1;
        }
        else
        {
            //Comparaison mois
            if (date1.mois > date2.mois)
            {
                dateAncienne = date2;
            }
            else
            {


                if (date1.mois < date2.mois)
                {
                    dateAncienne = date1;
                }
                else
                {
                    //Comparaison jours
                    if (date1.numJour > date2.numJour)
                    {
                        dateAncienne = date2;
                    }
                    else
                    {

                        if (date1.numJour < date2.numJour)
                        {
                            dateAncienne = date1;
                        }
                        else
                        {
                            dateEgales = true;
                        }
                    }

                }
            }
        }
    }



    //Afficher résultat
    if (dateEgales == false)
    {
        cout <<"Les deux dates ne sont pas égales, la plus ancienne est :" << endl;

        //Afficher Jour
        cout << dateAncienne.numJour << "/";

        //Afficher mois
        switch (dateAncienne.mois)
        {
            case 1 : cout <<"Janvier"; break;
            case 2 : cout <<"Fevrier"; break;
            case 3 : cout <<"Mars"; break;
            case 4 : cout <<"Avril"; break;
            case 5 : cout <<"Mai"; break;
            case 6 : cout <<"Juin"; break;
            case 7 : cout <<"Juillet"; break;
            case 8 : cout <<"Aout"; break;
            case 9 : cout <<"Septembre"; break;
            case 10 : cout <<"Octobre"; break;
            case 11 : cout <<"Novembre"; break;
            case 12 : cout <<"Decembre"; break;
        }

        //Afficher année
        cout << "/" << dateAncienne.numAnnee << endl;
    }
    else
    {
        cout << "Les dates sont egales";
    }


    return 0;
}
