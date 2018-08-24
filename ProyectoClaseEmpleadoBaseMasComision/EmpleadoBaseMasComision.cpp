#include "stdafx.h"
#include <iostream>
using std::cout;
#include "EmpleadoBaseMasComision.h"

//constructor
EmpleadoBaseMasComision::EmpleadoBaseMasComision(const string& nombre,
	const string& apellido,const string& nss, double ventas, 
	double tarifa,double salario)
{
	primerNombre = nombre;
	apellidoPaterno = apellido;
	numeroSeguroSocial = nss;
	setVentasBrutas(ventas);
	setTarifaComision(tarifa);
	setSalarioBase(salario);
}

EmpleadoBaseMasComision::~EmpleadoBaseMasComision()
{
}

void EmpleadoBaseMasComision::setPrimerNombre(const string& nombre) {
	primerNombre = nombre;
}

string EmpleadoBaseMasComision::getPrimerNombre() const {
	return primerNombre;
}

void EmpleadoBaseMasComision::setApellidoPaterno(const string& apellido) {
	apellidoPaterno = apellido;
}

string EmpleadoBaseMasComision::getApellidoPaterno() const {
	return apellidoPaterno;
}

void EmpleadoBaseMasComision::setNumeroSeguroSocial(const string& nss) {
	numeroSeguroSocial = nss;
}

string EmpleadoBaseMasComision::getNumeroSeguroSocial() const {
	return numeroSeguroSocial;
}

void EmpleadoBaseMasComision::setVentasBrutas(double ventas) {
	ventasBrutas = (ventas < 0.0) ? 0.0 : ventas;
}

double EmpleadoBaseMasComision::getVentasBrutas() const {
	return ventasBrutas;
}

void EmpleadoBaseMasComision::setTarifaComision(double tarifa) {
	tarifaComision = (tarifa > 0 && tarifa < 1.0) ? tarifa : 0.0;
}

double EmpleadoBaseMasComision::getTarifaComision() const {
	return tarifaComision;
}

void EmpleadoBaseMasComision::setSalarioBase(double salario) {
	salarioBase = (salario < 0.0) ? 0.0 : salario;
}

double EmpleadoBaseMasComision::getSalarioBase() const {
	return salarioBase;
}

double EmpleadoBaseMasComision::ingresos() const {
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