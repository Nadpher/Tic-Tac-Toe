#pragma once

template <typename T>
struct Coord
{
    T x;
    T y;
};

typedef Coord<int> iCoord;
typedef Coord<float> fCoord;