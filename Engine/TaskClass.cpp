# include "TaskClass.h"

extern FontClass *Font;	
extern FilesClass Files;

TaskClass::TaskClass()
{

}

VOID TaskClass::Create(ConfigClass& Config)
{
	LPWSTR tmpString = new WCHAR[MAX_FILE_NAME_LEN];

	bReMode = Config.GetBool();
	bFormating = Config.GetBool();
	bItalicStyle = Config.GetBool();
{
	UINT nFonts = Config.GetInt();
	FontClass::nFonts = nFonts;
	Font = new FontClass[nFonts];
	for(UINT i = 0; i < nFonts; i++)
	{
		Config.GetString(tmpString, MAX_FILE_NAME_LEN);
		Font[i].Add(tmpString);
	}
}

	UINT nGroups = Config.GetInt();
	GLayout = new GLayoutClass[nGroups];

	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
	{
	{
		UINT task, index;
		switch(Config.GetChar())
		{
		case 'L':								// Line
			task = SECTION_LINE;
			switch(Config.GetChar())
			{
			case 'F':							// First
				index = SECTION_LINE_FIRST;
				break;
			case 'L':							// Last
				index = SECTION_LINE_LAST;
				break;
			default:
				exit(ERROR_FORMAT_GROUP_LINE);
			} break;
		case 'B':
			task = SECTION_BLOCK;
			switch(Config.GetChar())
			{
			case '#':								// Rect
				{
				index = SECTION_BLOCK_PX;
				UINT beginX, endX, beginY, endY;
				beginX = Config.GetInt();
				endX = Config.GetInt();
				beginY = Config.GetInt();
				endY = Config.GetInt();
				GLayout[iGroup].SetBlock(beginX, endX, beginY, endY);
				}
				break;
			case '^':								// Remaining
				index = SECTION_BLOCK_REMAIN;
				Page.rGroup = iGroup;
				break;
			default:
				exit(ERROR_FORMAT_GROUP_BLOCK);
			} break;
		default:
			exit(ERROR_FORMAT_GROUP);
		}
		GLayout[iGroup].SetType(task);
		GLayout[iGroup].SetIndex(index);
	}
	{
		UINT nSections = Config.GetInt();
		GLayout[iGroup].InitSections(nSections);

		for(UINT iSection = 0; iSection < nSections; iSection++)
		{
		{
			UINT part;

			switch(Config.GetChar())
			{
			case 'L':							// Left
				part = SECTION_LEFT;
				break;
			case 'R':							// Right
				part = SECTION_RIGHT;
				break;
			case '*':							// Right
				part = SECTION_ALL;
				break;
			default:
				exit(ERROR_FORMAT_SECTION_PART);
			}

			GLayout[iGroup].SetPart(iSection, part);
		}
		{
			UINT nFonts;
			nFonts = Config.GetInt();
			GLayout[iGroup].TFonts(iSection, nFonts);
			do
			{
				UINT iFont;
				iFont = Config.GetInt();
				GLayout[iGroup].AddFontI(iSection, iFont, Font[iFont].MaxHSeparation(), Font[iFont].Leaping());
			} while(--nFonts);
		}
		}
	}
	}

	delete tmpString;
	Page.nGroups = nGroups;
}

UINT TaskClass::Mode()
{
	return bReMode;
}

VOID TaskClass::Execute(VOID (*UpdateMsg)())
{
	for(Files.iFile = 0; Files.iFile < Files.nFiles; Files.iFile++)
	{
		if(Mode())
		{//Rects
 			PageLoad();
		}
		else
		{//Text
			Page.Init(Files.CurName());
			PageGen();
		}
		if(UpdateMsg)
			UpdateMsg();
	}
}

VOID TaskClass::PageGen()
{
	Page.Generate(GLayout);
	Page.WriteORT(GLayout);
	Page.WriteText(GLayout);
}

VOID TaskClass::PageLoad()
{
	Page.ReadORT(GLayout);
//	Page.TextGen();
	Page.WriteText(GLayout);
}
