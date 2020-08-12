#pragma once
#include "myMalloc.h"
#include "myFree.h"

void* __cdecl myRealloc(
	void*  _Block,
	size_t _Size,
	char* _File, 
	int _Line
);