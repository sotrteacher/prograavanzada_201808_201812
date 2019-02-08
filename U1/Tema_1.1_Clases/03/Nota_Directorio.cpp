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
}

/*Destruir el directorio cuando ya no se necesita*/
Nota_Directorio::~Nota_Directorio(){
}

/**Cargar datos desde el archivo que contiene los datos de las notas del directorio,
 * @param source_name El nombre del archivo (fuente de datos) con 
 *                    las entradas del directorio de Notas 
 */
void Nota_Directorio::load_data(const std::string& source_name){
}

void Nota_Directorio::add(const std::string& rem,const std::string& dest,const std::string& content){
}


