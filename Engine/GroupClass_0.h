# ifndef GROUP_CLASS_0_HEADER
# define GROUP_CLASS_0_HEADER

# include <Windows.h>

# include "PieceClass.h"
# include "GLayoutClass.h"
# include <SectionClass.h>
# include "ORTClass.h"
# include "TextClass.h"
# include "HTMLClass.h"

# define GROUP_LINE					0
# define GROUP_BLOCK				1
# define GROUP_LINE_FIRST			0
# define GROUP_LINE_LAST			1
# define GROUP_BLOCK_PX				0
# define GROUP_BLOCK_REMAIN			1

class GroupClass_0 : public PieceClass
{
protected:
	SectionClass* Section;
	UINT nSections;

public:
	VOID GenORT(ORTClass& ORT);
	VOID SetORT(ORTClass& ORT);

	VOID GenText(TextClass& Txt, GLayoutClass& GLayout);
	VOID GenHTML(HTMLClass HTML, GLayoutClass& GLayout);
};

# endif // GROUP_CLASS_0_HEADER
