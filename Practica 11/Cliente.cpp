#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[]) {

	char arreglo[100] = "Hola mundo \0";
	char *ip;
	int puerto;
	int operacion = 1;


	ip =argv[1];
	puerto = atoi(argv[2]);
	Solicitud cliente;

	printf("La respuesta del servidor es :\n\n%s\n", cliente.doOperation(ip, puerto, operacion, arreglo));

	return 0;
}
