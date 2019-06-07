#include <stdlib.h>/*int __attribute__((__cdecl__)) atoi(const char *_Str);*/
#include <fstream> /* ifstream,ofstream */
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"
#include "Par_int_intPt.h"
//Asignaci\'on P1.2
//2016620256 SUASTEGUI PEREZ ULISES
void Nota__Nota(Nota *NotaPt,int intFecha){
  NotaPt->intFecha=intFecha;
}

//Asignaci\'on P1.3
//2015090165 DOMINGUEZ MOTA CARLOS DANIEL
void Nota__Nota(Nota *NotaPt,string stringFecha){
  NotaPt->stringFecha=stringFecha;
}

//Asignaci\'on P1.4
//2015040092 ARELLANO AGUILAR RUDYARD SAMUEL
int Nota__contar_notas_del_remitente(Nota_Directorio& el_dir,string rem){
  int count=0,size=el_dir.size;
  Nota *directorio=el_dir.directorio;
  string el_rem;
  for(int i=0;i<size;i++){
  	el_rem=directorio[i].stringRemitente;
  	if(rem==el_rem){
  		count++;
	  }
  }
  return count;
}

//Asignaci\'on P1.5
//2018640271 ALVAREZ HUERTA MARIO IGNACIO
int Nota__contar_notas_del_remitente_al_destinatario(
    Nota_Directorio& el_nota_dir,string rem,string dest){
  int count=0,size=el_nota_dir.size;
  string el_rem,el_dest;  /*el remitente,el destinatario*/
  Nota *dir=el_nota_dir.directorio;
  for(int i=0;i<size;i++){
  	el_rem=dir[i].stringRemitente;
  	el_dest=dir[i].stringDestinatario;
  	if((rem==el_rem)&&(dest==el_dest)){
  		count++;
	}
  }
  return count;
}

// Stub
//Asignaci\'on P1.6
//2014030116 BALLESTEROS MARTINEZ JUAN LUIS
int Nota__contar_notas_del_destinatario(string stringNombreDelDestinatario,
		  Nota_Directorio& el_dir){
  int count=0,size=el_dir.size;
  Nota *directorio=el_dir.directorio;
  string el_dest;  /*el destinatario*/
  for(int i=0;i<size;i++){
  	el_dest=directorio[i].stringDestinatario;
  	if(stringNombreDelDestinatario==el_dest){
  		count++;
	  }
  }
  return count;
}

//Asignaci\'on P1.7
//2016640031 BAUTISTA MARTINEZ JOSE EDUARDO
void Nota_Directorio__Nota_Directorio(Nota_Directorio* el_dirPt){
	el_dirPt->size=0;
	el_dirPt->capacity=100;
	el_dirPt->directorio=new Nota[100];
	el_dirPt->modified=false;
}

//Asignaci\'on P1.8
//2011640360 GARCIA MARTINEZ DANIEL MARTIN
void Nota_Directorio__tilde_Nota_Directorio(Nota_Directorio* el_dirPt){
        delete[] el_dirPt->directorio;
}

/**Cargar datos desde el archivo que contiene los datos de las notas del directorio,
 * @param source_name El nombre del archivo (fuente de datos) con 
 *                    las entradas del directorio de Notas 
 */
//Asignaci\'on P1.9
//2017640791 RAMIREZ CORTES JULIO MISAEL
void Nota_Directorio__load_data(Nota_Directorio* el_dirPt,
                    const std::string& source_name){
	//2019.03.20
	//recordar el nombre de la fuente de datos para utilizarlo 
	//al guardar.
	el_dirPt->source_name=source_name;
	//Crear una cadena de entrada desde este archivo.
	ifstream in(source_name.c_str()); 
	if(in){//si el flujo existe
	  string fecha,rem,dest,contenido;
	  while(getline(in,fecha)){
	  	int intF=atoi(&fecha[0]);
	  	if(getline(in,rem)){
	  	  if(getline(in,dest)){
	  	    if(getline(in,contenido)){
	  	      el_dirPt->add(intF,rem,dest,contenido);
			}	
		  }	
		}
	  }
	  //cerrar el archivo
	  in.close();
	}
}

//Asignaci\'on P1.10
//2013090388 FERNANDEZ SANTANA VIVIANA ELIZABETH
struct Par_int_intPt* Nota_Directorio__buscar_entradas(
                      const Nota_Directorio* el_dirPt,string palabra){
  int j=0;
  struct Par_int_intPt *result=new Par_int_intPt();
  result->n=0;
  string el_content;
  int size=el_dirPt->size;
  Nota *dirN=el_dirPt->directorio;
  for(int i=0;i<size;i++){
  	el_content=dirN[i].stringContenidoDeNota;
  	if(el_content.find(palabra,0)!=string::npos){
  	  result->n++;	
	}
  }
  result->intPt=new int[result->n];
  for(int i=0;i<size;i++){
  	el_content=dirN[i].stringContenidoDeNota;
  	if(el_content.find(palabra,0)!=string::npos){
  	  *(result->intPt+j)=i;
	  j++;	
	}
  }
  return result;
}

//Asignaci\'on P1.11
//2015031144 ROJAS CASTILLO AXEL RICARDO
void Nota_Directorio__add(Nota_Directorio* el_dirPt,
                    const std::string& rem,const std::string& dest,
					const std::string& content){
    //2019.03.19 --Review file 2015031144.cpp
	*(el_dirPt->directorio+el_dirPt->size++)=Nota(rem,dest,content);
        el_dirPt->save();
	el_dirPt->modified=true;
}

void Nota_Directorio__add(Nota_Directorio* el_dirPt,const int intFech,
                    const std::string& rem,const std::string& dest,
					const std::string& content){
    //2019.03.19 --Review file 2015031144.cpp
	*(el_dirPt->directorio+el_dirPt->size++)=Nota(intFech,rem,dest,content);
	el_dirPt->modified=true;
}

//Asignaci\'on P1.12
//2016640087 FLORES JUAREZ DAVID ALEJANDRO
void Nota_Directorio__remove_entry(Nota_Directorio* el_dirPt,int index){
	//por ahora vacio 2019.03.19 --Review file 2016640087.cpp
	int i,size=el_dirPt->size;
	Nota *dir=el_dirPt->directorio;
	if ((index>=size)||(index<0)){
		cout<<"\nIndex de nota no v\\'alido!"<<endl<<endl;
	}else{
		 for(i=0; i<size; i++){
		 	if((i==index)&&(i<size-1)){	
		 		while(i<size-1){
		 			dir[i]=dir[i+1];
		 			i++;
			 	}//si index es igual a size-1, solo
			 	 //hay que restarle 1 a el_dirPt->size
			 	 cout<<"La nota ha sido eliminada.\n"<<endl;
				break;
		    }
		 }	
		 el_dirPt->size=size-1;
	}
}

//Asignaci\'on P1.13
//2015080063 AQUINO PAZ GUSTAVO
void Nota_Directorio__reallocate(Nota_Directorio *dir){
  int i;
  Nota *tmp=dir->directorio;
  dir->directorio=new Nota[2*dir->capacity];
	for(i=0;i<dir->size;i++){
		dir->directorio[i]=tmp[i];
	}
}

//Asignaci\'on P1.14
//2014090040 ARELLANO SANCHEZ JOSE ALBERTO
void Nota_Directorio__save(Nota_Directorio *el_dirPt){
	//por ahora vacio 2019.03.19 --Falta el archivo 2014090040.cpp
	bool modified=el_dirPt->modified;
	string source_name=el_dirPt->source_name;
	int size=el_dirPt->size;
	Nota *NotaPt=el_dirPt->directorio;
	//string stringFechaComoNum;
	//char str[32];
	if(modified){//If not modified, do nothing
	  //crear una cadena de salida
	  ofstream out(source_name.c_str());
	  for(int i=0;i<size;i++){
	  	//sprintf(str,"%d",NotaPt[i].intFecha);
	  	//stringFechaComoNum=string(str);
	  	out<<NotaPt[i].intFecha<<"\n";
	  	out<<NotaPt[i].stringRemitente<<"\n";
	  	out<<NotaPt[i].stringDestinatario<<"\n";
	  	out<<NotaPt[i].stringContenidoDeNota<<"\n";
	  }
	  //cerrar la cadena de salida
	  out.close();
	  el_dirPt->modified=false;
	}
}






