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

LRESULT _stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);						// прототип оконной процедуры
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)		// основная процедура
{
		// Первая составляющая часть основной процедуры - создание окна: сначала описывается оконный класс wc, затем создаётся окно hWnd
	WNDCLASS wc;
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;						// имя оконной процедуры, закрепленной за данным классом
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;						// идентификатор приложения, содержащий адрес начала выделенной ему области памяти
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(6);
	wc.lpszMenuName = 0;							// меню в оконном классе отсутствует
	wc.lpszClassName = (LPCSTR)"MainWindowClass";	// имя оконного класса, используемое при создании экземпляров окна
	RegisterClass(&wc);								// регистрация класса wc

	HWND hWnd = CreateWindow(						// hWnd - дескриптор, идентифицирующий окно; функция создания окна заполняет дескриптор hWnd ненулевым значением
		(LPCSTR)"MainWindowClass",					// имя оконного класса
		(LPCSTR)"Lab3 - 3D Engine",					// заголовок окна
		WS_OVERLAPPEDWINDOW,						// стиль окна
		200, 200, 400, 400,							// координаты на экране левого верхнего угла окна, его ширина и высота
		nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Вторая составляющая часть основной процедуры - основной цикл обработки системных сообщений, который ожидает сообщения и рассылает их соответствующим окнам
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))				// функция GetMessage выбирает из очереди сообщение и заносит его в структуру msg
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);						// функция DispatchMessage оповещает систему о необходимости вызова оконной процедуры
	}

	return 0;
}

// В основном модуле объявляется только одна глобальная переменная - создаётся объект класса Scene2D
// Все дальнейшие действия осуществляются посредством обращения к методам, реализованным в этом классе
std::map<HWND, Scene2D*> windows;

FileModelReader reader("elephant.txt");
Model2D model = reader.Read2DModel();

LRESULT _stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)		// оконная процедура принимает и обрабатывает все сообщения, отправленные окну
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
			scene->Clear();				// Вызов реализованного в классе Camera2D метода, отвечающего за очистку рабочей области окна hWnd
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