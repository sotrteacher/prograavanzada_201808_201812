//Nota.h
#ifndef NOTA_H
#define NOTA_H
/**
 * Clase para representar Notas de recordatorio
 * o posiblemente notas de pie de de p\'agina. En fin,
 * Una nota que podr\'iamos anotar por ejemplo en un post it.
 * Esta clase tambi\'en muestra como podemos declarar 
 * clases sin secciones privadas. 
 */

struct Nota{
  int intFecha;
  string stringFecha;
  string stringContenidoDeNota;
  string stringDestinatario;
  string stringRemitente;
  void mostrar(){/* Ejemplo de un M\'etodo */
    cout<<"Fecha:               "<<stringFecha<<endl;
    cout<<"PARA:"<<stringDestinatario<<endl;
    cout<<"DE:"<<stringRemitente<<endl;
    cout<<stringContenidoDeNota<<endl;
  }
  void print_message();
  Nota(){ } //deliberadamente vacio.
  /**
   * Adem\'as de inicializar el atributo intFecha, que  tambi\'en 
   * establezca la fecha como cadena:
   * <nombre del dia> <29> de <enero> de <2019>
   * (29,enero y 2019 son un ejemplo). Para todas las fechas del 
   * calendario Gregoriano desde que empez\'o hasta el 31 de diciembre 
   * de 2399.
   */
  Nota(int intFecha);

  /**
   * Adem\'as de inicializar el atributo stringFecha del objeto que se 
   * estar\'a instanciando, tambi\'en deber\'a inicializar el atributo 
   * intFecha con el n\'umero entero que corresponda a la fecha pasada 
   * como cadena a este constructor, esto es, por ejemplo, para la fecha:
   * Martes 29 de enero de 2019
   * deberá inicializar también el atributo entero intFecha con el valor 
   * entero 20190129.
   */
  Nota(string stringF);

  /**
   * Deber\'a contar la cantidad de notas creadas hasta el momento por 
   * el remitente cuyo nombre se pasa como cadena a este mi\'etodo.
   */ 
  static int contar_notas_del_remitente(string stringNombreDelRemitente);

  /**
   * Deber\'a contar la cantidad de notas que el remitente rem haya enviado 
   * al destinatario dest hasta el momento en que se ejecute este m\'etodo.
   */ 
  static int contar_notas_del_remitente_al_destinatario(string rem,string dest);

  /**
   * Deber\'a contar la cantidad de notas "recibidas" hasta el momento por 
   * el destinatario cuyo nombre se pasa como cadena a este mi\'etodo.
   */ 
  static int contar_notas_del_destinatario(string stringNombreDelDestinatario);
};//end struct Nota

#endif /* NOTA_H */
