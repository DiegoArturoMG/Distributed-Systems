#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

char randomLetra(){
	return rand()%26+'A';
}

string randomPalabra(){
	string s;
	for(int i=0;i<3;i++){
		s += randomLetra();
	}
	return s;
}

void imprimirCadenota(string cadena){
	cout << "Cadena" << endl;
	cout << cadena << endl; 
}

void imprimirCadenotaC(const char* cadena){
	for(int i=0;i<strlen(cadena);i+=4){
		cout << cadena[i] << cadena[i+1] << cadena[i+2] << cadena [i+3];
	}
	cout << endl;
}

void generateString(){
	string cadenota;
	int n = 10;
	int caractTot = 3;
	int totCaractAlph = pow(26,caractTot);
	
	for(int i=0;i<n*totCaractAlph;i++){
		cadenota.append(randomPalabra());
		cadenota.append(" ");
	}	

	imprimirCadenota(cadenota);

	int conteo = 0;
	int pos;

	for(int i=0;i<cadenota.length();){
		pos = cadenota.find("IPN",i);
		if(pos != cadenota.npos){
			conteo++;
			i = pos + 4;
			continue;
		}
		break;
	}

	cout << "Se encontraron: " << conteo << " ocurrencias" << endl;
}

void generateCString(){
	char* cadenota = (char*)malloc(0);
	int pos;
	int n = 10;
	int caractTot = 3;
	int totCaractAlph = pow(26,caractTot);
	
	for(pos=0;pos<n*totCaractAlph*(caractTot+1);pos+=(caractTot+1)){
		cadenota = (char*)realloc(cadenota,pos+(caractTot+1));
		cadenota[pos] = randomLetra();
		cadenota[pos+1] = randomLetra();
		cadenota[pos+2] = randomLetra();
		cadenota[pos+3] = ' ';
	}

	imprimirCadenotaC(cadenota);
		
	int conteo = 0;
	
	for(int i = 0;i < strlen(cadenota) ; i += 4){
		if(cadenota[i] == 'I' && cadenota[i+1] == 'P' && cadenota[i+2] == 'N'){
			conteo++;
		}
	}
	cout << "Se encontraron: " << conteo << " ocurrencias" << endl;
}



int main(int argc, char*argv[]){
	srand(time(NULL));
	generateCString();
	//generateString();
}
