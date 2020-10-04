# include "PageClass_0.h"

# define MAX_N_SYMBOLS_LINE		2000
# define OCR_ORT_FILE_HDR		0x4852434F		//OCRH

# define TXT_FILE_EXTN			L"txt"
# define ORT_FILE_EXTN			L"ort"
# define BMP_FILE_EXTN			L"bmp"
# define HTML_FILE_EXTN			L"html"

extern FilesClass Files;
extern NotifyMessageBoxClass NotifyMessageBox;

VOID PageClass_0::WriteORT(GLayoutClass* GLayout)
{
	ORTClass ORT;
	ORT.WriteInit();

	{
	UINT width = Width();
	ORT.Put((LPBYTE)&width, sizeof(width));
	}
	{
	UINT height = Height();
	ORT.Put((LPBYTE)&height, sizeof(height));
	}
	ORT.Put((LPBYTE)(&nGroups), sizeof(nGroups));
	GenORT(ORT, GLayout);

	Files.Write(ORT.Buffer(), ORT.Size(), L"." ORT_FILE_EXTN);
}

VOID PageClass_0::GenORT(ORTClass& ORT, GLayoutClass* GLayout)
{
//	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		GLayout[iGroup].Serialize(ORT.Buffer(), ORT.Index());
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		Group[iGroup].GenORT(ORT);
}

VOID PageClass_0::ReadORT(GLayoutClass*& GLayout, BOOL bVerifyD)
{
	ORTClass ORT;
	DWORD nBytesRead;
	Files.Read(ORT.BufferRf(), &nBytesRead, L"." ORT_FILE_EXTN);
	ORT.ReadInit();

	{
	UINT width;
	ORT.Get((LPBYTE)(&width), sizeof(width));
	if(bVerifyD && width != Object.Width())
		exit(-456);
	}
	{
	UINT height;
	ORT.Get((LPBYTE)(&height), sizeof(height));
	if(bVerifyD && height != Object.Height())
		exit(-457);
	}
	ORT.Get((LPBYTE)(&nGroups), sizeof(nGroups));
	GLayout = new GLayoutClass[nGroups];
	Group = new GroupClass[nGroups];
	SetORT(ORT, GLayout);
}

VOID PageClass_0::SetORT(ORTClass& ORT, GLayoutClass* GLayout)
{
//	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		GLayout[iGroup].DeSerialize(ORT.Buffer(), ORT.Index());
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		Group[iGroup].SetORT(ORT);
}

VOID PageClass_0::WriteText(GLayoutClass* GLayout)
{
	TextClass Txt;
	GenText(Txt, GLayout);
	Files.Write(Txt.Buffer(), Txt.Size(), L"." TXT_FILE_EXTN);
}

VOID PageClass_0::GenText(TextClass& Txt, GLayoutClass* GLayout)
{
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
	{
		Group[iGroup].GenText(Txt, GLayout[iGroup]);
		if(iGroup != nGroups-1)
			Txt.NewLine();
	}
}

VOID PageClass_0::WriteHTML(GLayoutClass *GLayout)
{
	HTMLClass HTML;
	GenHTML(HTML, GLayout);
	Files.Write(HTML.Buffer(), HTML.Size(), L"." HTML_FILE_EXTN);
}

VOID PageClass_0::GenHTML(HTMLClass HTML, GLayoutClass *GLayout)
{
	for(UINT iGroup = 0; iGroup < nGroups; iGroup++)
		Group[iGroup].GenHTML(HTML, GLayout[iGroup]);
}
