#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#include "claseEjAbstr.h"

int main(int argc, char** argv) {
#ifdef EJEMPLO
	char letter1,letter2;   //first two initials
	string lastName;
	//Enter letters and print message
	cout<<"Teclea dos iniciales y un nombre: ";
	cin>>letter1>>letter2>>lastName;
	cout<<"Hola "<<letter1<<"."<<letter2<<"."
	    <<lastName<<"!"<<endl;
	cout<<"Esperamos que disfrute estudiando C++."<<endl;
#endif
	ClaseEjAbstr *CEA=new ClaseEjAbstr(20);
	ClaseEjAbstr obj(30);
	cout<<"Atributo cantidad="<<CEA->get_cantidad()<<"\n";
	cout<<"Atributo cantidad="<<obj.get_cantidad()<<"\n";
	return 0;
}









