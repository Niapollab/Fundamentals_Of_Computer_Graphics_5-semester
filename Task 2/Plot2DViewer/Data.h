#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

// �������� �������� ���������� X0, Y0, px, py
double X0 = 200, Y0 = 200, px = 50, py = 100;

double Parabola(double x)
{
	return x * x - 2;
}

double Sinusoid(double x)
{
	return sin(x);
}