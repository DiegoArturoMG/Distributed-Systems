#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){

    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 500000;

	SocketDatagrama socket = SocketDatagrama(0,timeout);
    
    int numeros[1];
    numeros[0] = 5;

    cout << "Cantidad a depositar: " << numeros[0] << endl;
    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),"127.0.0.1", 7300);
    socket.envia(datagramaEnvia);
    
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    socket.recibeTimeout(datagramaRecibe,timeout.tv_sec,timeout.tv_usec);
    int * ans = (int*)datagramaRecibe.obtieneDatos();
    cout << "Resultado: " << *ans << endl;
    return 0;
}
