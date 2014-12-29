#include "op_coord.hpp"

bool operator==(Coord &a, Coord &b)
{
	if (a.x() == b.x() && a.y() == b.y())
		return true;

	return false;
}