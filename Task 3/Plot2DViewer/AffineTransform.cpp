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

Matrix<double> Identity()
{
	return
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
}

Matrix<double> Rotation(double c, double s)
{
	return
	{
		{c, s, 0},
		{-s, c, 0},
		{0, 0, 1}
	};
}

Matrix<double> Rotation(double rad)
{
	return Rotation(cos(rad), sin(rad));
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

Matrix<double> ReflectOX()
{
	return Scaling(-1, 1);
}

Matrix<double> ReflectOY()
{
	return Scaling(1, -1);
}

Matrix<double> ReflectAll()
{
	return Scaling(-1, -1);
}