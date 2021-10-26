#include "Sight.h"

Sight::Sight(int size, int offsetX, int offsetY) : Figure(size, offsetX, offsetY)
{
}

void Sight::Draw(HDC dc)
{
	Ellipse(dc, offsetX - size, offsetY - size, offsetX + size, offsetY + size);
	MoveToEx(dc, offsetX - size, offsetY, NULL);
	LineTo(dc, offsetX + size, offsetY);
	MoveToEx(dc, offsetX, offsetY - size, NULL);
	LineTo(dc, offsetX, offsetY + size);
}

bool Sight::InnerPoint(int X, int Y) const
{
	return (X - offsetX) * (X - offsetX) + (Y - offsetY) * (Y - offsetY) <= size * size;
}