# include "GroupClass.h"

# define MAX_UINT	0xFFFFFFFF

VOID GroupClass::Generate(GLayoutClass& GLayout)
{
	nSections = GLayout.GetNSections();
	Section = new SectionClass[nSections];
	static UINT rBeginY = 0;
	static UINT rEndY = MAX_UINT;
	switch(GLayout.GetType())
	{
	case GROUP_LINE:
		//nLines = 1;
		switch(GLayout.GetIndex())
		{
		case GROUP_LINE_FIRST:
			{
			UINT sBeginX = MAX_UINT, sEndX = 0, sBeginY = MAX_UINT, sEndY = 0;
			for(UINT i = 0; i < nSections; i++)
				//if(i != rSection)
				{
					//LayoutClass& Layout = GLayout.GetLayout(i);
					Section[i].Generate(DOWN, 1, 0, Object.width-1, NULL, Object.height-1, GLayout.GetLayout(i));
					if(rEndY > Section[i].BeginY())
						rEndY = Section[i].BeginY()-1;
					if(sBeginX > Section[i].BeginX())
						sBeginX = Section[i].BeginX();
					if(sEndX < Section[i].EndX())
						sEndX = Section[i].EndX();
					if(sBeginY > Section[i].BeginY())
						sBeginY = Section[i].BeginY();
					if(sEndY < Section[i].EndY())
						sEndY = Section[i].EndY();
				}
			//if(rSection != 0xFFFFFFFF)
			//{
			//	Section[rSection].Generate(DOWN, 1, 0, Object.width-1, NULL, Object.height-1, GLayout.GetLayout(rSection));
			//	if(beginY > Section[rSection].BeginY())
			//	beginY = Section[rSection].BeginY();
			//}
			//rEndY = beginY-1;
			Set(sBeginX, sEndX, sBeginY, sEndY);
			}
			break;

		case GROUP_LINE_LAST:
			{
			UINT sBeginX = MAX_UINT, sEndX = 0, sBeginY = MAX_UINT, sEndY = 0;
			for(UINT i = 0; i < nSections; i++)
				//if(i != rSection)
				{
					Section[i].Generate(UP, 1, 0, Object.width-1, 0, Object.height-1, GLayout.GetLayout(i));
					if(rBeginY < Section[i].EndY())
						rBeginY = Section[i].EndY()+1;
					if(sBeginX > Section[i].BeginX())
						sBeginX = Section[i].BeginX();
					if(sEndX < Section[i].EndX())
						sEndX = Section[i].EndX();
					if(sBeginY > Section[i].BeginY())
						sBeginY = Section[i].BeginY();
					if(sEndY > Section[i].EndY())
						sEndY = Section[i].EndY();
				}
			//if(rSection != 0xFFFFFFFF)
			//{
			//	Section[rSection].Generate(UP, 1, 0, Object.width-1, 0, NULL, GLayout.GetLayout(rSection));
			//	if(endY < Section[rSection].EndY())
			//		endY = Section[rSection].EndY();
			//}
			//rBeginY = endY+1;
			Set(sBeginX, sEndX, sBeginY, sEndY);
			}
			//break;
		}
		break;
	case GROUP_BLOCK:
		//nLines = 0;
		switch(GLayout.GetIndex())
		{
		case GROUP_BLOCK_PX:
			//GLayout.GetBlock(sBeginX, sEndX, rBeginY, rEndY); // ToDo
			break;
		case GROUP_BLOCK_REMAIN:
			Section[0].Generate(DOWN, 0xFFFFFFFF, 0, Object.width-1, rBeginY, rEndY, GLayout.GetLayout(0));
			Set(Section[0].GetPortion());
			//break;
		}
	}
}
