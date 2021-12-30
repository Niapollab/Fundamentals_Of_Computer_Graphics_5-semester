#pragma once

#include "Camera2D.h"
#include "Model2D.h"
#include "Model3D.h"
#include "ProjectionType.h"
#include "Matrix.h"

class Scene2D : public Camera2D
{
private:
	void RenderFacet(const Model3D& model, const MatrixRow<int>& facetRow, ProjectionType type);
	typedef double (*Func)(double);

public:
	Scene2D(HWND window, double X0, double Y0, double px, double py);

	void Plot(Func f, bool axes = true);

	void Render(const Model2D& model);

	void Render(const Model3D& model, ProjectionType type = ProjectionType::XOY, int distance = 20);
};