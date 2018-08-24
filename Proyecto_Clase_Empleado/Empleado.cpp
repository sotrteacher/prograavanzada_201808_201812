/** Empleado.cpp - Resuelve los m\'etodos de la clase Empleado */
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
#include <cstring>
//using std::strlen;
//using std::strcpy;
using namespace std;

#include "Empleado.h"
int Empleado::cuenta=0;


int Empleado::getCuenta(){
	return cuenta;
}

Empleado::Empleado(const char *const nombre,const char *const apellido){
	primerNombre=new char[strlen(nombre)+1];
	//strcpy(primerNombre,nombre);
	strcpy_s(primerNombre,strlen(nombre)+1,nombre);

	apellidoPaterno=new char[strlen(apellido)+1];
	//strcpy(apellidoPaterno,apellido); 
	strcpy_s(apellidoPaterno,strlen(apellido)+1, apellido);

	cuenta++;
	cout<<"Se llam\\'o al constructor de empleado para "<<primerNombre<<" "
	    <<apellidoPaterno<<"."<<endl;
}

//el destructor desaigna la la memoria asignada en forma din\'amica
Empleado::~Empleado(){
	cout<<"Se llam\\'o a ~Empleado() para "<<primerNombre
	    <<' '<<apellidoPaterno<<endl;
	delete [] primerNombre;
	delete [] apellidoPaterno;
	cuenta--;
}

const char* Empleado::getPrimerNombre() const{
	return primerNombre;
}

const char* Empleado::getApellidoPaterno() const{
	return apellidoPaterno;
}
