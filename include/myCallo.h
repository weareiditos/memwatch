#pragma once
#include "myMalloc.h"

void* __cdecl myCalloc(
	size_t _Count,
	size_t _Size,
	char* _File,
	int _Line
);