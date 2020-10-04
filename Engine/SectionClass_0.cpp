# include "SectionClass_0.h"

SectionClass_0::SectionClass_0()
{
//	iFonts = new UINT[MAX_SECTION_FONTS];
	nLines = 0;
};

VOID SectionClass_0::GenORT(ORTClass& ORT)
{
	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Put((LPBYTE)(&nLines), sizeof(nLines));
	for(UINT iLine = 0; iLine < nLines; iLine++)
		Line[iLine]->GenORT(ORT);
}

VOID SectionClass_0::SetORT(ORTClass& ORT)
{
	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Get((LPBYTE)(&nLines), sizeof(nLines));
	Line = new LineClass*[nLines];
	for(UINT iLine = 0; iLine < nLines; iLine++)
	{
		Line[iLine] = new LineClass;
		Line[iLine]->SetORT(ORT);
	}
}

VOID SectionClass_0::GenText(TextClass& Txt, BOOL bLeft)
{
	for(UINT iLine = 0; iLine < nLines; iLine++)
	{
		Line[iLine]->GenText(Txt);
		if(!bLeft)
			if(iLine != nLines-1)
				Txt.NewLine();
	}
}

VOID SectionClass_0::GenHTML(HTMLClass& HTML, BOOL bLeft)
{
	for(UINT iLine = 0; iLine < nLines; iLine++)
	{
		Line[iLine]->GenHTML(HTML);
		if(!bLeft)
			if(iLine != nLines-1)
				HTML.NewLine();
	}
}
