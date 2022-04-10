#ifndef COORDONNEES_H_INCLUDED
#define COORDONNEES_H_INCLUDED
#include <allegro.h>
#include <winalleg.h>

class Coordonnees
{
    private:
        int m_x;
        int m_y;
    public:
        Coordonnees();
        Coordonnees(int x, int y);
        ~Coordonnees();
        int get_x()const;
        int get_y()const;
        void set_x(int val);
        void set_y(int val);
};

#endif // COORDONNEES_H_INCLUDED
