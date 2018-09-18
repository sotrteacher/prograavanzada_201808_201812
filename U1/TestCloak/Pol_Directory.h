/** Basado en Listado 1.9 Array_Based_PD.h, p\'ag 114 del libro:
    Estructura de datos con C++, Objetos, abstracciones y dise\~no, 
	de Elliot B. Koffman/Paul A. T. Wolfgang, 
	Editorial Mc Graw Hill Interamericana, 2008.
	ISBN-10:970-10-6578-6
	ISBN-13:978-970-10-6578-5  
*/
#ifndef POL_DIRECTORY
#define POL_DIRECTORY
#include <string>
/**Archivo de especificaci\'on para el directorio 
   de polinomios basado en un conjunto. */

//class Directory_entry;	/* Declaraci\'on anticipada de clase */
#include "Directory_entry.h"

class Pol_Directory {
	public:
	/** Construir un directorio de polinomios vacio. */
	Pol_Directory();
	
	/** Destruir el directorio de polinomios cunado ya no se necesita. */
	~Pol_Directory();
	
	/** Cargar el o los archivos de datos que contienen el directorio, 
	    establecer la conexi\'on con la fuente de datos.
		@param source_name El nombre del archivo (fuente de datos) con 
		                   las entradas del directorio de polinomios. */
	void load_data(const std::string& source_name);
	
	/** Buscar una entrada.
	    @param name El nombre de la variable a buscar
	    @return Los coefiecientes asociados con la variable o una 
	            cadena vacia si la variable no se encuentra en el 
				directorio.
	*/
	std::string lookup_entry(const std::string& var_name) const;
	
	/** Modificar el contenido asociado con el nombre de la variable 
	   var_name por el de coeffs, o agregar una nueva entrada con el 
	   nombre de variable var_name y los coeficientes coeffs.
	   @param var_name El nombre de la variable
	   @param coeffs Los nuevos coeficientes
	   @return Los coeficientes antiguos o una cadena vacia si esta 
	           es una nueva entrada
	*/
	std::string add_or_change_entry(const std::string& var_name,const std::string& coeffs);
	
	/** Eliminar la entrada con un nombre espec\'ifico del directorio.
	    @param var_name El nombre de la variable a remover
	    @return El nombre de la variable o una cadena vacia si es que no se 
	            encuentra en el directorio.
	*/
	std::string remove_entry(const std::string& var_name);
	
	/** Escribir el contenido del directorio en el archivo de datos. */
	void save();
	
	private:
	// Funciones privadas
	/** Buscar en el directorio el nombre de la variable var_name.
	    @param var_name El nombre de variable a ser encontrado
		@return El indice de la entrada que contiene el nombre de la variable, 
		        o el tama\~no del directorio en caso de que el nombre de la 
				variable no se haya encontrado. 
	*/
	int find(const std::string& var_name) const;
	
	/** Agregar una nueva entrada con un nombre espec\'ifico y sus coeficientes 
	    al arreglo de entradas del directorio de polinomios.
	    @param var_name El nombre de la variable a ser agregada
	    @param coeffs Los coefcientes de la variable a ser agregada
	*/
	void add(const std::string& var_name,const std::string& coeffs);
	
	/** Eliminar la entrada de un \'indice espec\'ifico.
	    @param index El \'indice de la entrada a ser eliminada
	*/
	void remove_entry(int index);
	
	/** Crear un nuevo conjunto de las entradas del directorio 
	    con el doble de la capacidad del actual.
	*/
	void reallocate();
	
	/** El n\'umero de entradas en el directorio. */
	int size;
	/** La capacidad real del directorio. */
	int capacity;
	/** Apuntador del arreglo que contiene los datos del directorio. */
	Directory_entry *the_directory;
	/** El nombre del archivo de datos que contiene los datos del directorio. */
	std::string source_name;
	/** Bandera booleana para indicar si se modific\'o el directorio. */
	bool modified;
};//end class Pol_Directory


#endif /*POL_DIRECTORY*/
