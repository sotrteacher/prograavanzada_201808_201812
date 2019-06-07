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

Nota::contar_notas_del_remitente(string stringNombreDelRemitente,Nota_Directorio& el_directorio){
	//Nota *directorio;
  	int search=0;
  	for (int _=0;_<sizeof *Nota;_++){
  		if(Nota[_].stringRemitente == stringNombreDelRemitente){
  			search++;
		  }
	  }
  	return search;
    };
    