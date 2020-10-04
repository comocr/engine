# include "GroupClass_1.h"

UINT GroupClass_1::NLine(GLayoutClass& GLayout)
{
	nLines = 0;
	for(UINT i = 0; i < nSections; i++)
		if(GLayout.GetPart(i) != SECTION_LEFT)	// or SECTION_RIGHT
			nLines += Section[i].NLine();
	return nLines;
}

UINT GroupClass_1::NSections()
{
	return nSections;
}

UINT GroupClass_1::NLine()
{
	return nLines;
}

UINT GroupClass_1::NSLine(UINT iSection)
{
	return Section[iSection].NLine();
}

UINT GroupClass_1::NSLWords(UINT iSection, UINT iLine)
{
	return Section[iSection].NLWord(iLine);
}
/*
UINT GroupClass_1::WordBeginX(UINT iSection, UINT iLine, UINT iWord)
{
	return Section[iSection].WordBeginX(iLine, iWord);
}
*/