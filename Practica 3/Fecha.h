#ifndef FECHA_H_
#define FECHA_H_
class Fecha{
private:
	int dia;
	int mes;
	int anio;
	char val[10000];
public:
	Fecha(int = 1, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leapyr();
};

#endif