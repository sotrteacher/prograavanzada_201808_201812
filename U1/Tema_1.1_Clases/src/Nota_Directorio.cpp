#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <stdio.h>
#include <fstream> /* ifstream,ofstream */
#ifndef __unix__
#include <stdlib.h>    /*atoi()*/
#endif
using namespace std;
#include "Nota_Directorio.h"
#include "Nota.h"
#include "Par_int_intPt.h"

/*************************************************
Version 04
**************************************************/
void Nota__Nota(Nota *,int);// __attribute__((weak));
void Nota__Nota(Nota *,string);// __attribute__((weak));
int Nota__contar_notas_del_remitente(Nota_Directorio&,string); 
//__attribute__((weak));
int Nota__contar_notas_del_remitente_al_destinatario(Nota_Directorio&,
    string,string);// __attribute__((weak));
int Nota__contar_notas_del_destinatario(string,Nota_Directorio&); 
//__attribute__((weak));
void Nota_Directorio__Nota_Directorio(Nota_Directorio*);// __attribute__((weak));
void Nota_Directorio__tilde_Nota_Directorio(Nota_Directorio*);// __attribute__((weak));
void Nota_Directorio__load_data(Nota_Directorio*,const std::string&); 
//__attribute__((weak));
struct Par_int_intPt* Nota_Directorio__buscar_entradas(const Nota_Directorio*,string); 
//__attribute__((weak));
void Nota_Directorio__add(Nota_Directorio*,const std::string&,const std::string&,
                      const std::string&);// __attribute__((weak));
void Nota_Directorio__add(Nota_Directorio*,const int,const std::string&,
                      const std::string&,const std::string&); 
//__attribute__((weak));
void Nota_Directorio__remove_entry(Nota_Directorio*,int);// __attribute__((weak));
void Nota_Directorio__reallocate(Nota_Directorio *);// __attribute__((weak));
void Nota_Directorio__save(Nota_Directorio *);// __attribute__((weak));

#ifndef DISC_2016620256
Nota::Nota(int intFecha){
  Nota__Nota(this,intFecha);
}
#endif /*DISC_2016620256*/

#ifndef DISC_2015090165
Nota::Nota(string stringFecha){
  Nota__Nota(this,stringFecha);
}
#endif /*DISC_2015090165*/

#ifndef DISC_2015040092
int Nota::contar_notas_del_remitente(string stringNombreDelRemitente,
Nota_Directorio& el_directorio){
  return Nota__contar_notas_del_remitente(el_directorio,
                                          stringNombreDelRemitente);
}
#endif /*DISC_2015040092*/

#ifndef DISC_2018640271
int Nota::contar_notas_del_remitente_al_destinatario(string rem,
string dest,Nota_Directorio& dir){
  return Nota__contar_notas_del_remitente_al_destinatario(dir,
         rem,dest);
}
#endif /*DISC_2018640271*/

#ifndef DISC_2014030116
int Nota::contar_notas_del_destinatario(string stringNombreDelDestinatario,
                 Nota_Directorio& el_directorio){
  return Nota__contar_notas_del_destinatario(stringNombreDelDestinatario,
               el_directorio);
}
#endif /*DISC_2014030116*/

#ifndef DISC_2016640031
Nota_Directorio::Nota_Directorio(){
	Nota_Directorio__Nota_Directorio(this);
}
#endif /*DISC_2016640031*/

#ifndef DISC_2011640360
Nota_Directorio::~Nota_Directorio(){
    Nota_Directorio__tilde_Nota_Directorio(this);
}
#endif /*DISC_2011640360*/

#ifndef DISC_2017640791
void Nota_Directorio::load_data(const std::string& source_name){
	Nota_Directorio__load_data(this,source_name);
}
#endif /*DISC_2017640791*/

#ifndef DISC_2013090388
struct Par_int_intPt* Nota_Directorio::buscar_entradas(string palabra) const{
	return Nota_Directorio__buscar_entradas(this,palabra);
}
#endif /*DISC_2013090388*/

#ifndef DISC_2015031144
void Nota_Directorio::add(const std::string& rem,const std::string& dest,
          const std::string& content){
    Nota_Directorio__add(this,rem,dest,content); 
}
#endif /*DISC_2015031144*/

void Nota_Directorio::add(const int intFech,const std::string& rem,
                          const std::string& dest,
                          const std::string& content){
    Nota_Directorio__add(this,intFech,rem,dest,content); 
}

#ifndef DISC_2016640087
void Nota_Directorio::remove_entry(int index){
	Nota_Directorio__remove_entry(this,index);
}
#endif /*DISC_2016640087*/

#ifndef DISC_2015080063
void Nota_Directorio::reallocate(){
  Nota_Directorio__reallocate(this);
}
#endif /*DISC_2015080063*/

#ifndef DISC_2014090040
void Nota_Directorio::save(){
	Nota_Directorio__save(this);
}
#endif /*DISC_2014090040*/



