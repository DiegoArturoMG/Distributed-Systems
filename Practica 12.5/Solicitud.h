#ifndef __Solicitud__
#define __Solicitud__

#include "SocketDatagrama.h"
#include <iostream>

using namespace std;

class Solicitud {
    
public:
    Solicitud(struct timeval);
    int doOperation(char *IP, int puerto, int operationId, int arguments);
    
private:
    SocketDatagrama *socketlocal;
    unsigned int id = 1;
    struct timeval timeoutSocket;
};

#endif
