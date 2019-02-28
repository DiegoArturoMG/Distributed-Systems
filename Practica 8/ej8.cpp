#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

const double PI = acos(-1.0);
//const float PI = acos(-1.0);
//const long double PI = acos(-1.0);

class Circulo{
private:
	double radio;
public:
	Circulo(double = 1.0);
	double calcval();
	//double getRadio();
};

Circulo::Circulo(double r) : radio(r){

}

double Circulo::calcval(){ //Area
	return(PI * radio * radio);
}

/*
double Circulo::getRadio(){
	return radio;
}
*/

class Cilindro : public Circulo{
protected:
	double longitud;
public:
	Cilindro(double r = 1.0, double l = 1.0) : Circulo(r), longitud(l) {}
	double calcval();
};

double Cilindro::calcval(){ //Volumen
	/*
	//return (longitud * getRadio() * getRadio() * PI);
	//return (longitud * radio * radio * PI);
	*/
	return (longitud * Circulo::calcval());
}

class Toroide: public Cilindro{
private:
public:
	Toroide(double l = 1.0) : Cilindro(l) {}	
	double calcval();
};

double Toroide::calcval(){ //Volumen
	/*
	//return (longitud * getRadio() * getRadio() * PI);
	//return (longitud * radio * radio * PI);
	*/
	return (longitud * Circulo::calcval());
}

int main(){
	
	//Ejercicio practica
	Circulo Circulo_1, Circulo_2(2);
	Cilindro Cilindro_1(3,4);
	cout << "El área de Circulo_1 es " << Circulo_1.calcval() << endl;
	cout << "El área de Circulo_2 es " << Circulo_2.calcval() << endl;
	cout << "El volumen de Cilindro_1 es " << Cilindro_1.calcval() << endl;
	Circulo_1 = Cilindro_1;
	cout << "\nEl área de Circulo_1 es ahora " << Circulo_1.calcval() << endl;

	//Ejercicio 1
	//double: 48 -> 8 bytes
	//float: 22 -> 4 bytes
	//Long double: 48 -> 16 bytes
	/*
	std::cout << std::fixed << std::setprecision(48) << PI << endl;
	cout << sizeof(PI) << endl; 
	*/

	//Ejercicio 2
	/*
	Cilindro_1 = Circulo_1;
	*/

	//Ejercicio 3
	Toroide t(5);
	cout << "El volumen de toroide es " << t.calcval() << endl;


}