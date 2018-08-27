#include "stdafx.h"
#include <iostream>
using std::cout;
#include "EmpleadoBaseMasComision.h"


EmpleadoBaseMasComision::EmpleadoBaseMasComision(const string& nombre, 
	const string& apellido, const string& nss,
	double ventas, double tarifa, double salario)
: EmpleadoPorComision(nombre,apellido,nss,ventas,tarifa)
{
	setSalarioBase(salario);
}

EmpleadoBaseMasComision::~EmpleadoBaseMasComision(){ }

void EmpleadoBaseMasComision::setSalarioBase(double salario) {
	salarioBase = (salario < 0.0) ? 0.0 : salario; 
}

double EmpleadoBaseMasComision::getSalarioBase() const{
	return salarioBase;
}

double EmpleadoBaseMasComision::ingresos() const{
	return salarioBase + (tarifaComision*ventasBrutas);
}

//Imprime el objeto EmpleadoBaseMasComision
void EmpleadoBaseMasComision::imprimir() const {
	cout << "Empleado por comisi\\'on con salario base: "
		<< primerNombre << ' ' << apellidoPaterno
		<< "\nNu\\'umero de seguro social: " << numeroSeguroSocial
		<< "\nVentas brutas: " << ventasBrutas
		<< "\nTarifa de comisi\\'on: " << tarifaComision
		<< "\nSalario base: " << salarioBase;
}