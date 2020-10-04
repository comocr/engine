# include "Engine.h"

extern FontsClass Fonts;

//#define O1
UINT OCR(ImageClass &Object, Viability *found, UINT nFonts, UINT* iFonts)
{
	UINT sWhite;
	UINT sBlack;
	float simillarity;
	UINT index;
	UINT i,j,k,l;
	UINT m = 0;
	UINT n;

	for(UINT p = 0; p < nFonts; p++)
	{
		Fonts.iFonts = iFonts[p];
		for(index = 0; index < Fonts.nSymbols(); index++)
		{
			if(Fonts.bitMap(index) == NULL) 
				continue;

			for(i = 0; (int)i <= (int)(Object.height - Fonts.height(index)); i++)
				for(j = 0; (int)j <= (int)(Object.width - Fonts.width(index)); j++)
				{
					sWhite = 0;
					sBlack = 0;
					for(k = 0; k < Fonts.height(index); k++)
						for(l = 0; l < Fonts.width(index); l++)
							if(Fonts.bitMap(index)[k*(Fonts.width(index))+l] == 0x00)
							{
								if(Object.bitMap[(i+k)*(Object.width)+j+l] == 0x00)
									sBlack++;
							}
							else if(Fonts.bitMap(index)[k*(Fonts.width(index))+l] == 0x0f)
							{
								if(Object.bitMap[(i+k)*(Object.width)+j+l] == 0x0f)
									sWhite++;
							};
					simillarity = ((float)sWhite/(float)Fonts.white(index) + (float)sBlack/(float)Fonts.black(index)) / (float)2;
					if(simillarity > Fonts.rAccuracy(index))
					{
						Fonts.xFonts = Fonts.iFonts;
//						found[m].fontIndex = Fonts.iFonts;
						found[m].code = Fonts.code(index);
						found[m].width = Fonts.width(index)-1-Fonts.lHang(index);
//						found[m].beginY = i;
						found[m].beginX = j+Fonts.lHang(index);

						found[m].simillarity = simillarity;
						m++;
					};
				};
		};
	}

		for(i = 0; i < m; i++)
			found[i].invalid = false;
//# ifndef O1
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(j != i)
					if(!found[i].invalid && !found[j].invalid)
						if(found[i].beginX >= found[j].beginX)
							if(found[i].width+found[i].beginX <= found[j].width+found[j].beginX)
								if(found[i].simillarity < found[j].simillarity || found[i].code == found[j].code)
									found[i].invalid = true;
//								else
//									found[j].invalid = true;
			};
//# endif
		};
		for(i = 0, n = 0; i < m; i++)
		{
			if(!found[i].invalid)
				found[n++] = found[i];
		};
		for(i = 1; i < n; i++)
			if(found[i].beginX < found[i-1].beginX)
			{
				unsigned int lwr = 0,mid,upr;
				upr = i;
				upr--;
				while(true)
				{
					mid = (upr+lwr)/2;

					if(found[i].beginX == found[mid].beginX)
						upr = lwr = mid;
					else if(found[i].beginX == found[upr].beginX)
						lwr = upr;
					else if(found[i].beginX == found[lwr].beginX)
						upr = lwr;
					else if(found[i].beginX > found[mid].beginX)
						lwr = mid+1;
					else
						upr = mid;

					if(lwr == upr)
					{
						Viability tmp = found[i];
						for(UINT k = i; k > upr; k--)
							found[k] = found[k-1];
						found[upr] = tmp;
						break;  
					};
				};
			};

	return n;
}
