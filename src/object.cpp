#include "object.hpp"

#include <iostream>
using namespace std;

Object::Object()
{
	m_first = NULL;
	m_last = NULL;

	m_next = NULL;
	m_prev = NULL;

	m_pos = Vector(0, 0);
	m_size = Vector(100, 100);
}

Object::Object(Vector pos, Vector size)
{
	m_first = NULL;
	m_last = NULL;

	m_next = NULL;
	m_prev = NULL;

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
		}

		cur = cur->getNext();
	}
}

void Object::set(Vector pos, Vector size)
{
	m_pos = pos;
	m_size = size;
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

		if (cur->isDynAlloc())
		{
			delete t;
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

void Object::draw(Vector pos, Vector size)
{
	Vector realPos, realSize;

	realPos = pos + m_pos * (size / 100);
	realSize = (size / 100) * m_size;

	if (m_first != NULL && m_last != NULL)
	{
		Triangle *cur = m_first;

		while (cur != NULL)
		{
			cur->draw(realPos, realSize);
			cur = cur->getNext();
		}
	}
}

void Object::rotate(Vector axis, float angle)
{
	if (m_first != NULL && m_last != NULL)
	{
		Triangle *cur = m_first;

		while (cur != NULL)
		{
			cur->rotate(axis, angle);
			cur = cur->getNext();
		}
	}
}

void Object::resetPos()
{
	if (m_first != NULL && m_last != NULL)
	{
		Triangle *cur = m_first;

		while (cur != NULL)
		{
			cur->resetPos();
			cur = cur->getNext();
		}
	}
}

void Object::copy(Object &obj)
{
	this->set(obj.getPos(), obj.getSize());
	Triangle *first = obj.getFirst();

	if (first != NULL)
	{
		Triangle *cur = first;

		while (cur != NULL)
		{
			this->create(*cur);
			cur = cur->getNext();
		}
	}
}

Vector Object::getPos()
{
	return m_pos;
}

Vector Object::getSize()
{
	return m_size;
}

Triangle *Object::getFirst()
{
	return m_first;
}

void Object::changeColor(Color c)
{
	if (m_first != NULL && m_last != NULL)
	{
		Triangle *cur = m_first;

		while (cur != NULL)
		{
			cur->changeColor(c);
			cur = cur->getNext();
		}
	}
}

void Object::setNext(Object *t)
{
	m_next = t;
}

void Object::setPrev(Object *t)
{
	m_prev = t;
}

Object* Object::getNext()
{
	return m_next;
}

Object* Object::getPrev()
{
	return m_prev;
}
