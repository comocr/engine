# include "LayoutClass.h"

# define SECTION_LINE				0
# define SECTION_BLOCK				1
# define SECTION_LINE_FIRST			0
# define SECTION_LINE_LAST			1
# define SECTION_LEFT				1
# define SECTION_RIGHT				2
# define SECTION_ALL				0

LayoutClass::LayoutClass()
{
	//iSection = 0;
	iFont = 0;
	maxHSeparation = 0;
	bLeaping = FALSE;
}

//VOID LayoutClass::Init(UINT n)
//{
//	nSections = n;
//	SectionL = new SectionLStruct(nSections);
//}

VOID LayoutClass::InitSection(UINT nFonts)
{
	//LayoutClass::nFonts = nFonts;
	fontI = new UINT[nFonts];	
}

VOID LayoutClass::SetPart(UINT part)
{
	LayoutClass::part = part;
}

//VOID LayoutClass::SetMaxHSeparation(UINT dX)
//{
//	maxHSeparation = dX;
//}

VOID LayoutClass::TFonts(UINT nFonts)
{
	LayoutClass::nFonts = nFonts;
	fontI = new UINT[nFonts];
}

VOID LayoutClass::AddFontI(UINT iFont, UINT dX, BOOL bLeaping)
{
	LayoutClass::fontI[LayoutClass::iFont] = iFont;
	if(maxHSeparation < dX)
		maxHSeparation = dX;
	if(bLeaping)
		LayoutClass::bLeaping = TRUE;
	//nFonts++;
}

UINT LayoutClass::TFonts()
{
	return nFonts;
}

UINT* LayoutClass::FontI()
{
	return fontI;
}

UINT LayoutClass::GetPart()
{
	return part;
}

UINT LayoutClass::GetMaxHSeparation()
{
	return maxHSeparation;
}

UINT LayoutClass::GetLeaping()
{
	return bLeaping;
}

VOID LayoutClass::Serialize(LPBYTE buffer, UINT& iBuffer)
{
	Put(buffer, iBuffer, (LPBYTE)&part, sizeof(UINT));
	Put(buffer, iBuffer, (LPBYTE)&nFonts, sizeof(UINT));
	for(UINT i = 0; i < nFonts; i++)
		Put(buffer, iBuffer, (LPBYTE)&(fontI[i]), sizeof(UINT));
	Put(buffer, iBuffer, (LPBYTE)&iFont, sizeof(UINT));
	Put(buffer, iBuffer, (LPBYTE)&maxHSeparation, sizeof(UINT));
	Put(buffer, iBuffer, (LPBYTE)&bLeaping, sizeof(BOOL));
}

VOID LayoutClass::Put(LPBYTE buffer, UINT& iBuffer, const LPBYTE bytes, UINT nBytes)	// Utilities
{
	for(UINT i = 0; i < nBytes; i++)
		buffer[iBuffer++] = bytes[i];
}

VOID LayoutClass::DeSerialize(LPBYTE buffer, UINT& iBuffer)
{
	Get(buffer, iBuffer, (LPBYTE)&part, sizeof(UINT));
	Get(buffer, iBuffer, (LPBYTE)&nFonts, sizeof(UINT));
	fontI = new UINT[nFonts];
	for(UINT i = 0; i < nFonts; i++)
		Get(buffer, iBuffer, (LPBYTE)&(fontI[i]), sizeof(UINT));
	Get(buffer, iBuffer, (LPBYTE)&iFont, sizeof(UINT));
	Get(buffer, iBuffer, (LPBYTE)&maxHSeparation, sizeof(UINT));
	Get(buffer, iBuffer, (LPBYTE)&bLeaping, sizeof(BOOL));
}

VOID LayoutClass::Get(const LPBYTE buffer, UINT& iBuffer, LPBYTE bytes, UINT nBytes)	// Utilities
{
	for(UINT i = 0; i < nBytes; i++)
		bytes[i] = buffer[iBuffer++];
}
