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

Matrix<double> Rotation(double triang_leg1, double triang_leg2)
{
	double hypotenuse = sqrt(triang_leg1 * triang_leg1 + triang_leg2 * triang_leg2);
	
	double c = triang_leg1 / hypotenuse;
	double s = triang_leg2 / hypotenuse;

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