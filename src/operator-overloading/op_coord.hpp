#pragma once

#include "../coord.hpp"

bool operator==(Coord a, Coord b);
bool operator!=(Coord a, Coord b);
Coord operator+(Coord a, Coord b);
void operator+=(Coord &a, Coord b);
Coord operator-(Coord a, Coord b);
Coord operator-(Coord a);
Coord operator*(Coord a, double b);
Coord operator/(Coord a, double b);