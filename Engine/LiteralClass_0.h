# ifndef LITERALCLASS__HEADER
# define LITERALCLASS__HEADER

# include <Windows.h>
# include "PieceClass.h"
# include "ORTClass.h"

class LiteralClass_0 : public PieceClass
{
private:

public:
	UINT fontIndex;
	UINT symbolIndex;
//	UINT sWhite;
//	UINT sBlack;
//Redundant:
	WCHAR code;
	UINT lHang;
	UINT rHang;
 //Format:
//	BOOL bold;
//	BOOL italic;
//	BOOL underlined;

	VOID GenORT(ORTClass& ORT);
	VOID SetORT(ORTClass& ORT);
};

# endif
