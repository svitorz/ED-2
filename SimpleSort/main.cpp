#include <iostream>
#include <cctype>
#include "header.h"

using namespace std;

int main(){
  int length, i;

  cout << "Insira o tamanho do vetor:";
  cin >> length;

  int vector[length];

  for (i = 0; i < length; i++) {
    cout << "\nInsira um valor inteiro para a posicao " << (i + 1) << " do vetor:";
    cin >> vector[i];
  }

  cout << "\nVetor desordenado.\n";
  for (i = 0; i < length; i++) {
    std::cout << vector[i] << ". "; 
  }

  char opc;
  cout << "\nInsira o metodo de ordenacao:\n"
          "b - bubble\n"
          "i - insertion\n"
          "s - selection:";

  cin >> opc;

  switch (tolower(opc)) {
    case 'b':
      bubble(vector, length);
      break;
    case 'i':
      insertion(vector, length);
      break;
    case 's':
      selection(vector, length);
      break;
    default:
      break;
      return 0;
  }

  cout << "\nVetor ordenado.\n";
  for (i = 0; i < length; i++) {
    cout << vector[i] << ". "; 
  }

  return 0;
}
