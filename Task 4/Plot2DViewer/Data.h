#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif

double					// �������� �������� ���������� L, R, B, T
	//L = -M_PI,
	L = -10.5,
	//R = M_PI,
	R = 10.5,
	B = -10.5,
	T = 10.5,
	speed = 0.4;

double X0 = 200, Y0 = 200, px = 50, py = 50;

bool dragging = false;

double Parabola(double x)
{
	return x * x - 2;
}

double Sinusoid(double x)
{
	return sin(x);
}