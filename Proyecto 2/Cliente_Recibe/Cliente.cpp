#include "SocketDatagrama.h"

using namespace std;

#define puerto 7300

PaqueteDatagrama enviar(char* valor){
    return PaqueteDatagrama(valor, sizeof(int),"127.0.0.1", puerto);
}

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(puerto);
        
    int identificador=1;

    cout << "Esperando clientes..." << endl;

    while(1){

        PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
        socket.recibe(datagramaRecibe);
        int * ans = (int*)datagramaRecibe.obtieneDatos();

        if(identificador == *ans){
            cout << "Se ha recibido correctamente: " << *ans << endl;
            identificador++;
        }else if(*ans == 0){
            cout << "Se recibieron todos los paquetes correctamente!" << endl;
            identificador = 1;
        }else{
            cout << "Se esperaba: " << identificador << endl;
            cout << "Se recibio: " << *ans << endl;
            PaqueteDatagrama datagramaEnvia = enviar((char*)ans);
            socket.envia(datagramaEnvia);
            exit();
        }



    }

    return 0;
}
