#include "myRealloc.h"

void* __cdecl myRealloc(void*  _Block, size_t _Size, char* _File, int _Line)
{
	if (_Block == NULL) return myMalloc(_Size, _File, _Line);
	if (_Size == 0) { myFree(_Block); return NULL; }

	Tinfo* element = (Tinfo*)((char*)_Block - sizeof(Tinfo));
	char *ptr = (char*)myMalloc(_Size, _File, _Line);
	if (ptr != NULL)
	{
		if (_Size < element->size)
			memcpy(ptr, _Block, _Size);
		else
			memcpy(ptr, _Block, element->size);
		myFree(_Block);
	}
	return (void*)ptr;
}