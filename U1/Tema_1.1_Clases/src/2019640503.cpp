#include <iostream>
using namespace std;
#include "Nota.h"
#include "Nota_Directorio.h"

void do_contar_Notas_de_un_destinatario(Nota_Directorio& el_directorio){
	string destinatario;
	cout << "INGRESE EL DESTINATARIO"<<endl;
	cin >> destinatario;
	int d;
	d=Nota::contar_notas_del_destinatario(destinatario,el_directorio);
	cout << "NUMERO DE NOTAS ACTUALES" << d<< endl;
//system("pause");
}
