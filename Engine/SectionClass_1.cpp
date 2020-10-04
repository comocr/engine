# include "SectionClass_1.h"

UINT SectionClass_1::NLine()
{
	return nLines;
}

UINT SectionClass_1::NLWord(UINT iLine)
{
	return Line[iLine]->NWord();
}

UINT SectionClass_1::WordBeginX(UINT iLine, UINT iWord)
{
	return Line[iLine]->WordBeginX(iWord);
}
