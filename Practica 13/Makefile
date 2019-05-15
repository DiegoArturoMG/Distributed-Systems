animaciongfx: animacion.cpp gfx.c animacion.o gfx.o
	g++ gfx.o animacion.o -o animacion -lX11
animacion: animacion.cpp gfx.o 
	g++ animacion.cpp -c
gfx: gfx.c gfx.h
	gcc gfx.c -c

