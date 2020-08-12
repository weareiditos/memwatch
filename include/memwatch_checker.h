#ifndef _MEMWATCH_CHECKER_H_
#define _MEMWATCH_CHECKER_H_

#include "myStruct.h"
#include "myMalloc.h"
#include "myCallo.h"
#include "myRealloc.h"
#include "myFree.h"
#include "nothrow_new.h"
#include "memwatch_logger.h"

extern Tinfo head;

#ifndef _OVERLOAD_CPLUSPLUS_MEMORY_ALLOCATION_FALG_
#define new				new(__FILE__, __LINE__)
#endif

#ifndef _OVERLOAD_C_MEMORY_ALLOCATION_FALG_
#define malloc(n)       myMalloc(n, __FILE__, __LINE__)
#define calloc(a, b)	myCalloc(a, b, __FILE__, __LINE__)
#define realloc(a, b)	myRealloc(a, b, __FILE__, __LINE__)
#define free(ptr)		myFree(ptr)
#endif 

class memwatch_checker
{
public:
	memwatch_checker();
	~memwatch_checker();
	void calc();
private:
	unsigned int elementNums;
	size_t MemoryAllocations;
	memwatch_logger mLog;
};

#endif