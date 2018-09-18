#pragma once
#ifndef ASALARIADO_H
#define ASALARIADO_H
#include <string>
using std::string;

#include "Empleado.h"
class EmpleadoAsalariado : public Empleado
{
public:
	EmpleadoAsalariado(const string&,const string&,
		const string&,double = 0);
	~EmpleadoAsalariado();

	void setSalarioSemanal(double);
	double getSalarioSemanal() const;

	//virtual indica el intento de sobrescribir
	virtual double ingresos() const;
	virtual void imprimir() const;

private:
	double salarioSemanal;
};//end class EmpleadoAsalariado

#endif /*ASALARIADO_H*/