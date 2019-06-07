// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int Nota::contar_notas_del_destinatario(string  dest, Nota_Directorio& el_directorio),
{
	int veces;
	char ltr;
	char destb[20];
	string dest;
	int cont;
	cout << "Ingresa destinatario:" << endl;
	cont = 0;
	for (int i = 0; i < 100; i++)
	{
		fflush(stdin);
		ltr = getchar();
		if (ltr == 20)
		{
			break;
		}
		else
		{
			printf("*");
			destb[cont] = ltr;
			cont++;
		}
	}

	dest = Convertir(destb[20]);
	veces= do_contar_Notas_de_un_destinatario(Nota_Directorio& dest);
	cout << "Hay" << veces << "nota(s) al destinatario" << endl;
	system("PAUSE");
	return 0;
}

string Convertir(char destb[20]) {
	return string(1, c);
}


