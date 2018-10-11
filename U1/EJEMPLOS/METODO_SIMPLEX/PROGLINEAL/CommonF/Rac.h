/** Rac.h - Una clase para representar n\'umeros racionales.
*/
#include <iostream>		/* cout, ostream*/
//#include <stdlib.h>	/* malloc() */
using namespace std;	

#ifndef Rac_h
#define Rac_h



    /** 
     *  Clase para representar n\'umeros racionales
     *  @author Lamberto Maza Casas
     *  @version 2018.02.12
     */
struct Rac {


    int calc_mcd();

    void set_mcd(int MCD);

    Rac& operator+(Rac& RacObj);
 
    Rac& operator-(Rac& RacObj);

    Rac& operator*(Rac& RacObj);

    Rac& operator/(Rac& RacObj);
    
    Rac& operator+(int intVal);
    
    friend Rac& operator+(int intVal,Rac& RacObj);
    
    friend ostream& operator<<(ostream& ostreamOut, Rac& RacObj);
    
//    friend ostream& operator<<=(ostream& ostreamOut,Rac& RacObj);
	Rac(const Rac&);

    Rac(int intNum, int intDen);

    Rac();
    Rac(int){ }

    void simplificar();
    
	std::string string_show();
 
    int n;		/* numerador */
    int d;		/* denominador*/
    int mcd;	/* m\'aximo com\'un divisor*/
};//end struct Rac

#endif // Rac_h
