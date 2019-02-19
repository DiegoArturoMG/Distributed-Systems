#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz){
	
}

double Coordenada::obtenerX(){
	return x;
}

double Coordenada::obtenerY(){
	return y;
}

double Coordenada::obtenerZ(){
	return z;
}

void Coordenada::setX(double xx){
	x = xx;
}

void Coordenada::setY(double yy){
	y = yy;
}

void Coordenada::setZ(double zz){
	y = zz;
}