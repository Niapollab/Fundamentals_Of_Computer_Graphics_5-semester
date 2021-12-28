#pragma once
#include <cmath>
#include "Matrix.h"

Matrix<double> Translation(double x, double y);

Matrix<double> Translation(double x, double y, double z);

Matrix<double> Identity(int length);

Matrix<double> Rotation2D(double c, double s);

Matrix<double> Rotation2D(double rad);

Matrix<double> Rotation3DByX(double triang_leg1, double triang_leg2);

Matrix<double> Rotation3DByX(double rad);

Matrix<double> Rotation3DByY(double triang_leg1, double triang_leg2);

Matrix<double> Rotation3DByY(double rad);

Matrix<double> Rotation3DByZ(double triang_leg1, double triang_leg2);

Matrix<double> Rotation3DByZ(double rad);

Matrix<double> Scaling(double kx, double ky);

Matrix<double> Scaling(double kx, double ky, double kz);

Matrix<double> Reflect2DOX();

Matrix<double> Reflect2DOY();

Matrix<double> Reflect2DAll();

// Здесь требуется реализовать функции, возвращающие матрицы базовых АП:
// Identity() - тождественное АП;
// Rotation(t) - поворот на угол t;
// Rotation(c, s) - поворот на угол, косинус и синус которого пропорциональны величинам c и s;
// Scaling(kx, ky) - масштабирование;
// Mapping (различные виды отражений) - по желанию, для создания матриц отражения можно использовать функцию Scaling.

// В приведённом примере используется конструктор матрицы из списка.
// Приветствуются идеи о других способах создания матриц.
// Например, вызов функции, создающей единичную матрицу,
// с последующим переопределением некоторых её коэффициентов.