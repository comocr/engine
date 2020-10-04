# include "LiteralClass_0.h"

# include "FontClass.h"
# include "SymbolClass.h"

extern FontClass *Font;

class LiteralClass : public LiteralClass_0
{
public:
	FLOAT simillarity;
	BOOL Generate(UINT i, UINT j, SymbolClass& Symbol, UINT iFont, UINT iSymbol, BOOL bLeft, BOOL bRight, BOOL bBottom, BOOL bTop);
	BOOL Generate(UINT i, UINT j, SymbolClass& Symbol, UINT iFont, UINT iSymbol);
	VOID Compare(UINT i, UINT j, SymbolClass& Symbol, UINT& sWhite, UINT& sBlack, BOOL bLeft, BOOL bRight, BOOL bBottom, BOOL bTop);
	VOID Compare(UINT i, UINT j, SymbolClass& Symbol, UINT& sWhite, UINT& sBlack);
	BOOL Check(UINT i, UINT j, UINT iFont, UINT iSymbol, SymbolClass& Symbol, UINT sWhite, UINT sBlack);
	UINT TBeginX();
	UINT TEndX();
	FLOAT Subsume(LiteralClass_0* LP, UINT *iFont);

};
