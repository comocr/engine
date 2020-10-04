# ifndef WORDCLASS_HEADER
# define WORDCLASS_HEADER

# define MAX_N_LITERALS_W		500
//# define MAX_N_JOINED_W			100

# define MIN_SUBSUME_SMLRTY		0.70

# include <Windows.h>
# include "PieceClass.h"
# include "FontClass.h"
# include <LiteralClass.h>
# include "ORTClass.h"
# include "TextClass.h"
# include "HTMLClass.h"

# define ERROR_NLITERALS_OVERBOUND	-343258378

class WordClass_0 : public PieceClass
{
protected:
	LiteralClass * *Literal;
	UINT nLiterals;

public:
	VOID GenORT(ORTClass& ORT);
	VOID SetORT(ORTClass& ORT);
	VOID GenText(TextClass& Txt);
	VOID GenHTML(HTMLClass& HTML);
	BOOL Breakable();
};

# endif