#include <iostream>
using namespace std;

void imprimir(bool vec[],int num){
  cout << "\nLos numeros primos son: " << endl;
  for(int l=2;l<=num;l++){
    if(vec[l] == true){
      cout << l << endl;
    }
  }
}

void calcularPrimos(bool* vec, int num){
  int j=0,k=0;

  for(int ini=2;ini<=num;ini++){
    j = 2 * ini;
    k = 3 * ini;
    if(j<=num && j%2==0){
      vec[j] = false;
    }
    if(k<=num && k%2==1) {
      vec[k] = false;
    }
  }
}

void iniciarVect(bool* vec,int num){
  for(int i=1;i<num;i++){
    vec[i] = true;
  }
}

int main(){
  int num,i,ini,l;

  cout << "Ingresa un numero: " << endl;
  cin >> num;
  
  bool vec[num];

  iniciarVect(&vec[0],num);
  calcularPrimos(&vec[0],num);
  imprimir(vec,num);

  return 0;
}
