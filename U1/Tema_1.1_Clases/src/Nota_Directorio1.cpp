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

/*Construir un directorio de Notas vacio*/
Nota_Directorio::Nota_Directorio(){
	directorio=new Nota[10];
	size=0;
	capacity=10;
}

/*Destruir el directorio cuando ya no se necesita*/
Nota_Directorio::~Nota_Directorio(){
	//cout<<"Nota_Directorio::~Nota_Directorio()"<<endl;
	delete[] directorio;
}

/**Cargar datos desde el archivo que contiene los datos de las notas del directorio,
 * @param source_name El nombre del archivo (fuente de datos) con 
 *                    las entradas del directorio de Notas 
 */
void Nota_Directorio::load_data(const std::string& source_name){
}

/**Agregar una nueva Nota con un remitente y destinatario espec\'ificos y un  
 * contenido de Nota espec\'ifico.
 * @param rem Remitente
 * @param dest Destinatario
 * @param content Contenido de la Nota
 */
void Nota_Directorio::add(const std::string& rem,const std::string& dest,const std::string& content){
	if(size==capacity){
		reallocate();
	}
	directorio[size]=Nota(rem,dest,content);
	size++;
}

/**Crear un nuevo conjunto de entradas del directorio de Notas con el doble de la
 * capacidad actual.
 */ 
void Nota_Directorio::reallocate(){

}

