#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangulo::Rectangulo():superiorIzq(0,0,0), inferiorDer(0,0,0){

}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq, double xInfDer, double yInfDer, double zInfDer):superiorIzq(xSupIzq,ySupIzq,zSupIzq), inferiorDer(xInfDer, yInfDer,zInfDer){

}

Rectangulo::Rectangulo(Coordenada c1, Coordenada c2):superiorIzq(c1),inferiorDer(c2){

}

double Rectangulo::obtieneArea(){
	double ancho, alto;
	alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
	ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();
	return (ancho*alto);
}

void Rectangulo::imprimeEsq(){
	cout << "Vertice: (" << superiorIzq.obtenerX() << "," << superiorIzq.obtenerY() << "," << superiorIzq.obtenerZ() << ")" << endl;
	cout << "Vertice: (" << inferiorDer.obtenerX() << "," << inferiorDer.obtenerY() << "," << inferiorDer.obtenerZ() << ")" << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
	return inferiorDer;
}