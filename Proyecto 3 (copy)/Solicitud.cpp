#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char* IP, int puerto, int operationId, char* arguments, int length) {
	struct mensaje msj;
	msj.messageType = 0;
	msj.requestId = id;
	id++;
	memcpy(msj.IP, IP, 16);
	msj.puerto = puerto;
	msj.lengthBytes = length;
	msj.operationId = operationId;

	if (arguments == NULL) {
        std::fill(msj.arguments, msj.arguments + TAM_MAX_DATA, 0);
    } else {
        std::copy(arguments, arguments + length, msj.arguments);
    }

	//copy(arguments, arguments + length, msj.arguments);

	PaqueteDatagrama paq(reinterpret_cast<char *>(&msj), sizeof(struct mensaje), IP, puerto, length);

	//cout << "===>" << paq.obtieneLengthBytes() << endl;

	socketlocal->envia(paq);
	
	PaqueteDatagrama paq1(TAM_MAX_DATA);
	socketlocal->recibe(paq1);

	char* resultado;
	resultado = paq1.obtieneDatos();

	return resultado;
}
