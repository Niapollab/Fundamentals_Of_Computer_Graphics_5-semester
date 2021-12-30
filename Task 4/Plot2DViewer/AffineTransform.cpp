#include "AffineTransform.h"

Matrix<double> Translation(double x, double y)
{
	return
	{
		{1, 0, x},
		{0, 1, y},
		{0, 0, 1}
	};
}

Matrix<double> Translation(const Point2D<double>& point)
{
	return Translation(point.x(), point.y());
}

Matrix<double> Translation(double x, double y, double z)
{
	return
	{
		{1, 0, 0, x},
		{0, 1, 0, y},
		{0, 0, 1, z},
		{0, 0, 0, 1}
	};
}

Matrix<double> Translation(const Point3D<double>& point)
{
	return Translation(point.x(), point.y(), point.z());
}

Matrix<double> Identity(int length)
{
	if (length < 0)
		return Matrix<double>();
	
	Matrix<double> result(length, length);
	for (int i = 0; i < length; ++i)
		result[i][i] = 1;

	return result;
}

std::pair<double, double> FindCSPair(double triang_leg1, double triang_leg2)
{
	double hypotenuse = sqrt(triang_leg1 * triang_leg1 + triang_leg2 * triang_leg2);
	
	double c = triang_leg1 / hypotenuse;
	double s = triang_leg2 / hypotenuse;

	return {c, s};
}

Matrix<double> Rotation2D(double triang_leg1, double triang_leg2)
{
	std::pair<double, double> cs = FindCSPair(triang_leg1, triang_leg2);

	return
	{
		{cs.first, cs.second, 0},
		{-cs.second, cs.first, 0},
		{0, 0, 1}
	};
}

Matrix<double> Rotation2D(double rad)
{
	return Rotation2D(cos(rad), sin(rad));
}

Matrix<double> Rotation3DByX(double triang_leg1, double triang_leg2)
{
	std::pair<double, double> cs = FindCSPair(triang_leg1, triang_leg2);

	return
	{
		{1, 0, 0, 0},
		{0, cs.first, -cs.second, 0},
		{0, cs.second, cs.first, 0},
		{0, 0, 0, 1}
	};
}

Matrix<double> Rotation3DByX(double rad)
{
	return Rotation3DByX(cos(rad), sin(rad));
}

Matrix<double> Rotation3DByY(double triang_leg1, double triang_leg2)
{
	std::pair<double, double> cs = FindCSPair(triang_leg1, triang_leg2);

	return
	{
		{cs.first, 0, cs.second, 0},
		{0, 1, 0, 0},
		{-cs.second, 0, cs.first, 0},
		{0, 0, 0, 1}
	};
}

Matrix<double> Rotation3DByY(double rad)
{
	return Rotation3DByY(cos(rad), sin(rad));
}

Matrix<double> Rotation3DByZ(double triang_leg1, double triang_leg2)
{
	std::pair<double, double> cs = FindCSPair(triang_leg1, triang_leg2);

	return
	{
		{cs.first, -cs.second, 0, 0},
		{cs.second, cs.first, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
}

Matrix<double> Rotation3DByZ(double rad)
{
	return Rotation3DByZ(cos(rad), sin(rad));
}

Matrix<double> Scaling(double kx, double ky)
{
	return
	{
		{kx, 0, 0},
		{0, ky, 0},
		{0, 0, 1}
	};
}

Matrix<double> Scaling(double kx, double ky, double kz)
{
	return
	{
		{kx, 0, 0, 0},
		{0, ky, 0, 0},
		{0, 0, kz, 0},
		{0, 0, 0, 1}
	};
}

Matrix<double> Reflect2DOX()
{
	return Scaling(-1, 1);
}

Matrix<double> Reflect2DOY()
{
	return Scaling(1, -1);
}

Matrix<double> Reflect2DAll()
{
	return Scaling(-1, -1);
}

Matrix<double> PerspectiveProjectionXOY(double distance)
{
	return
	{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0},
		{0, 0, -1 / distance, 1}
	};
}

Matrix<double> PerspectiveProjectionZOX(double distance)
{
	return
	{
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 1, 0},
		{0, -1 / distance, 0, 1}
	};
}

Matrix<double> PerspectiveProjectionYOZ(double distance)
{
	return
	{
		{0, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{-1 / distance, 0, 0, 1}
	};
}