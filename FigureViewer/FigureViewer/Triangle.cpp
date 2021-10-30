#include "Triangle.h"
#include <cmath>

Triangle::Triangle(int size, int offsetX, int offsetY) : Figure(size, offsetX, offsetY)
{
}

void Triangle::Draw(HDC dc)
{
	TrianglePoints points = GetTrianglePoints();

	MoveToEx(dc, points[0].first, points[0].second, NULL);
	for (int i = 1; i <= 3; ++i)
		LineTo(dc, points[i % 3].first, points[i % 3].second);
}

int SolveLinearInTwoPointView(int x, int x1, int x2, int y1, int y2)
{
	const double y2SubY1 = y2 - y1;
	return ((y2SubY1 * x - y2SubY1 * x1) / (x2 - x1)) + y1;
}

bool Triangle::InnerPoint(int X, int Y) const
{
	std::vector<int> sides = GetRealYRelativeXPositions(X);
	return (sides[0] >= Y && sides[1] >= Y && sides[2] < Y);
}

std::vector<int> Triangle::GetRealYRelativeXPositions(int X) const
{
	TrianglePoints points = GetTrianglePoints();
	std::vector<int> sides(3);

	for (int i = 0; i < 3; ++i)
	{
		int next = (i + 1) % 3;
		sides[i] = SolveLinearInTwoPointView(X, points[i].first, points[next].first, points[i].second, points[next].second);
	}

	return sides;
}

// point		x					y
//	1	offsetX - size / 2	offsetY - size / 2
//	2		offsetX			offsetY + size / 2
//	3	offsetX + size / 2	offsetY - size / 2
Triangle::TrianglePoints Triangle::GetTrianglePoints() const
{
	return
	{
		{ offsetX - size / 2, offsetY - size / 2 },
		{ offsetX, offsetY + size / 2 },
		{ offsetX + size / 2, offsetY - size / 2 }
	};
}