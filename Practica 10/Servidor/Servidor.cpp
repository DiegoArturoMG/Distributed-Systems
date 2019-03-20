#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){

	int argumento = atoi(argv[1]);

	cout << argumento << endl;
	SocketDatagrama socket = SocketDatagrama(argumento);
    int * numeros;
    
    while(1){
    	PaqueteDatagrama datagrama = PaqueteDatagrama( 3 * sizeof(int));
	    socket.recibe(datagrama);
	    numeros = (int *) datagrama.obtieneDatos();
	    
	    int valInicial = *numeros;
	    numeros++;
		int valFinal = *numeros;
		numeros++;
		int n = *numeros;

		cout << "Valor Inicial: " << valInicial << endl;
		cout << "Valor Final: " << valFinal << endl;
		cout << "n: " << n << endl;
	    	
    	int cont=0;
	    //Calcular si es primo o no, del lado del cliente
		for(int i = valInicial ; i <= valFinal ; i++){
			if(n % i == 0){
				cout << "i: " << i << endl;
				cont++;
			}
		}
		int resultado[1];
		if(cont >= 2){
			cout << "No es Primo" << endl;
			resultado[0] = 0;
			PaqueteDatagrama datagramaRegreso =  PaqueteDatagrama((char*) resultado, sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	    	socket.envia(datagramaRegreso);
		}else{
			cout << "Si es Primo" << endl;
			resultado[0] = 1;
			PaqueteDatagrama datagramaRegreso =  PaqueteDatagrama((char*) resultado, sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	    	socket.envia(datagramaRegreso);
		}
		
	}
	
	return 0;
}
