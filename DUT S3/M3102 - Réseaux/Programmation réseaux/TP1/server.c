#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
//VARIABLES

    char requete[150]; // La requete envoyée au serveur

    char reponse[150]; // La réponse recue du serveur

    int portLocal = 10501; // Port auquel les machines vont se connecter

    int sockService; // Le socket de service

    int sockEcoute; //Le socket d'attente

    struct sockaddr_in adresseLocale; // L'adresse locale

    struct sockaddr_in adresseDistante; // L'adresse à contacter

    char adresseL[50] = "10.3.224.215";

    double moyenne;

    int quotient;

    int somme;






//TRAITEMENTS

    //Init

    //creation

    sockEcoute = socket(AF_INET, SOCK_STREAM, 0);

    //Attachement

    memset((char*) &adresseLocale, '\0', sizeof(struct sockaddr_in));

    memset((char*) &adresseDistante, '\0', sizeof(struct sockaddr_in));


    adresseLocale.sin_family = AF_INET; //Redef famille ip

    adresseLocale.sin_addr.s_addr = inet_addr(adresseL);  // remplissage adr ip

    adresseLocale.sin_port = htons(portLocal); //Définition du port



    bind (sockEcoute, (struct sockaddr*) &adresseLocale, sizeof(struct sockaddr));

    //Mise à l'écoute

    listen(sockEcoute, 3);

    //Boucle de fonctionnement
    while (1)
    {

    printf("oui !");
        int c = sizeof(struct sockaddr);
        sockService = accept(sockEcoute, (struct sockaddr*)&adresseDistante, (socklen_t*)&c);

        sprintf(reponse, "%s", "OK");

        do
        {

            recv(sockService, (void*)requete, sizeof(reponse)+1, 0);

            //utiliser moyenne

            int chiffreEnvoye = atoi(requete);

            if (chiffreEnvoye > 0)
            {
                somme = somme + chiffreEnvoye;
                quotient++;
            }
            else
            {
                if (chiffreEnvoye == 0)
                {
                    quotient++;
                }
                else
                {

                    if (chiffreEnvoye < 0)
                    {

                        moyenne = (double)somme / (double)quotient;

                        sprintf(reponse, "%f", moyenne);

                    }
                }
            }

            //Répondré
            send(sockService, (void*)reponse, sizeof(reponse), 0);
        }
        while (strcmp(reponse, "OK") == 0);

        shutdown(sockService, 2);

        close(sockService);
    }

    return 0;
}

