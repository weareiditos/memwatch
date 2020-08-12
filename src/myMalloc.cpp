#include "myMalloc.h"

void* __cdecl myMalloc(size_t _Size, char* _File, int _Line)
{
	// 重新计算需要分配的空间大小
	size_t new_size = _Size + sizeof(Tinfo);
	Tinfo* new_element = (Tinfo*)malloc(new_size);
	// 设置大小以及相关信息
	new_element->size = _Size;
	// 如果有文件信息, 则保存下来
	if (_File)
	{
		new_element->file = (char*)malloc(strlen(_File) + 1);
		strcpy(new_element->file, _File);
	}
	else
		new_element->file = 0;

	new_element->line = _Line;
	// 头插法插入元素
	new_element->next = head.next;
	if (head.next)
		head.next->pre = new_element;
	head.next = new_element;
	new_element->pre = &head;

	return (char*)new_element + sizeof(Tinfo);
}