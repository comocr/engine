# include "LiteralClass.h"

BOOL LiteralClass::Generate(UINT y, UINT x, SymbolClass& Symbol, UINT iFont, UINT iSymbol, BOOL bLeft, BOOL bRight, BOOL bBottom, BOOL bTop)
{
	UINT sWhite = 0;
	UINT sBlack = 0;

	if(bLeft)
		sWhite += Symbol.Left();
	if(bRight)
		sWhite += Symbol.Right();
	if(bBottom)
		sWhite += Symbol.Bottom();
	if(bTop)
		sWhite += Symbol.Top();

	if(Symbol.BottomLeft())
		if(bLeft || bBottom)
			sWhite++;
	if(Symbol.BottomRight())
		if(bRight || bBottom)
			sWhite++;
	if(Symbol.TopLeft())
		if(bLeft || bTop)
			sWhite++;
	if(Symbol.TopRight())
		if(bRight || bTop)
			sWhite++;

	Compare(y, x, Symbol, sWhite, sBlack, bLeft, bRight, bBottom, bTop);
	return Check(y-(int)bBottom, x-(int)bLeft, iFont, iSymbol, Symbol, sWhite, sBlack);
}

BOOL LiteralClass::Generate(UINT y, UINT x, SymbolClass& Symbol, UINT iFont, UINT iSymbol)
{
	UINT sWhite = 0;
	UINT sBlack = 0;
	Compare(y, x, Symbol, sWhite, sBlack);
	return Check(y, x, iFont, iSymbol, Symbol, sWhite, sBlack);
}

VOID LiteralClass::Compare(UINT y, UINT x, SymbolClass &Symbol, UINT& sWhite, UINT& sBlack, BOOL bLeft, BOOL bRight, BOOL bBottom, BOOL bTop)
{
	UINT kEnd = (bTop)?Symbol.Height()-1:Symbol.Height();
	UINT lEnd = (bRight)?Symbol.Width()-1:Symbol.Width();
	for(UINT k = 0; k+(UINT)bBottom < kEnd; k++)
		for(UINT l = 0; l+(UINT)bLeft < lEnd; l++)
			switch(Symbol.PelVal(l+(UINT)bLeft, k+(UINT)bBottom))
			{
			case PEL_BLACK:
				if(PelVal(x+l, y+k) == PEL_BLACK)
					sBlack++;
				break;
			case PEL_WHITE:
				if(PelVal(x+l, y+k) == PEL_WHITE)
					sWhite++;
			};
}

VOID LiteralClass::Compare(UINT y, UINT x, SymbolClass &Symbol, UINT& sWhite, UINT& sBlack)
{
	for(UINT k = 0; k < Symbol.Height(); k++)
		for(UINT l = 0; l < Symbol.Width(); l++)
			switch(Symbol.PelVal(l, k))
			{
			case PEL_BLACK:
				if(PelVal(x+l, y+k) == PEL_BLACK)
					sBlack++;
				break;
			case PEL_WHITE:
				if(PelVal(x+l, y+k) == PEL_WHITE)
					sWhite++;
			};
}

BOOL LiteralClass::Check(UINT y, UINT x, UINT iFont, UINT iSymbol, SymbolClass& Symbol, UINT sWhite, UINT sBlack)
{
	FLOAT simillarity;
	simillarity = ((float)sWhite/(float)Symbol.White() + (float)sBlack/(float)Symbol.Black()) / (float)2;
	if(simillarity > Symbol.RAccuracy())
	{
		LiteralClass::fontIndex = iFont;
		LiteralClass::symbolIndex = iSymbol;
		LiteralClass::code = Symbol.Code();
		LiteralClass::simillarity = simillarity;
//		LiteralClass::sWhite = sWhite;
//		LiteralClass::sBlack = sBlack;
		lHang = Symbol.LHang();
		rHang = Symbol.RHang();
		BeginX(x);
		EndX(x+Symbol.Width()-1);
		BeginY(y);
		EndY(y+Symbol.Height()-1);
		return TRUE;
	}
	else
		return FALSE;
}

UINT LiteralClass::TBeginX()
{
	return (BeginX()+lHang);
}

UINT LiteralClass::TEndX()
{
	return (EndX()-rHang);
}

FLOAT LiteralClass::Subsume(LiteralClass_0* LP, UINT *fontI)
{
	SymbolClass& C = Font[(fontI[fontIndex])].Symbol[symbolIndex];
	SymbolClass& P = Font[(fontI[fontIndex])].Symbol[LP->symbolIndex];
	UINT sBlack = 0;
	UINT sWhite = 0;
	UINT tBlack = 0;
	UINT tWhite = 0;
	UINT x = BeginX()-(LP->BeginX());
	UINT y = BeginY()-(LP->BeginY());
	if((int)x < 0 || (int)y < 0)	// Should Guard for corner 0 begin
		return 0;
	for(UINT k = 0; k < C.Height(); k++)
		for(UINT l = 0; l < C.Width(); l++)
			switch(C.PelVal(l, k))
			{
			case PEL_BLACK:
				tBlack++;
				if(P.PelVal(x+l, y+k) == PEL_BLACK)
					sBlack++;
				break;
			case PEL_WHITE:
				tWhite++;
				if(P.PelVal(x+l, y+k) == PEL_WHITE)
					sWhite++;
			};
	return ((float)sWhite/(float)tWhite + (float)sBlack/(float)tBlack) / (float)2;
}
