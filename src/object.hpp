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
	 * \param pos : position od the drawing
	 * \param size : size of the drawing
	 *	
	*/
	void draw();
	void draw(Vector pos, Vector size);

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

	/* \fn Object::getPos
	 *	
	 *	Get the position of the Object
	 *	
	*/
	Vector getPos();

	/* \fn Object::getSize
	 *	
	 *	Get the size of the Object
	 *	
	*/
	Vector getSize();

	/* \fn Object::changeColor
	 *	
	 *	Change the color of the Object
	 *	
	 *	\param c : Color
	 *	
	*/
	void changeColor(Color c);

	/*! \fn Object::setNext
	 *	
	 *	Set the pointer of the next Object
	 *	
	 *	\param obj : next Object
	 *	
	*/
	void setNext(Object *obj);

	/*! \fn Object::setPrev
	 *	
	 *	Set the pointer of the prev Object
	 *	
	 *	\param obj : prev Object
	 *	
	*/
	void setPrev(Object *obj);

	/*! \fn Object::getNext
	 *	
	 *	Get the pointer of the next Object
	 *	
	*/
	Object* getNext();

	/*! \fn Object::getPrev
	 *	
	 *	Get the pointer of the prev Object
	 *	
	*/
	Object* getPrev();

private:

	Triangle *getFirst();

/* Variables */

	Vector m_pos;
	Vector m_size;

	Triangle *m_first;
	Triangle *m_last;

    Object *m_prev;
    Object *m_next;
};