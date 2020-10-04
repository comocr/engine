# ifndef OCR_ENGINE_HEADER
# define OCR_ENGINE_HEADER

# include <Windows.h>
# include <Math.h>
# include <Strsafe.h>

# include "FontClass.h"
# include "TaskClass.h"
# include "..\\Utilities\\Files\\FilesClass.h"
//# include "..\\\NotifyMessageBoxClass.h"
# include "..\\Utilities\\Settings\\SettingsClass.h"
# include "..\\Utilities\\TaskIcon\\TaskIconClass.h"
# include "MainWindowClass.h"
# include "Lang\CommonLangIDs.h"

DWORD WINAPI EngineThread(LPVOID lpParameter);
VOID Update();

# endif
