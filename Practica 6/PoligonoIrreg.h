#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include "Coordenada.h"
#include <vector>

using namespace std;


class PoligonoIrregular{
	private:
		vector<Coordenada> vertices;
		vector<double> magnitud;
	public:
		PoligonoIrregular();
		PoligonoIrregular(int n);
		//void anadeVertice(Coordenada v);
		void imprimirVertices();
		void ordenar();
 };

 #endif