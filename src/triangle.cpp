#include "triangle.hpp"

Triangle::Triangle()
{
	m_prev = NULL;
	m_next = NULL;
}

Triangle::Triangle(Coord apex1, Coord apex2, Coord apex3, Color color)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color;
	m_color[1] = color;
	m_color[2] = color;

	m_prev = NULL;
	m_next = NULL;
}

Triangle::Triangle(Coord apex1, Coord apex2, Coord apex3, Color color1, Color color2, Color color3)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color1;
	m_color[1] = color2;
	m_color[2] = color3;

	m_prev = NULL;
	m_next = NULL;
}

Triangle::~Triangle()
{

}

void Triangle::set(Coord apex1, Coord apex2, Coord apex3, Color color)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color;
	m_color[1] = color;
	m_color[2] = color;
}

void Triangle::set(Coord apex1, Coord apex2, Coord apex3, Color color1, Color color2, Color color3)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color1;
	m_color[1] = color2;
	m_color[2] = color3;
}

void Triangle::draw()
{
	for (int i = 0; i < 3; ++i)
	{
		glColor3ub(m_color[i].r(), m_color[i].g(), m_color[i].b());
		glVertex2d((m_apex[i].x() / 100) * 2 - 1, ((100 - m_apex[i].y()) / 100) * 2 - 1);
	}
}

void Triangle::translate(Coord a)
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		m_apex[i] = m_apex[i] + a;
	}
}

void Triangle::translate(double x, double y)
{
	Coord a(x, y);

	int i;
	for (i = 0; i < 3; ++i)
	{
		m_apex[i] = m_apex[i] + a;
	}
}

void Triangle::setNext(Triangle *t)
{
	m_next = t;
}

void Triangle::setPrev(Triangle *t)
{
	m_prev = t;
}

Triangle* Triangle::getNext()
{
	return m_next;
}

Triangle* Triangle::getPrev()
{
	return m_prev;
}
