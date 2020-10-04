# ifndef MAINWINDOWCLASS_HEADER
# define MAINWINDOWCLASS_HEADER

# include <Windows.h>

# include "Resource.h"
# include "..\\..\\CommonIDs.h"

# ifndef MAX_WINDOW_CLASS_LEN
# define MAX_WINDOW_CLASS_LEN	500
# endif
# ifndef MAX_WINDOW_TITLE_LEN
# define MAX_WINDOW_TITLE_LEN	500
# endif


# define WINDOW_CLASS_NAME		L"Main"
# define WINDOW_NAME			L"Pankh OCR Engine"

# define WINDOW_TITLE			L"OCR Engine Error"

# define ERROR_REG_WINDOW		L"Error Registering Window"
# define EROOR_CREATE_WINDOW	L"Error Creating Window"

# define WINDOW_WIDTH			600
# define WINDOW_HEIGHT			400

class MainWindowClass
{
private:
	WNDCLASSEX wc;
	LPWSTR szWindowClass;
	LPWSTR szWindowTitle;
public:
	HWND hWnd;
	MainWindowClass();
	VOID Create();
};

# endif
