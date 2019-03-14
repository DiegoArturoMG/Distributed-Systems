prac_compo: p8_ej4.cpp PoligonoIrreg.o Rectangulo.o Coordenada.o
	g++ p8_ej4.cpp PoligonoIrreg.o Rectangulo.o Coordenada.o -o p8_ej4
PoligonoIrreg: PoligonoIrreg.cpp Rectangulo.o Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c