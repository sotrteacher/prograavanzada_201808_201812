#pragma once
#ifndef BASEMAS_H
#define BASEMAS_H
#include <string>
using std::string;
#include "EmpleadoPorComision.h"
class EmpleadoBaseMasComision : public EmpleadoPorComision{
public:
	EmpleadoBaseMasComision(const string&,const string&,
		const string&,double=0.0,double=0.0,double=0.0);
	~EmpleadoBaseMasComision();

	//void setPrimerNombre(const string&);
	//string getPrimerNombre() const;

	//void setApellidoPaterno(const string&);
	//string getApellidoPaterno() const;

	//void setNumeroSeguroSocial(const string&);
	//string getNumeroSeguroSocial() const;

	//void setVentasBrutas(double);
	//double getVentasBrutas() const;

	//void setTarifaComision(double);
	//double getTarifaComision() const;

	void setSalarioBase(double);  //establece el salario base
	double getSalarioBase() const;//devuelve el salario base

	//virtual indica la intenci\'on de sobrescribir
	virtual double ingresos() const;   //calcula los ingresos
	virtual void imprimir() const;     //imprime el objeto EmpleadoBaseMasComision

private:
	//string primerNombre;
	//string apellidoPaterno;
	//string numeroSeguroSocial;
	//double ventasBrutas;      //ventas brutas por semana
	//double tarifaComision;    //porcentaje de comisi\'on
	double salarioBase;
};//end class EmpleadoBaseMasComision

#endif /* BASEMAS_H */
