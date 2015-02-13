#pragma once

#include "coord.hpp"
#include "vector.hpp"
#include "color.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(Vector apex1, Vector apex2, Vector apex3, Color color);
	Triangle(Vector apex1, Vector apex2, Vector apex3, Color color1, Color color2, Color color3);
	~Triangle();

	/* \fn Triangle::set
	 *	
	 *	Set the variables of the triangle
	 *	
	 *	\param apex1 : Apex 1
	 *	\param apex2 : Apex 2
	 *	\param apex3 : Apex 3
	 *	\param color : Color of the triangle
	 *	\param color1 : Color of the first apex
	 *	\param color2 : Color of the second apex
	 *	\param color3 : Color of the third apex
	 *	
	*/
	void set(Vector apex1, Vector apex2, Vector apex3, Color color);
	void set(Vector apex1, Vector apex2, Vector apex3, Color color1, Color color2, Color color3);

	/* \fn Triangle::dynAlloc
	 *	
	 * Set m_dynAlloc to true
	 *	
	*/
	void dynAlloc();

	/*! \fn Triangle::dynAlloc
	 *	
	 *	Returns true if the Triangle was allocated dynamicly.
	 *	
	*/
	bool isDynAlloc();

	/* \fn Triangle::draw
	 *	
	 * Draw the triangle
	 * 
	 * \param pos : position od the drawing
	 * \param size : size of the drawing
	 *	
	*/
	void draw();
	void draw(Vector pos, Vector size);

	/* \fn Triangle::translate
	 *	
	 *	Translate the triangle
	 *	
	 *	\param a : Vector 
	 *	\param x : x of the vector
	 *	\param y : y of the vector
	 *	
	*/
	void translate(Vector a);
	void translate(double x, double y);

	/* \fn Triangle::rotate
	 *	
	 *	Rotate the triangle
	 *	
	 *	\param axis : Axis of rotation 
	 *	\param angle : Angle of rotation
	 *	
	*/
	void rotate(Vector axis, float angle);

	/* \fn Triangle::resetPos
	 *	
	 *	Reset the position of the triangle
	 *	
	*/
	void resetPos();

	/*! \fn Triangle::setNext
	 *	
	 *	Set the pointer of the next triangle
	 *	
	 *	\param t : next triangle
	 *	
	*/
	void setNext(Triangle *t);

	/*! \fn Triangle::setPrev
	 *	
	 *	Set the pointer of the prev triangle
	 *	
	 *	\param t : prev triangle
	 *	
	*/
	void setPrev(Triangle *t);

	/*! \fn Triangle::getNext
	 *	
	 *	Get the pointer of the next triangle
	 *	
	*/
	Triangle* getNext();

	/*! \fn Triangle::getPrev
	 *	
	 *	Get the pointer of the prev triangle
	 *	
	*/
	Triangle* getPrev();

	/* \fn Triangle::changeColor
	 *	
	 *	Change the color of the Triangle
	 *	
	 *	\param c : Color of all apexes
	 *	\param c1 : Color of the first apex
	 *	\param c2 : Color of the second apex
	 *	\param c3 : Color of the third apex
	 *	
	*/
	void changeColor(Color c);
	void changeColor(Color c1, Color c2, Color c3);

private:
	Vector m_apex[3]; // Positions of the 3 apex of the triangle (in percentage of the screen (or surface))
	Vector m_origApex[3]; // Original positions of the 3 apex of the triangle (it never change)
	Color m_color[3]; // Colors of each apex

    Triangle *m_prev;
    Triangle *m_next;

    bool m_dynAlloc;
};