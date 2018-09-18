// ConsoleApplication_Empleado_Herencia_Polimorfismo.cpp: define el punto de entrada de la aplicaci½n de consola.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <string>
using std::string;

#include <vector>
using std::vector;
#include <windows.h> /* SetConsoleOutputPC() */

#include "Empleado.h"
#include "EmpleadoAsalariado.h"
#include "EmpleadoPorHoras.h"
#include "EmpleadoPorComision.h"
#include "EmpleadoBaseMasComision.h"
#define JERARQUIA_DE_CLASES
//#define ENLAZADO_ESTATICO
#define ENLAZADO_DINAMICO
//#define VIA_APUNTADOR
#define VIA_REFERENCIA

#ifdef JERARQUIA_DE_CLASES
using std::fill_n;
#define MAXSIZE	1000
int last_backslash(TCHAR*);
void get_substr(TCHAR* cmdL, int intCantidad, char charBuf[MAXSIZE]);
TCHAR STR[] = _T("project1.exe");
#endif /* JERARQUIA_DE_CLASES */
void virtualViaApuntador(const Empleado *const);
void virtualViaReferencia(const Empleado&);

int main()
{
#ifdef JERARQUIA_DE_CLASES
	TCHAR*              cmdline;
	STARTUPINFO         startup_info;
	PROCESS_INFORMATION process_info;
	char charBuffer[MAXSIZE];
	char exepath[MAXSIZE];
	char str[MAXSIZE];
	cmdline = GetCommandLine();/*obtiene la orden o comando equivalente 
							   de CLI (Command Line Interface) */
	string stringCmdline = string(cmdline);
	size_t lastBackslash = stringCmdline.find_last_of('\\',stringCmdline.length());
	string cmdline1 = stringCmdline.substr(1,lastBackslash);
	//cout << "cmdline1\n"<<cmdline1 << endl;
	cmdline1 = cmdline1 + "project1.exe";
	//cout << "cmdline1\n" << cmdline1 << endl;
	LPCSTR PROYECTO1 = LPCSTR(cmdline1.c_str());
	//int intCantidad = last_backslash(cmdline);
	//get_substr(cmdline, intCantidad, charBuffer);
	//
	//sprintf_s(exepath, "%s%s", charBuffer, "project1.exe");
	//printf("%s\n", exepath);

	fill_n((char*)&process_info, sizeof(PROCESS_INFORMATION), 0);
	fill_n((char*)&startup_info, sizeof(STARTUPINFO), 0);

	startup_info.cb = sizeof(STARTUPINFO);
	if (!CreateProcess(PROYECTO1,STR, NULL, NULL, TRUE,
		NORMAL_PRIORITY_CLASS,NULL,NULL,&startup_info,
		&process_info)) {
		return 2;
	}
	CloseHandle(process_info.hThread);
	// wait for the child program to terminate
	WaitForSingleObject(process_info.hProcess, INFINITE);
#endif /* JERARQUIA_DE_CLASES */
	SetConsoleOutputCP(850);
	//establecer el formato de de salida de punto flotante
	cout << fixed << setprecision(2);

	//Creaci\'on de objetos de las clases derivadas
	EmpleadoAsalariado empleadoAsalariado(
		"John","Smith","11-111-1111",800);
	EmpleadoPorHoras empleadoPorHoras(
		"Karen","Price","222-22-2222",16.75,40);
	EmpleadoPorComision empleadoPorComision(
		"Sue","Jones","333-33-3333",10000,0.06);
	EmpleadoBaseMasComision empleadoBaseMasComision(
		"Bob","Lewis","444-44-4444",5000,0.04,300);
	cout << "Se instanciaron 4 objetos de clases derivadas" << endl;
#ifdef ENLAZADO_ESTATICO
	cout << "Empleados procesados en forma individual, \
usando enlazado estÿtico:\n\n";
	//Imprime la informaci\'on de cada empleado y sus ingresos 
	//usando enlazado est\'atico
	empleadoAsalariado.imprimir();
	cout << "\nobtuvo: $" << empleadoAsalariado.ingresos()<<"\n\n";
	empleadoPorHoras.imprimir();
	cout << "\nobtuvo: $" << empleadoPorHoras.ingresos() << "\n\n";
	empleadoPorComision.imprimir();
	cout << "\nobtuvo: $" << empleadoPorComision.ingresos() << "\n\n";
	empleadoBaseMasComision.imprimir();
	cout << "\nobtuvo: $" << empleadoBaseMasComision.ingresos() << "\n\n";
#endif /* ENLAZADO_ESTATICO */
	//Vector de 4 apuntadores a objetos de clase base
	vector<Empleado*> empleado(4);
	//Se inicializa el vector
	empleado[0] = &empleadoAsalariado;
	empleado[1] = &empleadoPorHoras;
	empleado[2] = &empleadoPorComision;
	empleado[3] = &empleadoBaseMasComision;

	//Empleados procesados usando polimorfismo
#ifdef ENLAZADO_DINAMICO
#ifdef VIA_APUNTADOR
	cout << "Empleados procesados usando polimorfismo mediante \
enlazado dinÿmico:\n\n";	
	cout << "Llamadas a funciones virtuales realizadas desde \
apuntadores a objetos de clase base:\n\n";
	for (size_t i = 0; i < empleado.size(); i++) {
		virtualViaApuntador(empleado[i]);
	}
#endif /* VIA_APUNTADOR */
#ifdef VIA_REFERENCIA
	cout << "Llamadas a funciones virtuales realizadas desde \
referencias a objetos de clase base:\n\n";
	for (size_t i = 0; i < empleado.size(); i++) {
		virtualViaReferencia(*empleado[i]);//observe la 
		                                   //derreferenciaci\'on del
		                                   //apuntador.
	}
#endif /* VIA_REFERENCIA */
#endif /* ENLAZADO_DINAMICO */

#ifdef __MINGW32__
	system("pause");
#endif
    return 0;
}

//llama a las funciones virtuales imprimir e ingresos de Empleado 
//a trav\'es de un apuntador a objeto de clase base mediante 
//enlazado din\'amico
void virtualViaApuntador(const Empleado *const claseBaseEmpleadoPtr) {
	claseBaseEmpleadoPtr->imprimir();
	cout << "\nobtuvo $" << claseBaseEmpleadoPtr->ingresos()<<"\n\n";
}

//llama a las funciones virtuales imprimir e ingresos de Empleado 
//a trav\'es de una referencia a objeto de clase base mediante 
//enlazado din\'amico
void virtualViaReferencia(const Empleado& claseBaseEmpleadoRef) {
	claseBaseEmpleadoRef.imprimir();
	cout << "\nobtuvo $" << claseBaseEmpleadoRef.ingresos()<< "\n\n";
}

//#ifdef JERARQUIA
///**
//* Devuelve la cantidad de car\'acteres que hay que usar de cmdL
//* para incluir hasta el \'ultimo backslash (es decir, desde el
//* car\'acter 0 hasta el car\'acter que devuelve esta funci\'on)
//*/
//int last_backslash(TCHAR* cmdL) {
//	int r = 0, i = 0, intI = 0;
//	while ('\0' != cmdL[i]) {
//		if ('\\' == cmdL[i]) {
//			r++;
//		}
//		i++;
//	}/*Now r is the amount of backslashes*/
//	i = 0;
//	while ((intI<r) && ('\0' != cmdL[i])) {
//		if ('\\' == cmdL[i]) {
//			intI++;
//		}
//		i++;
//	}
//	return i;
//}
//
//void get_substr(TCHAR* cmdL, int intCantidad, char charBuf[MAXSIZE]) {
//	int i = 0;
//	/*int i = 3;*/
//	while (i<intCantidad) {
//		charBuf[i] = cmdL[i];
//		i++;
//	}
//	charBuf[i] = '\0';
//}
//#endif /* JERARQUIA */

