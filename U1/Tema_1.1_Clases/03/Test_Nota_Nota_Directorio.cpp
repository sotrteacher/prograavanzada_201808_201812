//Test_Nota_Nota_Directorio.cpp
//Driver de prueba para las clases Nota y Nota_Directorio que 
//utiliza la consola I/O.

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

//Declaraci\'on de las funciones
void procesar_comandos(Nota_Directorio& el_directorio);
//void do_add_change_entry(Nota_Directorio& el_directorio);
void do_agregar_Nota(Nota_Directorio& el_directorio);
void do_contar_Notas_de_un_remitente(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_contar_Notas_de_un_destinatario(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_contar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_mostrar_Notas_de_un_remitente(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_mostrar_Notas_de_un_destinatario(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_mostrar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_buscar_entradas(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_remove_entry(Nota_Directorio& el_directorio) __attribute__ ((weak));
void do_salir(Nota_Directorio& el_directorio) __attribute__ ((weak));

int main(int argc,char* argv[])
{
	if(argc<2){
		cerr<<"Debe especificar el nombre del archivo de datos"
		    <<"que contiene el directorio\n";
		printf("Forma de uso:./%s <archivo_de_datos.txt>\n",argv[0]);
		return 1;
	}
	Nota_Directorio el_directorio;
	el_directorio.load_data(argv[1]);
	procesar_comandos(el_directorio);

#ifndef __unix__
    system("pause");
#endif
	return 0;
}//end main()


void procesar_comandos(Nota_Directorio& el_directorio){
	std::string comando[]={
		"Agregar Nota",
		"Contar Notas de un remitente",
		"Contar Notas de un destinatario",
		"Contar Notas de un remitente a un destinatario",
		"Mostrar Notas de un remitente",
		"Mostrar Notas de un destinatario",
		"Mostrar Notas de un remitente a un destinatario",
		"Buscar palabras en Notas",
		"Eliminar Nota",
		"Salir"
	};
	const int NUM_COMMANDS=10;
	int opcion=NUM_COMMANDS-1;
	do{
		for(int i=0;i<NUM_COMMANDS;i++){
			cout<<i<<") "<<comando[i]<<"\n";
		}
		cin>>opcion;
		cin.ignore(numeric_limits<int>::max(),'\n');
		switch(opcion){
			case 0:{do_agregar_Nota(el_directorio);break;}
			case 1:{do_contar_Notas_de_un_remitente(el_directorio);break;}
			case 2:{do_contar_Notas_de_un_destinatario(el_directorio);break;}
			case 3:{do_contar_Notas_de_un_remitente_a_un_destinatario(el_directorio);break;}
			case 4:{do_mostrar_Notas_de_un_remitente(el_directorio);break;}
			case 5:{do_mostrar_Notas_de_un_destinatario(el_directorio);break;}
			case 6:{do_mostrar_Notas_de_un_remitente_a_un_destinatario(el_directorio);break;}
			case 7:{do_buscar_entradas(el_directorio);break;}
			case 8:{do_remove_entry(el_directorio);break;}
			case 9:{do_salir(el_directorio);break;}
		}
	}while(opcion<NUM_COMMANDS-1);
}//end void procesar_comandos()

void do_agregar_Nota(Nota_Directorio& el_directorio){
	string rem;
	string dest;
	string contenido;
	cout<<"Remitente: ";
	getline(cin,rem);
	cout<<"Destinatario: ";
	getline(cin,dest);
	cout<<"Contenido: ";
	getline(cin,contenido);
	el_directorio.add(rem,dest,contenido);
	cout<<"Se ha agregado una nota de "<<rem<<" para "<<dest<<".\n";
}

void do_contar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
}

void do_contar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
}

void do_contar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio){
}

void do_mostrar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
}

void do_mostrar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
}

void do_mostrar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio){
}

void do_buscar_entradas(Nota_Directorio& el_directorio){
}

void do_remove_entry(Nota_Directorio& el_directorio){
}

void do_salir(Nota_Directorio& el_directorio){
}


