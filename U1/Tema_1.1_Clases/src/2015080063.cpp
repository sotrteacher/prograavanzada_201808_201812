#include <cstdlib>
#include <iostream> 
#include <stdio.h>     
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h" 

void Nota_Directorio::reallocate(){
	int i;
	Nota *tmp=directorio;
	directorio=new Nota[capacity*2];
	for(i=0;i<(size-1);i++){
		directorio[i]=tmp[i];
	}
		
}


