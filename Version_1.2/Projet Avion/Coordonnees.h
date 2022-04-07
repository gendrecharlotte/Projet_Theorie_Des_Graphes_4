#ifndef COORDONNEES_H_INCLUDED
#define COORDONNEES_H_INCLUDED

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
};

#endif // COORDONNEES_H_INCLUDED
