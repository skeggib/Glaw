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

void Object::rem(Triangle *t)
{
	if (m_first != NULL)
	{
		Triangle *cur = m_first;
		Triangle *prev = NULL;

		while (cur != t && cur != NULL)
		{
			prev = cur;
			cur = cur->getNext();
		}

		if (cur != NULL && prev != NULL)
		{
			prev->setNext(cur->getNext());
		}

		else if (cur != NULL && prev == NULL)
		{
			m_first = cur->getNext();
		}
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