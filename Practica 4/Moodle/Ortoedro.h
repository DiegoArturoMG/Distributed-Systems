#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_

#include "Rectangulo.h"
#include "Coordenada.h"

class Ortoedro{
private:
	Rectangulo rectangulo[6];
	Coordenada CA,CH;
public:
	Ortoedro();
	Ortoedro(Coordenada c1, Coordenada c2);
	void obtieneVerticesOr();
	void obtieneAreaOr();
	void obtieneVolumenOr();
	void imprimeEsqOr();
};
#endif