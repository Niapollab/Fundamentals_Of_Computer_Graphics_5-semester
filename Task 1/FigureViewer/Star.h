#pragma once
#include "Polygon.h"

class Star : public Polygon
{
public:
	Star(int size = 12, int offsetX = 100, int offsetY = 100);
	
	virtual bool InnerPoint(int X, int Y) const;

protected:
	virtual std::vector<std::pair<int, int>> GetPoints() const;

private:
	bool InBottomPart(const std::vector<int>& RealYRelativeXPositions, int Y) const;

	bool InCenterPart(const std::vector<int>& RealYRelativeXPositions, int Y) const;

	bool InUpperPart(const std::vector<int>& RealYRelativeXPositions, int Y) const;
};

