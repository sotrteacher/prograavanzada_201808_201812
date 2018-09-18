#include "stdafx.h"
#include <iostream>
using std::cout;
#include "Empleado.h"


Empleado::Empleado(const string& nombre, 
	const string &apellido, const string& nss)
:primerNombre(nombre),apellidoPaterno(apellido),
numeroSeguroSocial(nss)
{ /*deliberadamente vacio*/ }

Empleado::~Empleado()
{ }

void Empleado::setPrimerNombre(const string&nombre) {
	primerNombre = nombre;
}

string Empleado::getPrimerNombre()const {
	return primerNombre;
}

void Empleado::setApellidoPaterno(const string& apellido) {
	apellidoPaterno = apellido;
}

string Empleado::getApellidoPaterno()const {
	return apellidoPaterno;
}

void Empleado::setNumeroSeguroSocial(const string& nss) {
	numeroSeguroSocial = nss;
}

string Empleado::getNumeroSeguroSocial()const {
	return numeroSeguroSocial;
}

void Empleado::imprimir() const{
	cout << getPrimerNombre() << ' ' << getApellidoPaterno()
		<< "\nN£mero de seguro social: " << getNumeroSeguroSocial();
}