# ifndef LINECLASS_HEADER
# define LINECLASS_HEADER

# define SPACE						L' '
# define MAX_N_WORDS_LINE			100

# define ERROR_NWORDS_OVER_BOUND	-378662

# include <Windows.h>
# include "PieceClass.h"
# include <WordClass.h>
# include "TextClass.h"
# include "HTMLClass.h"

class LineClass_0 : public PieceClass
{
protected:
	WordClass **Word;
	UINT nWord;						// Total Number: Pieces ;Line number of words
public:
//	LineClass();
	VOID GenORT(ORTClass& ORT);
	VOID SetORT(ORTClass& ORT);
	VOID GenText(TextClass& Txt);
	VOID GenHTML(HTMLClass& HTML);
};

# endif
