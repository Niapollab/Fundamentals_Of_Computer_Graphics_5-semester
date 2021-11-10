#include "Triangle.h"
#include <cmath>

Triangle::Triangle(int size, int offsetX, int offsetY) : Polygon(size, offsetX, offsetY)
{
}

bool Triangle::InnerPoint(int X, int Y) const
{
	std::vector<int> sides = GetRealYRelativeXPositions(X);
	return (sides[0] >= Y && sides[1] >= Y && sides[2] < Y);
}

// point		x					y
//	1	offsetX - size / 2	offsetY - size / 2
//	2		offsetX			offsetY + size / 2
//	3	offsetX + size / 2	offsetY - size / 2
std::vector<std::pair<int, int>> Triangle::GetPoints() const
{
	return
	{
		{ offsetX - size / 2, offsetY - size / 2 },
		{ offsetX, offsetY + size / 2 },
		{ offsetX + size / 2, offsetY - size / 2 }
	};
}