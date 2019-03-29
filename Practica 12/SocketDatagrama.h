#define SOCKET_DATAGRAMA_H_

#include "PaqueteDatagrama.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

#include <errno.h>
#include <sys/time.h>

class SocketDatagrama
{
public:
	SocketDatagrama(int, struct timeval);
	~SocketDatagrama();
	//Recibe un paquete tipo datagrama proveniente de este socket
	int recibe(PaqueteDatagrama & paquete);
	//Envia un paquete tipo datagrama desde este socket 
	int envia(PaqueteDatagrama & paquete);
	//Recibe un paquete tipo datagrama proveniente de este socket con timeout
	int recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos);
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket
	struct timeval timeoutSocket;
};