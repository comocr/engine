# include "WordClass_0.h"

class WordClass : public WordClass_0
{
private:
	VOID LiteralLoop(UINT nFonts, UINT *fontI);
	VOID CleanUp(UINT *fontI);
	VOID Order();
	VOID Prep();

public:
	BOOL *bSpaceAmb;
	BOOL Generate(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT nFonts, UINT *fontI, UINT maxHSeparation);
	BOOL BreakUp(WordClass* Word, UINT& iLiteral, UINT *iFont);
	VOID SpaceAmbInit();
};
