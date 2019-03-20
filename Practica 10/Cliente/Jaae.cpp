#include "Jaae.h"

using namespace std;

Jaae::Jaae(char *ipDir, int puert, int valIni, int valFin, unsigned int num){
    memcpy(ip, ipDir, sizeof(char)*16);
    puerto = puert;
	valInicial = valIni;
	valFinal = valFin; 			
	n = num; 		
}

char * Jaae::obtieneDireccion(){
	return ip;
}
	
int Jaae::obtienePuerto(){
	return puerto;
}

int Jaae::obtieneValInicial(){
	return valInicial;
}

int Jaae::obtieneValFinal(){
	return valFinal;
}

unsigned int Jaae::obtieneN(){
	return n;
}