#include <cstdlib>
#include <iostream>    /*  cout  */
#include <stdio.h>     /* sprintf() */
using namespace std;    /*  cout  */
#include "Nota.h"


int main(int argc, char *argv[])
{
    Nota N;
    N.intFecha=20180810;
    char str[20];
    sprintf(str,"%d",N.intFecha);
    N.stringFecha=string(str);
    N.stringRemitente="David Helvio";
    N.stringDestinatario="John";
    N.stringContenidoDeNota="Visto lo visto, sapere aude";
    N.mostrar();
    N.print_message();
#ifndef __unix__
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}//end 






