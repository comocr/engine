# include "SymbolClass.h"

SymbolClass::SymbolClass()
{
	top = 0;
	bottom = 0;
	left = 0;
	right = 0;
}

BOOL SymbolClass::LoadBMP(LPWSTR filePath)
{
	return Img.LoadBMP(filePath, TRUE);
}

VOID SymbolClass::CountBorder()
{
	for(UINT x = 1; x < Img.Width()-1; x++)
		if(Img.PelVal(x, Img.Height()-1) == PEL_WHITE)
			top++;
	for(UINT x = 1; x < Img.Width()-1; x++)
		if(Img.PelVal(x, 0) == PEL_WHITE)
			bottom++;
	for(UINT y = 1; y < Img.Height()-1; y++)
		if(Img.PelVal(0, y) == PEL_WHITE)
			left++;
	for(UINT y = 1; y < Img.Height()-1; y++)
		if(Img.PelVal(Img.Width()-1, y) == PEL_WHITE)
			right++;
	bTopLeft = (Img.PelVal(0, Img.Height()-1) == PEL_WHITE);
	bTopRight = (Img.PelVal(Img.Width()-1, Img.Height()-1) == PEL_WHITE);
	bBottomLeft = (Img.PelVal(0, 0) == PEL_WHITE);
	bBottomRight = (Img.PelVal(Img.Width()-1, 0) == PEL_WHITE);
}

LPBYTE SymbolClass::BitMap()
{
	return Img.bitMap;
}

BYTE SymbolClass::PelVal(UINT x, UINT y)
{
	return Img.PelVal(x, y);
}

UINT SymbolClass::Height()
{
	return Img.height;
}

UINT SymbolClass::Width()
{
	return Img.width;
}

UINT SymbolClass::White()
{
	return Img.white;
}

UINT SymbolClass::Black()
{
	return Img.black;
}

UINT SymbolClass::Left()
{
	return left;
}

UINT SymbolClass::Right()
{
	return right;
}

UINT SymbolClass::Bottom()
{
	return bottom;
}

UINT SymbolClass::Top()
{
	return top;
}

UINT SymbolClass::BottomLeft()
{
	return bBottomLeft;
}

UINT SymbolClass::BottomRight()
{
	return bBottomRight;
}

UINT SymbolClass::TopLeft()
{
	return bTopLeft;
}

UINT SymbolClass::TopRight()
{
	return bTopRight;
}

VOID SymbolClass::RAccuracy(FLOAT a)
{
	rAccuracy = a;
}

FLOAT SymbolClass::RAccuracy()
{
	return rAccuracy;
}


VOID SymbolClass::Code(WCHAR c)
{
	code = c;
}

VOID SymbolClass::LHang(UINT d)
{
	lHang = d;
}

VOID SymbolClass::RHang(UINT d)
{
	rHang = d;
}

WCHAR SymbolClass::Code()
{
	return code;
}

UINT SymbolClass::LHang()
{
	return lHang;
}

UINT SymbolClass::RHang()
{
	return rHang;
}
