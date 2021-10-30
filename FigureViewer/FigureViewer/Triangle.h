#pragma once
#include <utility>
#include <vector>
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle(int size = 12, int offsetX = 100, int offsetY = 100);

	virtual void Draw(HDC dc);

	virtual bool InnerPoint(int X, int Y) const;

private:
	using TrianglePoints = std::vector<std::pair<int, int>>;

	TrianglePoints GetTrianglePoints() const;

	std::vector<int> GetRealYRelativeXPositions(int X) const;
};

