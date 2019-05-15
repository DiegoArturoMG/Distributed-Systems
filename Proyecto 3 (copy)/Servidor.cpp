#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Respuesta.h"

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc < 3) {
      std::cerr << "Insertar lo siguiente: puerto | Nombre de archivo" << endl;
      exit(EXIT_FAILURE);
  }

  const short puerto = atoi(argv[1]);
  const char *fileName = const_cast<char *>(argv[2]);

  Respuesta respuesta(puerto);
  struct mensaje mensajeRecibido;
  std::ofstream file(fileName, std::fstream::binary);
  std::streamsize beforeWrite = 0;
  std::streamsize bytesWritten;

  if (!file) {
      cout << "Error" << endl;
      exit(EXIT_FAILURE);
  }

  //int cont = 0;

  cout << "Esperando clientes..." << endl;

  while(1) {
      memcpy(&mensajeRecibido, respuesta.getRequest(), sizeof(struct mensaje));
      //mensajeRecibido = respuesta.getRequest();
      //cout << "Llego cliente" << endl;

      if (mensajeRecibido.operationId == 1) {
          //cout << "mensaje: " << mensajeRecibido.arguments << endl;
          //cout << "tamanio: " << mensajeRecibido.lengthBytes << endl;
          file.write(mensajeRecibido.arguments, mensajeRecibido.lengthBytes);
          bytesWritten = file.tellp() - beforeWrite;
          respuesta.sendReply(reinterpret_cast<char *>(&bytesWritten), mensajeRecibido.IP, mensajeRecibido.puerto, bytesWritten);
          beforeWrite += bytesWritten;
          cout << "Se escribieron: " << file.tellp() << " bytes" << endl;
          //cout << "->" << cont << endl;
          //cont++;
      } else if (mensajeRecibido.operationId == 2) {
          cout << "Archivo recibido con exito" << endl;
          respuesta.sendReply(reinterpret_cast<char *>(&beforeWrite), mensajeRecibido.IP, mensajeRecibido.puerto, beforeWrite);
          file.close();
      }
  }

	return 0;
}
