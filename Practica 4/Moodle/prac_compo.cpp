#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main(){
	//Rectangulo rectangulo1(2,3,5,1);
	
	//Coordenadas Rectangulares
	Coordenada CA(1,4,7);
	Coordenada CH(2,5,8);
	Ortoedro ortoedro(CA,CH);
	
	ortoedro.obtieneVerticesOr();
	ortoedro.obtieneAreaOr();
	ortoedro.obtieneVolumenOr();

	return 0;
}