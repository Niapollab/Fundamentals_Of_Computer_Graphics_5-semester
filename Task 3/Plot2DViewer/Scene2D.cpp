#include "Scene2D.h"

Scene2D::Scene2D(HWND window, double X0, double Y0, double px, double py) : Camera2D(window, X0, Y0, px, py)
{
}

void Scene2D::Plot(Func func, bool axes)
{
	if (axes)
		Axes();

	MoveTo(ScreenToWorldX(0), func(ScreenToWorldX(0)));

	for (int xf = 0; xf < W; ++xf)
	{
		double yf = func(ScreenToWorldX(xf));
		LineTo(ScreenToWorldX(xf), yf);
	}
}