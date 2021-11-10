#include "Star.h"

Star::Star(int size, int offsetX, int offsetY) : Polygon(size, offsetX, offsetY)
{
}

bool Star::InnerPoint(int X, int Y) const
{
	std::vector<int> sides = GetRealYRelativeXPositions(X);

	return InBottomPart(sides, Y) || InCenterPart(sides, Y) || InUpperPart(sides, Y);
}

std::vector<std::pair<int, int>> Star::GetPoints() const
{
	return
	{
		// Left side
		{ offsetX, offsetY + size / 4 },
		{ offsetX - size / 4, offsetY + size / 2 },
		{ offsetX - size / 5, offsetY + size / 10 },
		{ offsetX - size / 2, offsetY - size / 10 },
		{ offsetX - size / 10, offsetY - 3 * size / 20 },
		{ offsetX, offsetY - size / 2 },
		// Right side
		{ offsetX + size / 10, offsetY - 3 * size / 20 },
		{ offsetX + size / 2, offsetY - size / 10 },
		{ offsetX + size / 5, offsetY + size / 10 },
		{ offsetX + size / 4, offsetY + size / 2 }
	};
}

bool Star::InBottomPart(const std::vector<int>& RealYRelativeXPositions, int Y) const
{
	const int last = RealYRelativeXPositions.size() - 1;

	return (RealYRelativeXPositions[0] >= Y
		&& RealYRelativeXPositions[1] <= Y
		&& RealYRelativeXPositions[2] <= Y)
		|| (RealYRelativeXPositions[last] >= Y
			&& RealYRelativeXPositions[last - 1] <= Y
			&& RealYRelativeXPositions[last - 2] <= Y);
}

bool Star::InCenterPart(const std::vector<int>& RealYRelativeXPositions, int Y) const
{
	const int last = RealYRelativeXPositions.size() - 1;

	return RealYRelativeXPositions[2] >= Y
		&& RealYRelativeXPositions[last - 2] >= Y
		&& RealYRelativeXPositions[3] <= Y
		&& RealYRelativeXPositions[last - 3] <= Y;
}

bool Star::InUpperPart(const std::vector<int>& RealYRelativeXPositions, int Y) const
{
	const int last = RealYRelativeXPositions.size() - 1;

	return RealYRelativeXPositions[3] >= Y
		&& RealYRelativeXPositions[4] <= Y
		&& RealYRelativeXPositions[last - 3] >= Y
		&& RealYRelativeXPositions[last - 4] <= Y;
}
