#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){

	struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 500000;
    
	SocketDatagrama socket = SocketDatagrama(7300,timeout);
    int * numeros;
    
    //while(1){
    	PaqueteDatagrama datagrama = PaqueteDatagrama( 2 * sizeof(int));
	    socket.recibeTimeout(datagrama,timeout.tv_sec,timeout.tv_usec);
	    numeros = (int *) datagrama.obtieneDatos();
	    
	    int resultado[1];
	    resultado[0] = numeros[0] + numeros[1];
	    cout << "Se ha establecido conexion:" << endl;
	    cout << "Cliente: " << datagrama.obtieneDireccion() << endl;
	    cout << "Puerto: " << datagrama.obtienePuerto() << endl;
	    cout << "Numero [" << numeros[0] << "]" << endl;
	    cout << "Se regresa resultado: " << *resultado << endl;
	    PaqueteDatagrama datagramaRegreso =  PaqueteDatagrama((char*) resultado, sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	    socket.envia(datagramaRegreso);
	//}
	
	return 0;
}
