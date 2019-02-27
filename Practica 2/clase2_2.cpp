#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa){
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha(){
	cout<<"La fecha es(dia-mes-anio): "<< dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	int resultado = anio * 10000 + mes * 100 + dia;
	return resultado;
}

bool Fecha::leapyr(){
	if(((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0)){
		return true;
	}else{
		return false;
	}
}

int main(){
	Fecha a,b,c(21,9,1973);
	b.inicializaFecha(17,6,2024);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	//Ejercicio 1
	/*cout << "Dia: " << a.dia << endl;
	cout << "Mes: " << a.mes << endl;
	cout << "Año: " << a.anio << endl;*/

	//Ejercicio 3
	cout<<"Resultado: " << a.convierte() << endl;
	
	//Ejercicio 4
	if(b.leapyr()){
		cout << "Anio bisiesto" << endl;
	}else{
		cout << "Anio no bisiesto" << endl;
	}
}
