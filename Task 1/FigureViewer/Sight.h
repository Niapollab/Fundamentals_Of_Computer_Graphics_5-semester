#pragma once
#include <wtypes.h>
#include "Figure.h"

class Sight : public Figure
{
public:
	Sight(int size = 12, int offsetX = 100, int offsetY = 100);

	virtual void Draw(HDC dc);

	virtual bool InnerPoint(int X, int Y) const;
};
