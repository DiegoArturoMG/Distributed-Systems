#include <iostream>
using namespace std;

int main(){
	const double PI = 3.1415926;
	double radio = 0;
	double area = 0;

	cout << "!!!Calcular area de circulo!!!" << endl;
	cout << "Radio: ";
	cin >> radio;

	//Modificar una constante
	//PI = 25;

	area = PI * (radio * radio);
	cout << "El area es: " << area << endl;

	return 0;
}