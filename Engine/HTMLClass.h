# ifndef HTMLCLASS_HEADER
# define HTMLCLASS_HEADER

# define MAX_HTML_BUFFER_SIZE	10240

# define UNICODE_FILE_HEADER	0xFEFF
# define HTM_FILE_EXTN			L"htm"

# define SPACE					L' '

//------------------------------HTML
# define TAG_TITLE				L"title"
# define TAG_PARAGRAPH			L"p"
# define TAG_LINE_BREAK			L"br"
# define TAG_ITALIC				L"i"

# define TAG_I_TITLE			0
# define TAG_I_PARAGRAPH		1 
# define TAG_I_LINE_BREAK		2
# define TAG_I_ITALIC			3

# define HTML_HEADER
# define ITALIC_STYLE_ELEMENT	L"<style type=\"text/css\"> i {color:red;} </style>\r\n"

# include <windows.h>

struct TagStruct
{
	LPWSTR tag;
	UINT len;
};

class HTMLClass
{
private:
	WCHAR *htmlBuffer;
	UINT iBuffer;
public:
	TagStruct *tags;
	HTMLClass();
	VOID Reset();
	VOID Put(WCHAR oneByte);
	VOID Put(LPWSTR manyWchars, UINT nBytes);
	VOID Space();
	VOID NewLine();
	VOID BeginTag(UINT tagID);
	VOID CloseTag(UINT tagID);
	VOID Tag(UINT tagID);
	bool Write(LPWSTR fileName);
	LPBYTE Buffer();
	UINT Size();
};

# endif
