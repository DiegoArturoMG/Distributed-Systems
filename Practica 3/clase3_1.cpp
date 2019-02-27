#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa){
	if((dia < 1 || dia > 31) || (anio < 0 || anio > 2019)){
		cout << "Valores ilegales!\n";
		exit(1);
	}
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
	Fecha a,b,c(31,9,2030);
	
	cout<<"Resultado: " << a.convierte() << endl;
	
	if(b.leapyr()){
		cout << "Anio bisiesto" << endl;
	}else{
		cout << "Anio no bisiesto" << endl;
	}
}
