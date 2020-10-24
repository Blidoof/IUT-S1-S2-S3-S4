#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>

using namespace std;

void calculMoyenneSimple (string nomSysFichierDonne);
/*
Soit un fichier texte de nombres entiers, �ventuellement vide mais non corrompu, dont le nom syst�me est fourni par le param�tre nomSysFichierDonne.
Affichage � l'�cran de la moyenne des hauteurs pluviom�triques contenues dans le fichier.
*/

void calculMoyenneOuArret (string nomSysFichierDonne);
/*
Soit un fichier texte de nombres entiers, �ventuellement vide et possiblement corrompu, dont le nom syst�me est fourni par le param�tre nomSysFichierDonne.
Le programme affiche � l'�cran, lorsque le fichier est correct, le nombre de hauteurs pluviom�triques contenues dans le fichier et, 
lorsque cela est possible, leur moyenne.
Lorsque le fichier est corrompu, le programme s'arr�te apr�s avoir affich� la raison du non calcul :
- la nature du PREMIER probl�me rencontr� 
- et l'endroit dans le fichier (=rang de la valeur probl�matique) o� il a �t� rencontr�
*/


void calculMoyenneOuFichierLog (string nomSysFichierDonne);
/*
Etant donn� un fichier texte de nombres entiers, �ventuellement vide,
�ventuellement corrompu, et dont le nom syst�me est fourni en param�tre,
cr�e un fichier texte, dont le nom syst�me sera fabriqu� � partir du nom syst�me du
fichier de relev�s pluviom�triques, contenant les informations sur le d�roulement
du programme, � savoir :
Quand cela est possible, le nombre de hauteurs pluviom�triques contenues dans le fichier donn� ainsi que leur moyenne.
Quand cela n�est pas possible (fichier corrompu), le programme s'arr�te apr�s avoir inscrit dans le rapport la raison du non calcul :
- la nature du PREMIER probl�me rencontr� 
- et l'endroit dans le fichier (=rang de la valeur probl�matique) o� il a �t� rencontr�
Le nom syst�me du fichier cr�� est fabriqu� par concat�nation de la cha�ne �rapportExecution_� suivie du nom syst�me du fichier de donn�es.

*/

#endif


