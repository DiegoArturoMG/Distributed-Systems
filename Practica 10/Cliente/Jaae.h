#define Jaae_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class Jaae
{
public:
	Jaae(char *, int, int, int, unsigned int);
	char *obtieneDireccion();
	int obtienePuerto();
	int obtieneValInicial();
	int obtieneValFinal();
	unsigned int obtieneN();
private:
	char ip[16];			//Almacena la IP
	int puerto; 			//Almacena el puerto	
	int valInicial;			//Almacena valor inicial
	int valFinal; 			//Almacena valor final			
	unsigned int n; 		//Almacena n
	
};