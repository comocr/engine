# include "LineClass_1.h"

UINT LineClass_1::NWord()
{
	return nWord;
}

UINT LineClass_1::WordBeginX(UINT nWord)
{
	return Word[nWord]->BeginX();
}
