/* Programme: tpCompositeV2incomplet.cpp

But: Programme incomplet à compléter. Ce programme efface l’écran et
crée un objet graphique composé d’autres objets graphiques en respectant
le Design Pattern ‘Composite’.
Ensuite, en 4 temps rythmés par la saisie d’un nouveau caractère par
l’utilisateur, affiche, efface, déplace et affiche l’objet graphique Composé.
Ces opérations sont à chaque fois déléguées (en cascade) aux objets qui
composent l’objet composé.

Date de création: /
Date de dernière modification: /
Auteur: P.Lopistéguy
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

using namespace std;

#define ESC '\033'
#define TRUE 1
#define FALSE 0

////////////////////////////// Terminal
class Terminal {
public:

	void clear () {
	  cout << ESC << "[H" << ESC << "[2J";
	};

	void charplot (int l, int c, char motif) {
	  cout << ESC << '[' << l << ';' << c << 'H' << motif;
	};

	void stringplot (int l, int c, string chaine) {
	  cout << ESC << '[' << l << ';' << c << 'H' << chaine;
	};
};


////////////////////////////// Graphique
class Graphique {
public :
	// operations à spécialiser selon l'objet composé / simple
	virtual void afficher (Terminal) { }; // affiche l’objet grahique
	virtual void effacer (Terminal) { };  // efface l’objet graphique
	virtual void deplacerDe (int, int) { }; // deplace l’objet graphique de dx,dy

	// méthodes permettant de gérer la composition
	virtual void ajouter (Graphique*) { }; // ajoute un composant
	virtual void supprimer (Graphique*) { }; // supprime un composant
	virtual Graphique* suisJeUneFeuille () {  return NULL;  }; // par défaut NON
protected:
	virtual void dessiner (bool, Terminal) {}; // implemente afficher et dessiner
};


////////////////////////////// GraphiqueSimple
class GraphiqueSimple : public Graphique {
public :
	void afficher (Terminal);
	void effacer (Terminal);
	virtual void deplacerDe (int, int) { };
};

void GraphiqueSimple::afficher (Terminal t) {
	dessiner (TRUE, t);
}

void GraphiqueSimple::effacer (Terminal t) {
	dessiner (FALSE, t);
}


////////////////////////////// Point
class Point : public GraphiqueSimple {
private :
	int x, y;   // coordonnees du point
	char motif; // motif a dessiner en x,y

public :
	Point (int, int, char); // constructeur
	void definir (int, int);// redefinition des coordonnees
	virtual void deplacerDe (int, int);
protected :
	void dessiner (bool, Terminal);
};

Point::Point (int a, int b, char c = 'o') {
	definir (a, b);
	motif = c;
}

void Point::definir (int a, int b) {
	x = a; y = b;
}

void Point::deplacerDe (int dx, int dy) {
	x += dx; y += dy;
}

void Point::dessiner (bool marquer, Terminal t) {
	t.charplot (x, y, marquer ? motif : ' ');
}

////////////////////////////// GraphiqueCompose
class GraphiqueCompose : public Graphique {
private : // membres gérant la composition
	int nbEnfants;			   // stocke la...
	Graphique* lesEnfants[10]; // ...compostion
public :
	GraphiqueCompose () { nbEnfants = 0; };
	virtual void ajouter (Graphique*);
	virtual void supprimer (Graphique*) { };
	virtual Graphique* jeSuisCompose () // spécialisée
        {  return this;  }; // retourne VRAI
public : // membres métier spécialisés
	virtual void afficher (Terminal);
	virtual void effacer (Terminal);
	virtual void deplacerDe (int, int);
};

void GraphiqueCompose::afficher (Terminal t) {
 for ( int i = 0; i< nbEnfants ; i++ )
 {
     lesEnfants[i]->afficher(t);
 }
}

void GraphiqueCompose::effacer (Terminal t) {
  for ( int i = 0; i< nbEnfants ; i++ )
 {
     lesEnfants[i]->effacer(t);
 }
}

void GraphiqueCompose::deplacerDe (int dx, int dy) {
 for ( int i =0; i < nbEnfants-1 ; i++ )
 {
     lesEnfants[i]->deplacerDe(dx,dy);
 }
}

void GraphiqueCompose::ajouter (Graphique* g) {
    if (nbEnfants < 10)
    {
        lesEnfants[nbEnfants] = g;
    	nbEnfants++;
    }

}


////////////////////////////// main tpCompositeV2incomplet
int main () {
	char c;
	Terminal t;
	Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);

	GraphiqueCompose gc;
	// initialiser l'objet "gc" en lui attribuant les 3 fils !
	gc.ajouter(&p1);
	gc.ajouter(&p2);
	gc.ajouter(&p3);

	t.clear ();

	t.stringplot (20, 1, "TP-V2 taper un car (affiche graphique compose) : ");
	cin >> c; gc.afficher (t);

	t.stringplot (20, 1, "TP-V2 taper un car (efface graphique compose)  : ");
	cin >> c; gc.effacer (t);

	t.stringplot (20, 1, "TP-V2 taper un car (deplace graphique compose) : ");
	cin >> c; gc.deplacerDe (-5, 10);

	t.stringplot (20, 1, "TP-V2 taper un car (affiche graphique compose) : ");
    cin >> c; gc.afficher (t);

	t.stringplot (20, 1, "T E R M I N E ...");

	return 0;
}
