#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(int num, int den){
	numerador = num;
	denominador = den;
}

void Fraccion::setValores(int num, int den){
	numerador = num;
	denominador = den;	
	return;
}

int Fraccion::getNumerador(){
	return numerador;
}

int Fraccion::getDenominador(){
	return denominador;
}

double Fraccion::devolverOperacion(){
	return (static_cast<double>(numerador)/denominador);
}

Fraccion Fraccion::devolverOperacionMinima(){
	Fraccion f_m;
	int b = 2;
	while(b <= numerador){
		if(denominador % b == 0 && numerador % b == 0){
			denominador = denominador / b;
			numerador = numerador / b;
		}else{
			b++;
		}
	}
	f_m.setValores(numerador,denominador);
	return f_m;
}

int main(){
	Fraccion f;
	f.setValores(25,15);
	double res = f.devolverOperacion();
	cout << res << endl;
	Fraccion f_m = f.devolverOperacionMinima();
	cout << f_m.getNumerador() << "/" << f_m.getDenominador() << endl;
}