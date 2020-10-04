# include "PageClass_1.h"

UINT PageClass_1::NGroup()
{
	return nGroups;
}

UINT PageClass_1::NGSection(UINT iGroup)
{
	return Group[iGroup].NSections();
}

UINT PageClass_1::NGLine(GLayoutClass* GLayout)
{
	UINT nLines = 0;
	for(UINT i = 0; i < nGroups; i++)
		nLines += Group[i].NLine(GLayout[i]);
	return nLines;
}

UINT PageClass_1::NGLine(UINT iGroup)
{
	return Group[iGroup].NLine();
}

UINT PageClass_1::NGSLine(UINT iGroup, UINT iSection)
{
	return Group[iGroup].NSLine(iSection);
}

UINT PageClass_1::NGSLWord(UINT iGroup, UINT iSection, UINT iLine)
{
	return Group[iGroup].NSLWords(iSection, iLine);
}
