#pragma once
#include <stddef.h>

typedef struct _tag_memwatch_info
{
	struct _tag_memwatch_info		*pre;
	struct _tag_memwatch_info		*next;
	size_t							size;
	char*							file;
	size_t							line;
}Tinfo;
