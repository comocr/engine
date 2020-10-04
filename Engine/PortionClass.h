# ifndef PORTION_CLASS_HEADER
# define PORTION_CLASS_HEADER

# include <Windows.h>

struct RectStruct
{
	UINT beginX;
	UINT endX;
	UINT beginY;
	UINT endY; //inv_beginY
	UINT width;
	UINT height;
};
/*
struct MaskStruct
{
	BYTE *mask;
	UINT size;
};
*/
class PortionClass
{
private:
	RectStruct rect;
//	MaskStruct mask;

public:
	UINT BeginX();
	UINT EndX();
	UINT BeginY();
	UINT EndY();
	UINT Width();
	UINT Height();

	VOID BeginX(UINT d);
	VOID EndX(UINT d);
	VOID BeginY(UINT d);
	VOID EndY(UINT d);
	VOID Width(UINT d);
	VOID Height(UINT d);
};

# endif // PORTION_CLASS_HEADER
