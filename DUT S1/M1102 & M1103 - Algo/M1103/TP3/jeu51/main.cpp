#include <iostream>
#include "stdlib.h"
#include "jeuDeCartes.h"
#include "file.h"

using namespace std;

unsigned int pointsCarte (UneCarte c) ;
// retourne le nombre de points apportés par la carte c

void afficherTapis (UneFile& t);
// affiche les cartes du joueur, les plus anciennement arrivées à gauche
// les plus nouvellement rajoutées à droite


int main()
{
   // DICTIONNAIRE des ELEMENTS
   enum UneFinDuJeuDu51 {abandon, gagne, perduPlusDeCartes, perduPlusDe51 };

   UneFinDuJeuDu51 finDePartie;    /* indique la manière dont la partie se termine :
                                        - perdu pour cause de paquet épuisé (plus de cartes)
                                        - perdu car le score est > 51 points
                                        - perdu par abandon du joueur
                                        - gagné avec un score = 51 */

   unsigned int score ;    // score du joueur
   char choixJoueur ;      /* choix de l'action du joueur :  (a/A) abandon de la partie ;
                                                             (g/G) garder la carte de gauche
                                                             (r/R) retirer la carte de gauche */

   UneCarte  carteCourante ;  /* carte courante manipulée par le joueur :
                                    - soit piochée du paquet, et ajoutée à droite du tapis
                                    - soit retirée à gauche du tapis */

   UneFile tapis;              // cartes du joueur déposées sur le tapis

   // ACTIONS

   // Initialisation du jeu >> tapis, score (et un nouveau paquet de cartes)
    initialiser(tapis);
    score = 0;
    nouveauPaquet();

   // tapis, score >> Jouer >> finDePartie
   while (true)
      {
      /* tapis, score >> JOUER UN COUP >> finDePartie */


         // piocher une carte >>  carteCourante
         try
            {
               carteCourante = nouvelleCarte();
            }
         catch (string const& chaine)
            {
               finDePartie = perduPlusDeCartes;
               break;
            }

         // poser la carte sur le tapis
         enfiler(tapis, carteCourante);

         // carteCourante, score >> mise à jour du score >> score
         score += pointsCarte(carteCourante);

         // score, tapis >> afficher le jeu (tapis et score)>> (écran)
         afficherTapis(tapis);
         cout << endl << endl << endl << "    score = " << score << endl;

         // score >> Analyse du score >> finDePartie
         if (score > 51 )
         {
             finDePartie = perduPlusDe51;
             break;
         }
         else
         {
             if (score == 51)
             {
                 finDePartie = gagne;
                 break;
             }
         }

         // saisie-verif >> choixJoueur
         cout << endl << endl <<  "    <G>arder carte de gauche   <R>ejeter carte de gauche   <A>bandonner   : " ;
         cin >> choixJoueur;

         // choix >> traiter choix du joueur
         if (choixJoueur == 'A')
         {
             finDePartie = abandon;
             break;
         }
         else
         {
             if (choixJoueur == 'R')
             {
                 defiler(tapis, carteCourante);
                 score -= pointsCarte(carteCourante);
             }
         }

      }

   // finDePartie >> Terminer la partie >> --
   switch(finDePartie)
      {
      case abandon :
         cout << endl << endl  << "    perdu, par abandon " << endl << endl;
         break;
      case perduPlusDeCartes :
         cout << endl << endl  << "    perdu, plus de cartes dans le paquet " << endl << endl;
         break;
      case perduPlusDe51 :
         cout << endl << endl  << "    perdu, votre score  = " << score << " est > 51 points " << endl << endl;
         break;
      case gagne :
         cout << endl << endl  << "    bravo, gagne. Votre score = " << score << " points." << endl << endl;
         break;
      default :
         break;
      }

   return 0;
}


unsigned int pointsCarte (UneCarte c)
{
   if ((c.valeur == valet) || (c.valeur == roi) || (c.valeur==dame))
   {
       return 10;
   }
   else
   {
       return c.valeur;
   }
   return 0;
}


void afficherTapis (UneFile& t)
{
   UneCarte carteCourante;

   // effacer écran
   system("cls"); //  avec #include "stdlib.h" // system("clear"); pour Linux
   cout << endl << endl << endl << "    ";

   // affichage du contenu du tapis :
   unsigned int tailleT; // Taille de la fille t
   tailleT = taille(t);
   for (unsigned short int i = 0; i<= tailleT-1; i++)
   {
       defiler(t, carteCourante);
       afficheCarte(carteCourante);
       enfiler (t, carteCourante);
   }

   // mise en page à respecter : afficher toutes les cartes sur la même ligne, PAS de saut de ligne à la fin (ce sera fait dans le main)
}
