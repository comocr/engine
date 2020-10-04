# ifndef SECTIONCLASS__HEADER
# define SECTIONCLASS__HEADER

# include <Windows.h>
# include "PieceClass.h"
# include "LayoutClass.h"
# include <LineClass.h>
# include "ORTClass.h"
# include "TextClass.h"
# include "HTMLClass.h"

# define CARRIAGE_RETURN			L'\r'
# define LINE_FEED					L'\n'

# define MAX_SECTION_FONTS			10
# define MAX_N_LINES_SECTN			100

# define SECTION_LINE				0
# define SECTION_BLOCK				1
# define SECTION_LINE_FIRST			0
# define SECTION_LINE_LAST			1
# define SECTION_BLOCK_PX			0
# define SECTION_BLOCK_REMAIN		1
# define SECTION_LEFT				1
# define SECTION_RIGHT				2
# define SECTION_ALL				0

# define DOWN						1
# define UP							0

# define ERROR_NLINES_OVER_BOUND	-30823422

class SectionClass_0 : public PieceClass
{
protected:
	LineClass **Line;
	UINT nLines;

public:
	SectionClass_0();
	VOID GenORT(ORTClass& ORT);
	VOID SetORT(ORTClass& ORT);

	VOID GenText(TextClass& Txt, BOOL bLeft);
	VOID GenHTML(HTMLClass& HTML, BOOL bLeft);
};

# endif
	