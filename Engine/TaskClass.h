# include <Windows.h>
# include "..\\Utilities\\Config\\ConfigClass.h"
# include "..\\Utilities\\Files\\FilesClass.h"
# include "FontClass.h" 
# include "GLayoutClass.h"
# include "PageClass.h"

# define NEXT_CHAR				true
# define MAX_FILE_NAME_LEN		200
# define N_OAF_VARS				3

# define ERROR_FORMAT_GROUP_LINE	-887266752
# define ERROR_FORMAT_GROUP_BLOCK	-698174284
# define ERROR_FORMAT_GROUP			-596671
# define ERROR_FORMAT_SECTION_PART	-86984521

class TaskClass
{
private:
	BOOL bReMode;
	BOOL bFormating;
	BOOL bItalicStyle;

//	UINT rGroup;
//	UINT nGroups;
	GLayoutClass *GLayout;

//	UINT iPage;
//	UINT nPages;
	PageClass Page;

public:
	TaskClass();
	VOID Create(ConfigClass& Config);
	UINT Mode();
	VOID Execute(VOID (*UpdateMsg)());
	VOID PageGen();
	VOID PageLoad();
//	VOID TextGen();
};
