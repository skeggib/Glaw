#pragma once

#include "vector.hpp"
#include "object.hpp"

class Container
{
public:

	/*! \fn Container::Container
	 *	
	 *	Contructor of a default Container
	 *	
	*/
	Container();

	/*! \fn Container::Container
	 *	
	 *	Contructor of a Container
	 *	
	 *	\param pos : Position of the container
	 *	\param size : Size of the container
	 *	
	*/
	Container(Vector pos, Vector size);

	~Container();

	/*! \fn Container::set
	 *	
	 *	Set the position and size of the Container
	 *	
	 *	\param pos : Position of the container
	 *	\param size : Size of the container
	 *	
	*/
	void set(Vector pos, Vector size);

	/*! \fn Container::add
	 *	
	 *	Add an Object to the Container
	 *	
	 *	\param obj : Object to add
	 *	
	*/
	void add(Object *obj);

	/*! \fn Container::rem
	 *	
	 *	Remove an Object from the Container
	 *	
	 *	\param obj : Object to remove
	 *	
	*/
	void rem(Object *obj);

	/*! \fn Container::draw
	 *	
	 *	Draw the container
	 *	
	*/
	void draw();

private:
	Vector m_pos;
	Vector m_size;

	Object *m_firstObject;
	Object *m_lastObject;
};