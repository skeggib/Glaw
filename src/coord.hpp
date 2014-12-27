#pragma once

class Coord
{
public:
	Coord();
	Coord(float x, float y);
	~Coord();

	/* \fn set
	 *	
	 *	Set the coordinates
	 *	
	 *	\param x : x
	 *	\param y : y
	 *	
	*/
	void set(float x, float y);

	/* \fn setX
	 *	
	 *	Set x
	 *	
	 *	\param x : x
	 *	
	*/
	void setX(float x);

	/* \fn setY
	 *	
	 *	Set y
	 *	
	 *	\param y : y
	 *	
	*/
	void setY(float y);

	/* \fn x
	 *	
	 *	Get x
	 *	
	*/
	float x();

	/* \fn y
	 *	
	 *	Get y
	 *	
	*/
	float y();

private:
	float m_x;
	float m_y;
};