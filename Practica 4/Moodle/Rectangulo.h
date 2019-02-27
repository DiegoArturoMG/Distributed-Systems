#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Coordenada.h"

class Rectangulo{
private:
	Coordenada superiorIzq;
	Coordenada inferiorDer;
public:
	Rectangulo();
	Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq, double xInfDer, double yInfDer, double zInfDer);
	Rectangulo(Coordenada c1, Coordenada c2);
	double obtieneArea();
	void imprimeEsq();
	void imprimeEsqPolar();
	Coordenada obtieneSupIzq();
	Coordenada obtieneInfDer();
};
#endif