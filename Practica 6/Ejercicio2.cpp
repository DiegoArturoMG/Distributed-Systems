#include "PoligonoIrreg.h"
#include "Coordenada.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){
	//Ejercicio 1
	int n = 10;
	PoligonoIrregular poligono(n);
	poligono.imprimirVertices();
	cout<<"\n"<<endl;
	//Ejercicio 2
	poligono.ordenar();
	poligono.imprimirVertices();
	
	return 0;
}