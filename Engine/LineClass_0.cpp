# include "LineClass_0.h"

VOID LineClass_0::GenORT(ORTClass& ORT)
{
	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Put((LPBYTE)(&nWord), sizeof(nWord));
	for(UINT iWord = 0; iWord < nWord; iWord++)
		Word[iWord]->GenORT(ORT);
}

VOID LineClass_0::SetORT(ORTClass& ORT)
{
	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Get((LPBYTE)(&nWord), sizeof(nWord));
	Word = new WordClass*[nWord];
	for(UINT iWord = 0; iWord < nWord; iWord++)
	{
		Word[iWord] = new WordClass;
		Word[iWord]->SetORT(ORT);
	}
}

VOID LineClass_0::GenText(TextClass& Txt)
{
	for(UINT iWord = 0;; iWord++)
	{
		Word[iWord]->GenText(Txt);
		if(iWord == nWord-1)
			break;
		else
			Txt.Space();
	}
}

VOID LineClass_0::GenHTML(HTMLClass& HTML)
{
	for(UINT iWord = 0;; iWord++)
	{
		Word[iWord]->GenHTML(HTML);
		if(iWord == nWord-1)
			break;
		else
			HTML.Space();
	}
}
