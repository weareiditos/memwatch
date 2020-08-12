#ifndef _MEMWATCH_LOGGER_H_
#define _MEMWATCH_LOGGER_H_
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

#define LOG_FILENAME	"./log_memory.log"
#define AUTHORNAME "lzs"

class memwatch_logger
{
public:
	memwatch_logger();
	~memwatch_logger();
	void log(void*);
	void set(unsigned int, size_t);
	
private:
	std::ofstream fout;
	unsigned int elementNums;
	size_t MemoryAllocations;
};

#endif // !_MEMWATCH_LOGGER_H_


