# ifndef PAGE_CLASS_0_HEADER
# define PAGE_CLASS_0_HEADER

# include <Windows.h>
# include "..\\Utilities\\NotifyMessageBox\\NotifyMessageBoxClass.h"
# include "..\\Utilities\\Files\\FilesClass.h"
# include "PieceClass.h"
# include "GLayoutClass.h"
# include <GroupClass.h>
# include "ORTClass.h"
# include "TextClass.h"
# include "HTMLClass.h"

class PageClass_0 : public PieceClass
{
protected:
	VOID GenORT(ORTClass& ORT, GLayoutClass* GLayout);
	VOID SetORT(ORTClass& ORT, GLayoutClass* GLayout);

public:
	GroupClass *Group;
	UINT nGroups;
	UINT rGroup;

	VOID WriteORT(GLayoutClass* GLayout);

	VOID ReadORT(GLayoutClass*& GLayout, BOOL bVerifyD = TRUE);

	VOID GenText(TextClass& Txt, GLayoutClass* GLayout);
	VOID GenHTML(HTMLClass HTML, GLayoutClass* GLayout);

	VOID WriteText(GLayoutClass* GLayout);
	VOID WriteHTML(GLayoutClass* GLayout);
};

# endif // PAGE_CLASS_0_HEADER
