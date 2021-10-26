#pragma once
#include <wtypes.h>

class Figure
{
protected:
	int size;
	int offsetX, offsetY;

private:
	bool isDragging;
	int previousX, previousY;

public:
	Figure(int size, int offsetX, int offsetY);

	virtual void Draw(HDC dc) = 0;

	virtual bool InnerPoint(int X, int Y) const = 0;

	void Clear(HDC dc);

	void MoveTo(int X, int Y);

	void Move(int X, int Y);

	void StartDragging(int X, int Y);

	void Drag(int X, int Y);

	void StopDragging();

	bool IsDragging() const;

	int GetSize() const;

	void Resize(int newSize);
};