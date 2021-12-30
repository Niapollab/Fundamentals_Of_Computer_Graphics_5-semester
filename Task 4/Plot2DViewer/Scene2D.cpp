#include "Scene2D.h"
#include "Point3D.h"
#include "AffineTransform.h"

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

void Scene2D::Render(const Model2D& model)
{
	const Matrix<int>& edges = model.GetEdges();
	const Matrix<double>& vertices = model.GetVertices();

	for (size_t i = 0; i < vertices.get_columns_size(); ++i)
	{
		for (size_t j = i + 1; j < vertices.get_columns_size(); ++j)
		{
			if (edges[i][j])
			{
				auto fpoint = model.GetVertex(i);
				auto spoint = model.GetVertex(j);
				
				MoveTo(fpoint.x(), fpoint.y());
				LineTo(spoint.x(), spoint.y());
			}
		}
	}
}

void Scene2D::RenderFacet(const Model3D& model, const MatrixRow<int>& facetRow, ProjectionType type)
{
	for (size_t i = 0; i < facetRow.get_size(); ++i)
	{
		Point3D<double> current_vertex = model.GetVertex(facetRow[i]);
		Point3D<double> next_vertex = model.GetVertex(facetRow[(i + 1) % facetRow.get_size()]);

		switch (type)
		{
		case ProjectionType::XOY:
			MoveTo(current_vertex.x(), current_vertex.y());
			LineTo(next_vertex.x(), next_vertex.y());
			break;
		case ProjectionType::ZOX:
			MoveTo(current_vertex.z(), current_vertex.x());
			LineTo(next_vertex.z(), next_vertex.x());
			break;
		case ProjectionType::YOZ:
			MoveTo(current_vertex.y(), current_vertex.z());
			LineTo(next_vertex.y(), next_vertex.z());
			break;
		}
	}
}

void Scene2D::Render(const Model3D& model, ProjectionType type, int distance)
{
	Model3D projection(model);
	switch (type)
	{
		case ProjectionType::XOY:
			projection.Apply(PerspectiveProjectionXOY(distance));
			break;
		case ProjectionType::ZOX:
			projection.Apply(PerspectiveProjectionZOX(distance));
			break;
		case ProjectionType::YOZ:
			projection.Apply(PerspectiveProjectionYOZ(distance));
			break;
	}

	const Matrix<int>& facets = model.GetFacets();
	
	for (size_t i = 0; i < facets.get_rows_size(); ++i)
		RenderFacet(projection, facets[i], type);
}