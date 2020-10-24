#ifndef INDIVIDUMENTEUR_H
#define INDIVIDUMENTEUR_H

#include <Individu.h>


class IndividuMenteur : public Individu
{
    public:
        /** Default constructor */
        IndividuMenteur(string n, string p, int a);
        /** Default destructor */
        virtual ~IndividuMenteur();

        virtual int get_age();

    protected:

    private:
};

#endif // INDIVIDUMENTEUR_H
