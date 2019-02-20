#include "PoligonoIrreg.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

PoligonoIrregular::PoligonoIrregular(){ 

}

double getAleatorio(){
	return (double)(rand() % 20001)/100-100.001;
} 

PoligonoIrregular::PoligonoIrregular(int n){ 
	srand((unsigned) time(NULL));
	for (int i = 0; i < n; i++){
		vertices.push_back(Coordenada(getAleatorio(),getAleatorio()));
	}	
}

void PoligonoIrregular::imprimirVertices(){
	vector<Coordenada>::iterator i;
	for (i = vertices.begin(); i != vertices.end(); i++){
 		cout << "x = " << i->obtenerX() << "\ty = " << i->obtenerY() << "\tMagnitud = " << i->obtenerMagnitud()<<endl;
	}
}

bool mayor(Coordenada c1, Coordenada c2){
	return c1.obtenerMagnitud() < c2.obtenerMagnitud();
}

void PoligonoIrregular::ordenar(){
	sort(vertices.begin(),vertices.end(),mayor);
}
