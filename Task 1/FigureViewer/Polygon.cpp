#include "Polygon.h"

Polygon::Polygon(int size, int offsetX, int offsetY) : Figure(size, offsetX, offsetY)
{
}

void Polygon::Draw(HDC dc)
{
	std::vector<std::pair<int, int>> points = GetPoints();
	
	if (points.size() < 1)
		return;

	MoveToEx(dc, points[0].first, points[0].second, NULL);
	for (int i = 1; (size_t)i <= points.size(); ++i)
		LineTo(dc, points[i % points.size()].first, points[i % points.size()].second);
	
}

int SolveLinearInTwoPointView(int x, int x1, int x2, int y1, int y2)
{
	const double y2SubY1 = y2 - y1;
	return (int)((y2SubY1 * x - y2SubY1 * x1) / (x2 - x1)) + y1;
}

std::vector<int> Polygon::GetRealYRelativeXPositions(int X) const
{
	std::vector<std::pair<int, int>> points = GetPoints();
	std::vector<int> sides(points.size());

	for (int i = 0; (size_t)i < points.size(); ++i)
	{
		int next = (i + 1) % points.size();
		sides[i] = SolveLinearInTwoPointView(X, points[i].first, points[next].first, points[i].second, points[next].second);
	}

	return sides;
}