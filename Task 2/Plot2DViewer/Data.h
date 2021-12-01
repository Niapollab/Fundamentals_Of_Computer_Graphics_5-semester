#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

// Исходные значения параметров X0, Y0, px, py
const double X0 = 200, Y0 = 200, px = 50, py = 100, FI_MIN = 0, FI_MAX = 2 * M_PI;

double Parabola(double x);

double Sinusoid(double x);

double ArchimedSpiral(double x);