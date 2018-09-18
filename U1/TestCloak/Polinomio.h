/** Polinomio.h - Una clase para representar polinomios.
*/
#include <iostream>		/* cout, ostream*/
//#include <stdlib.h>	/* malloc() */
using namespace std;
#include "Rac.h"

#ifndef Polinomio_h
#define Polinomio_h
#define maximo(a,b)	((a>b)?a:b)

struct Polinomio {

    Polinomio& operator+(Polinomio& PolObj);

    Polinomio& operator-(Polinomio& PolObj);

    Polinomio& operator*(Polinomio& PolObj);

//    FcnDTrans& operator/(Polinomio& PolObj);

    friend ostream& operator<<(ostream& ostreamObj, Polinomio& PolObj);
    
    std::string string_show();

    Polinomio(int intGrado, Rac * RacPt);
    Polinomio(){ }
    Polinomio(int){ }

    int grado;
    Rac * A;
};//end struct Polinomio

#endif // Polinomio_h
