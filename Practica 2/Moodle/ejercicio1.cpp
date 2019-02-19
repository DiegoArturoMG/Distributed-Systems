#include "Temperatura.h"
#include <iostream>
using namespace std;

Temperatura::Temperatura(double k){
	kelvin = k;
}

void Temperatura::setTempKelvin(double k){
	kelvin = k;
	return;
}

void Temperatura::setTempFahrenheit(double f){
	kelvin = (f - 32) * static_cast<double>(5)/9 + 273.15;
	return;
}

void Temperatura::setTempCelsius(double c){
	kelvin = 273.15 + c;
	return;
}

void Temperatura::mostrarKelvin(){
	cout << "Grados Kelvin: " << kelvin << endl;
	return;
}

void Temperatura::mostrarFahrenheit(){
	cout << "Grados Fahrenheit: " << ((kelvin - 273.15) * static_cast<double>(9)/5 + 32)  << endl;
	return;
}

void Temperatura::mostrarCelsius(){
	cout << "Grados Centigrados: " << kelvin - 273.15 << endl;
	return;
}

int main(){
	Temperatura t;
	t.setTempFahrenheit(36);
	t.mostrarFahrenheit();

	t.setTempCelsius(50);
	t.mostrarCelsius();

	t.setTempKelvin(21);
	t.mostrarKelvin();

}
