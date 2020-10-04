# include "TextClass.h"

# define TXT_FILE_EXTN			L"txt"
# define MAX_TEXT_BUFFER_SIZE	10240

# define UNICODE_FILE_HEADER	0xFEFF

# define SPACE					L' '
# define CARRIAGE_RETURN		L'\r' //0x0D
# define LINE_FEED				L'\n' //0x0A

TextClass::TextClass()
{
	txtBuffer = new WCHAR[MAX_TEXT_BUFFER_SIZE];
	iBuffer = 0;
	txtBuffer[iBuffer++] = UNICODE_FILE_HEADER;
}

void TextClass::Put(WCHAR c)
{
	txtBuffer[iBuffer++] = c;
}

void TextClass::Space()
{
	txtBuffer[iBuffer++] = SPACE;
}

void TextClass::NewLine()
{
	txtBuffer[iBuffer++] = CARRIAGE_RETURN;
	txtBuffer[iBuffer++] = LINE_FEED;
}

LPBYTE TextClass::Buffer()
{
	return (LPBYTE)txtBuffer;
}

UINT TextClass::Size()
{
	return iBuffer*(UINT)(sizeof(WCHAR));
}
