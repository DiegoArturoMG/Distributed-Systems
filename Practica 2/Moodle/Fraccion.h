#ifndef Fraccion_H_
#define Fraccion_H_
class Fraccion{
private:
	int numerador;
	int denominador;
public:
	Fraccion(int = 0, int = 0);
	void setValores(int,int);
	int getNumerador();
	int getDenominador();
	double devolverOperacion();
	Fraccion devolverOperacionMinima();
};

#endif