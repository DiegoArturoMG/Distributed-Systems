#include "SocketDatagrama.h"

#define SEC_PER_DAY   86400
#define SEC_PER_HOUR  3600
#define SEC_PER_MIN   60

using namespace std;

struct timeval getTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);

	printf("Segundos  = %lld\n", (long long) tv.tv_sec);
	printf("Milisegundos  = %lld\n", (long long) tv.tv_usec);

	long hms = tv.tv_sec % SEC_PER_DAY;
	printf("HMS: %ld\n", hms);  
	// mod `hms` to insure in positive range of [0...SEC_PER_DAY)

	// Tear apart hms into h:m:s
	int hour = hms / SEC_PER_HOUR;
	int min = (hms % SEC_PER_HOUR) / SEC_PER_MIN;
	int sec = (hms % SEC_PER_HOUR) % SEC_PER_MIN; // or hms % SEC_PER_MIN

	printf("Current local time: %d:%02d:%02d\n", hour, min, sec);

	return tv;
}

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(7300);
    int * numeros;

    while(1){
    	PaqueteDatagrama datagrama = PaqueteDatagrama(sizeof(int));
	    socket.recibe(datagrama);

	    struct timeval val;
	    val = getTime();
	    
		cout << "Numero [" << val.tv_sec << "]"<< endl;
		cout << "Numero [" << val.tv_usec << "]"<< endl;

		long long valores[2];
		valores[0] = val.tv_sec;
		valores[1] = val.tv_usec;

	    cout << "Se ha establecido conexion:" << endl;
	    cout << "Cliente: " << datagrama.obtieneDireccion() << endl;
	    cout << "Puerto: " << datagrama.obtienePuerto() << endl;
	    PaqueteDatagrama datagramaRegreso =  PaqueteDatagrama((char*) valores, 2*sizeof(long long), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	    socket.envia(datagramaRegreso);
	}
	
	return 0;
}
