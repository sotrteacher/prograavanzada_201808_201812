#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"

 int Nota::contar_notas_del_destinatario(string stringNombreDelDestinatario, Nota_Directorio& el_directorio){
Nota *dir=el_directorio.directorio; //*dir 1 nota
//Nota Nota0= *dir;
//Nota Nota0= *(dir+0); equivalente
//for para escanear ;


bool test_cadena(string cad,string arr[],int tam=0){
	int i=0;
	while(i<size){
		if (cad==arr[i++]) return true;
	}
	return false;
}



for (int i=0,i<=size){
		if(test_cadena(str,stringNombreDelDestinatario,size)){
			cuentadestinatario++;
	}
	return 0;
	Nota Nota0= dir[i++];
}



		  
return -1;
}
