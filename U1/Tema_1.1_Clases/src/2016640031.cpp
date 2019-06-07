#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
using namespace std;

#include "Nota_Directorio.h"
#include "Nota.h"

Nota_Directorio::Nota_Directorio(){
	size=0;
	capacity=100;
	directorio=new Nota[100];
}

