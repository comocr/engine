# ifndef PIECE_CLASS_HEADER
# define PIECE_CLASS_HEADER

# include <ImageClass.h>
# include "PortionClass.h"

class PieceClass
{
protected:
	static ImageClass Object;
	PortionClass Portion;
public:
	UINT BeginX();
	UINT EndX();
	UINT BeginY();
	UINT EndY();
	UINT Width();
	UINT Height();

	VOID BeginX(UINT x);
	VOID EndX(UINT x);
	VOID BeginY(UINT y);
	VOID EndY(UINT y);
	VOID Width(UINT w);
	VOID Height(UINT h);

	PortionClass& GetPortion();

	BYTE PelVal(UINT x, UINT y);
	VOID Set(UINT beginX, UINT endX, UINT beginY, UINT endY);
	VOID Set(PortionClass& Portion);
	BOOL FindCutDn(/*UINT &beginX, UINT &endX, UINT &beginY, UINT &endY, */UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY);
	BOOL FindCutUp(/*UINT &beginX, UINT &endX, UINT &beginY, UINT &endY, */UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY);
	BOOL FindCutRt(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY, UINT maxDX);
	BOOL FindCutLf(UINT sBeginX, UINT sEndX, UINT sBeginY, UINT sEndY);
	VOID SqueezeV(/*UINT beginX, UINT endX, UINT& beginY, UINT& endY*/);
};

# endif // PIECE_CLASS_HEADER
