#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

int main(){
	//Rectangulo rectangulo1(2,3,5,1);
	
	//Coordenadas Rectangulares
	Rectangulo rectangulo1(Coordenada(2,3),Coordenada(5,1));

	//Coordenadas Polares
	//Rectangulo rectangulo1(Coordenada(3.4641016151377544,56.309932474020215),Coordenada(5.0990195135927845,11.309932474020213));
	//rectangulo1.transformar();

	rectangulo1.obtieneArea();

	return 0;
}