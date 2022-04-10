#include "Coordonnees.h"

Coordonnees::Coordonnees(){}

Coordonnees::Coordonnees(int x, int y, int z):m_x(x),m_y(y), m_z(z){}

Coordonnees::~Coordonnees(){}

int Coordonnees::get_x() const
{
    return m_x;
}

int Coordonnees::get_y() const
{
    return m_y;
}

int Coordonnees::get_z() const
{
    return m_z;
}

void Coordonnees::set_x(int val)
{
    m_x=val;
}

void Coordonnees::set_y(int val)
{
    m_y=val;
}

void Coordonnees::set_z(int val)
{
    m_z=val;
}
