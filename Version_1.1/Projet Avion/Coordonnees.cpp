#include "Coordonnees.h"

Coordonnees::Coordonnees(){}

Coordonnees::Coordonnees(int x, int y):m_x(x),m_y(y){}

Coordonnees::~Coordonnees(){}

int Coordonnees::get_x() const
{
    return m_x;
}

int Coordonnees::get_y() const
{
    return m_y;
}
