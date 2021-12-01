#include <windows.h>
#include <windowsx.h>
#include <string>
#include <map>
#include "Data.h"
#include "Scene2D.h"

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

/**/
Matrix<double> V
{
	{1.0, 1.0, 2.0, 2.0},
	{1.0, 2.0, 1.0, 2.0},
	{1.0, 1.0, 1.0, 1.0}
};

Matrix<int> E
{
	{0, 1, 1, 0},
	{1, 0, 0, 1},
	{1, 0, 0, 1},
	{0, 1, 1, 0}
};

Model2D model(V, E);

/*
Model2D model("vertices.txt", "edges.txt");
*/

LRESULT _stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)		// ������� ��������� ��������� � ������������ ��� ���������, ������������ ����
{
	const char KEY_W = 0x57;
	Scene2D* scene = windows[hWnd];
	switch (msg)
	{
	case WM_CREATE:
	{
		windows[hWnd] = new Scene2D(hWnd, L, R, B, T, model);
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
	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_UP:
				{
					scene->GetModel().Apply(Translation(1, 0));
					break;
				}
			case VK_DOWN:
				{
					
					break;
				}
			case VK_LEFT:
				{
					
					break;
				}
			case VK_RIGHT:
				{
					
					break;
				}
			case KEY_W:
				{
					
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