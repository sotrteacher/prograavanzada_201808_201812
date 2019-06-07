#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
using namespace std;
#include "Nota_Directorio.h"
#include "Nota.h"

contar_notas_del_remitente(string stringNombreDelRemitente, Nota_Directorio& el_directorio){
	
	Nota* directorio = el_directorio.directorio;
	int size = el_directorio.size;
	int search = 0;
	for (int _ = 0; _ < size; _ ++){
		if(el_directorio.directorio[_].stringRemitente == stringNombreDelRemitente){
			search++;
		}
	}
	return search;
};
    	
