#pragma once

#include "triangle.hpp"

class Object
{
public:
	Object();
	~Object();

	/*! \fn add
	 *	
	 *	Add a triangle to the list
	 *	
	 *	\param t : triangle's pointer
	 *	
	*/
	void add(Triangle *t);

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
	Triangle *m_first;
	Triangle *m_last;
};