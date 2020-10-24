/*
Programme: tpCompositeV1.cpp

But: Efface l'écran, puis affiche 3 points, chacun apres la saisie
d'un nouveau caractere par l'utilisateur.

Date de création: /
Date de dernière modification: /
Auteur: P.Lopistéguy
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define ESC '\033'
#define TRUE 1
#define FALSE 0

#define abs(i) (i < 0 ? -i : i)

using namespace std;

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

////////////////////////////// GraphiqueSimple
class GraphiqueSimple {
public :
	void afficher (Terminal);
	void effacer (Terminal);
protected:
	virtual void dessiner (bool, Terminal) {};
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
	int x, y;
public :
	Point (int, int, char);
	void definir (int, int);
protected :
	char motif;
	void dessiner (bool, Terminal);
};

Point::Point (int a, int b, char c = 'o') {
	definir (a, b);
	motif = c;
}

void Point::definir (int a, int b) {
	x = a; y = b;
}

void Point::dessiner (bool marquer, Terminal t) {
	t.charplot (x, y, marquer ? motif : ' ');
//	if (marquer)
//		t.charplot (x, y, motif);
//	else	t.charplot (x, y, ' ');
}

class Ligne : public GraphiqueSimple {
private :
    int xo, yo;
    int xa, ya;
    int longueur;
    char motif;
public :
    Ligne(int xorr, int yorr, int xarr, int yarr, char s) {definir(xorr,yorr,xarr,yarr); motif = s;};
    void definir (int a, int b, int c, int d) {xo = a; yo = b; xa = c; ya =d;};
protected :

    void dessiner (bool, Terminal);
};

void Ligne::dessiner(bool marquer, Terminal t) {
/* PREMEIR ESSAI
    if (yo == ya)
    {
        string chaineTmp = "";

        longueur = abs(xa-xo);

        for (int i = 0; i < longueur ; i++ )
        {
            chaineTmp = chaineTmp + motif;
        }

        if(xa < xo) {
            t.stringplot(xo-xa,yo-ya, marquer ? chaineTmp : " ");
        }
        else if (xa > xo) {
            t.stringplot(xo,yo, marquer ? chaineTmp : " ");
        }

    }
    else if (xo == xa)
    {
        string chaineTmp = "";
        longueur = abs(ya-yo);

        int xtemp = xo;
        int ytemp = yo;

        for (int i = 0; i < longueur ; i++ )
        {

            t.charplot(xtemp,ytemp, marquer ? motif : ' ');
            xtemp++;
        }
    }
    else
    {

    }

*/
    int dx, dy; //Distances
    int sensX, sensY;
    float pasX; //Pas entre abscices
    float pasY; //Pas entre ordonnées
    int nbPas;

    //Distances
    dx = xa - xo;
    dy = ya - yo;

    //Sens
    sensX = (dx >= 0 ? 1 : -1);
    sensY = (dy >= 0 ? 1 : -1);

    //Pas
    if (abs(dx) > abs(dy))
    {
        nbPas = abs(dx);
        pasX = 1.0 * sensX;
        pasY = float(dy) / float(dx) * sensY;
    }
    else
    {
        nbPas = abs(dy);
        pasY = 1.0 * sensY;
        pasX = float(dx) / float(dy) * sensX;
    }

    //Calculer et dessiner points

    for (int i = 0; i<= nbPas ; i++ )
    {
        int x = xo + int (i * pasX + 0.5);
        int y = yo + int (i * pasY + 0.5);
        t.charplot(x,y,motif);
    }
}

/////////////////////CLASSE RECTANGLE A IMPLEMENTER


////////////////////////////// main tpCompositeV1
int main () {
	Terminal t;
	char c;
	Point p1 (6, 10, '*'), p2 (6, 20, '#'), p3 (10, 15);
	Ligne l1 (4, 7, 20, 20, '@');

	t.clear ();
	t.stringplot (20, 1, "TP-V1 taper un car (affiche point p1) : ");
	cin >> c; p1.afficher (t);

	t.stringplot (20, 1, "TP-V1 taper un car (affiche point p2) : ");
	cin >> c; p2.afficher (t);

	t.stringplot (20, 1, "TP-V1 taper un car (affiche point p3) : ");
	cin >> c; p3.afficher (t);

	t.stringplot (20, 1, "TP-V1 taper un car (affiche ligne l1) : ");
	cin >> c; l1.afficher (t);

	t.stringplot (20, 1, "T E R M I N E ...");

	return 0;
}

