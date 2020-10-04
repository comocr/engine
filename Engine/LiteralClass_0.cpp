# include "LiteralClass_0.h"

VOID LiteralClass_0::GenORT(ORTClass& ORT)
{
	ORT.Put((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Put((LPBYTE)(&fontIndex), sizeof(fontIndex));
	ORT.Put((LPBYTE)(&symbolIndex), sizeof(symbolIndex));
	ORT.Put((LPBYTE)(&code), sizeof(code));
	ORT.Put((LPBYTE)(&lHang), sizeof(lHang));
	ORT.Put((LPBYTE)(&rHang), sizeof(rHang));
}

VOID LiteralClass_0::SetORT(ORTClass& ORT)
{
	ORT.Get((LPBYTE)(&Portion), sizeof(Portion));
	ORT.Get((LPBYTE)(&fontIndex), sizeof(fontIndex));
	ORT.Get((LPBYTE)(&symbolIndex), sizeof(symbolIndex));
	ORT.Get((LPBYTE)(&code), sizeof(code));
	ORT.Get((LPBYTE)(&lHang), sizeof(lHang));
	ORT.Get((LPBYTE)(&rHang), sizeof(rHang));
}
