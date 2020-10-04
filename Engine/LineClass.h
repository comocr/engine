# include "LineClass_0.h"

class LineClass : public LineClass_0
{
private:
	VOID WordLoop(UINT nFonts, UINT *iFonts, UINT maxHSeparation, BOOL bLeaping);

public:
	BOOL Generate(BOOL bDnMode, UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT nFonts, UINT *iFont, UINT maxHSeparation, BOOL bLeaping);
	VOID BreakLoop(UINT *iFont);
};
