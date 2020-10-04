# ifndef GLAYOUT_CLASS_HEADER
# define GLAYOUT_CLASS_HEADER

# include "LayoutClass.h"

class GLayoutClass
{
private:
	UINT type;
	UINT index;

	UINT beginX;		// Co-ordinates only for Block type Layout
	UINT endX;
	UINT beginY;
	UINT endY;

	UINT nSections;
	LayoutClass *Layout;

public:
	VOID InitSections(UINT nSections);
	VOID SetType(UINT type);
	VOID SetIndex(UINT index);
	VOID SetBlock(UINT beginX, UINT endX, UINT beginY, UINT endY);
	VOID SetPart(UINT iSection, UINT part);
	VOID TFonts(UINT iSection, UINT nFonts);
	VOID AddFontI(UINT iSection, UINT iFont, UINT maxHSeparation, BOOL bLeaping);

	UINT GetType();
	UINT GetIndex();
	VOID GetBlock(UINT& beginX, UINT& endX, UINT& beginY, UINT& endY);
	UINT GetPart(UINT iSection);
	UINT GetNSections();

	VOID Serialize(LPBYTE buffer, UINT& iBuffer);
	VOID DeSerialize(LPBYTE buffer, UINT& iBuffer);
	VOID Put(LPBYTE buffer, UINT& iBuffer, const LPBYTE bytes, UINT nBytes);
	VOID Get(const LPBYTE buffer, UINT& iBuffer, LPBYTE bytes, UINT nBytes);

	LayoutClass& GetLayout(UINT iSection);
};

# endif // GLAYOUT_CLASS_HEADER
