#include "SocketDatagrama.h"

using namespace std;

#define puerto 7300
#define MAX_HILOS 10

PaqueteDatagrama enviarDat(char* valor){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto);
}

void enviar(const char ){
    SocketDatagrama socket = SocketDatagrama(puerto);
    int numeros[1],val=1;
    numeros[0] = val;
    //Convertimos de char* a int
    long n = strtol(argv[1], NULL, 10);

    do{
        PaqueteDatagrama datagramaEnvia = enviarDat((char*)numeros);
        socket.envia(datagramaEnvia);
        val++;
        numeros[0] = val;

        //Se envia el ultimo paquete que seria el valor 0
        if(val > n){
            int num[1];
            num[0] = 0;
            PaqueteDatagrama datagramaEnvia = enviarDat((char*) num);
            socket.envia(datagramaEnvia);
        }

    }while(numeros[0] <= n);

}

void recibir(){

}

int main(int argc, char const *argv[]){
    int i;
    pthread_attr_t atributos;
    pthread_t thid[MAX_HILOS];

    pthread_attr_init($atributos);
    pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);

    pthread_create(&thid[0],&atributos,(void *) enviar,NULL);
    pthread_create(&thid[1],&atributos,(void *) recibir,NULL);



    sleep(6);    

    return 0;
}
