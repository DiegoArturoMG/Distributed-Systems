#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

Solicitud::Solicitud(struct timeval timeout) {
	timeoutSocket = timeout;
	socketlocal = new SocketDatagrama(0,timeout);
}

int Solicitud::doOperation(char* IP, int puerto, int operationId, int arguments) {
	struct mensaje * resultado;
	struct mensaje msj;

	int cont = 0,cont_aux = 0;

	for(int i=0;i<arguments;i++){	
		msj.messageType = 0;
		msj.requestId = id;
		id++;
		memcpy(msj.IP, IP, 16);
		msj.puerto = puerto;
		msj.operationId = operationId;
		msj.arguments = 1;

		PaqueteDatagrama paq((char*) &msj, sizeof(msj), IP, puerto);
		socketlocal->envia(paq);
		PaqueteDatagrama paq1(sizeof(msj));
		socketlocal->recibeTimeout(paq1,timeoutSocket.tv_sec,timeoutSocket.tv_usec);

		resultado = (struct mensaje *)paq1.obtieneDatos();
		
		cont = resultado->arguments;
		if(cont != cont_aux+1 && cont_aux != 0 && msj.operationId == 2){
			cout << "Llego perdida de paquetes: "<<cont<<"->"<<cont_aux<< endl;
			break;
		}else{
			cont_aux = cont;
		}

		if(msj.operationId == 2){
			cout << "se recibe del servidor: " << resultado->arguments << endl;
		}
	}

	msj.operationId = 1;
	PaqueteDatagrama paq((char*) &msj, sizeof(msj), IP, puerto);
	socketlocal->envia(paq);
	PaqueteDatagrama paq1(sizeof(msj));
	socketlocal->recibeTimeout(paq1,timeoutSocket.tv_sec,timeoutSocket.tv_usec);
	resultado = (struct mensaje *)paq1.obtieneDatos();

	return resultado->arguments;
}
