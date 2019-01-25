#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//class Hola0{
struct Hola0{
	std::string S;
public:
	static int cuenta;	//contar los objetos instanciados
	Hola0(std::string str){
		S=str;
		cuenta++;
	}
	friend ostream& operator<<(ostream& out,Hola0 h0){
		out<<h0.S;
		return out;
	}
	friend std::string operator+(std::string str,Hola0 h0){
		std::string STR=str+"->"+h0.S;
		return STR;
	}
	friend std::string operator+(Hola0 h0,std::string str){
		return h0.S+" "+str;
	}
};//end class Hola0
int Hola0::cuenta=0;
int main(int argc, char** argv) {
	Hola0 H0=Hola0("2MV3");
	cout<<"cantidad="<<H0.cuenta<<endl;
	cout<<"S="<<H0.S<<endl;
	Hola0 H1("Atributos static");
	cout<<"cantidad="<<H0.cuenta<<endl;
	cout<<"Hola Mundo C++:"<<endl;//
	//cout<<H0<<endl;
	cout<<"/******************************************/"<<endl;
	cout<<"Hola Mundo C++:"<<H0<<endl;
	std::string cad="Martes 22 de enero de 2019, grupo:"+H0;
	cout<<cad<<endl;
	cout<<"Viernes 25 de enero de 2019, grupo:"+H0<<endl;
	cout<<H0+"Tema 1.1 Clases"<<endl;
	cout<<"/******************************************/"<<endl;
	return 0;
}//end main()









