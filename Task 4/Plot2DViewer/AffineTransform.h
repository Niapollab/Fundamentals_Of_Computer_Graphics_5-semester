#pragma once
#include <cmath>
#include "Matrix.h"

Matrix<double> Translation(double x, double y);

Matrix<double> Identity();

Matrix<double> Rotation(double c, double s);

Matrix<double> Rotation(double rad);

Matrix<double> Scaling(double kx, double ky);

Matrix<double> ReflectOX();

Matrix<double> ReflectOY();

Matrix<double> ReflectAll();

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