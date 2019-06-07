#include <iostream>
#include <string>
#include <windows.h>
#include <time.h> 
#include <fstream>

using namespace std;
#include "Nota_Directorio.h"
#include "Nota.h"

Nota::do_mostrar_Notas_de_un_destinatario(string stringNombreDelDestinatario, Nota_Directorio& el_directorio)
{	
	int nnd=0;
	for (int _=0;_<sizeof *Nota;_++){
	if(array[_]->stringDestinatario==stringNombreDelDestinatario){
	nnd ++;}
	}
	
	if(nnd!=0){cout<<"Se encontraron estas notas para "<<stringNombreDelDestinatario<<endl;}
	
	else{cout<<"No se encontraron notas para "<<stringNombreDelDestinatario<<endl;}	
	
	for (int _=0;_<sizeof *Nota;_++){
		if(array[_]->stringDestinatario==stringNombreDelDestinatario){
		cout<<"   Nota"<<_<<":"<<endl;
		array[_]->mostrar();	
		cout<<endl<<endl;
		}
	}	
};
