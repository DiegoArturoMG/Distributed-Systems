#include "Fecha.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int masVieja_1(Fecha fecha1, Fecha fecha2);
int masVieja_2(Fecha &fecha1, Fecha& fecha2);
int masVieja_3(Fecha *fecha1, Fecha *fecha2);
void setValores(Fecha &fecha);

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

int Fecha::convierte(){
	int resultado = anio * 10000 + mes * 100 + dia;
	return resultado;
}

void Fecha::muestraFecha(){
	cout<<"La fecha es(dia-mes-anio): "<< dia << "-" << mes << "-" << anio << endl;
	return;
}

int masVieja_1(Fecha fecha1, Fecha fecha2){
	int f1 = fecha1.convierte();
	int f2 = fecha2.convierte();
	if(f1 > f2){
		return 1;
	}else if(f1 == f2){
		return 0;
	}else{
		return -1;
	}
}

int masVieja_2(Fecha &fecha1, Fecha& fecha2){
	int f1 = fecha1.convierte();
	int f2 = fecha2.convierte();
	if(f1 > f2){
		return 1;
	}else if(f1 == f2){
		return 0;
	}else{
		return -1;
	}
}

int masVieja_3(Fecha *fecha1, Fecha *fecha2){
	int f1 = fecha1->convierte();
	int f2 = fecha2->convierte();
	if(f1 > f2){
		return 1;
	}else if(f1 == f2){
		return 0;
	}else{
		return -1;
	}
}


void setValores(Fecha &fecha){
	int dia = rand() % 31 + 1;
	int mes = rand() % 12 + 1;
	int anio = rand() % 35 + 1985;
	fecha.inicializaFecha(dia,mes,anio);
	return;
}

int main(){
	Fecha a,b,*a_p,*b_p;

	for(int i=0;i<1000000;i++){
		setValores(a);
		setValores(b);
		
		a_p = &a;
		b_p = &b;
		
		//int val_1 = masVieja_1(a,b);
		//int val_2 = masVieja_2(a,b);
		//int val_3 = masVieja_3(a_p,b_p);
	}

	//printf("%lu\n",sizeof(a));
	//printf("%lu\n",sizeof(&a));
	printf("%lu\n",sizeof(a_p));

}
