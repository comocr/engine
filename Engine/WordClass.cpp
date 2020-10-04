# include "WordClass.h"

BOOL WordClass::Generate(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT nFonts, UINT *fontI, UINT maxHSeparation)
{
	if(FindCutRt(sBeginX, sEndX, sBeginY, sEndY, maxHSeparation))
	{
		LiteralLoop(nFonts, fontI);
		CleanUp(fontI);
		Order();
		SpaceAmbInit();
		return TRUE;
	}
	else
		return FALSE;
}

VOID WordClass::LiteralLoop(UINT nFonts, UINT *fontI)
{
	nLiterals = 0;
	Literal = new LiteralClass*[MAX_N_LITERALS_W];
	Literal[nLiterals] = new LiteralClass;
	for(UINT iFont = 0; iFont < nFonts; iFont++)
	{
		UINT f = fontI[iFont];
		for(UINT iSymbol = 0; iSymbol < Font[f].Get_nSymbols(); iSymbol++)
		{
			BOOL bVSand = (Height()+2 == Font[f].Symbol[iSymbol].Height());
			BOOL bHSand = (Width()+2 == Font[f].Symbol[iSymbol].Width());
			if(bVSand && bHSand)
			{
				UINT y = BeginY();
				UINT x = BeginX();
				BOOL bLeft = TRUE;
				BOOL bRight = TRUE;
				BOOL bBottom = TRUE;
				BOOL bTop = TRUE;
				if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol, bLeft, bRight, bBottom, bTop))
					Literal[++nLiterals] = new LiteralClass;
			}
			else
			{
			{
				UINT y = BeginY();
				for(UINT x = BeginX(); (int)x <= (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-(int)bHSand-2); x++)
				{
					BOOL bLeft = (x == BeginX());
					BOOL bRight = ((int)x == (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-(int)bHSand-2));
					BOOL bBottom = TRUE;
					BOOL bTop = bVSand;//((int)y == (int)EndY() - ((int)Font[f].Symbol[iSymbol].Height()-(int)bVSand-2));
					if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol, bLeft, bRight, bBottom, bTop))
						Literal[++nLiterals] = new LiteralClass;
				}
				if(!bVSand)
				{
					UINT y = (int)EndY() - ((int)Font[f].Symbol[iSymbol].Height()-2);
					for(UINT x = BeginX(); (int)x <= (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-(int)bHSand-2); x++)
					{
						BOOL bLeft = (x == BeginX());
						BOOL bRight = ((int)x == (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-(int)bHSand-2));
						BOOL bBottom = FALSE;
						BOOL bTop = TRUE;
						if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol, bLeft, bRight, bBottom, bTop))
							Literal[++nLiterals] = new LiteralClass;
					}
				}
			}
			{
				UINT x = BeginX();
				for(UINT y = BeginY(); (int)y < (int)EndY() - ((int)Font[f].Symbol[iSymbol].Height()-2); y++)
				{
					BOOL bLeft = TRUE;
					BOOL bRight = ((int)x == (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-(int)bHSand-2));
					BOOL bBottom = FALSE;
					BOOL bTop = FALSE;
					if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol, bLeft, bRight, bBottom, bTop))
						Literal[++nLiterals] = new LiteralClass;
				}
				if(!bHSand)
				{
					UINT x = (int)EndX() - ((int)Font[f].Symbol[iSymbol].Width()-2);
					for(UINT y = BeginY(); (int)y < (int)EndY() - ((int)Font[f].Symbol[iSymbol].Height()-2); y++)
					{
						BOOL bLeft = FALSE;
						BOOL bRight = TRUE;
						BOOL bBottom = FALSE;
						BOOL bTop = FALSE;
						if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol, bLeft, bRight, bBottom, bTop))
							Literal[++nLiterals] = new LiteralClass;
					}
				}
			}

				for(UINT y = BeginY(); (int)y <= ((int)EndY() - (int)Font[f].Symbol[iSymbol].Height() + 1); y++)
					for(UINT x = BeginX(); (int)x <= ((int)EndX() - (int)Font[f].Symbol[iSymbol].Width() + 1); x++)
						if(Literal[nLiterals]->Generate(y, x, Font[f].Symbol[iSymbol], iFont, iSymbol))
							Literal[++nLiterals] = new LiteralClass;
			};
		}
	}
	if(nLiterals > MAX_N_LITERALS_W)
		exit(ERROR_NLITERALS_OVERBOUND);
	delete[] Literal[nLiterals];
}

VOID WordClass::CleanUp(UINT *fontI)
{
	BOOL *invalid = new BOOL[nLiterals];
	for(UINT i = 0; i < nLiterals; i++)
		invalid[i] = FALSE;
//# ifndef O1
	for(UINT i = 0; i < nLiterals; i++)
	{
		for(UINT j = 0; j < nLiterals; j++)
		{
			if(j != i)
				if(!invalid[i] && !invalid[j])
					if(Literal[i]->BeginX() >= Literal[j]->BeginX())
						if(Literal[i]->BeginX()+Literal[i]->Width() <= Literal[j]->BeginX()+Literal[j]->Width())
							if(Literal[i]->BeginY() >= Literal[j]->BeginY())
								if(Literal[i]->BeginY()+Literal[i]->Height() <= Literal[j]->BeginY()+Literal[j]->Height())
								{
									if(Literal[i]->code == Literal[j]->code)//|| Literal[i]->simillarity < Literal[j]->simillarity
										if(Literal[i]->fontIndex == Literal[j]->fontIndex)
										{
											invalid[i] = TRUE;
											continue;
										}
									if(Literal[i]->Subsume(Literal[j], fontI) >= MIN_SUBSUME_SMLRTY)//((Literal[i]->sWhite/Literal[j]->sBlack)+(Literal[i]->sBlack/Literal[j]->sBlack)) < 1)	// Partial Matches
										invalid[i] = TRUE;
								};
		};
//# endif
	};
{
	UINT iLiteral = 0;
	for(UINT i = 0; i < nLiterals; i++)
	{
		if(!invalid[i])
			Literal[iLiteral++] = Literal[i];
	};
	nLiterals = iLiteral;
}
	delete invalid;
	Order();
}

VOID WordClass::Order()
{
	for(UINT i = 1; i < nLiterals; i++)
		if(Literal[i]->TBeginX() < Literal[i-1]->TBeginX())
		{
			unsigned int lwr = 0,mid,upr;
			upr = i;
			upr--;
			while(TRUE)
			{
				mid = (upr+lwr)/2;

				if(Literal[i]->TBeginX() == Literal[mid]->TBeginX())
					upr = lwr = mid;
				else if(Literal[i]->TBeginX() == Literal[upr]->TBeginX())
					lwr = upr;
				else if(Literal[i]->TBeginX() == Literal[lwr]->TBeginX())
					upr = lwr;
				else if(Literal[i]->TBeginX() > Literal[mid]->TBeginX())
					lwr = mid+1;
				else
					upr = mid;

				if(lwr == upr)
				{
					LiteralClass *tmp = Literal[i];
					for(UINT k = i; k > upr; k--)
						Literal[k] = Literal[k-1];
					Literal[upr] = tmp;
					break;
				};
			};
		};
}

BOOL WordClass::BreakUp(WordClass* Word, UINT& iLiteral, UINT *iFont)
{
	UINT iLiteralB = iLiteral;
	for(;iLiteral < nLiterals-1; iLiteral++)
	{
		INT dX = Literal[iLiteral+1]->TBeginX() - Literal[iLiteral]->TEndX();
		UINT i = iFont[(Literal[iLiteral+1]->fontIndex)];
		UINT j = iFont[(Literal[iLiteral]->fontIndex)];
		if(i == j)
		{
			if(dX > (INT)Font[i].MaxHSeparation())
				break; // Break
			else
				bSpaceAmb[iLiteral] = FALSE;
		}
		else
		{
			UINT mXi = Font[i].MaxHSeparation();
			UINT mXj = Font[j].MaxHSeparation();
			if(dX > (INT)mXi && dX > (INT)mXj)
			{
				break; // Break
			}
			else if(dX < (INT)mXi && dX < (INT)mXj)
			{
				bSpaceAmb[iLiteral] = FALSE;
				continue;
			}
			else // (dX > mXi && dX < mXj) || (dX < mXi && dX > mXj)
			{
				bSpaceAmb[iLiteral] = TRUE; // Flag
			}
		}
	}
	if(iLiteral == nLiterals-1)
		if(iLiteralB == 0)
			return FALSE;
	{ // Break:
		Word->BeginX(Literal[iLiteralB]->BeginX());
		Word->BeginY(BeginY());	// Literal[iLiteral]->BeginY()
		Word->EndX(Literal[iLiteral]->EndX());
		Word->EndY(EndY());		// Literal[iLiteral]->EndY()
		Word->nLiterals = iLiteral-iLiteralB+1;
		if(iLiteralB != 0) 
			Word->Literal = new LiteralClass*[Word->nLiterals];
		Word->SpaceAmbInit();
	{
		UINT i = 0;
		while(i < Word->nLiterals-1)
		{
			Word->Literal[i] = Literal[iLiteralB+i];
			Word->bSpaceAmb[i] = bSpaceAmb[iLiteral+i];
			i++;
		};
		Word->Literal[i] = Literal[iLiteralB+i];
	}
		iLiteral++;
		if(iLiteral == nLiterals)
			return FALSE;
		else
			return TRUE;
	}
}

VOID WordClass::SpaceAmbInit()
{
	if(nLiterals > 1)
		bSpaceAmb = new BOOL[nLiterals-1];
}
