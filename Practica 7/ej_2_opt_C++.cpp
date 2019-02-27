#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	double i=0;
	int Max=10000000;
	double seno=0,coseno=0,tangente=0,logaritmo=0,raizCuad=0;
	while(i < Max){
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raizCuad += sqrt(i);
		i++;
	}
	return 0;
}