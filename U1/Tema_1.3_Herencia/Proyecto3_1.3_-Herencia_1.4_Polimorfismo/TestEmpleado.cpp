/** TestEmpleado.cpp - USa la clase Empleado*/
#include <iostream>
using std::cout;
using std::endl;


#include "Empleado.h"

int main()
{
	cout<<"El n\\'umero de empleados antes de instanciar cualquier objeto es "
	    <<Empleado::getCuenta()<<endl;
    Empleado *e1Ptr=new Empleado("Susan","Baker");
    Empleado *e2Ptr=new Empleado("Robert","Jones");
	cout<<"El n\\'umero de empleados despu\\'es de instanciar \
los objetos es "<<Empleado::getCuenta()<<endl;
	    
    system("pause");
	return 0;
}
