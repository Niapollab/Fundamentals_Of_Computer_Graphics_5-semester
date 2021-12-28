#include <windows.h>
#include <windowsx.h>
#include <string>
#include <map>
#include "Data.h"
#include "Scene2D.h"
#include "FileModelReader.h"

#define moveCoeff	0.1
#define	scalCoeff	0.05
#define	rotateCoeff	0.1
#define	distCoeff	1

LRESULT _stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);						// �������� ������� ���������
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)		// �������� ���������
{
		// ������ ������������ ����� �������� ��������� - �������� ����: ������� ����������� ������� ����� wc, ����� �������� ���� hWnd
	WNDCLASS wc;
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;						// ��� ������� ���������, ������������ �� ������ �������
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;						// ������������� ����������, ���������� ����� ������ ���������� ��� ������� ������
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(6);
	wc.lpszMenuName = 0;							// ���� � ������� ������ �����������
	wc.lpszClassName = (LPCSTR)"MainWindowClass";	// ��� �������� ������, ������������ ��� �������� ����������� ����
	RegisterClass(&wc);								// ����������� ������ wc

	HWND hWnd = CreateWindow(						// hWnd - ����������, ���������������� ����; ������� �������� ���� ��������� ���������� hWnd ��������� ���������
		(LPCSTR)"MainWindowClass",					// ��� �������� ������
		(LPCSTR)"Lab3 - 3D Engine",					// ��������� ����
		WS_OVERLAPPEDWINDOW,						// ����� ����
		200, 200, 400, 400,							// ���������� �� ������ ������ �������� ���� ����, ��� ������ � ������
		nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ������ ������������ ����� �������� ��������� - �������� ���� ��������� ��������� ���������, ������� ������� ��������� � ��������� �� ��������������� �����
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))				// ������� GetMessage �������� �� ������� ��������� � ������� ��� � ��������� msg
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);						// ������� DispatchMessage ��������� ������� � ������������� ������ ������� ���������
	}

	return 0;
}

// � �������� ������ ����������� ������ ���� ���������� ���������� - �������� ������ ������ Scene2D
// ��� ���������� �������� �������������� ����������� ��������� � �������, ������������� � ���� ������
std::map<HWND, Scene2D*> windows;

FileModelReader reader("elephant.txt");
Model2D model = reader.Read2DModel();

LRESULT _stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)		// ������� ��������� ��������� � ������������ ��� ���������, ������������ ����
{
	const char KEY_W = 0x57;
	const char KEY_Q = 0x51;
	const char KEY_E = 0x45;

	Scene2D* scene = windows[hWnd];
	switch (msg)
	{
	case WM_CREATE:
	{
		windows[hWnd] = new Scene2D(hWnd, X0, Y0, px, py, model);
		return 0;
	}
	case WM_PAINT:
		{
			scene->Clear();				// ����� �������������� � ������ Camera2D ������, ����������� �� ������� ������� ������� ���� hWnd
			scene->Render();
			ReleaseDC(hWnd, scene->GetDC());
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	case WM_SIZE:
		{
			scene->SetResolution();
			ReleaseDC(hWnd, scene->GetDC());
			InvalidateRect(hWnd, nullptr, false);
			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	case WM_MOUSEWHEEL:
		{
			Model2D& model = scene->GetModel();
			double wheelNow = GET_WHEEL_DELTA_WPARAM(wParam);

			if (wheelNow > 0) {
				model.Apply(Scaling(1.5, 1.5));
			}
			else {
				model.Apply(Scaling(0.75, 0.75));
			}

			InvalidateRect(hWnd, nullptr, false);
		}
	case WM_KEYDOWN:
		{
			Model2D& model = scene->GetModel();
			switch (wParam)
			{
			case VK_UP:
				{
					model.Apply(Translation(0, 1));
					break;
				}
			case VK_DOWN:
				{
					model.Apply(Translation(0, -1));
					break;
				}
			case VK_LEFT:
				{
					model.Apply(Translation(-1, 0));
					break;
				}
			case VK_RIGHT:
				{
					model.Apply(Translation(1, 0));
					break;
				}
			case KEY_W:
				{
					auto edge_point_start = model.GetVertex(0);
					auto edge_point_end = model.GetVertex(1);

					model.Apply(Translation(-edge_point_start.x(), -edge_point_start.y()))
						.Apply(Rotation2D(edge_point_end.x() - edge_point_start.x(), edge_point_end.y() - edge_point_start.y()))
						.Apply(Reflect2DOY())
						.Apply(Rotation2D(edge_point_end.x() - edge_point_start.x(), edge_point_start.y() - edge_point_end.y()))
						.Apply(Translation(edge_point_start.x(), edge_point_start.y()));
					
					break;
				}
			case KEY_Q:
				{
					auto point = model.GetVertex(0);

					model.Apply(Translation(-point.x(), -point.y()))
						.Apply(Rotation2D(M_PI / 4))
						.Apply(Translation(point.x(), point.y()));

					break;
				}
			case KEY_E:
				{
					auto point = model.GetVertex(0);

					model.Apply(Translation(-point.x(), -point.y()))
						.Apply(Rotation2D(-M_PI / 4))
						.Apply(Translation(point.x(), point.y()));

					break;
				}
			}
			InvalidateRect(hWnd, NULL, false);
			return 0;
		}

	default:
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}
	return 0;
}