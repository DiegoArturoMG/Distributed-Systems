#include <cstdlib>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(int argc, char const *argv[]) {
	 
  struct timeval timeout;
  timeout.tv_sec = 2;
  timeout.tv_usec = 500000; 

  //Inicializacion de cuenta de cliente
  int cuentaCliente = 0;
  cout << cuentaCliente << endl;
  //Fin de lectura de archivo

  cout << "Esperando conexion : " << endl;

  Respuesta respuesta(atoi(argv[1]),timeout);

  while(1) {

		struct mensaje msj;
    struct mensaje m1;
    char * cadenaInversa;
		memcpy(&msj, respuesta.getRequest(), sizeof(struct mensaje));
    //cout << "Atendiendo a Cliente" << endl;

    char * paquete;

		switch(msj.operationId) {
			case 1:
        m1.arguments = cuentaCliente;  
        m1.messageType = 1;
        memcpy(m1.IP, msj.IP, 16);
        m1.puerto = msj.puerto;
        m1.requestId = msj.requestId;
        
        paquete = (char *) &m1;

        respuesta.sendReply(paquete,m1.IP, msj.puerto);

        break;
      case 2:
        cuentaCliente += msj.arguments;
        cout << cuentaCliente << endl;
        m1.arguments = cuentaCliente;
        m1.messageType = 1;
        memcpy(m1.IP, msj.IP, 16);
        m1.puerto = msj.puerto;
        m1.requestId = msj.requestId;

        paquete = (char *) &m1;
        respuesta.sendReply(paquete,m1.IP, msj.puerto);
        msj.operationId = 0;     

        break;
			
      default:
				exit(-1);
		}
	}

	return 0;
}
