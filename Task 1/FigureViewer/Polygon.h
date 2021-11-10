#pragma once
#include "Figure.h"
#include <vector>

class Polygon : public Figure
{
public:
	Polygon(int size, int offsetX, int offsetY);

	virtual void Draw(HDC dc);

protected:
	virtual std::vector<std::pair<int, int>> GetPoints() const = 0;

	std::vector<int> GetRealYRelativeXPositions(int X) const;
};

