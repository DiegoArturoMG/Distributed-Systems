#include "SocketDatagrama.h"

using namespace std;

#define puerto 7300
#define puerto2 7400
#define MAX_HILOS 2

PaqueteDatagrama enviarDat(char* valor){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto);
}

void * enviar(void * arg){

    int *argumento = (int *) arg;

    SocketDatagrama socket = SocketDatagrama(puerto);
    int numeros[1],val=1;
    numeros[0] = val;
    //Convertimos de char* a int
    long n = (long int)*argumento;

    //cout << n << endl;

    do{
        //cout << "Se envia paquete" << endl;
        PaqueteDatagrama datagramaEnvia = enviarDat((char*)numeros);
        socket.envia(datagramaEnvia);
        //cout << "Se ha enviado paquete" << endl;
        val++;
        numeros[0] = val;

        //Se envia el ultimo paquete que seria el valor 0
        if(val > n){
            int num[1];
            num[0] = 0;
            PaqueteDatagrama datagramaEnvia = enviarDat((char*) num);
            socket.envia(datagramaEnvia);
            //cout << "Se han enviado todos los paquetes" << endl;
        }

    }while(numeros[0] <= n);

    //sleep(3);
    //pthread_exit(0);

}

void imprimirPaquetesPerdidos(int * paquetesP, int cant, long n){
    cout << "Pauqetes perdidos: " << cant << endl;
    for(int i=0;i<cant;i++){
        cout << *paquetesP++ << endl;
    }
    double result = (100.00 - ((cant*100.00)/n));
    cout << "Porcentaje de paquetes enviados: " << result << endl;
}

void * recibir(void * arg){

    int *argumento = (int *) arg;
    long n = (long int)*argumento;

    SocketDatagrama socket = SocketDatagrama(puerto2);
    int * paquetes_perdidos = NULL;
    int cant = 2,cant_aux=0;

    paquetes_perdidos = (int *)malloc(1*sizeof(int));

    cout << "Esperando respuesta de Servidor..." << endl;

    while(1){

        PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
        socket.recibe(datagramaRecibe);

        paquetes_perdidos = (int *)realloc(paquetes_perdidos,cant*sizeof(int));

        int * respuesta = (int*)datagramaRecibe.obtieneDatos();

        //cout << "Llego paquete perdido: " << *respuesta << endl;
        if(*respuesta == 0){
            //cout << "Se ha terminado envio de paquetes" << endl;
            imprimirPaquetesPerdidos(&paquetes_perdidos[0],cant_aux,n);
            exit(1);
        }else{
            paquetes_perdidos[cant_aux] = *respuesta;
            cant_aux++;cant++;
        }

    }

    //sleep(3);
    //pthread_exit(0);
}

int main(int argc, char const *argv[]){

    //Se le envia parametro por consola
    long conv = atoi(argv[1]);

    int i;
    pthread_attr_t atributos;
    pthread_t thid[MAX_HILOS];

    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);

    pthread_create(&thid[0],&atributos,enviar,&conv);
    pthread_create(&thid[1],&atributos,recibir,&conv);

    sleep(1000); 

    return 0;   
}
