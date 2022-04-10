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

void Coordonnees::set_x(int val)
{
    m_x=val;
}

void Coordonnees::set_y(int val)
{
    m_y=val;
}
