#include <iostream>
using namespace std;

int main(){
	int n = 0;
	double r,t;

	cout << "Numero que desea calcular la raiz: ";
	cin >> n;

	r = static_cast<double>(n);
	t = 0;

	while(t != r){
		t = r;
		r = (static_cast<double>(1)/2) * ((n / r) + r);
	}

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
	cout << "Raiz de " << n << " es " << r << endl;

}