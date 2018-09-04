/** Directory_entry.cpp
*/
#include "Directory_entry.h"

Directory_entry::Directory_entry()
{ //Deliberadamente vacio
}

Directory_entry::Directory_entry(std::string var_name,std::string coeffs){
	this->var_name=var_name;
	this->coeffs=coeffs;
}


