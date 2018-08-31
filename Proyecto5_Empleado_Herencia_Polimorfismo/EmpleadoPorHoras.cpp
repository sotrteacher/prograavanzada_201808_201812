#include "stdafx.h"
#include <iostream>
using std::cout;
#include "EmpleadoPorHoras.h"


EmpleadoPorHoras::EmpleadoPorHoras(const string& nombre,
	const string& apellido,const string& nss,
	double sueldoHora, double horasTrabajadas)
:Empleado(nombre,apellido,nss){
	setSueldo(sueldoHora);
	setHoras(horasTrabajadas);
}

EmpleadoPorHoras::~EmpleadoPorHoras()
{ }

void EmpleadoPorHoras::setSueldo(double sueldoHora) {
	sueldo = sueldoHora < 0.0 ? 0.0 : sueldoHora;
}
double EmpleadoPorHoras::getSueldo()const {
	return sueldo;
}

void EmpleadoPorHoras::setHoras(double horasTrabajadas) {
	horas = (horasTrabajadas >= 0.0) ? horasTrabajadas : 0.0;
}
double EmpleadoPorHoras::getHoras()const {
	return horas;
}

double EmpleadoPorHoras::ingresos() const{
	if (getHoras() <= 40)
		return getSueldo()*getHoras();
	else
		return 40 * getSueldo() + ((getHoras()-40)*getSueldo()*1.5);
}
void EmpleadoPorHoras::imprimir() const {
	cout << "Empleado por horas: ";
	Empleado::imprimir();//code reuse
	cout << "\nSueldo por hora: " << getSueldo()
		<< "; horas trabajadas: " << getHoras();
}
