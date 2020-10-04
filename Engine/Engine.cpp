# include "Engine.h"

# define MAX_N_SYMBOLS			80
# define MAX_N_FILES			500
# define MAX_N_FONTS			10
# define MAX_FONT_NAME_LEN		100
# define MAX_FILE_NAME_LEN		200
# define MAX_WORD_LEN			1000
# define MAX_PATH_LEN			1000
# define MAX_WORD_HEIGHT		200
# define MAX_WORD_WIDTH			1000
# define MAX_INFO_LEN			256

# define SIZE_OF_FINISHED		10

# define EXIT_DELAY				1000

//# define LINE_HEIGHT_FRACTION	0.5
//# define LINE_BODY_TOP_TH		2.0
//# define LINE_BODY_BTM_TH		2.5

extern LocaleClass Locale;
extern SettingsClass Settings;
extern TaskIconClass TaskIcon;
extern MainWindowClass MainWindow;

FontClass *Font;
TaskClass Task;
FilesClass Files;

DWORD WINAPI EngineThread(LPVOID lpCmdLine)
{
	{
	ConfigClass Config((LPWSTR) lpCmdLine);

	LPWSTR wPath = new WCHAR[MAX_PATH_LEN];
	GetCurrentDirectory(MAX_PATH_LEN, wPath);

	LPWSTR mPath = new WCHAR[MAX_PATH_LEN];
	GetModuleFileName(NULL, mPath, MAX_PATH_LEN);
	FilesClass::GetFilePath(mPath);
	SetCurrentDirectory(mPath);
	delete mPath;

	Task.Create(Config);
	SetCurrentDirectory(wPath);

	delete wPath;
	}

	LPWSTR szInfo = new WCHAR[MAX_INFO_LEN];
	Locale.GetString(IDS_NOTIFICATION_FINISHED, szInfo, MAX_INFO_LEN);

	Files.InitLoadFileNames((LPWSTR)lpCmdLine, L"*." GIF_FILE_EXTN, false);

	Task.Execute((Settings.GetValue(SHOW_NOTIFICATIONS))? Update : NULL);

	if(Settings.GetValue(SHOW_NOTIFICATIONS))
	{
		Locale.GetString(IDS_NOTIFICATION_END, szInfo, MAX_INFO_LEN);
		TaskIcon.Modify(szInfo);
	}
	SetTimer(MainWindow.hWnd, ID_TIMER_1, EXIT_DELAY, NULL);
	delete szInfo;

	return true;
}

VOID Update()
{
	TaskIcon.Update(SIZE_OF_FINISHED, Files.CurName());
}
