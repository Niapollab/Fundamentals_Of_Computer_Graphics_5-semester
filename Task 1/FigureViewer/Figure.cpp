#include "Figure.h"

Figure::Figure(int size, int offsetX, int offsetY) : size(size), offsetX(offsetX), offsetY(offsetY), isDragging(false), previousX(0), previousY(0)
{
	if (this->size < 1)
		this->size = 1;
}

void Figure::Clear(HDC dc)
{
	RECT r;
	GetClientRect(WindowFromDC(dc), &r);
	Rectangle(dc, 0, 0, r.right, r.bottom);
}

void Figure::MoveTo(int X, int Y)
{
	offsetX = X;
	offsetY = Y;
}

void Figure::Move(int X, int Y)
{
	MoveTo(offsetX + X, offsetY + Y);
}

void Figure::StartDragging(int X, int Y)
{
	isDragging = InnerPoint(X, Y);
	previousX = X;
	previousY = Y;
}

void Figure::Drag(int X, int Y)
{
	Move(X - previousX, Y - previousY);
	previousX = X;
	previousY = Y;
}

void Figure::StopDragging()
{
	isDragging = false;
}

bool Figure::IsDragging() const
{
	return isDragging;
}

int Figure::GetSize() const
{
	return size;
}

void Figure::Resize(int newSize)
{
	size = newSize < 1
		? 1
		: newSize;
}