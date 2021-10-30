#pragma once
#include <utility>
#include <vector>
#include "Polygon.h"

class Triangle : public Polygon
{
public:
	Triangle(int size = 12, int offsetX = 100, int offsetY = 100);

	virtual bool InnerPoint(int X, int Y) const;

protected:
	virtual std::vector<std::pair<int, int>> GetPoints() const;
};

