#include "stdafx.h"
#include <iostream>
using std::cout;
#include "EmpleadoAsalariado.h"

EmpleadoAsalariado::EmpleadoAsalariado(const string& nombre,
	const string& apellido,
	const string& nss, double salario)
: Empleado(nombre,apellido,nss)
{
	setSalarioSemanal(salario);
}

EmpleadoAsalariado::~EmpleadoAsalariado()
{ }

void EmpleadoAsalariado::setSalarioSemanal(double salario) {
	salarioSemanal = (salario < 0.0) ? 0.0 : salario;
}

double EmpleadoAsalariado::getSalarioSemanal() const {
	return salarioSemanal;
}

//sobrescribe la funci\'on virtual
double EmpleadoAsalariado::ingresos() const {
	return getSalarioSemanal();
}

void EmpleadoAsalariado::imprimir() const {
	cout << "Empleado asalariado: ";
	Empleado::imprimir();//reutiliza la funci\'on imprimir
	                     //de la clase base abstracta
	cout << "\nSalario semanal: " << getSalarioSemanal();
}

