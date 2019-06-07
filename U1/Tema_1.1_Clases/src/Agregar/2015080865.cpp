#include <iostream>
#include <string>
#include <windows.h>
#include <time.h> 
#include <fstream>

using namespace std;
#include "Nota_Directorio.h"
#include "Nota.h"

do_mostrar_Notas_de_un_destinatario(string stringNombreDelDestinatario, Nota_Directorio& el_directorio)
{	
	Nota* directorio = el_directorio.directorio;
    int Tam = el_directorio.size;
	int nnd=0;
	for (int i = 0 ; i < size; i ++){
		if(el_directorio.directorio[i].stringDestinatario == stringNombreDelDestinatario){
		nnd ++;}
	}
	
	if(nnd!=0){cout<<"Se encontraron estas notas para "<<stringNombreDelDestinatario<<endl;}
	
	else{cout<<"No se encontraron notas para "<<stringNombreDelDestinatario<<endl;}	
	
	for (int i=0; i < size;i ++){
		if(el_directorio.directorio[i].stringDestinatario == stringNombreDelDestinatario){
		cout<<"   Nota"<<i<<":"<<endl;
		cout<<el_directorio.directorio[i];	
		cout<<endl<<endl;
		}
	}	
};
