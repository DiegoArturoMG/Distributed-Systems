#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
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