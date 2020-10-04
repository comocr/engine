# include "MainWindowClass.h"

extern HINSTANCE g_hInstance;
extern LRESULT CALLBACK MainProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

MainWindowClass::MainWindowClass()
{
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = MainProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
	wc.lpszMenuName = NULL;
	// = MAIN_WINDOW_CLASS;

	szWindowClass = new WCHAR[MAX_WINDOW_CLASS_LEN];
	szWindowTitle = new WCHAR[MAX_WINDOW_TITLE_LEN];
};

VOID MainWindowClass::Create()
{
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hInstance = g_hInstance;
	wc.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ENGINE_ICON));
	wc.hIconSm = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ENGINE_ICON));
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, ERROR_REG_WINDOW, WINDOW_TITLE, MB_ICONERROR | MB_OK);
		exit(-1);
	}

	hWnd = CreateWindowEx(
		0,
		WINDOW_CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH)/2,
		(GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT)/2,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL, NULL, g_hInstance, NULL);

	if(hWnd == NULL)
	{
		MessageBox(NULL, EROOR_CREATE_WINDOW, WINDOW_TITLE, MB_ICONERROR | MB_OK);
		exit(-2);
	}
};
