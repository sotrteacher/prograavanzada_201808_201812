//destructor de nota directorio
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"
	/*Destruir el directorio cuando ya no se necesita*/
	Nota_Directorio::~Nota_Directorio(){
        cout<<"se esta destruyendo a nota_ directorio";
        delete[] directorio;
        //void operator delete[] (void* directorio) throw();
        }	

