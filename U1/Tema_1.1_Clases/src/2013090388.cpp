#include <bits/stdc++.h> 
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>

#include <stdlib.h>
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"

struct  Par_int_intPt{
	int n;//Contador de notas con la palabra buscada
	int *intPt[100];// Arreglo que guarda las notas que contengan la palabra buscada
	string x[500];//Arreglo en donde se meten las palabras del contenido

	int tam;//Número de palabras del contenido
	int i;//Número de palabras que se guardan en el arreglo x
	int cont;//Contador para verificar que haya la palabra buscada en la nota
	int v;//Número del arreglo intPt en donde se guarda el número de la nota que tenga la palabra buscada
}p1;//Objeto de struct para enviar valores

	//Función para buscar palabras
struct Par_int_intPt* Nota_Directorio::buscar_entradas(std::string palabra) const{
	
		for(int j=0; j<size; j++){
			p1.i=0;
			
			//1.Agrega cada palabra del contenido de la nota en un arreglo
			istringstream ss(directorio[j].stringContenidoDeNota);//nota es el arreglo de las notas, depende de como se va a llamar este arreglo
			
			do { // Leer una palabra
        		string word; 
        		ss >> word; 
  				p1.x[p1.i]=word;
  				p1.i=p1.i+1;
        	// Mientras haya más que leer
    		} while (ss); //1. Fin
    		
    		//2. Compara la palabra buscada con cada palabra del arreglo, en caso de que coincida alguna el contador sube 1
    		p1.tam=p1.i;
    		p1.cont=0;
    		
    		for(int h=0; h<=p1.tam; h++){
    			if(palabra==p1.x[h]){
    				p1.cont++;
				}	
			}//2. Fin
			
			//3. Si el contador es mayor a 0 significa que está una o mas veces la palabra buscada en el contenido
			// el contador n del numero de notas en las cuales está la palabra sube 1 y se guarda en el arreglo el número de nota
			// que contengan la palabra
			if(p1.cont>0){
				p1.n++;
			 	p1.intPt[p1.v]=&j;
			 	p1.v++;
			}//3. Fin		
		}
    	
		cout <<"Numero de notas que contienen la palabra: "<<p1.n<<"\n notas que la contienen:" <<endl; 
		for(int g=0; g<=p1.v-1; g++){
			cout<<"\n"<<p1.intPt[g];
		}
};
