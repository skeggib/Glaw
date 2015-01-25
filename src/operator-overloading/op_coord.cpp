#include "op_coord.hpp"

bool operator==(Coord a, Coord b)
{
	if (a.x() == b.x() && a.y() == b.y())
		return true;

	return false;
}

bool operator!=(Coord a, Coord b)
{
	if (a.x() != b.x() || a.y() != b.y())
		return true;

	return false;
}

Coord operator+(Coord a, Coord b)
{
	Coord res;
	res.setX(a.x() + b.x());
	res.setY(a.y() + b.y());

	return res;
}

void operator+=(Coord &a, Coord b)
{
	a.setX(a.x() + b.x());
	a.setY(a.y() + b.y());
}

Coord operator-(Coord a, Coord b)
{
	Coord res;
	res.setX(a.x() - b.x());
	res.setY(a.y() - b.y());

	return res;
}

Coord operator-(Coord a)
{
	Coord res;
	res.setX(-a.x());
	res.setY(-a.y());

	return res;
}

Coord operator*(Coord a, double b)
{
	Coord res;
	res.setX(a.x() * b);
	res.setY(a.y() * b);

	return res;
}

Coord operator/(Coord a, double b)
{
	Coord res;
	res.setX(a.x() / b);
	res.setY(a.y() / b);

	return res;
}