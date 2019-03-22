//Test_Nota_Nota_Directorio.cpp
//Driver de prueba para las clases Nota y Nota_Directorio que 
//utiliza la consola I/O.

#include <iostream>
//#include <istream>
//#include <ostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
using namespace std;

#include "Nota.h"
#include "Nota_Directorio.h"
#include "Test_Nota_Nota_Directorio.h"


int main(int argc,char* argv[])
{
	if(argc<2){
		cerr<<"Debe especificar el nombre del archivo de datos "
		    <<"que contiene el directorio\n";
		printf("Forma de uso:%s <archivo_de_datos.txt>\n",argv[0]);
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
		//cin.ignore(256,'\n');
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


/*2019.03.21*/
void do_agregar_Nota(Nota_Directorio& el_directorio){
	LMC_do_agregar_Nota(el_directorio);
}

//Asignaci\'on P1.15
//2017362541 ROSETE CORTES JAVIER
#ifndef DISC_2017362541
void do_contar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
	LMC_do_contar_Notas_de_un_remitente(el_directorio);
}
#endif /*DISC_2017362541*/

//V\'ease archivo ../Aclaracion_2019_2-parcial_1.txt
//Asignaci\'on P1.16
//2019640503 NAVARRO MEDINA DAFNE YESENIA
#ifndef DISC_2019640503
void do_contar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
	LMC_do_contar_Notas_de_un_destinatario(el_directorio);
}
#endif /*DISC_2019640503*/

//Asignaci\'on P1.17
//2014030995 ORTIZ GONZALEZ ESDRAS BENJAMIN
#ifndef DISC_2014030995
void do_mostrar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
	LMC_do_mostrar_Notas_de_un_remitente(el_directorio);
}
#endif /*DISC_2014030995*/

//Asignaci\'on P1.19
//2015080693 JUAREZ CRUZ BRANDON ARATH
#ifndef DISC_2015080693
void do_contar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio){
	LMC_do_contar_Notas_de_un_remitente_a_un_destinatario(el_directorio);
}
#endif /*DISC_2015080693*/

//Asignaci\'on P1.20
//2015080865 MELGAREJO RAMIREZ JOHAN
#ifndef DISC_2015080865
void do_mostrar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
	LMC_do_mostrar_Notas_de_un_destinatario(el_directorio);
}
#endif /*DISC_2015080865*/

//Asignaci\'on P1.21
//2016640273 SANCHEZ AMARO GUSTAVO
#ifndef DISC_2016640273
void do_mostrar_Notas_de_un_remitente_a_un_destinatario(Nota_Directorio& el_directorio){
	LMC_do_mostrar_Notas_de_un_remitente_a_un_destinatario(el_directorio);
}
#endif /*DISC_2016640273*/

//Asignaci\'on P1.22
//2016640385 ALMANZA ALVARADO LUIS FERNANDO
#ifndef DISC_2016640385
void do_buscar_entradas(Nota_Directorio& el_directorio){
	LMC_do_buscar_entradas(el_directorio);
}
#endif /*DISC_2016640385*/

/*Esta funci\'on parece que no la he asignado aun a 
  ning\'un discente (2019.03.19.18.04) */
void do_remove_entry(Nota_Directorio& el_directorio){
	LMC_do_remove_entry(el_directorio);
}

/*Esta funci\'on parece que no la he asignado aun a 
  ning\'un discente (2019.03.19.18.04) */
void do_salir(Nota_Directorio& el_directorio){
	LMC_do_salir(el_directorio);
}




