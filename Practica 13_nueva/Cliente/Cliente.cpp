#include "SocketDatagrama.h"
#include <cmath>
#include "gfxModified.h"
#include <unistd.h>

using namespace std;

#define ANCHURA 810
#define ALTURA 200
#define SEC_PER_DAY   86400
#define SEC_PER_HOUR  3600
#define SEC_PER_MIN   60

int getMilliSeconds(long long milliseconds){
    return milliseconds/10000;
}

int getSecond(long long segundos){
    return (segundos) % SEC_PER_MIN;
}

int getMinute(long long segundos){
    return (segundos / SEC_PER_MIN) % 60;
}

int getHour(long long segundos){
    return (segundos / SEC_PER_HOUR) % 24;
}

void graficar(long long seconds, long long millisec){
    int i, contador;

    gfx_open(ANCHURA, ALTURA, "Reloj");
    gfx_color(87,1,2);
    //cout << "Segundos = " << seconds << endl;

    cout << getHour(seconds) << ":" << getMinute(seconds) << ":" << getSecond(seconds) << ":" << getMilliSeconds(millisec) << endl;

    int hora,minutos,segundos,milisegundos;

    gfx_color(4, 255, 0);

    while(1){
        //Hora
        hora = getHour(seconds);

        //Minutos
        minutos = getMinute(seconds);

        //Segundos
        segundos = getSecond(seconds);

        //Milisegundos
        milisegundos = getMilliSeconds(millisec);

        gfx_clear();
        gfx_display_ascii(30, 10, 10 , (hora/10)+48);
        gfx_display_ascii(120, 10, 10 , (hora%10)+48);      

        gfx_display_ascii(250, 10, 10 , (minutos/10)+48);
        gfx_display_ascii(340, 10, 10 , (minutos%10)+48);

        gfx_display_ascii(470, 10, 10 , (segundos/10)+48);
        gfx_display_ascii(570, 10, 10 , (segundos%10)+48);
     
        gfx_display_ascii(710, 10, 10 , (milisegundos/10)+48);
        millisec +=  10000;

        gfx_flush();

        usleep(10000);

        if(millisec > 1000000){
            millisec = 0;
            seconds++;
        }
    }

}

int main(int argc, char const *argv[]){
    //Inicio
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long inicio_sec = tv.tv_sec;
    long long inicio_usec = tv.tv_usec;

	SocketDatagrama socket = SocketDatagrama(0);
    int numeros[1];
    numeros[0] = 0;

    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) numeros, sizeof(int), "127.0.0.1", 7300);
    socket.envia(datagramaEnvia);
    
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(2*sizeof(long long));
    socket.recibe(datagramaRecibe);

    //Recibe
    gettimeofday(&tv, NULL);
    long long final_sec = tv.tv_sec;
    long long final_usec = tv.tv_usec;

    int result_sec = final_sec - inicio_sec;
    int result_usec = final_usec - inicio_usec;
    cout << "Segundos Restantes:" << result_sec << endl;
    cout << "Milisegundos Restantes:" << result_usec << endl;

    long long * ans = (long long*)datagramaRecibe.obtieneDatos();
    cout << "Resultado: " << ans[0] << endl;
    cout << "Resultado: " << ans[1] << endl;

    ans[0] = ans[0] + (result_sec/2);
    ans[1] = ans[1] + (result_usec/2);

    graficar(ans[0],ans[1]);

    return 0;
}
