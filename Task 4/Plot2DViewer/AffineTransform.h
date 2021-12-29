#pragma once
#include <cmath>
#include "Matrix.h"
#include "Point2D.h"
#include "Point3D.h"

Matrix<double> Translation(double x, double y);

Matrix<double> Translation(const Point2D<double>& point);

Matrix<double> Translation(double x, double y, double z);

Matrix<double> Translation(const Point3D<double>& point);

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

Matrix<double> PerspectiveProjectionXOY(double distance);

Matrix<double> PerspectiveProjectionZOX(double distance);

Matrix<double> PerspectiveProjectionYOZ(double distance);

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