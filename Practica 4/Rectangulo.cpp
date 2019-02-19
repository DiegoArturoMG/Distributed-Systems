#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangulo::Rectangulo():superiorIzq(0,0), inferiorDer(0,0){

}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq,ySupIzq), inferiorDer(xInfDer, yInfDer){

}

Rectangulo::Rectangulo(Coordenada c1, Coordenada c2):superiorIzq(c1),inferiorDer(c2){

}

void Rectangulo::transformar(){
	double x, y;
	double radY;

	radY = (superiorIzq.obtenerY() * M_PI) / 180;
	x = superiorIzq.obtenerX() * cos(radY);
	y = superiorIzq.obtenerX() * sin(radY);
	superiorIzq.setX(x);
	superiorIzq.setY(y);

	radY = (inferiorDer.obtenerY() * M_PI) / 180;
	x = inferiorDer.obtenerX() * cos(radY);
	y = inferiorDer.obtenerX() * sin(radY);
	inferiorDer.setX(x);
	inferiorDer.setY(y);
}

void Rectangulo::obtieneArea(){
	double ancho, alto;
	cout << "Calculando el area de un rectangulo dadas sus coordenadas en un plano cartesiano:\n";
	imprimeEsq();

	alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
	ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();

	cout << "El area del rectangulo es = " << ancho * alto << endl;
}

void Rectangulo::imprimeEsq(){
	cout << "Para la esquina superior izquierda.\n";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
	return inferiorDer;
}