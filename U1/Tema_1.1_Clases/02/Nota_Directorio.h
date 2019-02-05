// Nota_Directorio.h - Declara la clase Nota_Directorio
#ifndef NOTA_DIRECTORIO
#define NOTA_DIRECTORIO
struct Nota;
struct Par_Int_IntPt;
struct Nota_Directorio{
	/*El numero de entradas en el directorio*/
	int size;

	/*La capacidad real del directorio*/
	int capacity;

	/*Apuntador a las notas del directorio de Notas*/
	Nota *directorio;

	/*El nombre del archivo de datos que contiene los datos(de las Notas) del directorio*/
	std::string source_name;

	/*Bandera booleana para indicar si se modific\'o el directorio*/
	bool modified;

	/*Construir un directorio de Notas vacio*/
	Nota_Directorio();

	/*Destruir el directorio cuando ya no se necesita*/
	~Nota_Directorio();

	/**Cargar datos desde el archivo que contiene los datos de las notas del directorio,
	 * @param source_name El nombre del archivo (fuente de datos) con 
	 *                    las entradas del directorio telef\'onicoentradas del directorio 
	 *                    telef\'onico*/
	void load_data(const std::string& source_name);

	/**Buscar una o m\'as entradas (Nota(s) que contengan una palabra). 
	 * @param palabra La palabra a buscar dentro del contenido de la nota
	 * @return un apuntador a struct Par_int_intPt, el int indicar\'a cuantas notas 
	 *         contienen la palabra buscada y el apuntador intPt apuntar\'a a los \'indices del 
	 *         arreglo directorio (Nota *directorio) correspondientes a notas que contienen la 
	 *         palabra buscada, el int ser\'a cero si no hay notas que contengan la palabra 
	 *         buscada.
	 */
	struct Par_int_intPt *buscar_entradas(std::string palabra) const;

	/**Agregar una nueva Nota con un remitente y destinatario espec\'ificos y un  
	 * contenido de Nota espec\'ifico.
	 * @param rem Remitente
	 * @param dest Destinatario
	 * @param content Contenido de la Nota
	 */
	void add(const std::string& rem,const std::string& dest,const std::string& content);

	/**Eliminar la entrada de un \'indice espec\'ifico.
	 * @param index El \'indice de la entrada del directorio de Notas a ser eliminada
	 */
	void remove_entry(int index);

	/**Crear un nuevo conjunto de entradas del directorio de Notas con el doble de la
	 * capacidad actual.
	 */ 
	void reallocate();
};//end class Nota_Directorio
#endif /* NOTA_DIRECTORIO */
