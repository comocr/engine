# include "LineClass.h"

BOOL LineClass::Generate(BOOL bDnMode, UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT nFonts, UINT *iFont, UINT maxHSeparation, BOOL bLeaping)
{
	BOOL bFound;
	if(bDnMode)
		bFound = FindCutDn(sBeginX, sEndX, sBeginY, sEndY);
	else
		bFound = FindCutUp(sBeginX, sEndX, sBeginY, sEndY);
	if(bFound)
	{
		WordLoop(nFonts, iFont, maxHSeparation, bLeaping);
		return TRUE;
	}
	else
		return FALSE;
}

VOID LineClass::WordLoop(UINT nFonts, UINT *iFont, UINT maxHSeparation, BOOL bLeaping)
{
	UINT sBeginX = Portion.BeginX();
	UINT sEndX = Portion.EndX();
	UINT sBeginY = Portion.BeginY();
	UINT sEndY = Portion.EndY();

	nWord = 0;
	Word = new WordClass*[MAX_N_WORDS_LINE];
	Word[0] = new WordClass;

	while(Word[nWord]->Generate(sBeginX, sEndX, sBeginY, sEndY, nFonts, iFont, maxHSeparation))
	{
		if(bLeaping)
			if(Word[nWord]->Breakable())
				BreakLoop(iFont);
		sBeginX = Word[nWord]->EndX()+1;
		nWord++;
		Word[nWord] = new WordClass;
		if(sBeginX >= sEndX)
			break;
	}
	if(nWord > MAX_N_WORDS_LINE)
		exit(ERROR_NWORDS_OVER_BOUND);
	delete[] Word[nWord];
}

VOID LineClass::BreakLoop(UINT *iFont)
{
	WordClass Word = *(LineClass_0::Word[nWord]);
	LineClass::Word[nWord]->SpaceAmbInit();
	UINT iLiteral = 0;
	while(Word.BreakUp(LineClass_0::Word[nWord], iLiteral, iFont))
		LineClass::Word[++nWord] = new WordClass;
}
