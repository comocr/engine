# include "ORTClass.h"

# define MAX_ORT_BUFFER_SIZE		9902400
# define ORT_FILE_HEADER			0x6F72736F

# define ERROR_INVALID_FILE_HEADER	-5684782

# define HEADER_OFFSET				4

ORTClass::ORTClass()
{
	iBuffer = HEADER_OFFSET;
}

VOID ORTClass::WriteInit()
{
	ortBuffer = new BYTE[MAX_ORT_BUFFER_SIZE];
	((LPDWORD)ortBuffer)[0] = ORT_FILE_HEADER;
}

VOID ORTClass::ReadInit()
{
	if(((LPDWORD)ortBuffer)[0] != ORT_FILE_HEADER)
		exit(ERROR_INVALID_FILE_HEADER);
}

VOID ORTClass::Put(LPBYTE byte, UINT nBytes)
{
	for(UINT i = 0; i < nBytes; i++)
		ortBuffer[iBuffer++] = byte[i];
}

VOID ORTClass::Get(LPBYTE byte, UINT nBytes)
{
	for(UINT i = 0; i < nBytes; i++)
		byte[i] = ortBuffer[iBuffer++];
}

LPBYTE ORTClass::Buffer()
{
	return (LPBYTE)ortBuffer;
}

LPBYTE& ORTClass::BufferRf()
{
	return (LPBYTE&)ortBuffer;
}

UINT ORTClass::Size()
{
	return iBuffer;
}

UINT& ORTClass::Index()
{
	return iBuffer;
}
