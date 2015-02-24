#pragma once

#include "vector.hpp"
#include "object.hpp"

/*! \class Container
 *	
 *	Contains Objects
 *	
*/
class Container
{
public:

	/*! \fn Container()
	 *	
	 *	Contructor of a default Container
	 *	
	*/
	Container();

	/*! \fn Container(Vector pos, Vector size)
	 *	
	 *	Contructor of a Container
	 *	
	 *	\param pos : Position of the container
	 *	\param size : Size of the container
	 *	
	*/
	Container(Vector pos, Vector size);

	/*! \fn ~Container()
	 *	
	 *	Destructor
	 *	
	*/
	~Container();

	/*! \fn set(Vector pos, Vector size)
	 *	
	 *	Set the position and size of the Container
	 *	
	 *	\param pos : Position of the container
	 *	\param size : Size of the container
	 *	
	*/
	void set(Vector pos, Vector size);

	/*! \fn add(Object *obj)
	 *	
	 *	Add an Object to the Container
	 *	
	 *	\param obj : Object to add
	 *	
	*/
	void add(Object *obj);

	/*! \fn rem(Object *obj)
	 *	
	 *	Remove an Object from the Container
	 *	
	 *	\param obj : Object to remove
	 *	
	*/
	void rem(Object *obj);

	/*! \fn draw()
	 *	
	 *	Draw the container
	 *	
	*/
	void draw();

private:
	Vector m_pos; // Position
	Vector m_size; // Size

	// Chain list of Objects
	Object *m_firstObject;
	Object *m_lastObject;
};