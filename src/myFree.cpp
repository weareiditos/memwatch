#include "myFree.h"

void __cdecl myFree(void* _Block)
{
	if (_Block == NULL)
		return;

	// 跳过STL中自定义的operator new
	Tinfo *pHead = head.next;
	while (pHead)
	{
		if ((char*)pHead == ((char*)_Block - sizeof(Tinfo)))
			break;
		pHead = pHead->next;
	}
	if (pHead == NULL)
		return;

	// 注意, 堆的空间自底向上增长. 所以此处为减去结构体大小
	Tinfo* cur_element = (Tinfo*)((char*)_Block - sizeof(Tinfo));

	// 更新链表，将自己的前一个结点指向后一个结点，后一个结点指向前一个结点
	cur_element->pre->next = cur_element->next;
	if (cur_element->next)
		cur_element->next->pre = cur_element->pre;
	
	// 注意，因为结构体Tinfo的file也是动态分配内存的，所以我们在释放Tinfo元素的时候，一定要先释放file
	if (cur_element->file != NULL)
		free(cur_element->file);

	// 释放空间
	free(cur_element);
}
