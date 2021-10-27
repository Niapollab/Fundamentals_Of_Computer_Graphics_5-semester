#pragma once
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle(int size = 12, int offsetX = 100, int offsetY = 100);

	virtual void Draw(HDC dc);

	virtual bool InnerPoint(int X, int Y) const;
};

