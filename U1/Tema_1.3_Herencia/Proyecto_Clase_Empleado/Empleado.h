/** Empleado.h - Declara la claase Empleado */
#ifndef EMPLEADO_H
#define EMPLEADO_H
class Empleado {
public:
  //Contructor
  Empleado(const char *const,const char *const);
  //Destructor
  ~Empleado();



  const char *getPrimerNombre() const; //devuelve el primer nombre
  const char *getApellidoPaterno() const; //devuelve el apellido paterno 

  static int getCuenta();    //devuelve el n\'umero de objetos instanciados
private:
  char *primerNombre;
  char *apellidoPaterno;

  //datos static
  static int cuenta;  //N\'umero de objetos instanciados
};//end class Empleado

#endif /* EMPLEADO_H */
