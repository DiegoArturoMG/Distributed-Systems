#include "SocketDatagrama.h"

using namespace std;

#define puerto 4200
#define puerto1 4300
#define puerto2 4400
#define puerto3 4500

int main(int argc, char const *argv[]){

  SocketDatagrama socket = SocketDatagrama(puerto);

  unsigned int num[3];
  
  //se divide el numero
  int valInicial = 1;
  int valFinal = 0;
  int n = 893029;

  valFinal = n / 3; //276596
  num[0] = valInicial;
  num[1] = valFinal;
  num[2] = n;
  cout << "valor inicial: " << valInicial << endl;
  cout << "valor final: " << valFinal << endl;
  PaqueteDatagrama datagramaEnvia1 = PaqueteDatagrama((char*)num, 3*sizeof(int),"127.0.0.1", puerto1);
  socket.envia(datagramaEnvia1);

  valInicial = valFinal+1;
  valFinal = valFinal * 2;
  num[0] = valInicial;
  num[1] = valFinal;
  num[2] = n;
  cout << "valor inicial: " << valInicial << endl;
  cout << "valor final: " << valFinal << endl;
  PaqueteDatagrama datagramaEnvia2 = PaqueteDatagrama((char*)num, 3*sizeof(int),"127.0.0.1", puerto2);
  socket.envia(datagramaEnvia2);

  valInicial = valFinal+1;
  valFinal = n;
  num[0] = valInicial;
  num[1] = valFinal;
  num[2] = n;
  cout << "valor inicial: " << valInicial << endl;
  cout << "valor final: " << valFinal << endl;
  PaqueteDatagrama datagramaEnvia3 = PaqueteDatagrama((char*)num, 3*sizeof(int),"127.0.0.1", puerto3);
  socket.envia(datagramaEnvia3);
  
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