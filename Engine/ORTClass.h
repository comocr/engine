# ifndef ORT_CLASS_HEADER
# define ORT_CLASS_HEADER
# include <Windows.h>

class ORTClass
{
private:
	BYTE* ortBuffer;
	UINT iBuffer;
public:
	ORTClass();
	VOID WriteInit();
	VOID ReadInit();
	VOID Put(LPBYTE byte, UINT nBytes);
	VOID Get(LPBYTE byte, UINT nBytes);
	LPBYTE Buffer();
	LPBYTE& ORTClass::BufferRf();
	UINT Size();
	UINT& Index();
};

# endif // ORT_CLASS_HEADER
