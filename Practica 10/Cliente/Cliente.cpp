#include "SocketDatagrama.h"

using namespace std;

#define puerto1 4300
#define puerto2 4400
#define puerto3 4500

PaqueteDatagrama enviarDat(char* valor,int puerto){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto);
}

int main(int argc, char const *argv[]){

  SocketDatagrama socket1 = SocketDatagrama(puerto1);
  SocketDatagrama socket2 = SocketDatagrama(puerto2);
  SocketDatagrama socket3 = SocketDatagrama(puerto3);

  unsigned int num[3];
  
  //se divide el numero
  


  num[2] = 829789;

  //num[0] = 4294967295; //Es divisible por 3

  int cont=0;

  PaqueteDatagrama datagramaEnvia = enviarDat((char*)num,puerto1);
  socket.envia(datagramaEnvia);
  PaqueteDatagrama datagramaEnvia = enviarDat((char*)num,puerto2);
  socket.envia(datagramaEnvia);
  PaqueteDatagrama datagramaEnvia = enviarDat((char*)num,puerto3);
  socket.envia(datagramaEnvia);

  for(int i=0;i<3;i++){
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    socket.recibe(datagramaRecibe);
    
    int * respuesta = (int*)datagramaRecibe.obtieneDatos();
    int resp = *respuesta;

    if(resp == 0){
      cout << "Respuesta del servidor (" << datagramaRecibe.obtienePuerto() << "): No es primo" << endl;
    }else if(resp == 1){
      cout << "Respuesta del servidor (" << datagramaRecibe.obtienePuerto() << "): Es primo" << endl;
    }
    
  }

  return 0;
}