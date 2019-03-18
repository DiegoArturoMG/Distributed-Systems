#include "SocketDatagrama.h"

using namespace std;

#define puerto 7300
#define puerto2 7400
#define MAX_HILOS 2

PaqueteDatagrama enviarDat(char* valor){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto2);
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
            val[0] = identificador;
            identificador++;
            PaqueteDatagrama datagramaEnvia = enviarDat((char*)val);
            socket.envia(datagramaEnvia);
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
