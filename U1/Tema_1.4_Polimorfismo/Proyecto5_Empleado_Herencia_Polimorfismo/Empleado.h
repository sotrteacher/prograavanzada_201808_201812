#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
using std::string;

class Empleado
{
public:
	Empleado(const string&,const string &,const string&);
	~Empleado();
	void setPrimerNombre(const string&);
	string getPrimerNombre() const;

	void setApellidoPaterno(const string&);
	string getApellidoPaterno() const;

	void setNumeroSeguroSocial(const string&);
	string getNumeroSeguroSocial() const;

	//funci\'on virtual pura
	virtual double ingresos() const = 0;

	//funci\'on virtual
	virtual void imprimir() const;

private:
	string primerNombre;
	string apellidoPaterno;
	string numeroSeguroSocial;
};//end class Empleado

#endif /*EMPLEADO_H*/