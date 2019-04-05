#ifndef __mensaje__
#define __mensaje__

#define TAM_MAX_DATA 4000

struct mensaje {
    int messageType;        //0 = Solicitud, 1 = Respuesta
    unsigned int requestId; //Identificador del mensaje
    char IP[16];
    int puerto;
    int operationId;        //Identificador del mensaje
    int arguments;
};

#endif
