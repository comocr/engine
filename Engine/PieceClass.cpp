# include "PieceClass.h"

ImageClass PieceClass::Object;

UINT PieceClass::BeginX()
{
	return Portion.BeginX();
}

UINT PieceClass::BeginY()
{
	return Portion.BeginY();
}

UINT PieceClass::EndX()
{
	return Portion.EndX();
}

UINT PieceClass::EndY()
{
	return Portion.EndY();
}

UINT PieceClass::Width()
{
	return Portion.Width();
}

UINT PieceClass::Height()
{
	return Portion.Height();
}

VOID PieceClass::BeginX(UINT x)
{
	Portion.BeginX(x);
}

VOID PieceClass::EndX(UINT x)
{
	Portion.EndX(x);
}

VOID PieceClass::BeginY(UINT y)
{
	Portion.BeginY(y);
}

VOID PieceClass::EndY(UINT y)
{
	Portion.EndY(y);
}

VOID PieceClass::Width(UINT w)
{
	Portion.Width(w);
}

VOID PieceClass::Height(UINT h)
{
	Portion.Height(h);
}

BYTE PieceClass::PelVal(UINT x, UINT y)
{
	return Object.PelVal(x, y);
}

PortionClass& PieceClass::GetPortion()
{
	return Portion;
}

VOID PieceClass::Set(UINT beginX, UINT endX, UINT beginY, UINT endY)
{
	Portion.BeginX(beginX);
	Portion.EndX(endX);
	Portion.BeginY(beginY);
	Portion.EndY(endY);
//	Portion.Width(endX - beginX + 1);
//	Portion.Height(beginY - endY + 1);
}

VOID PieceClass::Set(PortionClass& Portion)
{
	PieceClass::Portion = Portion;
}

BOOL PieceClass::FindCutDn(/*UINT &beginX, UINT &endX, UINT &beginY, UINT &endY, */UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY)
{
	UINT beginX, endX, beginY, endY;
	for(endY = sEndY; (int)endY >= sBeginY; endY--)
	{
		for(UINT xBeginX = sBeginX; xBeginX <= sEndX; xBeginX++)
		{
			if(!(PelVal(xBeginX, endY)))
			{
				beginX = xBeginX;
				for(endX = sEndX; PelVal(endX, endY); endX--);
				for(beginY = endY-1; (int)beginY >= sBeginY; beginY--)
				{
					{
					UINT xBeginX;
					for(xBeginX = sBeginX; xBeginX <= sEndX; xBeginX++)
						if(!PelVal(xBeginX, beginY))
						{
							if(xBeginX < beginX)
								beginX = xBeginX;
							break;
						}
					if(xBeginX > sEndX)
						break;
					}
					for(UINT xEndX = sEndX; xEndX >= beginX; xEndX--)
						if(!PelVal(xEndX, beginY))
						{
							if(xEndX > endX)
								endX = xEndX;
							break;
						}
				}
				beginY++;
				Set(beginX, endX, beginY, endY);
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL PieceClass::FindCutUp(/*UINT &beginX, UINT &endX, UINT &beginY, UINT &endY, */UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY)
{
	UINT beginX, endX, beginY, endY;
	for(beginY = sBeginY; (int)beginY <= sEndY; beginY++)
	{
		for(UINT xBeginX = sBeginX; xBeginX <= sEndX; xBeginX++)
		{
			if(!(PelVal(xBeginX, beginY)))
			{
				beginX = xBeginX;
				for(endX = sEndX; PelVal(endX, beginY); endX--);
				for(endY = beginY+1; (int)endY <= sEndY; endY++)
				{
					UINT xBeginX;
					for(xBeginX = sBeginX; xBeginX <= sEndX; xBeginX++)
						if(!(PelVal(xBeginX, endY)))
						{
							if(xBeginX < beginX)
								beginX = xBeginX;
							break;
						}
					if(xBeginX > sEndX)
						break;
					for(UINT xEndX = sEndX; xEndX >= beginX; xEndX--)
						if(!PelVal(xEndX, endY))
						{
							if(xEndX > endX)
								endX = xEndX;
							break;
						}
				}
				endY--;
				Set(beginX, endX, beginY, endY);
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL PieceClass::FindCutRt(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT maxDX)
{
	UINT beginX, endX, beginY, endY;
	for(beginX = sBeginX; beginX <= sEndX; beginX++)
		for(UINT xEndY = sEndY; (int)xEndY >= (int)sBeginY; xEndY--)
			if(!PelVal(beginX, xEndY))
			{
				endY = xEndY;
				for(beginY = sBeginY; PelVal(beginX, beginY); beginY++);
				for(endX = beginX+1; endX <= sEndX; endX++)
				{
					{
					UINT xEndY;
					for(xEndY = sEndY; (int)xEndY >= (int)sBeginY; xEndY--)
						if(!PelVal(endX, xEndY))
						{
							if(xEndY > endY)
								endY = xEndY;
							break;
						}
					{
					UINT nEndY = endY;
					if((int)xEndY < (int)sBeginY)
					{
						UINT nBeginX;
						for(nBeginX = endX+1; nBeginX <= sEndX; nBeginX++)
						{
							for(UINT y = sBeginY; y <= sEndY; y++)
								if(!PelVal(nBeginX, y))
								{
									if(y > nEndY)
										nEndY = y;
									goto P;
								}
						}
					P:	if(nBeginX > sEndX)
							break;
						else if((nBeginX - endX) <= maxDX)	//Join
						{
							endX = nBeginX;
							endY = nEndY;
						}
						else
							break;
					}
					}
					}
					for(UINT xBeginY = sBeginY; xBeginY <= xEndY; xBeginY++)
						if(!PelVal(endX, xBeginY))
						{
							if(xBeginY < beginY)
								beginY = xBeginY;
							break;
						}
				}
				if(endX > sEndX)
					endX = sEndX;
				else
					endX--;
				Set(beginX, endX, beginY, endY);
				return TRUE;
			}
	return FALSE;
}

BOOL PieceClass::FindCutLf(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY)
{
	//ToDo
	return FALSE;
}

VOID PieceClass::SqueezeV(/*UINT beginX, UINT endX, UINT& beginY, UINT& endY*/)
{
	UINT beginX, endX, beginY, endY;
	beginX = Portion.BeginX();
	endX = Portion.EndX();
	beginY = Portion.BeginY();
	endY = Portion.EndY();
	UINT bLoop = TRUE;
	UINT nEndY;				// to keep old line endY be
	for(nEndY = endY; bLoop; nEndY--)
		for(UINT xBeginX = beginX; xBeginX <= endX; xBeginX++)
			if(!PelVal(xBeginX, nEndY))
			{
				bLoop = FALSE;
				break;
			}
	nEndY++;

	UINT nBeginY;
	bLoop = TRUE;
	for(nBeginY = beginY; bLoop; nBeginY++)
		for(UINT xBeginX = beginX; xBeginX <= endX; xBeginX++)
			if(!PelVal(xBeginX, nBeginY))
			{
				bLoop = FALSE;
				break;
			}
	nBeginY--;
	Portion.BeginY(beginY);
	Portion.EndY(endY);
}
