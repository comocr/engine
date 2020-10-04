# ifndef MAIN_HEADER
# define MAIN_HEADER

# include "Resource.h"
# include "..\\..\\CommonIDs.h"
# include "..\\Lang\\CommonLangIDs.h"

# include <Windows.h>

# include "..\\Utilities\\TaskIcon\\TaskIconClass.h"
# include "..\\Utilities\\SplashWindow\\SplashWindowClass.h"
# include "..\\Utilities\\Locale\\LocaleClass.h"
# include "..\\Utilities\\Settings\\SettingsClass.h"
# include "..\\Utilities\\NotifyMessageBox\\NotifyMessageBoxClass.h"
# include "MainWindowClass.h"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd);
LRESULT CALLBACK MainProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

# endif
