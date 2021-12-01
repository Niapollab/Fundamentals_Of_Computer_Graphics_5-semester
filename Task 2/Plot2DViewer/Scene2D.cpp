#include "Scene2D.h"
#include "Data.h"

Scene2D::Scene2D(HWND window, double X0, double Y0, double px, double py) : Camera2D(window, X0, Y0, px, py)
{
}

void Scene2D::Plot(const std::function<double(double)>& func, bool axes)
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

void Scene2D::PolarPlot(const std::function<double(double)>& polarFunc, bool axes)
{
	const int SPLITTING_FREQUENCY = 1000;
	const double DELTA = (FI_MAX - FI_MIN) / SPLITTING_FREQUENCY;

	if (axes)
		Axes();

	auto start_point = ConvertPolarPointToCartesian(FI_MIN, polarFunc(FI_MIN));
	MoveTo(start_point.first, start_point.second);

	for (double fi = FI_MIN; fi <= FI_MAX; fi += DELTA)
	{
		auto points = ConvertPolarPointToCartesian(fi, polarFunc(fi));
		LineTo(points.first, points.second);
	}

	auto end_point = ConvertPolarPointToCartesian(FI_MAX, polarFunc(FI_MAX));
	LineTo(end_point.first, end_point.second);
}