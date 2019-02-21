#include <iostream>
using namespace std;

int main() {

  int num, i, inicia, j, k, l;

  cout << "Ingresa un numero natural: " << endl;
  cin >> num;
  bool vector[num];

  cout << endl;

  for (size_t i = 1; i < num; i++){
    /* code */
    vector[i] = {true};
  }

  for (size_t inicia = 2; inicia <= num; inicia++) {
    /* code */
    j = 2 * inicia;
    k = 3 * inicia;
    if (j <= num && j%2 == 0) {
      /* code */
      vector[j] = {false};
    }
    if (k <= num && k%2 == 1) {
      /* code */
      vector[k] = {false};
    }
  }

  for (size_t l = 2; l <= num; l++) {
    /* code */
    if (vector[l] == true) {
      /* code */
      cout << l << endl;
    }
  }

  cout << endl;

  return 0;
}
