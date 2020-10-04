# include "Main.h"

# define MAX_MENU_COMMAND_L		16

# define S_MESSAGE_TITLE				L"Settings Error"
# define INVALID_REG_SETTINGS			0x0000103
# define S_ERROR_INVALID_REG_SETTINGS	L"Invalid Registry Sttings"

extern DWORD WINAPI EngineThread(LPVOID lpParameter);

HINSTANCE g_hInstance;

TaskIconClass TaskIcon;
MainWindowClass MainWindow;
LocaleClass Locale;
SettingsClass Settings(HKEY_CURRENT_USER, SOFTWARE_REG_KEY SETTINGS_KEY, SETTINGS_ID_BASE, SETTINGS_N_VAR, SETTINGS_N_FLOAT, SETTINGS_N_STRING);
NotifyMessageBoxClass NotifyMessageBox;
SplashWindowClass SplashWindow;

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
	g_hInstance = hInstance;

	if(!Settings.Load())
	{
		MessageBox(NULL, S_ERROR_INVALID_REG_SETTINGS, S_MESSAGE_TITLE, MB_OK);
		exit(INVALID_REG_SETTINGS);
	}

	MSG msg;
	DWORD dwThreadId;
	HANDLE hThread;

	MainWindow.Create();
	SplashWindow.Create(hInstance, IDI_ENGINE_ICON, MainWindow.hWnd);
	NotifyMessageBox.Set_hWnd(MainWindow.hWnd);
	TaskIcon.Init(hInstance, MainWindow.hWnd, IDI_ENGINE_ICON);
	Locale.GetString(IDS_NOTIFICATION_ID, TaskIcon.NotifyIconData.szTip, 128);
	Locale.GetString(IDS_NOTIFICATION_TITLE, TaskIcon.NotifyIconData.szInfoTitle, 64);
	Locale.GetString(IDS_NOTIFICATION_BEGIN, TaskIcon.NotifyIconData.szInfo, 256);
	if(Settings.GetValue(SHOW_NOTIFICATIONS))
		TaskIcon.NotifyIconData.uFlags |= NIF_INFO;

	TaskIcon.Add();

	LPWSTR tmp = new WCHAR[MAX_MENU_COMMAND_L];

	Locale.GetString(IDS_EXIT, tmp, MAX_MENU_COMMAND_L);
	AppendMenu(TaskIcon.hMenu_SysTray, MF_STRING, ID_TRAY_EXIT, tmp);
	Locale.GetString(IDS_ABOUT, tmp, MAX_MENU_COMMAND_L);
	AppendMenu(TaskIcon.hMenu_SysTray, MF_STRING, ID_TRAY_ABOUT, tmp);

	hThread = CreateThread(NULL, 0, EngineThread, lpCmdLine, 0, &dwThreadId);
	if (hThread == NULL)
		NotifyMessageBox.NotifyMessage(IDS_THREAD_FAIL, IDS_ERROR, MB_ICONERROR | MB_OK);

	ShowWindow(MainWindow.hWnd, SW_HIDE);
	if(Settings.GetValue(SHOW_SPLASH))
	{
		ShowWindow(SplashWindow.HWnd(), nShowCmd);
		SplashWindow.BeginFade();
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};

	if(Settings.GetValue(PLAY_END_SOUND))
		MessageBeep(MB_ICONASTERISK);
	TaskIcon.Remove();
	return 0;
}

LRESULT CALLBACK MainProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_TIMER:
		switch(wParam)
		{
		case ID_TIMER_1:
			PostQuitMessage(WM_QUIT);
			return 0;
		}
		return 0;
	case WM_CLOSE:
		PostQuitMessage(WM_QUIT);
		return 0;
	case CM_TRAYICON:
		{
			switch(wParam)
			{
			case IDI_ENGINE_ICON:
				break;
			}

			switch(lParam)
			{
			case WM_LBUTTONUP:
				//Restore(NotifyIconData);
				break;
			case WM_RBUTTONDOWN:
				{

					POINT curPoint ;
					GetCursorPos( &curPoint ) ;

					SetForegroundWindow(hWnd); 

					TrackPopupMenu(						// TrackPopupMenu blocks
						TaskIcon.hMenu_SysTray,
						TPM_NONOTIFY,
						curPoint.x,
						curPoint.y,
						0,
						hWnd,
						NULL
						);

					//SendMessage(hWnd, WM_NULL, 0, 0); // Send benign message to window to make sure the menu goes away.
				}
			}
			return 0;
		case WM_COMMAND:
			{
				switch(LOWORD(wParam))
				{
				case ID_TRAY_EXIT:
					PostQuitMessage( 0 );
					break;
				case ID_TRAY_ABOUT:
					SplashWindow.BeginFade();
					ShowWindow(SplashWindow.HWnd(), SW_NORMAL);
				}
			}
			return 0;
		}
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
