#include "coord.hpp"

Coord::Coord()
{

}

Coord::Coord(float x, float y)
{
	m_x = x;
	m_y = y;
}

Coord::~Coord()
{

}

void Coord::set(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Coord::setX(float x)
{
	m_x = x;
}

void Coord::setY(float y)
{
	m_y = y;
}

float Coord::x()
{
	return m_x;
}

float Coord::y()
{
	return m_y;
}
