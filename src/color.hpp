#pragma once

struct Color
{
    int r;
    int g;
    int b;
    int a;

    Color() : r(0), g(0), b(0), a(0) {};
    Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {};
};