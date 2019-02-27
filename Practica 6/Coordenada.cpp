#include "Coordenada.h"

#include <iostream>
#include <cmath>

using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){
	magnitud = sqrt(pow(xx,2)+pow(yy,2));
}

double Coordenada::obtenerX(){
	return x;
}

double Coordenada::obtenerY(){
	return y;
}

double Coordenada::obtenerMagnitud(){
	return magnitud;
}