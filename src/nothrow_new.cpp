#include "nothrow_new.h"

void* __CRTDECL operator new(size_t _Size, char *_File, int _Line)
{
	return myMalloc(_Size, _File, _Line);
}
void* __CRTDECL operator new[](size_t _Size, char *_File, int _Line)
{
	return myMalloc(_Size, _File, _Line);
}
void __CRTDECL operator delete(void* _Block) throw()
{
	myFree(_Block);
}
void __CRTDECL operator delete[](void* _Block) throw()
{
	myFree(_Block);
}