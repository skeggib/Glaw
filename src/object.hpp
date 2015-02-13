#pragma once

#include "triangle.hpp"

class Object
{
public:
	Object();
	Object(Vector pos, Vector size);
	~Object();

	/* \fn Object::set
	 *	
	 *	Set position and size
	 *	
	*/
	void set(Vector pos, Vector size);

	/*! \fn Object::add
	 *	
	 *	Add a triangle to the list
	 *	
	 *	\param t : triangle's pointer
	 *	
	*/
	void add(Triangle *t);

	/* \fn Object::create
	 *	
	 * Dynamicly allocate a triangle, add it to the list and return its pointer
	 *	
	 * \param t : triangle to copy 
	 *	
	*/
	Triangle* create(Triangle t);

	/*! \fn Object::rem
	 *	
	 *	Remove a triangle from the list
	 *	
	 *	\param t : triangle's pointer
	 *	
	*/
	void rem(Triangle *t);

	/*! \fn Object::draw
	 *	
	 *	Draw the object
	 *	
	*/
	void draw();

	/*! \fn Object::rotate
	 *	
	 *	Rotate all triangles in the object
	 *	
	 *	\param axis : Axis of rotation 
	 *	\param angle : Angle of rotation
	 *	
	*/
	void rotate(Vector axis, float angle);

	/* \fn Object::resetPos
	 *	
	 *	Reset the position of all triangles in the object
	 *	
	*/
	void resetPos();

	/* \fn Object::copy
	 *	
	 *	Copy an Object into this Object
	 *	
	 *	\param obj : Object to copy
	 *	
	*/
	void copy(Object &obj);

private:

/* Getters */

	Vector getPos();
	Vector getSize();
	Triangle *getFirst();

/* Variables */

	Vector m_pos;
	Vector m_size;

	Triangle *m_first;
	Triangle *m_last;
};