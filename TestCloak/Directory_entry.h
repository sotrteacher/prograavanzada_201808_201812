/** Directory_entry.h
*/
#ifndef DIRECTORY_ENTRY
#define DIRECTORY_ENTRY
#include <string>
class Directory_entry {
public:
	std::string var_name;
	std::string coeffs;
	
	Directory_entry();
	Directory_entry(std::string var_name,std::string coeffs);
};

#endif /*DIRECTORY_ENTRY*/
