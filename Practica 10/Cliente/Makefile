Cliente: Cliente.cpp PaqueteDatagrama.o SocketDatagrama.o Jaae.o
	g++ Cliente.cpp PaqueteDatagrama.o SocketDatagrama.o Jaae.o -pthread -o Cliente
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
Jaae.o: Jaae.cpp Jaae.h
	g++ Jaae.cpp -c
