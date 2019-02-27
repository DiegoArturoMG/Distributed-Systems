#include <iostream>
using namespace std;

int main(){
	int sTot = 0;
	int s = 0, m = 0, h = 0;

	cout << "Segundos totales: ";
	cin >> sTot;

	h = sTot / 3600;
	sTot = (sTot - (3600 * h)); 
	m = sTot / 60;
	sTot = sTot - (60 * m); 
	s = sTot;

	cout << "Equivalente: " << h << " horas, " << m << " minutos, " << s << " segundos " << endl;

}