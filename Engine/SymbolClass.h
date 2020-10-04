# ifndef SYMBOLCLASS_HEADER
# define SYMBOLCLASS_HEADER

# include "ImageClass.h"

class SymbolClass
{
private:
	ImageClass Img;

	UINT left;
	UINT right;
	UINT bottom;
	UINT top;
	BOOL bBottomLeft;
	BOOL bBottomRight;
	BOOL bTopLeft;
	BOOL bTopRight;

	FLOAT rAccuracy;

	WCHAR code;
	UINT lHang;
	UINT rHang;

public:
	SymbolClass();
	BOOL LoadBMP(LPWSTR filePath);

	LPBYTE BitMap();
	BYTE PelVal(UINT x, UINT y);
	UINT White();
	UINT Black();

	UINT Height();
	UINT Width();

	VOID CountBorder();

	FLOAT RAccuracy();
	VOID RAccuracy(FLOAT a);

	UINT Left();
	UINT Right();
	UINT Bottom();
	UINT Top();
	UINT BottomLeft();
	UINT BottomRight();
	UINT TopLeft();
	UINT TopRight();

	VOID Code(WCHAR c);
	VOID LHang(UINT d);
	VOID RHang(UINT d);

	WCHAR Code();
	UINT LHang();
	UINT RHang();
};

# endif
