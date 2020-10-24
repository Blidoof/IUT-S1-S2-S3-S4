#ifndef M3202_H
#define M3202_H

#include "Fenetre.h"
#include <iostream>
#include <iomanip>
#include <vector> 
using namespace std;


// Classe pour manipuler des matrices contenant des valeurs réelles.
// Matrice m(2,3,0) : déclaration d'une matrice m à 2 lignes, 3 colonnes,
//                    dont les cases sont initialisées par des 0
// m(1,1) : première case de la matrice m
// m(lig,col) : case sur la ligne lig et la colonne col
// m(m.nbLignes(), m.nbColonnes()) : dernière case de la matrice m
// cout << m : écrit le contenu de la matrice m dans la console
class Matrice{
  friend ostream& operator<< (ostream& , const Matrice& );
 public:
  Matrice (int=3, int=3, double = 0.0);
  Matrice(const Matrice&);
  Matrice& operator=(const Matrice&);
  double& operator()(int, int);
  const double& operator()(int, int) const;
  int nbLignes() const;
  int nbColonnes() const;
  
 private :
  vector<vector <double> > m_grille;
};


// Classe pour manipuler des points dans le plan 
// Point p(50,100) : déclare un point p aux coordonnées (50,100)
// p = p2 : recopie le point p2 dans le point p
// p.x() et p.y() : permettent de connaitre les coordonnées du point p
class Point{
 public:
  Point(int=0, int=0);
  Point (const Point&);
  Point& operator=(const Point&);
  int x() const;
  int y() const;


 private:
  int m_x, m_y;
};


// Classe pour manipuler des polygones : une suite ordonnée de points,
// une fois dans le polygone, les points sont manipulés via leurs indices
// qui démarrent à zéro.
// Polygone poly : déclare un polygone poly
// poly.ajouter (Point(x,y)) : ajoute un point en dernière position dans le polygone 
// poly.dessiner(f, coul) : dessine le polygone dans la fenètre f avec la couleur coul
// poly[0] : premier point du polygone
// poly[poly.nbPoints()-1] : dernier point du polygone
class Polygone{
public:
  Polygone();
  Polygone(const Polygone&);
  void ajouter(Point);
  Polygone& operator=(const Polygone&);
  Point& operator[](int);
  const Point& operator[](int) const;
  void dessiner(Fenetre&, Couleur = Couleur()) const ;
  int nbPoints() const;

private :
  vector <Point> m_points;

};

#endif
