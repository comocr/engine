# ifndef TEXT_CLASS_HEADER
# define TEXT_CLASS_HEADER

# include <Windows.h>

class TextClass
{
private:
	WCHAR* txtBuffer;
	UINT iBuffer;
public:
	TextClass();
	VOID Put(WCHAR c);
	VOID Space();
	VOID NewLine();
	LPBYTE Buffer();
	UINT Size();
};

# endif // TEXT_CLASS_HEADER
