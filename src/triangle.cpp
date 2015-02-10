#include "triangle.hpp"

Triangle::Triangle()
{
	m_dynAlloc = false;

	m_prev = NULL;
	m_next = NULL;
}

Triangle::Triangle(Vector apex1, Vector apex2, Vector apex3, Color color)
{
	m_dynAlloc = false;

	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_origApex[0] = apex1;
	m_origApex[1] = apex2;
	m_origApex[2] = apex3;
	m_color[0] = color;
	m_color[1] = color;
	m_color[2] = color;

	m_prev = NULL;
	m_next = NULL;
}

Triangle::Triangle(Vector apex1, Vector apex2, Vector apex3, Color color1, Color color2, Color color3)
{
	m_dynAlloc = false;

	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_origApex[0] = apex1;
	m_origApex[1] = apex2;
	m_origApex[2] = apex3;
	m_color[0] = color1;
	m_color[1] = color2;
	m_color[2] = color3;

	m_prev = NULL;
	m_next = NULL;
}

Triangle::~Triangle()
{

}

void Triangle::set(Vector apex1, Vector apex2, Vector apex3, Color color)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_origApex[0] = apex1;
	m_origApex[1] = apex2;
	m_origApex[2] = apex3;
	m_color[0] = color;
	m_color[1] = color;
	m_color[2] = color;
}

void Triangle::set(Vector apex1, Vector apex2, Vector apex3, Color color1, Color color2, Color color3)
{
	m_apex[0] = apex1;
	m_apex[1] = apex2;
	m_apex[2] = apex3;
	m_origApex[0] = apex1;
	m_origApex[1] = apex2;
	m_origApex[2] = apex3;
	m_color[0] = color1;
	m_color[1] = color2;
	m_color[2] = color3;
}

void Triangle::dynAlloc()
{
	m_dynAlloc = true;
}

bool Triangle::isDynAlloc()
{
	return m_dynAlloc;
}

void Triangle::draw()
{
	for (int i = 0; i < 3; ++i)
	{
		glColor3ub(m_color[i].r, m_color[i].g, m_color[i].b);
		glVertex2d((m_apex[i].x / 100) * 2 - 1, ((100 - m_apex[i].y) / 100) * 2 - 1);
	}
}

void Triangle::draw(Vector pos, Vector size)
{
	Vector newPos;

	for (int i = 0; i < 3; ++i)
	{
		newPos = pos + size * (m_apex[i] / 100);

		glColor3ub(m_color[i].r, m_color[i].g, m_color[i].b);
		glVertex2d((newPos.x / 100) * 2 - 1, ((100 - newPos.y) / 100) * 2 - 1);
	}
}

void Triangle::translate(Vector a)
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		m_apex[i] = m_apex[i] + a;
	}
}

void Triangle::translate(double x, double y)
{
	Vector a(x, y);

	int i;
	for (i = 0; i < 3; ++i)
	{
		m_apex[i] = m_apex[i] + a;
	}
}

void Triangle::rotate(Vector axis, float angle)
{
	int i;

	float dist[3];
	float origAngle[3];

	for (i = 0; i < 3; ++i)
	{
		dist[i] = sqrt( pow((axis.x - m_apex[i].x), 2) + pow((axis.y - m_apex[i].y), 2) );
		
		if (dist[i] != 0)
		{
			origAngle[i] = acos( (m_apex[i].x - axis.x) / dist[i] ) / (M_PI / 180);
			if (m_apex[i].y > axis.y)
				origAngle[i] = -origAngle[i];
			origAngle[i] = -origAngle[i];

			m_apex[i].x = cos((origAngle[i] + angle) * M_PI / 180) * dist[i] + axis.x;
			m_apex[i].y = sin((origAngle[i] + angle) * M_PI / 180) * dist[i] + axis.y;
		}
	}
}

void Triangle::resetPos()
{
	for (int i = 0; i < 3; ++i)
	{
		m_apex[i] = m_origApex[i];
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
