#include "triangle.hpp"

Triangle::Triangle()
{

}

Triangle::Triangle(Coord apex1, Coord apex2, Coord apex3, Color color)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color;
	m_color[1] = color;
	m_color[2] = color;
}

Triangle::Triangle(Coord apex1, Coord apex2, Coord apex3, Color color1, Color color2, Color color3)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_color[0] = color1;
	m_color[1] = color2;
	m_color[2] = color3;
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