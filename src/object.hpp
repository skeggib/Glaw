#pragma once

#include "triangle.hpp"

class Object
{
public:
	Object();
	Object(Vector2 pos, Vector2 size);
	~Object();

	/*! \fn add
	 *	
	 *	Add a triangle to the list
	 *	
	 *	\param t : triangle's pointer
	 *	
	*/
	void add(Triangle *t);

	/* \fn create
	 *	
	 * Dynamicly allocate a triangle, add it to the list and return its pointer
	 *	
	 * \param t : triangle to copy 
	 *	
	*/
	Triangle* create(Triangle t);

	/*! \fn rem
	 *	
	 *	Remove a triangle from the list
	 *	
	 *	\param t : triangle's pointer
	 *	
	*/
	void rem(Triangle *t);

	void draw();

private:
	Vector2 m_pos;
	Vector2 m_size;

	Triangle *m_first;
	Triangle *m_last;
};