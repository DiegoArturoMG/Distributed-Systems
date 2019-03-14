#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>


class PoligonoIrreg{
  private:
    vector<Coordenada> datos;
  public:
    PoligonoIrreg(Coordenada dato);
    void anadeVertice(Coordenada newCoor);
    void imprimeVertice();
};

#endif