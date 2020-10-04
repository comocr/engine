# include "PortionClass.h"

# define MAX_ORT_BUFFER_NSIZE	20000

//# define INDEX_N_LINES			1
//# define INDEX_N_WORDS			2
//# define INDEX_WIDTH			3
//# define INDEX_HEIGHT			4

UINT PortionClass::BeginX()
{
	return rect.beginX;
}

UINT PortionClass::BeginY()
{
	return rect.beginY;//inv_beginY);//-rect.height);
}

UINT PortionClass::EndX()
{
	return rect.endX;//.beginX+rect.width);
}

UINT PortionClass::EndY()
{
	return rect.endY;//.inv_beginY;//endY;
}

UINT PortionClass::Width()
{
	return rect.width;
}

UINT PortionClass::Height()
{
	return rect.height;
}

VOID PortionClass::BeginX(UINT beginX)
{
	rect.beginX = beginX;
}

VOID PortionClass::EndX(UINT endX)
{
	rect.endX = endX;
	rect.width = endX+1 - rect.beginX;
}

VOID PortionClass::BeginY(UINT beginY)
{
	rect.beginY = beginY;
}

VOID PortionClass::EndY(UINT endY)
{
	rect.endY = endY;
	rect.height = endY+1 - rect.beginY;
}

VOID PortionClass::Width(UINT width)
{
	rect.width = width;
	rect.endX = rect.beginX + width-1;
}

VOID PortionClass::Height(UINT height)
{
	rect.height = height;
	rect.endY = rect.beginY + height-1;
}
