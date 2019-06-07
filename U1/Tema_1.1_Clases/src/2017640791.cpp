#include <iostream>
#include <stdlib.h>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	
	//Creacion de Clase
	class NOTA {
		private://Atributos
			int intFecha;
			string stringFecha;
			string stringRemitente;
			string stringDestinatario;
			string stringContenidoDeNota;
		
		public://Metodos
			NOTA(int,string,string,string,string);//Constructor
			void mostrar();
		
	};
	
	NOTA::NOTA(int _intFecha,string _stringFecha,string _stringRemitente,string _stringDestinatario,string _stringContenidoDeNota){
		intFecha=_intFecha;
		stringFecha=_stringFecha;
		stringRemitente=_stringRemitente;
		stringDestinatario=_stringDestinatario;
		stringContenidoDeNota=_stringContenidoDeNota;
	}
	void NOTA::mostrar(){
		cout<<"               NOTA\n\n"<<endl;
		cout<<"\t\tFecha: "<<stringFecha<<'('<<intFecha<<')'<<endl<<endl;
		cout<<"Buenas Tardes "<<stringDestinatario;
		cout<<"\n\n"<<stringContenidoDeNota;
		cout<<"\n\n\n\t\t   Att: "<<stringRemitente<<"\n\n";
		
	}
	
	int main(){
		NOTA n1=NOTA(1022019,"01 de Febrero de 2019","Ramirez Cortes Julio Misael","Maria Carla Rodriguez","   Esto es una Prueba");
		n1.mostrar();
		system("pause");
		return 0;
	}
	
