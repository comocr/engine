# include "GLayoutClass.h"

# define SECTION_BLOCK_PX			0
# define SECTION_BLOCK_REMAIN		1

VOID GLayoutClass::InitSections(UINT nSections)
{
	GLayoutClass::nSections = nSections;
	Layout = new LayoutClass[nSections];
}

VOID GLayoutClass::SetBlock(UINT beginX, UINT endX, UINT beginY, UINT endY)
{

}

VOID GLayoutClass::SetType(UINT type)
{
	GLayoutClass::type = type;
}

VOID GLayoutClass::SetIndex(UINT index)
{
	GLayoutClass::index = index;
}

VOID GLayoutClass::SetPart(UINT iSection, UINT part)
{
	Layout[iSection].SetPart(part);
}

VOID GLayoutClass::TFonts(UINT iSection, UINT nFonts)
{
	Layout[iSection].TFonts(nFonts);
}

VOID GLayoutClass::AddFontI(UINT iSection, UINT iFont, UINT maxHSeparation, BOOL bLeaping)
{
	Layout[iSection].AddFontI(iFont, maxHSeparation, bLeaping);
}

UINT GLayoutClass::GetType()
{
	return type;
}

UINT GLayoutClass::GetIndex()
{
	return index;
}

VOID GLayoutClass::GetBlock(UINT &beginX, UINT &endX, UINT &beginY, UINT &endY)
{
	beginX = GLayoutClass::beginX;
	endX = GLayoutClass::endX;
	beginY = GLayoutClass::beginY;
	endY = GLayoutClass::endY;
}

UINT GLayoutClass::GetPart(UINT iSection)
{
	return Layout[iSection].GetPart();
}

UINT GLayoutClass::GetNSections()
{
	return nSections;
}

VOID GLayoutClass::Serialize(LPBYTE buffer, UINT& iBuffer)
{
	Put(buffer, iBuffer, (LPBYTE)&type, sizeof(UINT));
	if(type == SECTION_BLOCK_PX)
	{
		Put(buffer, iBuffer, (LPBYTE)&beginX, sizeof(UINT));
		Put(buffer, iBuffer, (LPBYTE)&endX, sizeof(UINT));
		Put(buffer, iBuffer, (LPBYTE)&beginY, sizeof(UINT));
		Put(buffer, iBuffer, (LPBYTE)&endY, sizeof(UINT));
	}
	Put(buffer, iBuffer, (LPBYTE)&index, sizeof(UINT));
	Put(buffer, iBuffer, (LPBYTE)&nSections, sizeof(UINT));
	for(UINT i = 0; i < nSections; i++)
		Layout[i].Serialize(buffer, iBuffer);
}

VOID GLayoutClass::Put(LPBYTE buffer, UINT& iBuffer, const LPBYTE bytes, UINT nBytes)	// Utilities
{
	for(UINT i = 0; i < nBytes; i++)
		buffer[iBuffer++] = bytes[i];
}

VOID GLayoutClass::DeSerialize(LPBYTE buffer, UINT& iBuffer)
{
	Get(buffer, iBuffer, (LPBYTE)&type, sizeof(UINT));
	if(type == SECTION_BLOCK_PX)
	{
		Get(buffer, iBuffer, (LPBYTE)&beginX, sizeof(UINT));
		Get(buffer, iBuffer, (LPBYTE)&endX, sizeof(UINT));
		Get(buffer, iBuffer, (LPBYTE)&beginY, sizeof(UINT));
		Get(buffer, iBuffer, (LPBYTE)&endY, sizeof(UINT));
	}
	Get(buffer, iBuffer, (LPBYTE)&index, sizeof(UINT));
	Get(buffer, iBuffer, (LPBYTE)&nSections, sizeof(UINT));
	Layout = new LayoutClass[nSections];
	for(UINT i = 0; i < nSections; i++)
		Layout[i].DeSerialize(buffer, iBuffer);
}

VOID GLayoutClass::Get(const LPBYTE buffer, UINT& iBuffer, LPBYTE bytes, UINT nBytes)	// Utilities
{
	for(UINT i = 0; i < nBytes; i++)
		bytes[i] = buffer[iBuffer++];
}

LayoutClass& GLayoutClass::GetLayout(UINT iSection)
{
	return Layout[iSection];
}
