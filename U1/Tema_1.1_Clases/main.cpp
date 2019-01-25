#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//class Hola0{
#include "Hola0.h"
int Hola0::cuenta=0;
int main(int argc, char** argv) {
	Hola0 H0=Hola0("2MV3");
	cout<<"cantidad="<<H0.cuenta<<endl;
	cout<<"S="<<H0.S<<endl;
	Hola0 H1("Atributos static");
	cout<<"cantidad="<<H0.cuenta<<endl;
	Hola0 *H3Pt=new Hola0("Apuntador a objeto");
	cout<<"cantidad="<<H3Pt->cuenta<<" = "<<Hola0::cuenta<<endl;
	Hola0 arr[3];
	Hola0::clase_Hola0();
	arr[0]=H0;arr[1]=H1;arr[2]=*H3Pt;
	Hola0 H2(10); 
	cout<<"cantidad="<<arr[0].cuenta<<" = "<<arr[2].cuenta<<endl;
	cout<<"Hola Mundo C++:"<<endl;//
//	//cout<<H0<<endl;
//	cout<<"/******************************************/"<<endl;
//	cout<<"Hola Mundo C++:"<<H0<<endl;
//	std::string cad="Martes 22 de enero de 2019, grupo:"+H0;
//	cout<<cad<<endl;
//	cout<<"Viernes 25 de enero de 2019, grupo:"+H0<<endl;
//	cout<<H0+"Tema 1.1 Clases"<<endl;
//	cout<<"/******************************************/"<<endl;
	return 0;
}//end main()









