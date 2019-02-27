#include "Rectangulo.h"
#include "Coordenada.h"
#include "Ortoedro.h"

#include <iostream>
#include <cmath>
using namespace std;

Ortoedro::Ortoedro():CA(0,0,0),CH(0,0,0){

}

Ortoedro::Ortoedro(Coordenada c1, Coordenada c2):CA(c1),CH(c2){
	rectangulo[0] = Rectangulo(Coordenada(CA.obtenerX(),CH.obtenerY(),CH.obtenerZ()),CA); //Cara A
	rectangulo[1] = Rectangulo(Coordenada(CA.obtenerX(),CA.obtenerY(),CH.obtenerZ()),Coordenada(CH.obtenerX(),CA.obtenerY(),CA.obtenerZ())); //Cara B
	rectangulo[2] = Rectangulo(Coordenada(CA.obtenerX(),CH.obtenerY(),CH.obtenerZ()),Coordenada(CH.obtenerX(),CA.obtenerY(),CH.obtenerZ())); //Cara C
	rectangulo[3] = Rectangulo(Coordenada(CA.obtenerX(),CH.obtenerY(),CA.obtenerZ()),Coordenada(CH.obtenerX(),CA.obtenerY(),CA.obtenerZ())); //Cara D
	rectangulo[4] = Rectangulo(CH,Coordenada(CA.obtenerX(),CH.obtenerY(),CA.obtenerZ())); //Cara E
	rectangulo[5] = Rectangulo(Coordenada(CH.obtenerX(),CA.obtenerY(),CH.obtenerZ()),Coordenada(CH.obtenerX(),CH.obtenerY(),CA.obtenerZ())); //Cara F
}

void Ortoedro::obtieneVerticesOr(){
	rectangulo[0].imprimeEsq();
	rectangulo[1].imprimeEsq();
	rectangulo[4].imprimeEsq();
	rectangulo[5].imprimeEsq();
}

void Ortoedro::obtieneAreaOr(){
	double areaBase = rectangulo[2].obtieneArea();
	cout << "El area de la superficie es: " << areaBase << endl;
}

void Ortoedro::obtieneVolumenOr(){
	double vol = rectangulo[2].obtieneArea()*(CH.obtenerZ()-CA.obtenerZ());
	cout << "El volumen del Ortoedro es: " << vol << endl;
}

void Ortoedro::imprimeEsqOr(){
	cout << "CA(x) = " << CA.obtenerX() << " CA(y) = " << CA.obtenerY() << " CA(z) = " << CA.obtenerZ() << endl;
	cout << "CH(x) = " << CH.obtenerX() << " CH(y) = " << CH.obtenerY() << " CH(z) = " << CH.obtenerZ() << endl;
}