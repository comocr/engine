# ifndef FONTSCLASS_HEADER
# define FONTSCLASS_HEADER

# define FONTS_DIR	L"Fonts\\"

/* Exit Codes: */
# define ERROR_SYMBOL_LOAD		-68549

# include "..\\Utilities\\Config\\ConfigClass.h"
# include "SymbolClass.h"

class FontClass
{
private:
	LPWSTR name;
	BOOL bItalic;
	BOOL bLeaping;
	UINT maxHSeparation;
//	UINT MaxVSeparation;
//	FLOAT MaxHypoWord;
	UINT nSymbols;

public:
	SymbolClass *Symbol;

	FontClass();
	VOID Add(LPWSTR name);

	static UINT nFonts;
	static UINT iFont;

	UINT Get_nSymbols();
	UINT MaxHSeparation();
	BOOL Leaping();
};

# endif
