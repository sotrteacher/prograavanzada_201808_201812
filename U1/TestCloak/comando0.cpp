#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include "Pol_Directory.h"
#include "String_Tokenizer.h"
#include "Polinomio.h"
#define PRINTING_DEBUG

//#define COMANDO_0
//Prototipos de funciones
void proccess_operation(Pol_Directory&,string&,unsigned char,string&);
void do_suma(Pol_Directory&,string&,string&);
void do_save(Pol_Directory&);
#ifdef COMANDO_0

int main(int argc,char *argv[]){
//	cout<<"Dummy HOLA MUNDO desde "<<argv[0]<<"!!!"<<endl;
//	cout<<"Dummy HOLA MUNDO!!!"<<endl;
	if(argc<2){
		cout<<"Faltan argumentos!"<<endl;
		return 1;
	}else{
		for(int i=0;i<argc-1;i++){
			cout<<"argv["<<i<<"]: "<<argv[i]<<endl;
		}
		Pol_Directory the_directory;
		string source_name(argv[1]);
		the_directory.load_data(source_name);
		string Operand1(argv[2]);
		string Operador(argv[3]);
		string Operand2(argv[4]);
		unsigned char *tmpPt=(unsigned char*)malloc(sizeof(unsigned char));
//		*tmpPt=*((unsigned char*)(&(*argv[3])));
		*tmpPt=*((unsigned char*)(argv[3]));
#ifdef PRINTING_DEBUG
		cout<<"*tmpPt="<<*tmpPt<<endl;
#endif
		proccess_operation(the_directory,Operand1,*tmpPt,Operand2);
	}
	return 0;
}
#endif /*COMANDO_0*/


void proccess_operation(Pol_Directory& the_directory,string& op1,unsigned char operador,string& op2){
#ifdef PRINTING_DEBUG
	cout<<"operador="<<operador<<endl;
#endif
	switch(operador){
		case '+':{
			do_suma(the_directory,op1,op2);
			break;
		}
	}
	do_save(the_directory);
}

void do_suma(Pol_Directory& the_directory,string& op1, string& op2){
	string operando1=op1;
	string operando2=op2;
#ifdef PRINTING_DEBUG
	cout<<"operando1="<<operando1<<endl;
	cout<<"operando2="<<operando2<<endl;
#endif
	string coeffs1=the_directory.lookup_entry(operando1);
	string coeffs2=the_directory.lookup_entry(operando2);
#ifdef PRINTING_DEBUG
	cout<<"coeffs1="<<coeffs1<<endl;
	cout<<"coeffs2="<<coeffs2<<endl;
#endif
	String_Tokenizer tokenizer1(coeffs1, ":");
	String_Tokenizer tokenizer2(coeffs2, ":");
	vector<string> arr1;
	vector<string> arr2;
	while(tokenizer1.has_more_tokens()){
        arr1.push_back(tokenizer1.next_token());
    }//end while()
	while(tokenizer2.has_more_tokens()){
        arr2.push_back(tokenizer2.next_token());
    }//end while()
#ifdef PRINTING_DEBUG
    for(int i=0;i<arr1.size();i++){
    	cout<<arr1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<arr2.size();i++){
    	cout<<arr2[i]<<" ";
	}
	cout<<endl;
#endif
	int num,den;	/*numerador,denominador*/
	Rac *RacPt1=new Rac[arr1.size()],*RacPt2=new Rac[arr2.size()];
	string stringIntNum,stringIntDen;
	String_Tokenizer tokenizerForRac;
	for(int i=0;i<arr1.size();i++){
		tokenizerForRac=String_Tokenizer(arr1[i],"/");
		
		stringIntNum=tokenizerForRac.next_token();
		num=atoi(stringIntNum.c_str());
		
		stringIntDen=tokenizerForRac.next_token();
		den=atoi(stringIntDen.c_str());
		
		*(RacPt1+i)=Rac(num,den);
	}
	Polinomio PolOp1(arr1.size()-1,RacPt1);
//	RacPt=new Rac[arr2.size()];
	for(int i=0;i<arr2.size();i++){
		tokenizerForRac=String_Tokenizer(arr2[i],"/");
		
		stringIntNum=tokenizerForRac.next_token();
		num=atoi(stringIntNum.c_str());
		
		stringIntDen=tokenizerForRac.next_token();
		den=atoi(stringIntDen.c_str());
		
		*(RacPt2+i)=Rac(num,den);
	}
	Polinomio PolOp2(arr2.size()-1,RacPt2);
	Polinomio PolResult=PolOp1+PolOp2;
	string resultado=PolResult.string_show();
#ifdef PRINTING_DEBUG	
	cout<<PolOp1<<endl;
	cout<<PolOp2<<endl;
	cout<<PolResult<<endl;
	cout<<resultado<<endl;
#endif
	the_directory.add_or_change_entry("ans",resultado);	
}

void do_save(Pol_Directory& the_directory){
	the_directory.save();
}
