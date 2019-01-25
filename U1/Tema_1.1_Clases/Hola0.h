
#ifndef HOLA0_H

#define HOLA0_H
struct Hola0{
	std::string S;
public:
	static int cuenta;	//contar los objetos instanciados
	int intA;
	Hola0(std::string str){
		S=str;
		cuenta++;
	}
	Hola0(){//cuenta++;
	}//deliberadamente vacio
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
	static void clase_Hola0(){
		cout<<"Clase Hola0. Se han instanciado "<<cuenta<<" objetos."<<endl;
	}
	Hola0(int);
};//end class Hola0
#endif
