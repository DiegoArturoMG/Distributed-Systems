#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
private:
	double x; //r
	double y; //theta
public:
	Coordenada(double = 0, double = 0);
	double obtenerX();
	double obtenerY();
	void setX(double xx);
	void setY(double yy);
};
#endif