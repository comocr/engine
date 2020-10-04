# include "GroupClass_0.h"

class GroupClass_1 : public GroupClass_0
{
protected:
	UINT nLines;

public:
	UINT NSections();
	UINT NLine(GLayoutClass& GLayout);
	UINT NLine();
	UINT NSLine(UINT iSection);
	UINT NSLWords(UINT iSection, UINT iLine);
	//UINT WordBeginX(UINT iSection, UINT iLine, UINT iWord);
};
