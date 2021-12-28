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