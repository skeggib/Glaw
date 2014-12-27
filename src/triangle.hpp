#pragma once

#include "coord.hpp"
#include "color.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

class Triangle
{
public:
	Triangle();
	Triangle(Coord apex1, Coord apex2, Coord apex3, Color color);
	Triangle(Coord apex1, Coord apex2, Coord apex3, Color color1, Color color2, Color color3);
	~Triangle();

	/* \fn set
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
	void set(Coord apex1, Coord apex2, Coord apex3, Color color);
	void set(Coord apex1, Coord apex2, Coord apex3, Color color1, Color color2, Color color3);

	/* \fn draw
	 *	
	 *	Draw the triangle
	 *	
	*/
	void draw();

private:
	Coord m_apex[3]; // Positions of the 3 apex of the triangle (in percentage of the screen (or surface))
	Color m_color[3]; // Colors of each apex
};