#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define TAM_MAX_DATA 3500

int main(int argc, char*argv[]) {

	if (argc < 4) {
        cout << "Insertar lo siguiente: IP | Puerto | Nombre del archivo" << endl;
        exit(EXIT_FAILURE);
    }

    char *address = const_cast<char *>(argv[1]);
    ushort port = atoi(argv[2]);
    char *fileName = const_cast<char *>(argv[3]);

	ifstream file(fileName, std::ifstream::binary);

    if (!file) {
        std::cerr << "Error al abrir archivo" << endl;
        exit(EXIT_FAILURE);
    }

    char buffer[TAM_MAX_DATA];
    char *archivoEnviar;
    std::streamsize bytesRead;
    std::streamsize bytesWritten;
    
    Solicitud solicitud;

    cout << "Enviando Archivo: '" << fileName << endl;

    //int cont = 0;

    while (!file.eof()) {
        file.read(buffer, sizeof(buffer));
        bytesRead = file.gcount();

        //cout << "Total de bytes a enviar: " << bytesRead << endl;
        //cout << "Enviando..." << endl;

        int operation = 1;

        archivoEnviar = solicitud.doOperation(address, port, operation, buffer, bytesRead);

        bytesWritten = *reinterpret_cast<streamsize *>(archivoEnviar);

        cout << "BytesWritten: " << bytesWritten << endl;
        //cout << "->" << cont << endl;
        //cont++;

        if (bytesWritten != bytesRead) {
            cout << "Error" << endl;
            exit(EXIT_FAILURE);
        }
    }

    archivoEnviar = solicitud.doOperation(address, port, 2, NULL, 0);

    bytesWritten = *reinterpret_cast<streamsize *>(archivoEnviar);
    cout << "Se envio el archivo correctamente" << endl;

	return 0;
}
