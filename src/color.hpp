#pragma once

class Color
{
public:
	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	~Color();

	/* \fn set
	 *	
	 *	Set the color
	 *	
	 *	\param r : Red
	 *	\param g : Green
	 *	\param b : Blue
	 *	\param a : Alpha
	 *	
	*/
	void set(unsigned char r, unsigned char g, unsigned char b);
	void set(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

	/* \fn r
	 *	
	 *	Get Red 
	 *	
	*/
	int r();
	
	/* \fn g
	 *	
	 *	Get Green 
	 *	
	*/
	int g();
	
	/* \fn b
	 *	
	 *	Get Blue 
	 *	
	*/
	int b();
	
	/* \fn a
	 *	
	 *	Get Alpha 
	 *	
	*/
	int a();

private:
	unsigned char m_r; // Red
	unsigned char m_g; // Green
	unsigned char m_b; // Blue
	unsigned char m_a; // Alpha
};