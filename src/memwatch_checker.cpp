#include "memwatch_checker.h"

memwatch_checker obj_checker;

memwatch_checker::memwatch_checker()
{
	this->elementNums = 0;
	this->MemoryAllocations = 0;
}

memwatch_checker::~memwatch_checker()
{
	this->calc();
	this->mLog.set(this->elementNums, this->MemoryAllocations);
	this->mLog.log(&head);
}

void memwatch_checker::calc()
{
	Tinfo* pHead = head.next;
	while (pHead)
	{
		this->elementNums++;
		this->MemoryAllocations += pHead->size;
		pHead = pHead->next;
	}
};