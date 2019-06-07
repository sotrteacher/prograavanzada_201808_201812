#include "Nota.h"
#include "Nota_Directorio.h"
using namespace std;


int main(){
	Nota_directorio dir;
	Nota juan;
	juan.contar_notas_del_remitente_al_destinatario("juan", "miguel", dir);
}
