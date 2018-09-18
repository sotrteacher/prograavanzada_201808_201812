#include <iostream>
#include <vector>
#include <stdlib.h>  /*malloc()*/
#include <fstream>  /*ofstream*/
#include <windows.h> /*STARTUPINFO, PROCESS_INFORMATION*/
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

#include "Polinomio.h"

#define PREFIX	"Operacion_"
#define VERSION	0
#define PDFLATEX	"C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe"
#define ACROBAT	"C:/Program Files (x86)/Adobe/Acrobat 10.0/Acrobat/Acrobat.exe"

void presentar(Polinomio& Pfpiv,    /*Polinomio fila pivote*/
               Rac& Rfactor1,       /*Racianal factor1*/
			   Polinomio& Pfpivc1,  /*Polinomio fila pivote c/ elemento pivote 1*/
			   Polinomio& Pnfpiv,   /*Polinomio no fila pivote*/
			   Rac& Rfactor2,       /*Racianal factor2*/
			   Polinomio& Pnfpivc0)/*Polinomio no fila pivote con 0 arriba o abajo del 1*/
{
  char str[128],str1[128];
  string dest_name;
  sprintf(str,"%s%d.tex",PREFIX,VERSION);
  dest_name=string(str);
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ofstream out(dest_name.c_str());
  out<<"\\documentclass[landscape]{article}"<<endl;
  out<<"\\usepackage[lmargin=1.73cm,rmargin=1.73cm,top=1.9cm,bottom=2.54cm]{geometry}"<<endl;
  out<<"\\pagestyle{empty}"<<endl;	/*Para que no ponga numeros de pagina*/
  out<<"\\begin{document}"<<endl;
  out<<"{\\Huge"<<endl;
  out<<"\\["<<endl;
  out<<"\\left["<<Rfactor1<<"\\right]"
     <<"\\left["<<Pfpiv<<"\\right]"<<endl;
//  out<<"=\\left[\\begin{array}{rrrrrrrr}"<<endl;
  out<<"=\\left["<<endl;
  out<<Pfpivc1<<"\\right]"<<endl;
  out<<"\\]"<<endl;
  out<<"\\["<<endl;
  out<<"\\left["<<Pnfpiv<<"\\right]\\,+\\,"<<endl;
  out<<"\\left["<<Rfactor2<<"\\right]"<<"\\left["<<Pfpivc1<<"\\right]";
  out<<"\\]"<<endl;
  out<<"\\["<<endl;
  out<<"=\\,\\left["<<Pnfpivc0<<"\\right]"<<endl;
  out<<"\\]"<<endl;  
  out<<"}"<<endl;
  out<<"\\end{document}"<<endl;
  
  out.close();
  ZeroMemory(&si,sizeof(si));
  si.cb=sizeof(si);
  ZeroMemory(&pi,sizeof(pi));
  sprintf(str,"pdflatex.exe ./%s%d.tex",PREFIX,VERSION);
  string msg=string(str);
  if(!CreateProcess(PDFLATEX,str,0,0,0,0,0,0,&si,&pi)){ 
	//Could not start process;
	cerr<<"Could not start process: "<<msg<<endl;
	return;
  }
  CloseHandle( pi.hThread );
  // wait for the child program to terminate
  WaitForSingleObject( pi.hProcess, INFINITE );
  
  ZeroMemory(&si,sizeof(si));
  si.cb=sizeof(si);
  ZeroMemory(&pi,sizeof(pi));
  sprintf(str,"%s",ACROBAT);
  sprintf(str1,"Acrobat.exe %s%d.pdf",PREFIX,VERSION);
  msg=string(str1);
  if(!CreateProcess(str,str1,0,0,0,0,0,0,&si,&pi)){
	//Could not start process;
	cerr<<"Could not start process: "<<msg<<endl;
    return;
  }
  CloseHandle( pi.hThread );
  // wait for the child program to terminate
  WaitForSingleObject(pi.hProcess,INFINITE);
}//end presentar()
