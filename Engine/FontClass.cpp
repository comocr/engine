# include "Engine.h"
# include <wchar.h>
# include "FontClass.h"

# define FONT_CONFIG_FILE		L"Font.ini"

//extern UINT g_ObjectMode;
//extern bool g_bFormating;
//extern bool g_bItalicStyle;
//extern UINT g_iSection;
//extern UINT g_nAWords;
//extern SectionClass Section[MAX_SECTION_FONTS];
//extern UINT g_nSections;

UINT FontClass::nFonts = 0;
UINT FontClass::iFont = 0;

FontClass::FontClass()
{
//	Fonts = new FontStruct[MAX_N_FONTS];
}

VOID FontClass::Add(LPWSTR name)
{
	UINT nameLen =(UINT)wcslen(name)+1;
	FontClass::name = new WCHAR[nameLen];
	wcscpy_s(FontClass::name, nameLen, name);
	ConfigClass Config;

	LPWSTR oPath = new WCHAR[MAX_FILE_NAME_LEN];
	GetCurrentDirectory(MAX_FILE_NAME_LEN, oPath);

	LPWSTR nPath = new WCHAR[MAX_FILE_NAME_LEN];
	wcscpy_s(nPath, MAX_FILE_NAME_LEN, FONTS_DIR);
	wcscat_s(nPath, MAX_FILE_NAME_LEN, name);
	SetCurrentDirectory(nPath);
	delete nPath;

	Config.Load(FONT_CONFIG_FILE);

	maxHSeparation = Config.GetInt();
	bItalic = Config.GetBool();
	bLeaping = Config.GetBool();
	nSymbols = Config.GetInt();
	Symbol = new SymbolClass[nSymbols];

	for(UINT i = 0; i < nSymbols; i++)
	{
		Symbol[i].Code(Config.GetChar());
		UINT len = Config.GetTokenLen()+sizeof(L"." BMP_FILE_EXTN)+1;
		LPWSTR filePath = new WCHAR[len];
		Config.GetString(filePath, len);
		wcscat_s(filePath, len, L"." BMP_FILE_EXTN);

		if(!Symbol[i].LoadBMP(filePath))
			exit(ERROR_SYMBOL_LOAD);
		Symbol[i].CountBorder();
		Symbol[i].RAccuracy(Config.GetFloat()/100);

		Symbol[i].LHang(bLeaping?Config.GetInt():0);
		Symbol[i].RHang(bLeaping?Config.GetInt():0);
	}

	SetCurrentDirectory(oPath);
	delete oPath;
}

UINT FontClass::Get_nSymbols()
{
	return nSymbols;
}

UINT FontClass::MaxHSeparation()
{
	return maxHSeparation;
}

BOOL FontClass::Leaping()
{
	return bLeaping;
}
