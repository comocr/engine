# ifndef PAGE_CLASS_1_HEADER
# define PAGE_CLASS_1_HEADER

# include "PageClass_0.h"

class PageClass_1 : public PageClass_0
{
public:

//	VOID NLWord(GLayoutClass *GLayout);
	UINT NGroup();
	UINT NGSection(UINT iGroup);
	UINT NGLine(GLayoutClass* GLayout);
	UINT NGLine(UINT iGroup);
	UINT NGSLine(UINT iGroup, UINT iSection);
	UINT NGSLWord(UINT iGroup, UINT iSection, UINT iLine);
};

# endif // PAGE_CLASS_1_HEADER
