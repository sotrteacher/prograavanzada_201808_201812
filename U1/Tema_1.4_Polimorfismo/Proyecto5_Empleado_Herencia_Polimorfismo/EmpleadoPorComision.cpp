#include "stdafx.h"
#include <iostream>
using std::cout;
#include "EmpleadoPorComision.h"

//constructor
EmpleadoPorComision::EmpleadoPorComision(const string& nombre,
	const string& apellido, const string&nss,
	double ventas, double tarifa)
:Empleado(nombre,apellido,nss)
{
	//primerNombre = nombre;
	//apellidoPaterno = apellido;
	//numeroSeguroSocial = nss;
	setVentasBrutas(ventas);
	setTarifaComision(tarifa);
}//end constructor EmpleadoPorComision

EmpleadoPorComision::~EmpleadoPorComision()
{ }

//void EmpleadoPorComision::setPrimerNombre(const string& nombre) {
//	primerNombre = nombre;
//}
//
//string EmpleadoPorComision::getPrimerNombre() const {
//	return primerNombre;
//}
//
//void EmpleadoPorComision::setApellidoPaterno(const string& apellido) {
//	apellidoPaterno = apellido;
//}
//
//string EmpleadoPorComision::getApellidoPaterno() const {
//	return apellidoPaterno;
//}
//
//void EmpleadoPorComision::setNumeroSeguroSocial(const string& nss) {
//	numeroSeguroSocial = nss;
//}
//
//string EmpleadoPorComision::getNumeroSeguroSocial() const {
//	return numeroSeguroSocial;
//}

void EmpleadoPorComision::setVentasBrutas(double ventas) {
	ventasBrutas = (ventas<0.0) ? 0.0 : ventas;
}

double EmpleadoPorComision::getVentasBrutas() const {
	return ventasBrutas;
}

void EmpleadoPorComision::setTarifaComision(double tarifa) {
	tarifaComision = (tarifa > 0.0 && tarifa < 1.0) ? tarifa : 0.0;
}

double EmpleadoPorComision::getTarifaComision() const {
	return tarifaComision;
}

//calcula los ingresos
double EmpleadoPorComision::ingresos() const {
	//return tarifaComision * ventasBrutas;
	return getTarifaComision()*getVentasBrutas();
}

//imprime el objeto EmpleadoPorComision
void EmpleadoPorComision::imprimir() const {
	/*cout << "Empleado por comisi¢n: " << primerNombre << ' '
		<< apellidoPaterno << "\nN£mero de seguro social: "
		<< numeroSeguroSocial << "\nVentas brutas: "
		<< ventasBrutas << "\nTarifa de comisi¢n: "
		<< tarifaComision;*/
	cout << "Empleado por comisi¢n: ";
	Empleado::imprimir(); //reutilizaci\'on de c\'odigo
	cout << "\nVentas brutas: " << getVentasBrutas()
		<< "; tarifa de comisi¢n: " << getTarifaComision();
}
