#pragma once

#include "Camera2D.h"
#include "Model2D.h"
#include "Matrix.h"

class Scene2D : public Camera2D
{
private:
	typedef double (*Func)(double);
	Matrix<double> Vertices;
	Matrix<int> Edges;
	Model2D model;

public:
	Scene2D(HWND window, double X0, double Y0, double px, double py, Model2D model);

	Model2D& GetModel();

	void Plot(Func f, bool axes = true);

	void Render();
};