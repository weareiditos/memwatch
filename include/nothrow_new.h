#pragma once
#include <new>
#include "myMalloc.h"
#include "myFree.h"

void* __CRTDECL operator new(
	size_t _Size, 
	char *_File, 
	int _Line
	);

void* __CRTDECL operator new[](
	size_t _Size, 
	char *_File, 
	int _Line
	);

void __CRTDECL operator delete(
	void* _Block
	);

void __CRTDECL operator delete[](
	void* _Block);
