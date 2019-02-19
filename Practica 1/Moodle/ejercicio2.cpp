#include <iostream>
using namespace std;

int main(){
	double t = 0;
	double h = 0;
	const double a = 9.81;

	cout << "Tiempo de caida del objeto: ";
	cin >> t;

	h = (static_cast<double>(1)/2) * a * (t * t);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
	cout << "La altura del edificio es " << h << endl;

}