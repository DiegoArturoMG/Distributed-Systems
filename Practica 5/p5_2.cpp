#include <iostream>
#include <vector>
using namespace std;
class Coordenada  {
  private:
    double x;
    double y;
  public:
    Coordenada(double = 0, double = 0);
    double obtenerX();
    double obtenerY();
};
class Rectangulo{
  private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
  public:
    Rectangulo();
    Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
};
class PoligonoIrreg{
  private:
    vector<Coordenada> datos;
  public:
    PoligonoIrreg(Coordenada dato);
    void anadeVertice(Coordenada newCoor);
    void imprimeVertice();
};
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
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){ }

double Coordenada::obtenerX() {
  return x;
}
double Coordenada::obtenerY(){
  return y;
}

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

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0){ }
Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }
void Rectangulo::imprimeEsq() {
  cout << "Para la esquina superior izquierda.\n";
  cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
  cout << "Para la esquina inferior derecha.\n";
  cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}
Coordenada Rectangulo::obtieneSupIzq() {
  return superiorIzq;
}
Coordenada Rectangulo::obtieneInfDer(){
  return inferiorDer;
}
