#include "object.hpp"

#include <iostream>
using namespace std;

Object::Object()
{
	m_first = NULL;
	m_last = NULL;
}

Object::~Object()
{

}

void Object::add(Triangle *t)
{
	if (m_first == NULL)
	{
		m_first = t;
		m_last = t;
	}

	else
	{
		m_last->setNext(t);
		Triangle *cur = m_last;

		while (cur->getNext() != NULL)
		{
			cur = cur->getNext();
		}

		m_last = cur;
	}
}

void Object::draw()
{
	if (m_first != NULL && m_last != NULL)
	{
		Triangle *cur = m_first;

		while (cur != NULL)
		{
			cur->draw();
			cur = cur->getNext();
		}
	}
}