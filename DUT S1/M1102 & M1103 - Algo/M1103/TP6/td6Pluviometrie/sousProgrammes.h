#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>

using namespace std;

void calculMoyenneSimple (string nomSysFichierDonne);
/*
Soit un fichier texte de nombres entiers, éventuellement vide mais non corrompu, dont le nom système est fourni par le paramètre nomSysFichierDonne.
Affichage à l'écran de la moyenne des hauteurs pluviométriques contenues dans le fichier.
*/

void calculMoyenneOuArret (string nomSysFichierDonne);
/*
Soit un fichier texte de nombres entiers, éventuellement vide et possiblement corrompu, dont le nom système est fourni par le paramètre nomSysFichierDonne.
Le programme affiche à l'écran, lorsque le fichier est correct, le nombre de hauteurs pluviométriques contenues dans le fichier et, 
lorsque cela est possible, leur moyenne.
Lorsque le fichier est corrompu, le programme s'arrête après avoir affiché la raison du non calcul :
- la nature du PREMIER problème rencontré 
- et l'endroit dans le fichier (=rang de la valeur problématique) où il a été rencontré
*/


void calculMoyenneOuFichierLog (string nomSysFichierDonne);
/*
Etant donné un fichier texte de nombres entiers, éventuellement vide,
éventuellement corrompu, et dont le nom système est fourni en paramètre,
crée un fichier texte, dont le nom système sera fabriqué à partir du nom système du
fichier de relevés pluviométriques, contenant les informations sur le déroulement
du programme, à savoir :
Quand cela est possible, le nombre de hauteurs pluviométriques contenues dans le fichier donné ainsi que leur moyenne.
Quand cela n’est pas possible (fichier corrompu), le programme s'arrête après avoir inscrit dans le rapport la raison du non calcul :
- la nature du PREMIER problème rencontré 
- et l'endroit dans le fichier (=rang de la valeur problématique) où il a été rencontré
Le nom système du fichier créé est fabriqué par concaténation de la chaîne «rapportExecution_» suivie du nom système du fichier de données.

*/

#endif


