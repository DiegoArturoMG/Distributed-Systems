#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[]) {
	
	struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 500000;

	int arreglo = atoi(argv[2]);
	char *ip;
	int puerto;
	int operacion = atoi(argv[1]);

	ip = "127.0.0.1";
	puerto = 5000;
	Solicitud cliente = Solicitud(timeout);

	printf("La respuesta del servidor es : %d\n", cliente.doOperation(ip, puerto, operacion, arreglo));

	return 0;
}
