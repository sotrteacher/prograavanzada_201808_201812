#pragma once
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;
#include "..\CommonF\Rac.h"
class FormaAumentada
{
	int m;                   /*N\'umero de restricciones*/
	int n;                   /*N\'umero total de variables: de 
							   decisi\'on m\'as las demas (holgura,
							   superhabit o artificiales)*/
	Rac **CbZAyb;         /*Coeficientes b\'asicos,fila Z,
							   Matriz Aumentada y columna b,
							   Apuntar\'a a un arreglo de m+1 por 
							   n+1 n\'umeros racionales. m+1 para 
							   incluir la fila Z en el arreglo, 
							   n+2 para incluir la columna b en el 
							   mismo arreglo.*/
	int indexVarEnt;      /*Indice Variable de Entrada*/
	int indexVarSal;      /*Indice Variable de Salida*/
	vector<int> vecs_base;/*vectores base, indices de los 
						    vectores base*/
	int indexDRelMin;     /*Indice de relaci\'on m\'inima*/
	set<int> setDIVarBas; /*set De Indexes De Variables B\'asicas*/
	vector<Rac> X;        /*vector de Rac soluci\'on de Forma 
						    Aumentada*/

public:
	FormaAumentada(Rac **doPt,int m,int n);
	~FormaAumentada();
	void set_base_usando_vecs_base();
	void mostrar();
	void set_setDIVarBas(set<int> a_set);
	void show_sol_diter_simplex();
	void add_index_dvecbase(int indDVecB);
	int get_index_dcoefbas_en_fila(int fila);
	void setIndexVarEnt(int ind);
	int get_indexVarEnt();
	void setIndexDRelMin(int indexDRelMin);
	int get_indexDRelMin();
	void setIndexVarSal(int ind);
	int get_indexVarSal();
	void show_rels();
	void hacer_iteracion(int row,int col);
private:
	void calc_sol_diter_simplex();
	int index_dluno_nvecbas(int indexVecBas);
	void multFormAument(int row,Rac reciproco);
	void hacer_ceros_arriba_y_abajo_dl_pivote();
};//end class FormaAumentada

#define MATRIX_D_RAC(M, N)	\
int opt = 1;\
Rac **E = new Rac*[M + 1];\
for (int k = 0; k <= M; k++) {\
	E[k] = new Rac[N + 2];\
}
/*end macro MATRIX_D_RAC()*/

/* VARiables BASICas*/
#define VAR_BASIC(IDVBas,FA)	\
int _i;\
for (int _i = 0; _i < sizeof(IDVBas) / sizeof(int); _i++){\
	FA.add_index_dvecbase(IDVBas[_i]);\
}\
set<int> setIDVBas;\
setIDVBas.insert(IDVBas, IDVBas + sizeof(IDVBas) / sizeof(int));\
FA##.##set_setDIVarBas(setIDVBas);\
FA##.##set_base_usando_vecs_base();
/*end macro VAR_BASIC()*/

/*MOSTRAR PREGUNTAR_ITERAR*/
#define MOSTRAR_PREG_ITERAR(FA)	\
int indDRelMin;\
int indDVarDEnt;\
FA.mostrar();\
FA.show_sol_diter_simplex();\
printf("[0: Salir/1: Continuar]:? ");\
scanf_s("%d%*c", &opt);\
if (opt) {\
	printf("Index de variable de entrada:? ");\
	scanf_s("%d%*c", &indDVarDEnt);\
	FA.setIndexVarEnt(indDVarDEnt);\
	FA.show_rels();\
	printf("Index de la relaci\\'on positiva min:? ");\
	scanf_s("%d", &indDRelMin);\
	FA.setIndexDRelMin(indDRelMin);\
	FA.setIndexVarSal(FA.get_index_dcoefbas_en_fila(indDRelMin));\
	printf("Variable de entrada: x_{%d}\n", FA.get_indexVarEnt());\
	printf("Variable de salida: x_{%d}\n", FA.get_indexVarSal());\
	FA.hacer_iteracion(FA.get_indexDRelMin(), FA.get_indexVarEnt());\
}
/*end macro MOSTRAR_PREG_ITERAR()*/
