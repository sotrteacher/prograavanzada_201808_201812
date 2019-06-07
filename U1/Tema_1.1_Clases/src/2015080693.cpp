#include <iostream> 
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

class Nota{
	public:
		int intFecha;
		string stringFecha;
		string stringRemitente;
		string stringDestinatario;
		string stringContenidoDeNota;
	
		Nota(int fecha, string strfecha,string remitente,string destinatario, string contenido){
			intFecha=fecha;
			stringFecha=strfecha;
			stringRemitente=remitente;
			stringDestinatario=destinatario;
			stringContenidoDeNota=contenido;
		};
		
		void mostrar(){
			//system("cls");
			cout<<"   Fecha(int): "<<intFecha<<endl;
			cout<<"   Fecha(string): "<<stringFecha<<endl;
			cout<<"   De: "<<stringRemitente<<endl;
			cout<<"   Para: "<<stringDestinatario<<endl;
			cout<<"   Mensaje: "<<endl;
			cout<<"   "<<stringContenidoDeNota<<endl;
		};
		
  int contar_notas_del_remitente_al_destinatario(string rem,string dest);
  
  		string remit(){
			return stringRemitente;
		};
		string destin(){
			return stringDestinatario;
		};
};



main(){
	
	cout<<"   Prueba de array:"<<endl;
	Nota*array[5];
	
	array[0]=new Nota(220219,"Marzo","Persona","Julio","Hola mucho gusto");
	array[1]=new Nota(221219,"abril","Persona","Julio","Hola");
	array[2]=new Nota(140419,"Febrero","Persona","Juan","Mensaje generico");
	array[3]=new Nota(140719,"Junio","Humano1","Allah","Mensaje generico 2");
	array[4]=new Nota(130819,"Diciembre","Humano2","Jose","Mensaje generico 3");
	
	for (int i=0;i<5;i++){
		cout<<"   Nota"<<i<<":"<<endl;
		array[i]->mostrar();	
		cout<<endl<<endl;
	}
	
	int search=0;
	for(int i;i<5;i++){
		if(array[i]->remit() =="Persona"){
			search++;
		}
	}
	fflush(stdin);
	//cout<<"Existen: "<<"   "<<search<<" notas de"<<" Arath"<<"de las cuales: "<<"    "<<search2<<"son para"<<" Rick"<<endl;	
	cout<<"   "<<search<<" notas son de "<<"Persona"<<endl;
	fflush(stdin);
	//cout<<"   "<<search2<<" notas son para "<<"Rick"<<endl;
	 
	
	system("PAUSE");
}
