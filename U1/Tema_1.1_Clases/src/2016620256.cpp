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
 
 
 Nota::Nota(int intFecha){
  	//int Fecha 8 Digitos YY/MM/DD 20190228
  	int yy;
	int mes;
	int dia;
	string nombreMes;
	yy = intFecha/10000;
	mes = (intFecha%10000)/100;
	dia = intFecha%100;
	
	switch(mes){
	case 1:{ nombreMes = "Enero";break;} 
	case 2:{ nombreMes = "Febrero";break;} 
	case 3:{ nombreMes = "Marzo";break;} 
	case 4:{ nombreMes = "Abril";break;} 
	case 5:{ nombreMes = "Mayo";break;} 
	case 6:{ nombreMes = "Junio";break;} 
	case 7:{ nombreMes = "Julio";break;} 
	case 8:{ nombreMes = "Agosto";break;} 
	case 9:{ nombreMes = "Septiembre";break;} 
	case 10:{ nombreMes = "Octubre";break;} 
	case 11:{ nombreMes = "Noviembre";break;} 
	case 12:{ nombreMes = "Diciembre";break;}
	}
	char stringFecha [50];
	int n=sprintf (stringFecha,"Mexico, CDMX, a %d de %s del %d", dia, nombreMes.c_str(),yy);
	cout<< stringFecha <<endl;
	//cout<< "Mexico, CDMX a "<< dia << " de " << nombreMes <<" del "<< yy <<endl; 
	}




