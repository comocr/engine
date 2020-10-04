# include "HTMLClass.h"

# define NTAGS			4

//# define TAG_I_PARAGRAPH	0 
//# define TAG_I_LINE_BREAK	1
//# define TAG_I_ITALIC		2

# ifndef TAG_TITLE
	# define TAG_TITLE		L"title"
#endif
# ifndef TAG_PARAGRAPH
	# define TAG_PARAGRAPH	L"p"
# endif
# ifndef TAG_LINE_BREAK
	# define TAG_LINE_BREAK L"br"
# endif
# ifndef TAG_ITALIC
	# define TAG_ITALIC		L"i"
# endif

extern bool bFormating;
extern bool bItalicStyle;

HTMLClass::HTMLClass()
{
	htmlBuffer = new WCHAR[MAX_HTML_BUFFER_SIZE];
	iBuffer = 0;
	htmlBuffer[iBuffer++] = UNICODE_FILE_HEADER;
	tags = new TagStruct[NTAGS];
	tags[0].tag = TAG_TITLE;
	tags[0].len = 5;
	tags[1].tag = TAG_PARAGRAPH;
	tags[1].len = 1;
	tags[2].tag = TAG_LINE_BREAK;
	tags[2].len = 2;
	tags[3].tag = TAG_ITALIC;
	tags[3].len = 1;
}

VOID HTMLClass::Reset()
{
	iBuffer = 1;
}

VOID HTMLClass::Put(WCHAR c)
{
	htmlBuffer[iBuffer++] = c;
}

VOID HTMLClass::Put(LPWSTR szString, UINT nBytes)
{
	for(UINT i = 0; i < nBytes; i++)
		Put(szString[i]);
}

VOID HTMLClass::Space()
{
	htmlBuffer[iBuffer++] = SPACE;
}

VOID HTMLClass::NewLine()
{
//	htmlBuffer[iBuffer++] = CARRIAGE_RETURN;
//	htmlBuffer[iBuffer++] = LINE_FEED;
	Tag(TAG_I_LINE_BREAK);
}

VOID HTMLClass::BeginTag(UINT tagID)
{
	Put(L'<');
	for(UINT i = 0; i < tags[tagID].len; i++)
		Put(tags[tagID].tag[i]);
	Put(L'>');
}

VOID HTMLClass::CloseTag(UINT tagID)
{
	Put(L'<');
	Put(L'/');
	for(UINT i = 0; i < tags[tagID].len; i++)
		Put(tags[tagID].tag[i]);
	Put(L'>');
}

VOID HTMLClass::Tag(UINT tagID)
{
	Put(L'<');
	for(UINT i = 0; i < tags[tagID].len; i++)
		Put(tags[tagID].tag[i]);
	Put(L'/');
	Put(L'>');
}

LPBYTE HTMLClass::Buffer()
{
	return (LPBYTE)htmlBuffer;
}

UINT HTMLClass::Size()
{
	return iBuffer*(UINT)(sizeof(WCHAR));
}

bool HTMLClass::Write(LPWSTR fileName)
{
	HANDLE hFile;
	DWORD dwNumRead;
	BOOL bTest;

	wcscat_s(fileName, (wcslen(fileName)+4)*2, L"." HTM_FILE_EXTN);

	hFile = CreateFile(fileName, GENERIC_WRITE, FILE_SHARE_WRITE,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
		if(GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			MessageBox(NULL, L"Error Index: 0", L"Console", MB_OK | MB_ICONEXCLAMATION);
		}
		else
			MessageBox(NULL, L"Error", L"Console", MB_OK | MB_ICONEXCLAMATION);
	bTest = WriteFile(hFile, htmlBuffer, iBuffer*sizeof(WCHAR), &dwNumRead, NULL);
	CloseHandle(hFile);
	fileName[wcslen(fileName)-4] = NULL;
	return true;
}
