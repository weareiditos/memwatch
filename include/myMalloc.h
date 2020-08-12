#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "myStruct.h"

extern Tinfo head;

void* __cdecl myMalloc(
	size_t _Size, char* _File, int _Line
);