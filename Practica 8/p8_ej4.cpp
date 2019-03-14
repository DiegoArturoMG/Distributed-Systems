#include <iostream>
#include <vector>
#include "Coordenada"
#include "Rectangulo"
#include "PoligonoIrreg"

using namespace std;

int main( ){
  Rectangulo rectangulo1(2,3,5,1);
  Coordenada adasd(0,0);
  Coordenada coor2(4,6);
  Coordenada coor3(7,2);
  Coordenada coor4(14,26);

  PoligonoIrreg poly(adasd);
  poly.anadeVertice(coor2);
  poly.anadeVertice(coor3);
  poly.anadeVertice(coor4);
  poly.imprimeVertice();
  return 0;
}




