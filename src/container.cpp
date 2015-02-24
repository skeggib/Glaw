#include "container.hpp"

Container::Container()
{
	m_firstObject = NULL;
	m_lastObject = NULL;

	m_pos = Vector(0, 0);
	m_size = Vector(100, 100);
}

Container::Container(Vector pos, Vector size)
{
	m_firstObject = NULL;
	m_lastObject = NULL;

	m_pos = pos;
	m_size = size;
}

Container::~Container()
{

}

void Container::set(Vector pos, Vector size)
{
	m_pos = pos;
	m_size = size;
}

void Container::add(Object *obj)
{
	// If the chain list is empty
	if (m_firstObject == NULL)
	{
		m_firstObject = obj;
		
		if (obj->getNext() == NULL)
			m_lastObject = obj;
		else
		{
			Object *cur = obj->getNext();
			while (cur->getNext() != NULL)
			{
				cur = cur->getNext();
			}

			m_lastObject = cur;
		}
	}

	else
	{
		m_lastObject->setNext(obj);
		Object *cur = m_lastObject;

		while (cur->getNext() != NULL)
		{
			cur = cur->getNext();
		}

		m_lastObject = cur;
	}
}

void Container::rem(Object *obj)
{
	if (m_firstObject != NULL)
	{
		Object *cur = m_firstObject;
		Object *prev = NULL;

		while (cur != obj && cur != NULL)
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
			m_firstObject = cur->getNext();
		}
	}
}

void Container::draw()
{
	if (m_firstObject != NULL && m_lastObject != NULL)
	{
		Object *cur = m_firstObject;

		while (cur != NULL)
		{
			cur->draw(m_pos, m_size);
			cur = cur->getNext();
		}
	}
}