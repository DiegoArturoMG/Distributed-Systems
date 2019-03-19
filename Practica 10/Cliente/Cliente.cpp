#include "SocketDatagrama.h"

using namespace std;

#define MAX_HILOS 3

PaqueteDatagrama enviarDat(char* valor,int puerto){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto);
}

void * enviar(void * arg){

    int *argumento = (int *) arg;

    SocketDatagrama socket = SocketDatagrama(*argumento);
    unsigned int num[1];
    num[0] = 829789;
    //num[0] = 4294967295; //Es divisible por 3

    int cont=0;

    PaqueteDatagrama datagramaEnvia = enviarDat((char*)num,*argumento);
    socket.envia(datagramaEnvia);

    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    socket.recibe(datagramaRecibe);

    int * respuesta = (int*)datagramaRecibe.obtieneDatos();
    int resp = *respuesta;

    if(resp == 0){
      cout << "Respuesta del servidor (" << datagramaRecibe.obtienePuerto() << "): No es primo" << endl;
    }else if(resp == 1){
      cout << "Respuesta del servidor (" << datagramaRecibe.obtienePuerto() << "): Es primo" << endl;
    }
    

    sleep(5);
    //pthread_exit(0);

}

int main(int argc, char const *argv[]){

  int puerto[3];
  
  puerto[0] = 7300;
  puerto[1] = 7400;
  puerto[2] = 7500;

  SocketDatagrama socket1 = SocketDatagrama(puerto[0]);
  SocketDatagrama socket2 = SocketDatagrama(puerto[1]);
  SocketDatagrama socket3 = SocketDatagrama(puerto[2]);

  int i;
  pthread_attr_t atributos;
  pthread_t thid[MAX_HILOS];

  pthread_attr_init(&atributos);
  pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);

  pthread_create(&thid[0],&atributos,enviar,&puerto[0]);
  pthread_create(&thid[1],&atributos,enviar,&puerto[1]);
  pthread_create(&thid[2],&atributos,enviar,&puerto[2]);

  sleep(1000);

  return 0;
}