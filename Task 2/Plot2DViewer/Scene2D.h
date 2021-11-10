#pragma once
#include "Camera2D.h"

class Scene2D : public Camera2D
{
private:
	typedef double (*Func)(double);

public:
	Scene2D(HWND window, double X0, double Y0, double px, double py);

	void Plot(Func f, bool axes = true);
};