#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_
class Temperatura{
private:
	double kelvin;
public:
	Temperatura(double = 35);
	void setTempKelvin(double);
	void setTempFahrenheit(double);
	void setTempCelsius(double);
	void mostrarKelvin();
	void mostrarFahrenheit();
	void mostrarCelsius();
};

#endif