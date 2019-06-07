//Test_Nota_Nota_Directorio_weak.cpp
#include "Nota.h"
#include "Nota_Directorio.h"
#include "Par_int_intPt.h"
//#include "Test_Nota_Nota_Directorio.h"

/*Esta funci\'on parece que no la he asignado aun a 
  ning\'un discente (2019.03.19.17.57) */
void LMC_do_agregar_Nota(Nota_Directorio& el_directorio){
	string rem;
	string dest;
	string contenido;
	cout<<"Remitente: ";
	getline(cin,rem);
	cout<<"Destinatario: ";
	getline(cin,dest);
	cout<<"Contenido: ";
	getline(cin,contenido);
	el_directorio.add(rem,dest,contenido);
	cout<<"Se ha agregado una nota de "<<rem<<" para "<<dest<<".\n\n";
}

//Asignaci\'on P1.15
//2017362541 ROSETE CORTES JAVIER
void LMC_do_contar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
	//2019.03.19 --Feedback el archivo 2017362541.cpp
	string rem;
	int intA;
	cout << "INGRESE EL REMITENTE: ";
	getline(cin,rem);
	intA=Nota::contar_notas_del_remitente(rem,el_directorio);
	cout<<rem<<" aparece como remitente en "<<intA<<" notas del directorio.\n\n";
}


//V\'ease archivo ../Aclaracion_2019_2-parcial_1.txt
//Asignaci\'on P1.16
//2019640503 NAVARRO MEDINA DAFNE YESENIA
void LMC_do_contar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
//	int intD=Nota::contar_notas_del_destinatario("Juan Luis",el_directorio);
//	printf("ZXCVBNMintD=%d\n",intD);
	string destinatario;
	cout << "INGRESE EL DESTINATARIO: ";
	getline(cin,destinatario);
	int d;
	d=Nota::contar_notas_del_destinatario(destinatario,el_directorio);
	cout << destinatario<<" aparece como destinatario en "<<d<<" notas.\n\n";
}


struct Par_int_intPt *find_entries_with_rem(
       Nota_Directorio& el_directorio,std::string rem){
  struct Par_int_intPt *R=new Par_int_intPt();
  R->n=Nota::contar_notas_del_remitente(rem,el_directorio);
  R->intPt=new int[R->n];
  Nota *NotaPt=el_directorio.directorio;
  int size=el_directorio.size,j=0;
  string el_rem;
  for(int i=0;i<size;i++){
  	el_rem=NotaPt[i].stringRemitente;
  	if(rem==el_rem){
  		*(R->intPt+j)=i;
  		j++;
	}
  }
  return R;       	
}
struct Par_int_intPt *find_entries_with_dest(
       Nota_Directorio& el_directorio,std::string dest){
  struct Par_int_intPt *R=new Par_int_intPt();
  R->n=Nota::contar_notas_del_destinatario(dest,el_directorio);
  R->intPt=new int[R->n];
  Nota *NotaPt=el_directorio.directorio;
  int size=el_directorio.size,j=0;
  string el_dest;
  for(int i=0;i<size;i++){
  	el_dest=NotaPt[i].stringDestinatario;
  	if(dest==el_dest){
  		*(R->intPt+j)=i;
  		j++;
	}
  }
  return R;       	
}
struct Par_int_intPt *find_entries_with_rem_y_dest(
       Nota_Directorio& el_directorio,std::string rem,std::string dest){
  struct Par_int_intPt *R=new Par_int_intPt();
  R->n=Nota::contar_notas_del_remitente_al_destinatario(rem,dest,el_directorio);
  R->intPt=new int[R->n];
  Nota *NotaPt=el_directorio.directorio;
  int size=el_directorio.size,j=0;
  string el_rem,el_dest;
  for(int i=0;i<size;i++){
  	el_rem=NotaPt[i].stringRemitente;
  	el_dest=NotaPt[i].stringDestinatario;
  	if((rem==el_rem)&&(dest==el_dest)){
  		*(R->intPt+j)=i;
  		j++;
	}
  }
  return R;       	
}

//Asignaci\'on P1.17
//2014030995 ORTIZ GONZALEZ ESDRAS BENJAMIN
void LMC_do_mostrar_Notas_de_un_remitente(Nota_Directorio& el_directorio){
	// --2019.03.19.17.00
	Nota Note;
	string rem;
	cout << "INGRESE EL REMITENTE: ";
	getline(cin,rem);
	Nota *NotaPt=el_directorio.directorio;
	struct Par_int_intPt *ParPt=find_entries_with_rem(el_directorio,rem);
	
	if(ParPt->n){
	  cout<<"NOTAS CON REMITENTE \""<<rem<<"\":"<<endl;
	  for(int i=0;i<ParPt->n;i++){
		Note=NotaPt[*(ParPt->intPt+i)];
		cout<<"Index: "<<*(ParPt->intPt+i)<<endl;
		cout<<"Destinatario: "<<Note.stringDestinatario<<endl;
		cout<<Note.stringContenidoDeNota<<endl<<endl; 
	  }
    }else{
    	cout<<"NO HAY NOTAS CON REMITENTE \""<<rem<<"\"."<<endl<<endl;
	}
}

//Asignaci\'on P1.19
//2015080693 JUAREZ CRUZ BRANDON ARATH
void LMC_do_contar_Notas_de_un_remitente_a_un_destinatario(
Nota_Directorio& el_directorio){
	//Por el momento vacio --2019.03.19.17.04
	string Rem,Dest;    /*Remitente,Destinatario*/
	cout<<"INGRESE EL REMITENTE: ";
	getline(cin,Rem);
	cout<<"INGRESE EL DESTINATARIO: ";
	getline(cin,Dest);
	int intA=Nota::contar_notas_del_remitente_al_destinatario(
	         Rem,Dest,el_directorio);
	cout<<"El remitente "<<Rem<<" tiene "<<intA<<" notas enviadas a "
	    <<Dest<<" en el directorio.\n\n";
}

//Asignaci\'on P1.20
//2015080865 MELGAREJO RAMIREZ JOHAN
void LMC_do_mostrar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
	//Por el momento vacio --2019.03.19.17.50
	Nota Note;
	string dest;
	cout << "INGRESE EL DESTINATARIO: ";
	getline(cin,dest);
	Nota *NotaPt=el_directorio.directorio;
	struct Par_int_intPt *ParPt=find_entries_with_dest(el_directorio,dest);
	
	if(ParPt->n){
	  cout<<"NOTAS CON DESTINATARIO \""<<dest<<"\":"<<endl;
	  for(int i=0;i<ParPt->n;i++){
		Note=NotaPt[*(ParPt->intPt+i)];
		cout<<"Index: "<<*(ParPt->intPt+i)<<endl;
		cout<<"Remitente: "<<Note.stringRemitente<<endl;
		cout<<Note.stringContenidoDeNota<<endl<<endl; 
	  }
    }else{
    	cout<<"NO HAY NOTAS CON DESTINATARIO \""<<dest<<"\"."<<endl<<endl;
	}
}

//Asignaci\'on P1.21
//2016640273 SANCHEZ AMARO GUSTAVO
void LMC_do_mostrar_Notas_de_un_remitente_a_un_destinatario(
     Nota_Directorio& el_directorio){
	Nota Note;
	string rem,dest;
	cout << "INGRESE EL REMITENTE: ";
	getline(cin,rem);
	cout << "INGRESE EL DESTINATARIO: ";
	getline(cin,dest);
	Nota *NotaPt=el_directorio.directorio;
	struct Par_int_intPt *ParPt=
	       find_entries_with_rem_y_dest(el_directorio,rem,dest);
	
	if(ParPt->n){
	  cout<<"NOTAS CON REMITENTE \""<<rem<<"\" Y DESTINATARIO \""
	      <<dest<<"\":"<<endl;
	  for(int i=0;i<ParPt->n;i++){
		Note=NotaPt[*(ParPt->intPt+i)];
		cout<<"Index: "<<*(ParPt->intPt+i)<<endl;
		cout<<"FECHA: "<<Note.intFecha<<endl;
		cout<<Note.stringContenidoDeNota<<endl<<endl; 
	  }
    }else{
    	cout<<"NO HAY NOTAS CON REMITENTE \""<<rem<<"\" Y DESTINATARIO \""
		    <<dest<<"\"."<<endl<<endl;
	}
}

//Asignaci\'on P1.22
//2016640385 ALMANZA ALVARADO LUIS FERNANDO
void LMC_do_buscar_entradas(Nota_Directorio& el_directorio){
	//Por el momento vacio --2019.03.19.18.01
	int intA;
	string wordOrPhrase;
	cout<<"INSERTE LA PALABRA O FRASE A BUSCAR: ";
	getline(cin,wordOrPhrase);
	struct Par_int_intPt *piintPt=
	       el_directorio.buscar_entradas(wordOrPhrase);
	intA=piintPt->n;
	cout<<"La palabra o frase \""<<wordOrPhrase<<"\" aparece "
	    <<"en "<<intA<<" notas del directorio.\n\n";
}

/*Esta funci\'on parece que no la he asignado aun a 
  ning\'un discente (2019.03.19.18.04) */
void LMC_do_remove_entry(Nota_Directorio& el_directorio){
	//Por el momento vacio --2019.03.19.18.03
	//2019.03.21
	int IndexToRemove;
	Nota Note;
	string rem_o_dest;
	cout<<"INGRESE UN REMITENTE O DESTINATARIO: ";
	//std::istream::getline(cin,rem_o_dest);
	getline(cin,rem_o_dest);
	Nota *NotaPt=el_directorio.directorio;
	struct Par_int_intPt *ParPt=find_entries_with_rem(el_directorio,rem_o_dest);
	
	if(ParPt->n)
	  cout<<"NOTAS CON REMITENTE \""<<rem_o_dest<<"\":"<<endl;
	for(int i=0;i<ParPt->n;i++){
		Note=NotaPt[*(ParPt->intPt+i)];
		cout<<"Index: "<<*(ParPt->intPt+i)<<endl;
		cout<<"Destinatario: "<<Note.stringDestinatario<<endl;
		cout<<Note.stringContenidoDeNota<<endl<<endl; 
	}
	
	ParPt=find_entries_with_dest(el_directorio,rem_o_dest);
	if(ParPt->n)
	  cout<<"NOTAS CON DESTINATARIO \""<<rem_o_dest<<"\":"<<endl;
	for(int i=0;i<ParPt->n;i++){
		Note=NotaPt[*(ParPt->intPt+i)];
		cout<<"Index: "<<*(ParPt->intPt+i)<<endl;
		cout<<"Remitente: "<<Note.stringRemitente<<endl;
		cout<<Note.stringContenidoDeNota<<endl<<endl; 
	}
	
	cout<<"INGRESE EL Index DE LA NOTA A ELIMINAR: ";
	cin>>IndexToRemove;
	el_directorio.remove_entry(IndexToRemove);
	delete ParPt;
}

/*Esta funci\'on parece que no la he asignado aun a 
  ning\'un discente (2019.03.19.18.04) */
void LMC_do_salir(Nota_Directorio& el_directorio){
	// --2019.03.20.19.05
	el_directorio.save();
}





