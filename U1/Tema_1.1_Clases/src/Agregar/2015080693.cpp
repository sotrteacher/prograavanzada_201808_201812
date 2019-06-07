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

do_contar_Notas_de_un_remitente_a_un_destinatario(string rem,string dest,Nota_Directorio& el_directorio){
  
    Nota* directorio = el_directorio.directorio;
    int Tam = el_directorio.size;
    int Bus = 0;

    for (int i = 0; i < size; i ++){
      if(el_directorio.directorio[i].stringRemitente == rem){
        if(el_directorio.directorio[i].stringDestinatario == dest){
          Bus++;
        }   
      }
    }
    return Bus
    };
    
