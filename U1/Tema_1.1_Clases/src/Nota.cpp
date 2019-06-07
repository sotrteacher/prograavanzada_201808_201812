#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#ifndef __unix__
#include <stdlib.h>
#endif
#include <ctime>
#include "gettingdate.h"

using namespace std;
#include "Nota.h"

Nota::Nota(std::string rem,std::string dest,std::string content):
	intFecha(0),stringRemitente(rem),stringDestinatario(dest),
	stringContenidoDeNota(content){
  time_t Now=time(0);
  tm *ltm=localtime(&Now);
  int year=get_year(ltm);
  int month=get_month(ltm);
  int day=get_day(ltm);
  intFecha=10000*year+100*month+day;
}

Nota::Nota(int int_fecha,std::string rem,std::string dest,
           std::string content):intFecha(int_fecha),stringRemitente(rem),
		   stringDestinatario(dest),stringContenidoDeNota(content){
}




