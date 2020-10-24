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

    int portDistant = atoi(argv[2]); // Port auquel se connecter

    int portLocal = 0; // Port auquel se connecter

    int sock; // Le socket

    struct sockaddr_in adresseLocale; // L'adresse locale

    struct sockaddr_in adresseDistante; // L'adresse à contacter

    //char adresseD[50] = "10.3.224.215";


//TRAITEMENTS

    //Init

        //creation
        sock = socket(AF_INET, SOCK_STREAM, 0);

        //Attachement

        memset((char*) &adresseLocale, '\0', sizeof(struct sockaddr_in));

        adresseLocale.sin_family = AF_INET; //Redef famille ip

        adresseLocale.sin_addr.s_addr = htonl(INADDR_ANY);  // remplissage adr ip

        adresseLocale.sin_port = htons(portLocal); //Définition du port

        bind (sock, (struct sockaddr*) &adresseLocale, sizeof(struct sockaddr));

        //Demande connexion

        memset((char*) &adresseDistante, '\0', sizeof(struct sockaddr_in));

        adresseDistante.sin_family = AF_INET; //Redef famille ip

        adresseDistante.sin_addr.s_addr = inet_addr(argv[1]);  // remplissage adr ip

        adresseDistante.sin_port = htons(portDistant); //Définition du port


        connect(sock, (struct sockaddr*) &adresseDistante, sizeof(struct sockaddr));


    //Dialogue

    do{

        //nvite de saisie

        printf("Valeur ?\n");

        //printf(argv[1]);

        //saisie nombre

        scanf(" %s", requete);

        //envoi

        send(sock, (void*)requete, strlen(requete)+1, 0);

        //Reception

        recv(sock, (void*)reponse, sizeof(reponse), 0);


    }
    while (strcmp(reponse, "OK") ==0);

    //Fin

        //Affichage résultat
        printf("La moyenne est : ");
        printf(reponse);
        printf("\n");


        //déconnexion
        close(sock);

    return 0;
}
