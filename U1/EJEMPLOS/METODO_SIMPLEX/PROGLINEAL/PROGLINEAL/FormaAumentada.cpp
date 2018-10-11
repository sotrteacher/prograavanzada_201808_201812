#include "stdafx.h"
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "FormaAumentada.h"
#include "..\CommonF\Set_Functions.h"

FormaAumentada::FormaAumentada(Rac **doPt,int M,int N):m(M),n(N)
{
	CbZAyb = doPt;
}

FormaAumentada::~FormaAumentada(){ }

void FormaAumentada::mostrar() {
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n+1; j++) {
			if (i > 0 && j == 0) {
				printf("   x_{%d}   ", CbZAyb[i][j].n);
			}
			else {
				printf("%5d/%-5d", CbZAyb[i][j].n, CbZAyb[i][j].d);
			}
		}
		printf("\n");
	}
}

void FormaAumentada::set_setDIVarBas(set<int> a_set) {
	setDIVarBas = a_set;
	//cout << "setDIVarBas is:" << setDIVarBas << endl;
}

void FormaAumentada::setIndexVarEnt(int ind) {
	indexVarEnt = ind;
}

int FormaAumentada::get_indexVarEnt() {
	return indexVarEnt;
}

void FormaAumentada::setIndexDRelMin(int indexDRelMin) {
	this->indexDRelMin = indexDRelMin;
}

int FormaAumentada::get_indexDRelMin() {
	return indexDRelMin;
}

void FormaAumentada::setIndexVarSal(int ind) {
	indexVarSal = ind;
}

int FormaAumentada::get_indexVarSal() {
	return indexVarSal;
}

/*Se debe usar para inicializar los indices de los 
  vectores/variables base; y se debe usar en el orden 
  de las ecuaciones de la forma aumentada: 1,2,3,...,m.
  De esa manera, usando el \'indice de la relaci\'on 
  m\'inima, del vector vecs_base obtendremos el \'indice 
  de la variable de salida, i.e., 
  vecs_base[index de rel minima]*/
void FormaAumentada::add_index_dvecbase(int indDVecB) {
	vecs_base.push_back(indDVecB);
}

void FormaAumentada::set_base_usando_vecs_base() {
	for (int i = 1; i <= m; i++) {
		CbZAyb[i][0] = Rac(vecs_base[i - 1], 1);
	}
}

/*Devuelve Index de ``coeficiente'' b\'asico en la fila fila.
fila debe ser mayor o igual a 1*/
int FormaAumentada::get_index_dcoefbas_en_fila(int fila) {
	return vecs_base[fila-1];
}

void FormaAumentada::show_rels() {
	int numdrels = 0;     /*n\'umero de relaciones*/
	Rac rel;
	for (int i = 1; i <=m; i++)
	{
		if (CbZAyb[i][indexVarEnt].n != 0) {
			rel = CbZAyb[i][n + 1] / CbZAyb[i][indexVarEnt];
			rel.set_mcd(rel.calc_mcd());
			rel.simplificar();
			printf("Fila index num:%-3d%5d/%-5d\n",i,rel.n,rel.d);
			numdrels++;
		}
	}
}

void FormaAumentada::calc_sol_diter_simplex() {
	X.clear();          /*primero limpio el vector de 
					      Rac soluci\'on de la iteraci\'on*/
	X.push_back(CbZAyb[0][n+1]); /*primero coloco z en la 
								  posici\'on 0*/
	for (int i = 1; i <= n; i++) {
		if (setDIVarBas.find(i) != setDIVarBas.end()) {/*si x_{i} es b\'asica*/
			X.push_back(CbZAyb[index_dluno_nvecbas(i)][n + 1]);
			//printf("x_{%d}=%5d/%-5d\n", i, X[i].n, X[i].d);
		}
		else {
			X.push_back(Rac(0, 1));
		}
	}
}

void FormaAumentada::show_sol_diter_simplex() {
	calc_sol_diter_simplex();
	for (int i = 1; i <=n; i++)
	{
		printf("x_{%d}=%5d/%-5d\n", i, X[i].n, X[i].d);
	}
}

int FormaAumentada::index_dluno_nvecbas(int indexVecBas) {
	for (int i = 1; i <= m; i++) {
		if ((1==CbZAyb[i][indexVecBas].n)&&(1 == CbZAyb[i][indexVecBas].d))
		{
			return i;
		}
	}
	return -1;
}

/*Mutiplicar la fila row de la matriz aumentada por el Rac
  reciproco*/
void FormaAumentada::multFormAument(int row, Rac reciproco) {
	for (int j = 1; j <= n + 1; j++) {
		CbZAyb[row][j] = CbZAyb[row][j] * reciproco;
		CbZAyb[row][j].set_mcd(CbZAyb[row][j].calc_mcd());
		CbZAyb[row][j].simplificar();
	}
}

/*(row,col) deben ser las cordenadas del elemento pivote,
  el cual por construcci\'on se supone que es distinto de
  cero
  pre: indexDRelMin debe haber sido asignado con un valor
       adecuado para la iteraci\'on; es decir, con el 
	   \'indice de la fila con relaci\'on m\'inima; o tal 
	   vez sea mejor usar row :-)
  pre: la variable de objeto indexVarEnt debe haber sido 
       inicializada con el valor adecuado; esto es, debe 
	   ser igual al \'indice de la variable de entrada.
  */
void FormaAumentada::hacer_iteracion(int row,int col) {
	Rac reci = Rac(CbZAyb[row][col].d, CbZAyb[row][col].n);
	reci.set_mcd(reci.calc_mcd());
	reci.simplificar();
	multFormAument(row,reci);
	hacer_ceros_arriba_y_abajo_dl_pivote();
	vecs_base[row - 1] = indexVarEnt;
	setDIVarBas.erase(indexVarSal);
	int arrInt[] = { indexVarEnt };
	setDIVarBas.insert(arrInt, arrInt + 1);
	for (int i = 1; i <= m; i++) {
		CbZAyb[i][0] = Rac(vecs_base[i-1],1);
	}
}

void FormaAumentada::hacer_ceros_arriba_y_abajo_dl_pivote() {
	int pivX = get_indexDRelMin();   /*index de fila del pivote*/
	int pivY = get_indexVarEnt();    /*index de columna del pivote*/
	Rac *arrRacTmp=new Rac[n + 2];
	for (int i = 0; i < n + 2; i++) {
		arrRacTmp[i] = Rac(0,1);
	}
	Rac factor;
	for (int i = 0; i < m + 1; i++) {
		if (pivX != i) {
			factor = Rac(-CbZAyb[i][pivY].n, CbZAyb[i][pivY].d);
			for (int j = 1; j <= n + 1; j++) {
				arrRacTmp[j] = factor * CbZAyb[pivX][j];
			}
			for (int j = 1; j <= n + 1; j++) {
				CbZAyb[i][j] = CbZAyb[i][j]+ arrRacTmp[j];
			}
		}
	}
}

