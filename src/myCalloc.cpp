#include "myCallo.h"

void* __cdecl myCalloc(size_t _Count, size_t _Size, char* _File, int _Line)
{
	void* p = myMalloc(_Count * _Size, _File, _Line);
	if (p == NULL) return NULL;
	memset(p, 0, _Count * _Size);
	return p;
}