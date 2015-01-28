#include "object.hpp"

#include <iostream>
using namespace std;

Object::Object()
{
	m_first = NULL;
	m_last = NULL;

	m_pos = Vector2(0, 0);
	m_size = Vector2(100, 100);
}

Object::Object(Vector2 pos, Vector2 size)
{
	m_first = NULL;
	m_last = NULL;

	m_pos = pos;
	m_size = size;
}

Object::~Object()
{
	Triangle *cur = m_first;
	Triangle *last;

	while (cur != NULL)
	{
		last = cur;
		if (last->isDynAlloc())
		{
			delete last;
			cout << "Deleted " << last << endl;
		}

		cur = cur->getNext();
	}
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

Triangle* Object::create(Triangle t)
{
	Triangle *temp = new Triangle();
	*temp = t;
	temp->dynAlloc();
	this->add(temp);

	return temp;
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
			cur->draw(m_pos, m_size);
			cur = cur->getNext();
		}
	}
}