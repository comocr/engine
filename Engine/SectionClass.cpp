# include "SectionClass.h"

VOID SectionClass::Generate(BOOL bVDir, UINT nRLines, UINT beginX, UINT endX, UINT beginY, UINT endY, LayoutClass& Layout)	//in terms of Pels
{
//	static UINT rBeginX, rEndX;//, sBeginY, sEndY; 
	switch(Layout.GetPart())
	{
	case SECTION_LEFT:
		endX = (endX-beginX+1)/2;
		break;
	case SECTION_RIGHT:
		beginX = (endX-beginX+1)/2;
		break;
//	case SECTION_REMAIN:
//		beginX = rBeginX;
//		endX = rEndX;
//		break;
	case SECTION_ALL:
		break;
	}

	UINT iLine = 0;
	{
	UINT maxNLines;
	if(nRLines == 0xFFFFFFFF)
		maxNLines = MAX_N_LINES_SECTN;
	else
		maxNLines = 1;
	Line = new LineClass*[maxNLines];
	}
	*Line = new LineClass;

	UINT sBeginX = 0xFFFFFFFF;
	UINT sEndX = 0;
	UINT sEndY = endY;
	while(nRLines && (Line[iLine]->Generate(bVDir, beginX, endX, beginY, endY, Layout.TFonts(), Layout.FontI(), Layout.GetMaxHSeparation(), Layout.GetLeaping())))
	{
		if(Line[iLine]->BeginX() < sBeginX)
			sBeginX = Line[iLine]->BeginX();
		if(Line[iLine]->EndX() > sEndX)
			sEndX = Line[iLine]->EndX();
		endY = Line[iLine]->BeginY()-1;
		iLine++;
		Line[iLine] = new LineClass;

		if(nRLines != 0xFFFFFFFF)
			nRLines--;
	}

	if(iLine > MAX_N_LINES_SECTN)
		exit(ERROR_NLINES_OVER_BOUND);
	delete Line[iLine];

	if(sBeginX != 0xFFFFFFFF)
		beginX = sBeginX;
	if(sEndX != 0)
		endX = sEndX;
	endY = (Line[0])->EndY();
	beginY = (Line[iLine-1])->BeginY();

	SectionClass::nLines = iLine;
	Set(beginX, endX, beginY, endY);
}
