#include "DebugLog.h"
#include <chrono>
#include <Windows.h>
#include <WinUser.h>

void Initialize()
{
	DebugLog::DebugOut("Initialize\n");
}

void ReadInput()
{
	DebugLog::DebugOut("Read input\n");
}

void Update()
{
	DebugLog::DebugOut("Update\n");
}

void Render()
{
	DebugLog::DebugOut("Render\n");
}


void Terminate()
{
	DebugLog::DebugOut("Terminate\n");
}


HWND windowHandle;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}


int WINAPI WinMain(
	_In_ HINSTANCE hInstance = GetModuleHandle(nullptr),
	_In_ HINSTANCE hPrevInstance = nullptr,
	_In_ LPSTR     lpCmdLine = GetCommandLineA(),
	_In_ int       nCmdShow = 1
)
{
	WNDCLASSEX wc; //window class extended structure

	wc.cbSize = sizeof(WNDCLASSEX); //how much memory to take up
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	wc.hIconSm = 0;

	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = "FullMetalEngine";
	wc.lpszMenuName = 0;

	wc.hCursor = LoadCursorA(0, IDC_ARROW);
	wc.hIcon = LoadIconA(0, IDI_APPLICATION);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassEx(&wc);

	windowHandle = CreateWindowExA(WS_EX_OVERLAPPEDWINDOW, "FullMetalEngine", "Game Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 800, 600, 0, 0, hInstance, 0);


	if (windowHandle == 0)
	{
		MessageBoxA(0, "Create Window Failed", "Error Message", 0);
		return 0;
	}

	ShowWindow(windowHandle, nCmdShow);

	UpdateWindow(windowHandle);

	MSG msg;

	SecureZeroMemory(&msg, sizeof(MSG));

	int returnVal = 0;

	while ((returnVal = GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if (returnVal == -1)
		{
			MessageBoxA(windowHandle, "GetMessage Failed!", "Error Message", 0);
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);


	}

	return (int)msg.wParam;

	DebugLog::DebugOut("We're in the WinMain\n");
	return 0;
}

int main()
{
#ifdef _WIN32
	DebugLog::DebugOut("This is Windows\n");
	WinMain();
#endif

	DebugLog::DebugOut("idk\n");
	//bool quit = false;

	////Setup systems/initialize prereq work
	//Initialize();


	////Main game loop
	//while (!quit)
	//{
	//	ReadInput();
	//	Update();
	//	Render();

	//}
	//
	////Properly shutdown systems and close application
	//Terminate();




	
	//DebugLog::DebugOut("Hello\n");
	//int x = 5;
	//DebugLog::DebugOut("Hello %d\n", x);
	//return 0;
}

