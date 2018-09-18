#pragma once
#include <string>
using std::string;
class EmpleadoPorComision
{
public:
	EmpleadoPorComision(const string&,const string&,const string&,
		double = 0.0,double = 0.0);
	~EmpleadoPorComision();

	void setPrimerNombre(const string&);
	string getPrimerNombre() const;

	void setApellidoPaterno(const string&);
	string getApellidoPaterno() const;

	void setNumeroSeguroSocial(const string&);
	string getNumeroSeguroSocial() const;

	void setVentasBrutas(double);
	double getVentasBrutas() const;

	void setTarifaComision(double);
	double getTarifaComision() const;

	double ingresos() const;   //calcula los ingresos
	void imprimir() const;     //imprime el objeto EmpleadoPorComision

private:
	string primerNombre;
	string apellidoPaterno;
	string numeroSeguroSocial;
	double ventasBrutas;      //ventas brutas por semana
	double tarifaComision;    //porcentaje de comisi\'on
};//end class EmpleadoPorComision

