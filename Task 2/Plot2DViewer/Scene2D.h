#pragma once
#include <functional>
#include "Camera2D.h"

class Scene2D : public Camera2D
{
public:
	Scene2D(HWND window, double X0, double Y0, double px, double py);

	void Plot(const std::function<double(double)>& func, bool axes = true);

	void PolarPlot(const std::function<double(double)>& polarFunc, bool axes = true);
};