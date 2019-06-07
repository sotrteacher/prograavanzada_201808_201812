#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"
void Nota_Directorio::add(const std::string& rem,const std::string& dest,const std::string& content)
{
	if(size==capacity)
    {
        reallocate();
    }
    directorio[size]=Nota(rem,dest,content);
    time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time.
    struct tm *tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo
    char fecha[10];
    int fechanum; //array donde guardo la fecha
    strftime(fecha,10,"%Y/%m/%d",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    fechanum=atoi(fecha);
    cout<<"\n"<<fechanum<<endl;
    directorio[size].stringFecha=fechanum;
    size++;
}
