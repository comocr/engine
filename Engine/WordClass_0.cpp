# include "WordClass_0.h"

extern FontClass *Font;	

VOID WordClass_0::GenORT(ORTClass& ORT)
{
	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Put((LPBYTE)(&nLiterals), sizeof(nLiterals));
	for(UINT iLiteral = 0; iLiteral < nLiterals; iLiteral++)
		Literal[iLiteral]->GenORT(ORT);//ORT.Put(Literal[iLiteral], sizeof(LiteralClass));
}

VOID WordClass_0::SetORT(ORTClass& ORT)
{
	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Get((LPBYTE)(&nLiterals), sizeof(nLiterals));
	Literal = new LiteralClass*[nLiterals];
	for(UINT iLiteral = 0; iLiteral < nLiterals; iLiteral++)
	{
		Literal[iLiteral] = new LiteralClass;
		Literal[iLiteral]->SetORT(ORT);//ORT.Put(Literal[iLiteral], sizeof(LiteralClass));
	}
}

VOID WordClass_0::GenText(TextClass& Txt)
{
	for(UINT iLiteral = 0; iLiteral < nLiterals; iLiteral++)
		Txt.Put(Literal[iLiteral]->code);
}

VOID WordClass_0::GenHTML(HTMLClass& HTML)
{
	for(UINT iLiteral = 0; iLiteral < nLiterals; iLiteral++)
		HTML.Put(Literal[iLiteral]->code);
}

BOOL WordClass_0::Breakable()
{
	if(nLiterals > 1)
		return TRUE;
	else
		return FALSE;
}
