#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;
#include "Nota_Directorio.h"
#include "Nota.h"

void Nota_Directorio::remove_entry(int index){
	int i;
	if (index>capacity){
		cout<<"\nPosicion ingresada no valida!"<<endl;
	}
	else{
		 for(i=0; i<capacity; i++){
		 	if(i==index){	
		 		while(i<capacity){
		 			Nota[i]=Nota[i+1];
		 			i++;
			 	}
				break;
		    }
		 }	
		 capacity=capacity-1;
		 cout<<"El elemento ha sido eliminado"<<endl;
	}
}


