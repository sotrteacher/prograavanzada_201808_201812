/** String_Tokenizer.h
*/
#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H
#include <string>
/** La clase String_Tokenizer divide una cadena en una secuencia 
    de subcadenas, denominadas tokens, y separadas por delimitadores
*/
class String_Tokenizer{
  public:
/** Construccion de un String_Tokenizer
    @param source La cadena a ser dividida en tokens
    @param delim La cadena que contiene los delimitadores. Si se omite
                 este parametro, se asume un caracter de espacio.
  */
  String_Tokenizer(std::string source, std::string delim=" "):
    the_source(source), the_delim(delim), start(0), end(0) {
    find_next();
  }
  String_Tokenizer():the_source(""), the_delim(" "), start(0), end(0) {
  	find_next();
  }
/** Determinar si existen mas tokens
    @return true si existen mas tokens
  */
  bool has_more_tokens();
/** Recuperar el siguiente token
    @return El siguiente token. Si no hay mas tokens, regresara un string 
            vacio
  */
  std::string next_token();

  private:
  /** Ubicar start y end de manera que start sea el indice del comienzo del 
      siguiente token y end sea la terminacion. 
    */
    void find_next();
  /** La cadena a ser dividida en tokens */
    std::string the_source;
  /** La cadena de delimitadores */
    std::string the_delim;
  /** El indice del inicio del siguiente token */
    size_t start;
  /** El indice de la terminacion del siguiente token */
    size_t end;
};//end class String_Tokenizer
    
#endif /* STRING_TOKENIZER_H */


