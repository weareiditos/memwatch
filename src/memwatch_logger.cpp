#include "memwatch_logger.h"

typedef struct _tag_LinkList
{
	struct _tag_LinkList		*pre;
	struct _tag_LinkList		*next;
	size_t						size;
	char*						file;
	size_t						line;
}Tlist;

void print_first_line(std::ofstream &fout)
{
	fout << std::endl
		<< "============= "
		<< " MEMWATCH "
		<< " author by "
		<< AUTHORNAME
		<< " ============="
		<< std::endl
		<< std::endl;

	fout << "Started at ";
	char* month[] = { "January", "February", "March", "April" ,"May",
		"June","July","August","September","October","November", "December" };
	time_t nowtime;
	time(&nowtime);
	struct tm* p = localtime(&nowtime);
	fout <<
		month[p->tm_mon] << "," <<
		p->tm_mday << " " <<
		p->tm_year + 1900 << ",";
	fout << std::setw(2) << std::setfill('0') <<
		p->tm_hour;
	fout << ":";
	fout << std::setw(2) << std::setfill('0') <<
		p->tm_min;
	fout << ":";
	fout << std::setw(2) << std::setfill('0') <<
		p->tm_sec;
	fout << std::endl
		<< std::endl;
}

void print_fileline(std::ofstream &fout, Tlist *head)
{
	while (head)
	{
		fout << "unfree:";
		if (head->file)
		{
			fout << "<line:" << head->line << ">";
			fout << head->file << std::endl;
		}
		else
			fout << "Failed to get file information." << std::endl;
		head = head->next;
	}
	fout << std::endl;
}

void print_global_info(std::ofstream &fout, unsigned int made, size_t total)
{
	fout << "Memory usage statistics(global):" << std::endl;
	fout << "Number of allocations made : " << made << std::endl;
	fout << "Unfreed bytes totals : " << total << std::endl;
	fout << "MEMWATCH detected " << made << " anomalies" << std::endl;
}

void memwatch_logger::log(void *head)
{
	Tlist* log = (Tlist*)head;
	print_first_line(this->fout);
	print_fileline(this->fout, log->next);
	print_global_info(this->fout, this->elementNums, this->MemoryAllocations);
}

void memwatch_logger::set(unsigned int made, size_t total)
{
	this->elementNums = made;
	this->MemoryAllocations = total;
};

memwatch_logger::memwatch_logger() : fout(LOG_FILENAME, std::ios::out | std::ios::app) {};
memwatch_logger::~memwatch_logger() { fout.close(); };