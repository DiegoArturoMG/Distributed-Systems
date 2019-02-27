#include <iostream>
#include <vector>
#include <time.h>
/*Using Reserve*/
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
class PoligonoIrreg{
  private:
    vector<Coordenada> datos;
  public:
    void numCoordenadas(int verticesPoly);
    PoligonoIrreg(Coordenada dato);
    void anadeVertice(Coordenada newCoor);
    void imprimeVertice();
};
int main( ){
	// srand(time(NULL));
  unsigned t0, t1;
  t0=clock();
	vector <PoligonoIrreg> poligonos;
	int numPoli=(rand()%100)+1;
	poligonos.reserve(numPoli);
	vector <int> vertices;
	vertices.reserve(numPoli);
  int su=0;
	for (int i = 0; i < numPoli; i++) {
		vertices[i]=(rand()%20)+1;
    poligonos[i].numCoordenadas(vertices[i]);
    su+=vertices[i];
	}
  static int verticesTotales=su;
  cout<<"Vertices totales generados "<<verticesTotales<<endl;
  t1 = clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo de ejecucion: " << time*1000<<" milisegundos" << endl;

  return 0;
}
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){ }

double Coordenada::obtenerX() {
  return x;
}
double Coordenada::obtenerY(){
  return y;
}

void PoligonoIrreg::numCoordenadas (int verticesPoly){
  datos.reserve(verticesPoly);

  for(int i=0;i<verticesPoly;i++){
    Coordenada help(rand()%10,rand()%15);
    anadeVertice(help);
  }

  cout << "Poligono Irregular con vertices " <<verticesPoly <<'\n';
  imprimeVertice();
  cout<<"****************************************"<<endl;
}

PoligonoIrreg::PoligonoIrreg(Coordenada x){
  datos.push_back(x);
}

void PoligonoIrreg::anadeVertice(Coordenada y){
  datos.resize(datos.size()+1);
  datos[datos.size()-1]=y;
  //datos.push_back(y);
}
void PoligonoIrreg::imprimeVertice(){
  cout<<"Imprimiendo vertices "<<endl;
  for(int i=0;i<datos.size();i++){
    cout<<"Vertice " << i+1 << endl;
    cout<<datos[i].obtenerX()<<",";
    cout<<datos[i].obtenerY()<<endl;
  }
}
