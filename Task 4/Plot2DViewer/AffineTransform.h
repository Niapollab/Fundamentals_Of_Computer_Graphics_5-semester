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

// ����� ��������� ����������� �������, ������������ ������� ������� ��:
// Identity() - ������������� ��;
// Rotation(t) - ������� �� ���� t;
// Rotation(c, s) - ������� �� ����, ������� � ����� �������� ��������������� ��������� c � s;
// Scaling(kx, ky) - ���������������;
// Mapping (��������� ���� ���������) - �� �������, ��� �������� ������ ��������� ����� ������������ ������� Scaling.

// � ���������� ������� ������������ ����������� ������� �� ������.
// �������������� ���� � ������ �������� �������� ������.
// ��������, ����� �������, ��������� ��������� �������,
// � ����������� ���������������� ��������� � �������������.