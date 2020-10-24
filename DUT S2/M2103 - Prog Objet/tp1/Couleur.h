#ifndef _COULEUR
#define _COULEUR

// Classe simple pour manipuler des couleurs
class Couleur {
private:
    int m_r,m_v,m_b;
public :
    // La construction sans paramètres donne du noir
    Couleur(int=0,int=0,int=0); // construction avec composantes RVB
    Couleur(const Couleur&); // construction de copie
    virtual ~Couleur(){}; // destructeur
    // la méthode suivante est utile pour les débutants qui n'utilisent pas
    // de paramètres de construction ou pour changer une couleur
    void definir(int,int,int); // changement des composantes RVB
    int rouge() const ; // retourne la composante rouge de la couleur
    int vert() const ; // retourne la composante verte de la couleur
    int bleu() const ; // retourne la composante bleue de la couleur
};
#endif

