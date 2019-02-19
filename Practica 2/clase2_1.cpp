#include <iostream>
using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int = 1, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
};

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

int main(){
	Fecha a,b,c(31,9,2016);
	b.inicializaFecha(17,6,2024);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
}
