#include <iostream>
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"

using namespace std;

PoligonoIrreg::PoligonoIrreg(Coordenada x){
  datos.push_back(x);
}

void PoligonoIrreg::anadeVertice(Coordenada y){
  datos.push_back(y);
}

void PoligonoIrreg::imprimeVertice(){
  cout<<"Imprimiendo vertices"<<endl;
  for(int i=0;i<datos.size();i++){
    cout<<"Vertice" << i+1 << endl;
    cout<<datos[i].obtenerX()<<",";
    cout<<datos[i].obtenerY()<<endl;
  }
}