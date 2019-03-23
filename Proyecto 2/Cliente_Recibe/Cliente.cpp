#include "SocketDatagrama.h"

using namespace std;

#define puerto 7300
#define puerto2 7400
#define MAX_HILOS 1

PaqueteDatagrama enviarDat(char* valor){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto2);
}

void * enviar(void * arg){
    //cout << "Se crea hilo enviar" << endl;
    char *argumento = (char *) arg;
    int *packPerdidos = (int *)argumento;
    int val_inicial = *packPerdidos;
    //cout << "-->" << *packPerdidos << endl;
    packPerdidos = packPerdidos+1;
    int val_final = *packPerdidos;
    //cout << "-->" << (*packPerdidos) << endl;

    SocketDatagrama socket = SocketDatagrama(puerto);
    //Se crea for para enviar cada paquete
    int numeros[1];
    for(int i=val_inicial;i<val_final;i++){
        numeros[0] = i;
        //cout << "->>> Se envia paquete" << endl;
        PaqueteDatagrama datagramaEnvia = enviarDat((char*)numeros);
        socket.envia(datagramaEnvia);
    }
    pthread_exit(0);
}

void creacionDeHiloEnviar(int *paqPerdidos){
        
    int paquetesPerdidos[2];
    paquetesPerdidos[0] = *paqPerdidos;
    paqPerdidos = paqPerdidos+1;
    paquetesPerdidos[1] = *paqPerdidos;

    //Creacion del hilo
    //cout << "Se crea hilo" << endl;
    pthread_attr_t atributos;
    pthread_t thid[1];
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);
    pthread_create(&thid[0],&atributos,enviar,paquetesPerdidos);
}

void * recibir(void *){

    SocketDatagrama socket = SocketDatagrama(puerto);
        
    int identificador=1;
    int val[1];

    cout << "Esperando clientes..." << endl;

    while(1){
        //cout << "Se espera paquete" << endl;
        PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
        socket.recibe(datagramaRecibe);
        //cout << "Se recibe paquete" << endl;
        int * respuesta = (int*)datagramaRecibe.obtieneDatos();

        if(identificador == *respuesta){
            //cout << "Se ha recibido correctamente: " << *respuesta << endl;
            identificador++;
        }else if(*respuesta == 0){
            //cout << "Se ha recibido paquete 0" << endl;
            val[0] = 0;
            PaqueteDatagrama datagramaEnvia = enviarDat((char*)val);
            socket.envia(datagramaEnvia);
            //cout << "Se ha regresado paquete 0" << endl;
            identificador = 1;
        }else{
            //cout << "Se esperaba: " << identificador << endl;
            //cout << "Se recibio: " << *respuesta << endl;

            //Se debe calcular grupo de paquetes que no estan llegando
            int paquetesPerdidos[2];
            paquetesPerdidos[0] = identificador;
            paquetesPerdidos[1] = *respuesta;

            identificador = (*respuesta+1);

            creacionDeHiloEnviar(paquetesPerdidos);

            //PaqueteDatagrama datagramaEnvia = enviarDat((char*)val);
            //socket.envia(datagramaEnvia);
            //cout << "Se ha regresado paquete fallido" << endl;

        }

    }

    //sleep(3);
    //pthread_exit(0);
}

int main(int argc, char const *argv[]){

    int i;
    pthread_attr_t atributos;
    pthread_t thid[MAX_HILOS];

    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);

    pthread_create(&thid[0],&atributos,recibir,NULL);

    sleep(10000);    

    return 0;
}
