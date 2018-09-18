#pragma once
#ifndef PORHORAS_H
#define PORHORAS_H
#include "Empleado.h"
class EmpleadoPorHoras : public Empleado
{
public:
	EmpleadoPorHoras(const string&,const string&,
		const string&,double=0.0,double=0.0);
	~EmpleadoPorHoras();

	void setSueldo(double);//establece el sueldo por hora
	double getSueldo()const;//devuelve el sueldo por hora

	void setHoras(double);//establece horas trabajadas
	double getHoras()const;//devuelve las horas trabajadas

	//virtual indica el intento de sobrescribir
	virtual double ingresos() const;//calcula los ingresos
	virtual void imprimir() const;//imprime el objeto EmpleadoPorHoras

private:
	double sueldo;//sueldo por hora
	double horas;//horas trabajadas por semana
};//end class EmpleadoPorHoras

#endif /*PORHORAS_H*/