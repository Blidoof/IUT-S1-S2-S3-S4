#ifndef PIECES_H
#define PIECES_H
#include <iostream>
using namespace std;

class Pieces
{
    public:
        Pieces(string refe ="", string libel ="", double pds =0, int flouze =0);
        virtual ~Pieces();

        string ref;
        string libelle;
        double poids;
        int prix;

    protected:

    private:
};

#endif // PIECES_H
