# ifndef LAYOUT_CLASS_HEADER
# define LAYOUT_CLASS_HEADER

# include <Windows.h>

class LayoutClass
{
private:
	//UINT type;
	//UINT index;
	UINT part;
	UINT nFonts;
	UINT *fontI;
	UINT iFont;

	UINT maxHSeparation;
	BOOL bLeaping;

public:
	LayoutClass();
	VOID InitSection(UINT nFonts);
	VOID SetPart(UINT part);
	//VOID SetMaxHSeparation(UINT dX);
	//VOID SetLeaping();
	VOID TFonts(UINT nFonts);
	UINT TFonts();
	VOID AddFontI(UINT iFont, UINT dX, BOOL bLeaping);
	UINT *FontI();
	UINT GetPart();
	UINT GetMaxHSeparation();
	UINT GetLeaping();

	VOID Serialize(LPBYTE buffer, UINT& iBuffer);
	VOID DeSerialize(LPBYTE buffer, UINT& iBuffer);
	VOID Put(LPBYTE buffer, UINT& iBuffer, const LPBYTE bytes, UINT nBytes);
	VOID Get(const LPBYTE buffer, UINT& iBuffer, LPBYTE bytes, UINT nBytes);
};

# endif LAYOUT_CLASS_HEADER
