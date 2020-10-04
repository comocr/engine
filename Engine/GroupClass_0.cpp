# include "GroupClass_0.h"

VOID GroupClass_0::GenORT(ORTClass& ORT)
{
	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Put((LPBYTE)(&nSections), sizeof(nSections));
	for(UINT i = 0; i < nSections; i++)
		Section[i].GenORT(ORT);
}

VOID GroupClass_0::SetORT(ORTClass& ORT/*, BOOL bVerifyD = TRUE*/)
{
	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Get((LPBYTE)(&nSections), sizeof(nSections));
	Section = new SectionClass[nSections];
	for(UINT i = 0; i < nSections; i++)
		Section[i].SetORT(ORT);
}

VOID GroupClass_0::GenText(TextClass& Txt, GLayoutClass& GLayout)
{
	for(UINT iSection = 0; iSection < nSections; iSection++)
	{
		BOOL bLeft = (GLayout.GetPart(iSection) == SECTION_LEFT);
		Section[iSection].GenText(Txt, bLeft);
		if(iSection != nSections-1)
		{
			if(bLeft)
				Txt.Space();
			else
				Txt.NewLine();
		}
	}
}

VOID GroupClass_0::GenHTML(HTMLClass HTML, GLayoutClass& GLayout)
{
	for(UINT iSection = 0; iSection < nSections; iSection++)
	{
		BOOL bLeft = (GLayout.GetPart(iSection) == SECTION_LEFT);
		Section[iSection].GenHTML(HTML, bLeft);
		if(iSection != nSections-1)
		{
			if(bLeft)
				HTML.Space();
			else
				HTML.NewLine();
		}
	}
}
