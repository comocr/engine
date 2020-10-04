# include "PageClass.h"

VOID PageClass::Init(LPWSTR szFile)
{
	Object.LoadHBMP(szFile, FALSE);
	Set(0, Object.width-1, 0, Object.height-1);
}

VOID PageClass::Generate(GLayoutClass *GLayout)
{
	Group = new GroupClass[nGroups];
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		if(iGroup != rGroup)
			Group[iGroup].Generate(GLayout[iGroup]);
	Group[rGroup].Generate(GLayout[rGroup]);
}
