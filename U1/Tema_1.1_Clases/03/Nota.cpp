#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
using namespace std;
#include "Nota.h"

Nota::Nota(std::string rem,std::string dest,std::string content):
	stringRemitente(rem),stringDestinatario(dest),stringContenidoDeNota(content){
}
