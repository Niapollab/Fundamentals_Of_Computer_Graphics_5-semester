#include "Triangle.h"

Triangle::Triangle(int size, int offsetX, int offsetY) : Figure(size, offsetX, offsetY)
{
}

void Triangle::Draw(HDC dc)
{
	MoveToEx(dc, offsetX - size / 2, offsetY - size / 2, NULL);
	LineTo(dc, offsetX, offsetY + size / 2);
	LineTo(dc, offsetX + size / 2, offsetY - size / 2);
	LineTo(dc, offsetX - size / 2, offsetY - size / 2);
}

bool Triangle::InnerPoint(int X, int Y) const
{
	return false;
}